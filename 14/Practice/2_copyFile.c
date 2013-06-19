/********************************************************
 * ���K14-2
 *
 * �t�@�C�����R�s�[����v���O�������쐬���Ă��������B
 * �^�u�͂��ׂĕ����̃X�y�[�X�ɓW�J���܂��B
 ********************************************************/
#include <stdio.h>

const unsigned int TAB_SETTING = 4;             /* �^�u�ݒ� */

int main(int argc, char *argv[])
{
    char    *src_file_name;
    char    *dst_file_name;
    FILE    *src_file;                          /* �R�s�[���t�@�C�� */
    FILE    *dst_file;                          /* �R�s�[��t�@�C�� */
    char    read_char;                          /* �ǂݏo������     */
    int     i;

    // check input parameters
    if (argc != 3) {
        fprintf(stderr, "Error : Command format error\n");
        fprintf(stderr, "Usage : [command] [src file] [dst file]\n");
        exit(8);
    }

    src_file_name   = argv[1];
    dst_file_name   = argv[2];

    // open src-file
    src_file = fopen(src_file_name, "r");
    if (src_file == NULL) {
        fprintf(stderr, "Error : Cannot open src file [%s]\n", src_file_name);
        exit(8);
    }
    
    // open dst-file
    dst_file = fopen(dst_file_name, "w");
    if (dst_file == NULL) {
        fprintf(stderr, "Error : Cannot open dst_file [%s]\n", dst_file_name);
        exit(8);
    }
    
    // copy routine
    while (1) {
        // read character from src-file
        read_char = fgetc(src_file);

        // check error
        if (ferror(src_file) != 0) {
            // error occur
            fprintf(stderr, "Error : Cannot read src-file [%s]\n", src_file);
            exit(8);
        }

        // check EOF
        if (read_char == EOF) {
            break;
        }

        // copy character 
        if (read_char == '\t') {
            // convert tab to space, and write
            for (i = 0; i < TAB_SETTING; i++) {
                fputc(' ', dst_file);
            }
        } else {
            // write character
            fputc(read_char, dst_file);
        }
    }

    fclose(src_file);
    fclose(dst_file);

    // print result
    printf("coping [%s] to [%s] is done.\n", src_file_name, dst_file_name);
    
    return 0;
}
