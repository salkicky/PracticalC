/********************************************************
 * 課題2-2
 * 
 * 与えられた数値を素因数分解して表示する。
 *********************************************************/
#include <stdio.h>

int main()
{
    char line[80];                              /* 入力バッファ     */
    int input_number;                           /* 入力値           */
    int check_number;                           /* 確認中の番号     */
    int cnt;                                    /* ループカウンタ   */

    int prime;

    int prime_decomp[100];
    int d_index;

    /* 数値を入力 */
    printf("Please Input Number > ");
    fgets(line, sizeof(line), stdin);
    if (sscanf(line, "%d", &input_number) == 0) {
        printf("Error : not a number [%s]\n", line);
        exit(9);
    }

    d_index = 0;
    check_number = input_number;

    while (1) {

        /* 素数のリストを取得する */
        prime = 0; 

        while (1) {
            prime = get_prime(prime);
            if (check_number <= prime) {
                /* 終了 */ 
                break;
            }

            if ((check_number % prime) == 0) {
                /* 要素として記憶 */
                prime_decomp[d_index] = prime;
                d_index++;
                /* 割った値を次のループでチェックする数として更新 */
                check_number = check_number / prime;
            }
        }

        if (check_number <= prime) {
            /* もう割り切れないので終了 */
            prime_decomp[d_index] = check_number;
            d_index++;
            break;
        }
    }

    printf("-------------------\n");
    for (cnt = 0; cnt < d_index; cnt++) {
        printf("%d\n", prime_decomp[cnt]);
    }
    
    return 0;
}

int get_prime(int min_prime)
{
    int i;
    int prime = min_prime;

    for (i = min_prime; 
}
