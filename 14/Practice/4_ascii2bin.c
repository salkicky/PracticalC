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
    char read_char;

    // get parameters
    if (argc != 3) {
        fprintf(stderr, "Error : command format error\n");
        fprintf(stderr, "Usage : [exe] [input file] [output file]\n");
        exit(8);
    }

    in_file_name    = argv[1];
    out_file_name   = argv[2];

    // open input file as ASCII
    in_file = fopen(in_file_name, "r");
    if (in_file == NULL) {
        fprintf(stderr, "Error : Cannot open file [%s]\n", in_file_name);
        exit(8);
    }

    // open output file as binary
    out_file = fopen(out_file_name, "wb");
    if (out_file == NULL) {
        fprintf(stderr, "Error : Cannot open file [%s]\n", out_file_name);
        exit(8);
    }

    while(1) {
        read_char = fgetc(in_file);

        // check error
        if (ferror(in_file) != 0) {
            fprintf(stderr, "Error : Cannot read file [%s]\n", in_file_name);
            exit(8);
        }

        // check EOF
        if (read_char == EOF) {
            break;
        }

        printf("%c", read_char);

        if (('0' <= read_char) && (read_char <= '9')) {
            // character is number 
            fputc((read_char-'0'), out_file);
        } else {
            // ignore other character
        }
    }

    // close file
    fclose(in_file);
    fclose(out_file);

    return 0;
}
