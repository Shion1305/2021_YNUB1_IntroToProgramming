#include <stdio.h>
#include <time.h>

int v2a(long v);

long a2v(int a);

int go(long a);

int go1(long a);

int go2(long a);

int go3(long a);

int go4(long a);

int go4_1(long a);

/**
 * 今回の素数を求めるプログラムでは、
 * 様々な工夫について考え、合計6通りのプログラムが完成しました。
 * 基本的に素数を求めるプログラムはgo関数で定義し、
 * main関数で呼び出すことによって処理を行うという形にしています。
 *
 * 実行時間での最終的な実験結果
 * go1 >> go > go3 > go2 >> go4 > go4_1
 */
int main() {
    long time;
    long a = 3954958801697;
    long cpu_time = 0, cpu_time1 = 0, cpu_time2 = 0;
    for (int i = 0; i < 10; i++) {
        time = clock();
        for (int j = 0; j < 100; ++j) {
            go2(a);
        }
        cpu_time += clock() - time;
        time = clock();
        for (int j = 0; j < 100; ++j) {
            go4(a);
        }
        cpu_time1 += clock() - time;
        time = clock();
        for (int j = 0; j < 100; ++j) {
            go4_1(a);
        }
        cpu_time2 += clock() - time;
    }

    printf("CPU時間0： %d\n", cpu_time);
    printf("CPU時間1： %d\n", cpu_time1);
    printf("CPU時間2： %d\n", cpu_time2);
}

/**
 * 最初につくったのがこのgo関数
 * 以前、～以下の素数を求めるというプログラムを書いた時に
 * longの配列を使うと、巨大な数になった時に
 * メモリ割り当て許容容量をオーバーしたり、オーバーフローが発生してプログラムが動かなくなってしまうということがあり
 * そこで「アドレスによって数値とアドレスをマッピングして必要データ量を削減する」という手法を取った
 * ことから今回その方針を採用して試作を作ってみました。
 * vectorを使えば煩雑なコードになることは防止できるのですが、今回はライブラリをできるだけ使わないという方針を
 * 貫きたかったので少し遠回りで煩雑なやり方になっています。
 * 素数を記録し、素数のみでaを割って確認することで計算量を減らそうとした。
 * @param a
 *
 * 振り返り・考察
 * 割るという試行を減らすために素数に限定して処理を行わせるためにこんな複雑なことをしたのですが
 * そもそも、%という演算は負担はそこまで大きくなく、素数を探索するということを行いながら@a が素数であるかを判断する
 * 方がとても負担が思いため。この方針は今回の問題には適さないと結論付けた。しかし単純に素数を全て見つけるのならば
 * この方針は一面において有用といえよう。
 */
int go(long a) {
    //mod6で1,5となるもの以外は素数でない。(2,3を除く)
    if (a % 6 != 1 && a % 6 != 5) {
        switch (a) {
            case 2:
                printf("%s", "素数です\n");
                return 0;
            case 3:
                printf("%s", "素数です\n");
                return 0;
            default:
                printf("%s", "素数ではありません\n");
                return 0;
        }
    }
    /**
     * @primes 素数を格納していくもの。
     * @flag primesの最大格納位置をflagによって管理している。vectorを使えばこれはいらないが、極力今回はライブラリ使いたくなかったので...
     */
    int primes[500000];
    int flag = 0;
    //アドレス1は5に対応する。
    primes[0] = 1;
    /**2乗の値を比較したかったのですが、オーバーフローが発生しそうと見たことからわざわざこんなコードにしたのですが
     * 後でよくよく考えてみたらaでオーバーフローしない時はオーバーフローは発生しがたいのでこんなことする必要なかった...
     */
    for (int i = 2; a / a2v(primes[flag]) >= a2v(primes[flag]); i++) {
        long target = a2v(i);
        int r = 0;
        for (int j = 0; target / a2v(primes[j]) >= a2v(primes[j]); j++) {
            int x = a2v(primes[j]);
            if (target % x == 0) {
                r = 1;
                break;
            }
        }
        if (r == 0) {
            if (a % target == 0) {
                printf("%s", "素数ではありません\n");
                return 0;
            }
            primes[++flag] = v2a(target);
        }
    }
    printf("%s", "素数です\n");
    return 0;
}

/**
 * go()で使用したアドレスを管理するための関数。
 * ここでは6の倍数に区切って数値とアドレスをマッピングすることで
 * 余計な処理を省こうとした。
 * @param a address
 * @return value
 */
long a2v(int a) {
    switch (a % 2) {
        case 0:
            return 1 + a * 3;
        case 1:
            return 5 + a / 2 * 6;
    }
}

/**
 * go()で使用したアドレスを管理するための関数。
 * これは数値をアドレスに変換する為の関数。
 * 同じく6の倍数ごとで管理している。
 * @param v value
 * @return address
 */
int v2a(long v) {
    switch (v % 6) {
        case 1:
            return v / 6 * 2;
        case 5:
            return v / 6 * 2 + 1;
    }
}

/**
 * go()関数を評価するために作成したもっとも簡単な素数判定方法。
 * aを1~a-1まで全て割り、割り切れるかを確認する。
 * @param a target value
 */
int go1(long a) {
    long i;
    int flag = 0;
    //ごり押し
    for (i = 2; i < a; ++i) {
        if (a % i == 0) {
            flag = 1;
            break;
        }
    }
    //判定結果の出力
    if (flag == 0)
        printf("素数です。\n");
    else
        printf("素数ではありません。\n");
    return 0;
}


/**
 * go()を評価するためにさらに作ったgo1()を改良した関数。
 * この関数は2飛ばしで試行を行い、
 * また試行を行う範囲を3~ルートnに限定している。
 */
#include <math.h>

int go2(long a) {
    int i;
    //2の倍数をはじく。
    if (!(a % 2)) {
        printf("素数ではありません\n");
        return 0;
    }
    //3~ルートnについて試行
    for (i = 3; i <= sqrt(a); i += 2) {
        if (a % i == 0) {
            printf("素数ではありません\n");
            return 0;
        }
    }
    printf("素数です2\n");
    return 0;
}

/**
 * この説明は後述
 */
int sqrtFast(int *current, long *nL, long target);

/**
 * go()関数を見直して制作したコード。結果的には前述した理由から今回の設問には適していないコードである。
 * 余計な部分でのアドレスの使用をとりやめ、必要のなかった煩雑な計算をやめた。Mathライブラリに含まれるsqrt関数を用いてみたが、
 * sqrt関数は本来小数点以下も含めて計算結果を出すものであり、その点で処理が重たい。
 * 今回は小数点以下は要らない。よってこれを改良すべくsqrtFast関数を生み出した。
 * @param a
 * @return
 */

int go3(long a) {
    if (a % 6 != 1 && a % 6 != 5) {
        printf("%s", "素数ではありません\n");
        return 0;
    }
    int primes[500000];
    int flag = 0;
    primes[0] = 1;
    /**
     * @aS sqrtFast関数を動かすための数値。この数値が結果的にx^2<=aとなる最大のxとなる。
     * @nL sqrtFast関数が複数同じ計算を行わないようにnLを設けている。
     * sqrtFastで回帰的に処理を行って上記のaSの値を計算している。
     */
    int aS = 2;
    long nL = 9;
    while (sqrtFast(&aS, &nL, a)) {}
    int tS = 2;
    nL = 9;
    // targetをアドレス値に対応させて変化させていくことによって素数を検証し、網羅している。
    for (int i = 2; aS >= a2v(primes[flag]); i++) {
        long target = a2v(i);
        int r = 0;
        /**
         * sqrtFast関数を用いてtarget>x^2となるxを回帰的に求めている。
         * sqrtFast関数の大きなメリットはここにあり、前の計算結果を引き継いで計算を続行することで
         * 余計な計算処理を防ぐ事ができる。
         */
        sqrtFast(&tS, &nL, target);
        long x;
        for (int j = 0; x = a2v(primes[j]), tS >= x; j++) {
            if (target % x == 0) {
                //targetが素数で割り切れたのでtargetは素数ではない。2つ下のfor文へと続行させる
                r = 1;
                break;
            }
        }
        if (r == 0) {
            //確認したいのはaが素数であるかどうか
            //ちなみにa==targetの場合はありえないのでここでは記述していない。
            if (a % target == 0) {
                printf("%s", "素数ではありません\n");
                return 0;
            }
            //primesに記録。
            primes[++flag] = v2a(target);
        }
    }
    printf("%s", "素数です3\n");
    return 0;
}


/**
 * いよいよsqrtFast関数の登場
 * この関数は、targetがcurrent^2以上であることは分かっているが(current+1)^2であるかどうかを調べる関数である。
 * 回帰的な処理でnLを使用して次の処理に計算結果をつなげることで計算量を減らしている。
 * @param current
 * @param nL
 * @param target
 * @return bool
 */
int sqrtFast(int *current, long *nL, long target) {
    if (target > *nL) {
        ++*current;
        *nL += *current * 2;
        ++*nL;
        return 1;
    }
    return 0;
}

/**
 * go(),go3()系統を諦め、go2()が速かったことを利用して、作ったものである。
 * Mathライブラリのsqrtが小数点以下も計算しているせいで重くなっていると考え、
 * sqrtFastで計算を軽くしたものである。
 * @param a
 * @return
 */
int go4(long a) {
    int j;
    if (!(a % 2)) {
        printf("素数ではありません\n");
        return 0;
    }
    int aS = 2;
    long nL = 9;
    while (sqrtFast(&aS, &nL, a)) {}
    for (j = 3; j <= aS; j += 2) {
        if (a % j == 0) {
            printf("素数ではありません\n");
            return 0;
        }
    }
    printf("素数です4\n");
    return 0;
}


/**
 * go4()の改良型である。go4()は2の倍数で偶数を弾いて高速化をおこなっていたが、
 * ここでは6の倍数で割ったあまりで管理することでさらなる高速化を実現している。
 * @param a
 * @return
 */
int go4_1(long a) {
    int j;
    if (!(a % 2)) {
        printf("素数ではありません\n");
        return 0;
    }
    int aS = 2;
    long nL = 9;
    while (sqrtFast(&aS, &nL, a)) {}
    if (a % 3 == 0) {
        printf("素数ではありません\n");
        return 0;
    }
    for (j = 7; j <= aS; j += 6) {
        if (a % j == 0 || a % (j + 4) == 0) {
            printf("素数ではありません\n");
            return 0;
        }
    }
    printf("素数です4_1\n");
    return 0;
}


