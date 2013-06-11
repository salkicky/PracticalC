#include <stdio.h>

/**
 * main
 **/
int main()
{
    char line[80];
    int check_num;
    int prime_counter;

    int i;

    /* チェック数列を入力 */
    printf("Please input check number > ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &check_num);

    prime_counter = 0;

    for (i = (check_num-1); 1 < i; i--) {
        if ((check_num % i) == 0) {
            break;
        }
    }

    if (i = 1) {
        prime_counter++;
    }

    printf("prime count : %d\n", prime_counter); 

    return 0;
}
