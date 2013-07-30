/********************************************************
 * 課題2-2
 * 
 * 与えられた数値を素因数分解して表示する。
 *********************************************************/
#include <stdio.h>


#define MAX_PRIME_LIST  100
const int MIN_PRIME = 2;

/*
 * プロトタイプ宣言
 */
static int init_prime(void);
static int get_prime_decomp(const int num, int *prime_decomp_p);
static int get_next_prime(int current_prime);

/******************************************************
 * main
 ******************************************************/
int main()
{
    char buf[80];                               /* 入力バッファ     */
    int input_num;
    int check_num;                              /* 確認中の番号     */
    int cnt;                                    /* ループカウンタ   */

    int prime_list[MAX_PRIME_LIST];
    int size;

    // 素因数分解する数値を取得
    printf("Please Input Number > ");
    fflush(stdout);
    fgets(buf, sizeof(buf), stdin);
    if (sscanf(buf, "%d", &input_num) == 0) {
        printf("Error : not a number [%s]\n", buf);
        return(9);
    }

    // 素因数分解
    size = get_prime_decomp(input_num, prime_list);

    // 計算結果の確認
    check_num = 1;
    for (cnt = 0; cnt < size; cnt++) {
        check_num *= prime_list[cnt];
    }
    if (check_num != input_num) {
        printf("Error : result is not equal input number.\n");
        return 1;
    }
    
    // 結果を出力
    printf("-------------------\n");
    for (cnt = 0; cnt < size; cnt++) {
        printf("%d\n", prime_list[cnt]);
    }
    
    return 0;
}

/***********************************************
 * get_prime_decomp 素因数分解結果の配列を取得する
 *
 * 
 * in       : num           素因数分解の対象となる数
 * in/out   : prime_listp   素因数分解結果
 * out      : 分解した素因数の数
 ************************************************/
int get_prime_decomp(const int num, int *prime_listp)
{
    int check_num;
    int prime;
    int size;

    check_num = num;
    prime = MIN_PRIME;
    size = 0;

    /*
     * check_num が素数であるか？をチェック
     */
    while (1) {
        //printf(" check_num = %d,\tprime = %d\n", check_num, prime);
        if (check_num <= prime) {
            // check_num が素数で割り切れなければ終了
            prime_listp[size] = check_num;
            size++;
            break;
        }

        if ((check_num % prime) == 0) {
            // 割り切れる素数が存在していたなら
            // 素因数として記憶
            prime_listp[size] = prime;
            size++;

            // 割った値を次のループでチェックする数として更新
            check_num = check_num / prime;
            // 素数の初期化
            prime = MIN_PRIME;
        } else {
            // 割り切れなければ、次に大きい素数を探す
            prime = get_next_prime(prime);
        }
    }
    
    return size;
}


/***********************************************
 * get_next_prime  次の素数を探す
 *
 * 引数で与えられた数値よりも大きい素数を返す 
 ***********************************************/
int get_next_prime(int current_prime)
{
    int i;
    int check_num;
    int next_prime = current_prime;

    for (check_num = (current_prime + 1); ; check_num++) {
        if (check_num & 0x0) {
            // 2の倍数なら抜ける
            continue;
        }
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
