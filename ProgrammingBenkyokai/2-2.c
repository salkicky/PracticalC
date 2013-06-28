/********************************************************
 * 課題2-2
 * 
 * 与えられた数値を素因数分解して表示する。
 *********************************************************/
#include <stdio.h>

/*
 * プロトタイプ宣言
 */
int get_next_prime(int current_prime);


/*
 * main
 */
int main()
{
    char line[80];                              /* 入力バッファ     */
    int input_num;                           /* 入力値           */
    int check_num;                           /* 確認中の番号     */
    int cnt;                                    /* ループカウンタ   */

    int prime;

    int prime_decomp[100];
    int d_index;

    // 素因数分解する数値を取得
    printf("Please Input Number > ");
    fgets(line, sizeof(line), stdin);
    if (sscanf(line, "%d", &input_num) == 0) {
        printf("Error : not a number [%s]\n", line);
        exit(9);
    }

    d_index = 0;
    check_num = input_num;

    while (1) {
        // 初期化
        prime = 2; 

        /*
         * check_num が素数であるか？をチェック
         */
        while (1) {
            prime = get_next_prime(prime);
            if (check_num <= prime) {
                /* 終了 */ 
                break;
            }

            if ((check_num % prime) == 0) {
                /* 要素として記憶 */
                prime_decomp[d_index] = prime;
                d_index++;
                /* 割った値を次のループでチェックする数として更新 */
                check_num = check_num / prime;
            }
        }

        /*
         * 終了判定 
         */
        if (check_num <= prime) {
            // check_num が素数なら終了
            prime_decomp[d_index] = check_num;
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

int get_next_prime(int current_prime)
{
    int i;
    int check_num;
    int next_prime = current_prime;

    for (check_num = (current_prime + 1); ; check_num++) {
        for (i = 2; i < check_num; i++) {
            if ((check_num % i) == 0) {
                // 割り切れるなら素数ではないので抜ける
                break;
            }
        }

        if (i = check_num) {
            // 素数なら
            next_prime = check_num;
            break;
        }
    }

    return next_prime;
}
