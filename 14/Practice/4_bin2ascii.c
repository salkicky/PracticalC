/*****************************************************
 * ���K14-4
 *
 * ���l�̃��X�g���܂�ASCII�t�@�C����ǂ݁A�������X�g���܂�
 * �o�C�i���t�@�C���ɏ������ރv���O�������쐬���Ă��������B
 * �܂��A�t�����ɓǂݏo���A�������݂��s���v���O�������쐬
 * ���Ă��������B��������΁A�v���O�������K�؂ɓ��삵�Ă���
 * ���ǂ������`�F�b�N�ł��܂��B
 *
 * bin -> ascii 
 * ****************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    char *ascii_file_name;
    char *bin_file_name;

    FILE *ascii_file;
    FILE *bin_file;

    char read_char;
    int read_size;

    // get parameters
    if (argc != 3) {
        fprintf(stderr, "Error : command format error\n");
        fprintf(stderr, "Error : [exe] [binary file] [ascii file]\n");
        exit(8);
    }

    bin_file_name   = argv[1];
    ascii_file_name = argv[2];

    // open binary file
    bin_file = fopen(bin_file_name, "rb");
    if (bin_file == NULL) {
        fprintf(stderr, "Error : Cannot open file [%s]\n", bin_file_name);
        exit(8);
    }

    // open ascii file
    ascii_file = fopen(ascii_file_name, "w");
    if (ascii_file == NULL) {
        fprintf(stderr, "Error : Cannot open file [%s]\n", ascii_file_name);
        exit(8);
    }

    while (1) {
        // read binary number
        read_size = fread((char *)&read_char, 1, 1, bin_file);

        // check EOF
        if (read_size == 0) {
            break;
        }

        // write ascii number
        if ((0 <= read_char) && (read_char <= 9)) {
            // convert bin->ascii
            read_char = read_char + '0';
            fputc(read_char, ascii_file);

            printf("%c", read_char);
        }
    }

    // exit
    fclose(bin_file);
    fclose(ascii_file);

    return 0;
}
