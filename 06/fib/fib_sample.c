#include <stdio.h>

int main()
{
    int old_number;     /* �O�̃t�B�{�i�b�`���� */
    int current_number; /* ���̃t�B�{�i�b�`���� */
    int next_number;    /* ���̃t�B�{�i�b�`���� */

    old_number = 1;
    current_number = 1;
    next_number = 0;

    printf("fib\t%d\n", 1);

    while( current_number < 200) {
        printf("fib\t%d\n", current_number);

        /* ���̐�����v�Z */
        next_number = current_number + old_number;

        /* �ێ����鐔��̈ʒu�����炷 */
        old_number = current_number;
        current_number = next_number;
    }

    return (0);

}
