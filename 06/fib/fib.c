#include <stdio.h>


int main()
{
    int old_number;     /* 1�O�̃t�B�{�i�b�`�� */
    int current_number; /* ���݂̃t�B�{�i�b�`�� */
    int next_number;    /* ���̃t�B�{�i�b�`�� */

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
