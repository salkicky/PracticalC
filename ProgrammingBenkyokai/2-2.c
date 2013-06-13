#include <stdio.h>

/********************************************************
 * main -- 素因数分解する
 * 
 *
 *********************************************************/
int main()
{
    char line[80];
    int input_number;

    int check_number;
    int cnt;

    /* 数値を入力 */
    printf("Please Input Number > ");
    fgets(line, sizeof(line), stdin);
    if (sscanf(line, "%d", &input_number) == 0) {
        printf("Error : not a number [%s]\n", line);
        exit(9);
    }


    /* まず素数のリストを作成する */


    /* 次に、素数のリストの中から、入力値が割り切れるか？を確認する */
    // 4
    while (input_number > 1) {
        for (cnt = 2; cnt < input_number; cnt++) {
            if (input_number % cnt == 0
        }
        input_number--;
    }
    
}
