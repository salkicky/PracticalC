#include <stdio.h>

/**
 * 仕様：
 *      下記の絵を印字する
 *      |    *
 *      |   ***
 *      |  ******
 *      | ********
 *      |**********
 **/
int main()
{
    int stairs_num;
    int astah_num;

    int cnt;

    astah_num = 1;

    for(stairs_num = 5; 0 < stairs_num; stairs_num--) {
        for (cnt = 0; cnt < stairs_num; cnt++) {
            printf(" ");
        }
        for (cnt = 0; cnt < astah_num; cnt++) {
            printf("*");
        }
        printf("\n");
        astah_num += 2;
    }
    return 0;

}
