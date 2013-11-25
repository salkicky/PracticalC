#include <stdio.h>

/* プロトタイプ宣言 */
void print_space(int total_stairs, int stairs);
void print_astah(int total_stairs, int stairs);

/**
 * main
 */
int main()
{
    char line[80];          /* 入力取り込み用バッファ */
    int total_stairs;       /* 段数 */
    int n;                  /* ループカウンタ */

    /* 段数の入力値を取り込み */
    printf("Please Input Stairs > ");
    fgets(line, sizeof(line), stdin);
    if (sscanf(line, "%d", &total_stairs) == 0) {
        printf("Error : Input Value is not Number.\n");
        exit(8);
    }

    /* 出力 */
    /* 初めの△を出力する */
    for (n = 0; n < total_stairs; n++) {
        print_space(total_stairs, n);
        print_astah(total_stairs, n);
        printf("\n");
    }

    /* 後の▽を出力する */
    for (n = (total_stairs - 2); 0 <= n; n--) {
        print_space(total_stairs, n);
        print_astah(total_stairs, n);
        printf("\n");
    }

    return 0;
}

/**
 * print_space : 空白を出力する
 * [in] int total_stairs        全段数
 * [in] int stairs              印字中の段数
 */
void print_space(int total_stairs, int stairs)
{
    int space_cnt;

    for (space_cnt = 0; space_cnt < (total_stairs - stairs - 1); space_cnt++) {
        printf(" ");
    }
}

/**
 * print_astah : アスタリスクを出力する。
 * [in] int total_stairs        全段数
 * [in] int stairs              印字中の段数
 * */
void print_astah(int total_stairs, int stairs)
{
    int astah_cnt;

    for (astah_cnt = 0; astah_cnt < (2*stairs + 1); astah_cnt++) {
        printf("*");
    }
}
