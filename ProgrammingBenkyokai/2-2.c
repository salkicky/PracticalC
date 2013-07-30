/********************************************************
 * �ۑ�2-2
 * 
 * �^����ꂽ���l��f�����������ĕ\������B
 *********************************************************/
#include <stdio.h>


#define MAX_PRIME_LIST  100
const int MIN_PRIME = 2;

/*
 * �v���g�^�C�v�錾
 */
static int init_prime(void);
static int get_prime_decomp(const int num, int *prime_decomp_p);
static int get_next_prime(int current_prime);

/******************************************************
 * main
 ******************************************************/
int main()
{
    char buf[80];                               /* ���̓o�b�t�@     */
    int input_num;
    int check_num;                              /* �m�F���̔ԍ�     */
    int cnt;                                    /* ���[�v�J�E���^   */

    int prime_list[MAX_PRIME_LIST];
    int size;

    // �f�����������鐔�l���擾
    printf("Please Input Number > ");
    fflush(stdout);
    fgets(buf, sizeof(buf), stdin);
    if (sscanf(buf, "%d", &input_num) == 0) {
        printf("Error : not a number [%s]\n", buf);
        return(9);
    }

    // �f��������
    size = get_prime_decomp(input_num, prime_list);

    // �v�Z���ʂ̊m�F
    check_num = 1;
    for (cnt = 0; cnt < size; cnt++) {
        check_num *= prime_list[cnt];
    }
    if (check_num != input_num) {
        printf("Error : result is not equal input number.\n");
        return 1;
    }
    
    // ���ʂ��o��
    printf("-------------------\n");
    for (cnt = 0; cnt < size; cnt++) {
        printf("%d\n", prime_list[cnt]);
    }
    
    return 0;
}

/***********************************************
 * get_prime_decomp �f�����������ʂ̔z����擾����
 *
 * 
 * in       : num           �f���������̑ΏۂƂȂ鐔
 * in/out   : prime_listp   �f������������
 * out      : ���������f�����̐�
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
     * check_num ���f���ł��邩�H���`�F�b�N
     */
    while (1) {
        //printf(" check_num = %d,\tprime = %d\n", check_num, prime);
        if (check_num <= prime) {
            // check_num ���f���Ŋ���؂�Ȃ���ΏI��
            prime_listp[size] = check_num;
            size++;
            break;
        }

        if ((check_num % prime) == 0) {
            // ����؂��f�������݂��Ă����Ȃ�
            // �f�����Ƃ��ċL��
            prime_listp[size] = prime;
            size++;

            // �������l�����̃��[�v�Ń`�F�b�N���鐔�Ƃ��čX�V
            check_num = check_num / prime;
            // �f���̏�����
            prime = MIN_PRIME;
        } else {
            // ����؂�Ȃ���΁A���ɑ傫���f����T��
            prime = get_next_prime(prime);
        }
    }
    
    return size;
}


/***********************************************
 * get_next_prime  ���̑f����T��
 *
 * �����ŗ^����ꂽ���l�����傫���f����Ԃ� 
 ***********************************************/
int get_next_prime(int current_prime)
{
    int i;
    int check_num;
    int next_prime = current_prime;

    for (check_num = (current_prime + 1); ; check_num++) {
        if (check_num & 0x0) {
            // 2�̔{���Ȃ甲����
            continue;
        }
        for (i = 2; i < check_num; i++) {
            if ((check_num % i) == 0) {
                // ����؂��Ȃ�f���ł͂Ȃ��̂Ŕ�����
                break;
            }
        }

        if (i = check_num) {
            // �f���Ȃ�
            next_prime = check_num;
            break;
        }
    }

    return next_prime;
}
