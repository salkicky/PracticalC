/*****************************
 * 例14-2
 *
 * sscanf の戻り値を使用する
 *******************************/
#include <stdio.h>

int main()
{
    char line[80];      /* 入力行 */
    int count, total;   /* エントリ数と統計値 */
    int scan_count;     /* 調べられたパラメータの数 */

    /* エントリ数と統計値の入力受付 */
    fgets(line, sizeof(line), stdin);
    scan_count = sscanf(line, "%d %d", &count, &total);

    switch (scan_count) {
        case EOF:
        case 0:
            printf("Didn't fine any number\n");
            break;
        case 1:
            printf("Found 'coun'(%d), but not 'total'\n", count);
            break;
        case 2:
            printf("Found 'count'(%d) and 'total'(%d)\n", count, total);
            break;
        default:
            /* 無効 */
            break;
    }

    return 0;
}
