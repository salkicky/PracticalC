/*****************************************************
 * ���K14-4
 *
 * ���l�̃��X�g���܂�ASCII�t�@�C����ǂ݁A�������X�g���܂�
 * �o�C�i���t�@�C���ɏ������ރv���O�������쐬���Ă��������B
 * �܂��A�t�����ɓǂݏo���A�������݂��s���v���O�������쐬
 * ���Ă��������B��������΁A�v���O�������K�؂ɓ��삵�Ă���
 * ���ǂ������`�F�b�N�ł��܂��B
 * ****************************************************/

#include <stdio.h>


int main(int argc, char *argv[])
{
    char *in_file_name;
    char *out_file_name;

    FILE *in_file;
    FILE *out_file;

    //////////////////////////////////////
    // get parameters

    if (argc != 3) {
        fprintf(stderr, "Error : command format error\n");
        fprintf(stderr, "Usage : [exe] [input file] [output file]\n");
        exit(8);
    }

    in_file_name    = argv[1];
    out_file_name   = argv[2];

    //////////////////////////////////////
    // open file
    in_file = fopen(in_file_name, "r");

}
