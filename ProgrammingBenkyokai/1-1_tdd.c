#include <stdio.h>

int main()
{
    char line[80];
    int stairs;     /* íiêî */
    int n;
    int space_cnt;
    int astah_cnt;

    /* íiêîÇÃì¸óÕ */
    printf("Please Input Stairs > ");
    fgets(line, sizeof(line), stdin);
    if (sscanf(line, "%d", &stairs) == 0) {
        printf("Error : Input Value is not Number.\n");
        exit(8);
    }

    /* èoóÕ */
    for (n = 0; n < stairs; n++) {
        for (space_cnt = 0; space_cnt < (stairs - n -1); space_cnt++) {
            printf(" ");
        }
        for (astah_cnt = 0; astah_cnt < (2*n + 1); astah_cnt++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
