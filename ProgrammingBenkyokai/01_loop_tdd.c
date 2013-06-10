#include <stdio.h>

int main()
{
    char line[80];
    int stairs;     /* ’i” */
    int n;
    int space_cnt;
    int astah_cnt;

    /* ’i”‚Ì“ü—Í */
    printf("Please Input Stairs > ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &stairs);

    /* o—Í */
    for (n = 1; n <= stairs; n++) {
        for (space_cnt = 0; space_cnt < (stairs - n); space_cnt++) {
            printf(" ");
        }
        for (astah_cnt = 0; astah_cnt < (2*n -1); astah_cnt++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
