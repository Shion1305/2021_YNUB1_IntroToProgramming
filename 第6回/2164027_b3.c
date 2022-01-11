#include <stdio.h>
#include <stdlib.h>

void youAreAnIdiot();

int go();

int getLN(int x);

int calcAD(int ap);

void input(int *s);

void printStatus();

void fight();

void train();

void printDigit(int x);

/**
 * HP stands for Hit Point.
 * AP stands for Attack Point.
 *
 * hp indicates HP of the player
 * ehp indicates HP of the monster
 * ap indicates AP of the player
 * eap indicates AP of the monster
 * r1,r2は入力範囲を調整するための変数。
 */
int hp, ehp, ap, eap, r1, r2, sd, esd;

int main() {
    //initial value for the player and monster
    hp = 2000, ehp = 1000, ap = 150, eap = 200;

    printf("レベル1のモンスターに出くわした!\n");
    if (go()) {
        printf("レベル1のモンスターに打ち勝った!\n");
        printf("休憩がてらラーメンを食べた!\n");
        printf("HPが%d増えた!\n", 3000);
        hp += 3000;
        printf("レベル2のモンスターに出くわした!\n");
        ehp = 3000;
        eap = 400;
        if (go()) {
            printf("レベル2のモンスターに打ち勝った!\n");
            printf("休憩がてらステーキを食べた!\n");
            printf("HPが%d増えた!\n", 3000);
            hp += 4000;
            printf("レベル2のモンスターに出くわした!\n");
            ehp = 6000;
            eap = 1500;

            printf("レベル3のモンスターに出くわした!\n");
            if (go()) {
                printf("レベル3のモンスターに打ち勝った!\n");
                printf("やった!君の運の強さが証明されたね!\n");
                return 0;
            } else {
                printf("君の運の強さは証明できなかった...");
            }
        } else {
            printf("君の運の強さは証明できなかった...");
        }
    } else {
        printf("君の運の強さは証明できなかった...");
    }
}

int go() {
    do {
        int in;
        r1 = rand() % 20000 - 10000;
        r2 = r1 + rand() % 500 + 100;

        printf("さあどうする?\n1. 戦う  2. スキルアップ\n");
        input(&in);
        switch (in) {
            case 1:
                fight();
                break;
            case 2:
                train();
                break;
            default:
                printf("問題文を読もう...\n");
        }
    } while (hp > 0 && ehp > 0);
    if (hp < 0) {
        return 0;
    } else {
        return 1;
    }
}


/**
 * This method calculates the damage of player/monster bases on their ap.
 * AttackDamage is set to be within  85% to 115% of their AttackPower.
 * @param ap
 * @return final AttackDamage
 */
int calcAD(int ap) {
    return ap * (rand() % 16 + 100) / 100;
}


void fight() {
    int in;
    printf("さあ%d~%dの中から好きな数字を入力して、君の運の強さを見せつけるんだ!!\n", r1, r2);
    input(&in);
    if (r1 > in || r2 < in) {
        youAreAnIdiot();
    } else {
        if (in % 3 == rand() % 3) {
            printf("呪文が効いた。\n");
            int dp = calcAD(ap);
            ehp -= dp;
            printf("%dのダメージを与える事に成功した。\n", dp);
        } else {
            printf("呪文は効かなかった。\n");
        }
        if (in % 4 == rand() % 4) {
            int edp = calcAD(eap);
            printf("モンスターから%dのダメージを受けた\n", edp);
            hp -= edp;
        }
        printStatus();
    }

}

void train() {
    int in;
    printf("さあ%d~%dの中から好きな数字を入力して、君の運の強さを見せつけるんだ!!\n", r1, r2);
    input(&in);
    if (r1 > in || r2 < in) {
        youAreAnIdiot();
    } else {
        if (in % 3 == rand() % 3) {
            printf("スキルアップに失敗...\n");
        } else {
            int up = (rand() % 30) + 10;
            printf("スキルアップに成功! 攻撃力(AP)が%d増加\n", up);
            ap += up;
        }
        if (in % 3 == rand() % 3) {
            int edp = calcAD(eap);
            printf("モンスターから%dのダメージを受けた\n", edp);
            hp -= edp;
        }
        printStatus();
    }
}

/**
 * This function prints the status of current game.
 */
/** DEFAULT FORMAT
 * ||==============================================||
 * || Name         || HP     | AP     | SUM DAMAGE ||
 * ||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||
 * || You          ||        |        |            ||
 * || Monster Lv.1 ||        |        |            ||
 * ||==============================================||
*/
void printStatus() {
    printf("||==============================================||\n|| NAME         || HP     | AP     | SUM DAMAGE ||\n||~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~||\n|| You          || ");
    printDigit(hp);
    printf("| ");
    printDigit(ap);
    printf("| ");
    printDigit(sd);
    printf("    ||\n|| Monster      || ");
    printDigit(ehp);
    printf("| ");
    printDigit(eap);
    printf("| ");
    printDigit(esd);
    printf("    ||\n||==============================================||\n");

}

void printDigit(int x) {
    printf("%d", x);
    for (int i = 0; i < 7 - getLN(x); ++i) {
        printf(" ");
    }
}


/**
 * scanfをinput関数内に置くことで、デバッグを楽にする。
 * →こうすると、勝率の計算を趣味レーションすることでゲームの難易度を調整することができる。
 */
void input(int *s) {
    scanf("%d", s);
}

/**☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺You Are An Idiot☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺
 * ☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺You Are An Idiot☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺
 * ☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺You Are An Idiot☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺
 * ☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺You Are An Idiot☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺
 * ☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺You Are An Idiot☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺☺
 */
void youAreAnIdiot() {
    printf("「あ...あれ...?なにかがおかしいぞう...??!!!!!」\n");
    printf("「呪文を間違えたぁ!!」\n");
    printf("勢いづいたモンスターからダイレクトに攻撃を間違えた数字を出してしまったため、間違えてモンスターの餌を与えてしまった。\n");
    printf("大やけどをした。25%%のダメージ\n");
    hp *= 3;
    hp /= 4;
    printStatus();
    printf("※問題文は良く読みましょう。\n");
}

/**
 * This func calculates the number of digits.
 * @return number of digits
 */

int getLN(int t) {
    int i = 1;
    if (t & 0x80000000) {
        //reverse negative value to posit++++++ive by
        t = t ^ 0xffffffff + 1;
        i++;
    }


    while (t > 9) {
        t /= 10;
        i++;
    }
    return i;
}