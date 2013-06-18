#include <stdio.h>

int main()
{
    char line[80];
    int max_stairs;
    int stairs;

    int space_cnt;
    int astah_cnt;

    /* ’i”‚Ì“ü—Í */
    printf("Please Input Max Stairs > ");
    fgets(line, sizeof(line), stdin);
    if (sscanf(line, "%d", &max_stairs) == 0) {
        printf("Error : Input Value is not Number.\n");
        exit(8);
    }

    /* o—Í */
    for (stairs = 0; stairs < max_stairs; stairs++) {
        char stairs_chr[200];
        char *index;

        index = stairs_chr;

        // set ' '
        space_cnt = max_stairs - stairs - 1;
        memset(index, ' ', space_cnt);
        index += space_cnt;

        // set '*'
        astah_cnt = 2 * stairs + 1;
        memset(index, '*', astah_cnt);
        index += astah_cnt;

        *index = '\0';

        printf("%s\n", stairs_chr);
    }

    return 0;
}
