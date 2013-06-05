#include <stdio.h>
#include <string.h>


/*******************************
 * 仕様：
 *      入力された数値を足し続ける。
 *      '0'を入力されたら抜ける。
 *******************************/
int main()
{
    char line[80];
    int total = 0;
    int input_num = 0;
    int scan_length = 0;

    while(1) {
        /* 入力数値の初期化 */
        input_num  = 0;

        /* 数値入力 */
        printf("please input number : ");
        fgets(line, sizeof(line), stdin);
        scan_length = sscanf(line, "%d", &input_num);

        /* 判定 */
        if (scan_length == 0) {
            /* 入力された文字が数字でなければ */
            printf("[ERROR] you input wrong number! please retry.\n");
        } else if(input_num == 0) {
            /* 0 を入力で抜ける */
            printf("bye\n");
            break;
        } else {
            /* ここまで正常なら加算 */
            total += input_num;
        }
        printf("  total = %d\n", total);
    }

    return (0);
}
