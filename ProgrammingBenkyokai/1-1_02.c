#include <stdio.h>

int main()
{
    char line[80];
    int max_stairs;
    int stairs;

    int space_cnt;
    int astah_cnt;

    /* 段数の入力 */
    printf("Please Input Max Stairs > ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &max_stairs);

    /* 出力 */
    for (stairs = 1; stairs <= max_stairs; stairs++) {
        char stairs_chr[80];
        char *index;

        index = stairs_chr;

        space_cnt = max_stairs - stairs;
        memset(index, ' ', space_cnt);
        index += space_cnt;

        astah_cnt = 2 * stairs - 1;
        memset(index, '*', astah_cnt);
        index += astah_cnt;

        *index = '\0';

        printf("%s\n", stairs_chr);
    }

    return 0;
}
