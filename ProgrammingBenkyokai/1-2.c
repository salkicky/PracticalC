#include <stdio.h>

/* プロトタイプ宣言 */
void print_space(int total_stairs, int stairs);
void print_astah(int total_stairs, int stairs);

/**
 * main
 */
int main()
{
    char line[80];
    int total_stairs;     /* 段数 */
    int n;
    int space_cnt;
    int astah_cnt;

    /* 段数の入力 */
    printf("Please Input Stairs > ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &total_stairs);

    /* 出力 */
    for (n = 1; n <= total_stairs; n++) {
        print_space(total_stairs, n);
        print_astah(total_stairs, n);
        printf("\n");
    }

    for (n = (total_stairs - 1); 0 < n; n--) {
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

    for (space_cnt = 1; space_cnt <= (total_stairs - stairs); space_cnt++) {
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

    for (astah_cnt = 1; astah_cnt <= (2*stairs -1); astah_cnt++) {
        printf("*");
    }
}
