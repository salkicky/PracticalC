/****************************************************************
 * ���K14-3
 *
 * ���l�̃��X�g���L�q����Ă���t�@�C����ǂ݁A�Q�̃t�@�C����
 * �����o���v���O�������쐬���Ă��������B�P�̃t�@�C���ɂ͂R��
 * ����؂�鐔�l�������������݁A������̃t�@�C���ɂ́A����
 * �ȊO�̐��l�����ׂď������݂܂��B
 *
 * ���͂��郊�X�g�t�@�C���̎d�l
 * �E���l��unsigned int�^�͈͓̔��̌����łȂ��Ă͂Ȃ�Ȃ��B
 ****************************************************************/
#include <stdio.h>

const char OUT_MULTIPLE3_FILE_NAME[]  = "out_m3.txt";
const char OUT_OTHER_FILE_NAME[]      = "out_xx.txt";


int main(int argc, char *argv[])
{
    char *in_file_name;                         // input file name
    FILE *in_file;                              // input file identifier
    FILE *out_multiple3_file;                   // output file identifier (write multiple of 3)
    FILE *out_other_file;                       // output file identifier (write other numbers)
    char char_data;                             // single character read from input file
    char num_str[100];                          // ASCII number read from input file
    unsigned int num;                           // number converted from ASCII number
    int index;                                  // position index for setting character to num_str
   
    /////////////////////////////////////
    // check command parameters 
    if (argc != 2) {
        fprintf(stderr, "Error : Command format error\n");
        fprintf(stderr, "Usage : [exe] [input file]\n");
        exit(8);
    }

    // get command parameters
    in_file_name = argv[1];

    ////////////////////////////////////
    // open input file
    in_file = fopen(in_file_name, "r");
    if (in_file == NULL) {
        fprintf(stderr, "Error : Cannot open file [%s]\n", in_file_name);
        exit(8);
    }

    // open output files (for multiple of 3)
    out_multiple3_file = fopen(OUT_MULTIPLE3_FILE_NAME, "w");
    if (out_multiple3_file == NULL) {
        fprintf(stderr, "Error : Cannot open file [%s]\n", OUT_MULTIPLE3_FILE_NAME);
        exit(8);
    }
   
    // open output files (others)
    out_other_file = fopen(OUT_OTHER_FILE_NAME, "w");
    if (out_other_file == NULL) {
        fprintf(stderr, "Error : Cannot open file [%s]\n", OUT_OTHER_FILE_NAME);
        exit(8);
    }

    //////////////////////////////////
    // initialize
    index = 0;
    num = 0;

    //////////////////////////////////////
    while (1) {
        ////////////////////////////////
        // read 1 character
        char_data = fgetc(in_file);
        
        // check error 
        if (ferror(in_file) != 0) {
            fprintf(stderr, "Error : Cannot read file [%s]\n", in_file_name);
            exit(8);
        }

        // check EOF
        if (char_data == EOF) {
            break;
        }

        ////////////////////////////////
        if (('0' <= char_data) && (char_data <= '9')) {
            // add character as number
            num_str[index] = char_data;
            index++;
        } else {
            // write number 
            if (index != 0) {
                // add NUL
                num_str[index] = '\0';

                // convert char[] to unsigned integer
                sscanf(num_str, "%d", &num);

                // select file, write number
                if ((num % 3) == 0) {
                    // num is multiple of 3
                    fprintf(out_multiple3_file, " %d", num);
                } else {
                    // num is other
                    fprintf(out_other_file, " %d", num);
                }
            }

            // reset index
            index = 0;
        }

    }

    // close file
    fclose(in_file);
    fclose(out_multiple3_file);
    fclose(out_other_file);

    return 0;
}
