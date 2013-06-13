#include <stdio.h>


/**
 * my_strchr
 *      �����񂩂�w�蕶���̈ʒu���������A�|�C���^�Ƃ��ĕԂ�
 * in : char *string_ptr        �����ΏۂƂȂ镶����ւ̃|�C���^
 * in : char find               �������镶��
 * out: char *                  �����������ʂփ|�C���^
 * out: NULL                    ������Ȃ������ꍇ��NULL��Ԃ�
 * */
char *my_strchr(char *string_ptr, char find)
{
    while (*string_ptr != find) {
        /* ������̏I�[���`�F�b�N */

        if (*string_ptr == '\0') {
            /* �I�[�Ȃ甲���� */
            return (NULL);
        }

        string_ptr++;
    }

    /* ���������ւ̃|�C���^��Ԃ� */
    return string_ptr;
}


/*-----------------------
 * main
 * ---------------------- */
int main()
{
    char line[80];
    char *first_ptr;
    char *last_ptr;

    printf("Please Input Your Name.(ex. 'nnn/xxx') > ");
    fgets(line, sizeof(line), stdin);

    /* ���͍s�Ō�̉��s���I�[������ɓ���ւ��� */
    line[strlen(line)-1] = '\0';

    last_ptr = line;
    first_ptr = my_strchr(line, '/');

    /* �G���[���`�F�b�N */
    if (first_ptr == NULL) {
        printf("Error : Unable to find slash in %s\n", line);
        exit(8);
    }

    /* ������𐩖��ɕ��� */
    *first_ptr = '\0';
    first_ptr++;

    printf("First:%s\nLast:%s\n", first_ptr, last_ptr);
    return 0;
}
