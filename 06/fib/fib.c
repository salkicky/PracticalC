#include <stdio.h>


int main()
{
    int old_number;     /* 1つ前のフィボナッチ数 */
    int current_number; /* 現在のフィボナッチ数 */
    int next_number;    /* 次のフィボナッチ数 */

    old_number = 1;
    current_number = 1;
    next_number = 0;

    printf("fib\t%d\n", current_number);

    while( next_number < 100) {
        next_number = current_number + old_number;
        printf("fib\t%d\n", current_number);
        
        old_number = current_number;
        current_number = next_number;
    }

    return 0;

}
