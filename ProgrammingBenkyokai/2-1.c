#include <stdio.h>

/**
 * main
 **/
int main()
{
    int check_num;
    int prime_counter;

    int i;

    check_num = 2;
    prime_counter = 0;

    for (i = check_num; 1 < i; i--) {
        if ((check_num % i) == 0) {
            break;
        }
    }

    if (check_num = 1) {
        prime_counter++;
    }

    printf("prime count : %d\n", prime_counter); 

    return 0;
}
