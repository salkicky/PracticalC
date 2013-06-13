#include <stdio.h>
#include <string.h>

/************************************
 * tmp-name -- �ꎞ�I�ȃt�@�C������Ԃ�
 *
 * ���̊֐��́A�Ăяo����邽�тɁA�V�������O��Ԃ�
 *
 * out : �V�����t�@�C�������w���|�C���^
 *************************************/
char *tmp_name(void)
{
    static char name[30];       /* �������閼�O         */
    static int sequence = 0;    /* �Ō�ɂ���ʂ��ԍ� */

    ++sequence;

    strcpy(name, "tmp-");

    /* �ʂ��ԍ���t���� */
    name[4] = sequence + '0';

    /* ��������I�� */
    name[5] = '\0';
    return name;

}

/****
 * main
 ******/
int main()
{
    int i;

    for (i=0; i < 20; i++) {
        printf("%s\n", tmp_name());
    }
    return 0;
}
