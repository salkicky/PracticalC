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

    /* 数値を入力 */
    printf("Please Input Number > ");
    fgets(line, sizeof(line), stdin);
    if (sscanf(line, "%d", &input_number) == 0) {
        printf("Error : not a number [%s]\n", line);
        exit(9);
    }

    check_number = input_number;

    /* 素数を探す */
    
    /* 素数があれば */
    check_number /= prime_number;

    /* 素数がなければ → 終了 */
    


    /* 素数リストの小さい順に割り切れるかチェック */
    /* 割り切れたらその値を格納する。*/
    /* 割り切れたらチェックする数値を更新 */
    

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

/************************************************************
 * 範囲内で一番小さい素数を探す
 * 
 * [in]  int max_number
 * [out] int 最小素数
 *************************************************************/
