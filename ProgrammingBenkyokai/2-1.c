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

    /* �`�F�b�N�������� */
    printf("Please input check number > ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &check_num);

    prime_counter = 0;

    for (i = 2; i < check_num; i++) {
        if ((check_num % i) == 0) {
            break;
        }
    }

    if (i == check_num) {
        prime_counter++;
    }

    printf("prime count : %d\n", prime_counter); 

    return 0;
}
