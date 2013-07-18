#include <stdio.h>

/**
 * main
 **/
int main()
{
    char line[80];
    int max_check_num;
    int check_num;
    int prime_counter;

    int i;

    /* チェック数列を入力 */
    printf("Please input number > ");
    fflush(stdout);
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &max_check_num);

    prime_counter = 0;

    /* 1から入力された数値まで順番に素数かどうかをチェックする */
    for (check_num = 1; check_num < max_check_num; check_num++) {
        /* check_numが素数かどうか？の判定 */
        for (i = 2; i < check_num; i++) {
            if ((check_num % i) == 0) {
                /* 割り切れるなら素数ではないので抜ける */
                break;
            }
        }

        /* 素数ならカウント */
        if (i == check_num) {
            prime_counter++;
        }
    }

    printf("prime count : %d\n", prime_counter); 

    return 0;
}
