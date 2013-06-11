#include <stdio.h>

int main()
{
    char line[80];
    int stairs;     /* 段数 */
    int n;
    int space_cnt;
    int astah_cnt;

    /* 段数の入力 */
    printf("Please Input Stairs > ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &stairs);

    /* 出力 */
    for (n = 1; n <= stairs; n++) {
        for (space_cnt = 1; space_cnt <= (stairs - n); space_cnt++) {
            printf(" ");
        }
        for (astah_cnt = 1; astah_cnt <= (2*n -1); astah_cnt++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
