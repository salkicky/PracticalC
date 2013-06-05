#include <stdio.h>

int main()
{
    int old_number;     /* 前のフィボナッチ数列 */
    int current_number; /* 今のフィボナッチ数列 */
    int next_number;    /* 次のフィボナッチ数列 */

    old_number = 1;
    current_number = 1;
    next_number = 0;

    printf("fib\t%d\n", 1);

    while( current_number < 200) {
        printf("fib\t%d\n", current_number);

        /* 次の数列を計算 */
        next_number = current_number + old_number;

        /* 保持する数列の位置をずらす */
        old_number = current_number;
        current_number = next_number;
    }

    return (0);

}
