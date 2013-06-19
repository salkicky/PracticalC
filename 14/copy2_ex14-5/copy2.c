/************************************************************
 * 例14-5 バッファリングを行わないIOの例
 *
 * バッファリングを行わずにファイルをコピーする。
 ************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <sys\stat.h>
#include <io.h>

#ifndef O_BINARY
#define O_BINARY                /* 未定義の場合はフラグを定義       */
#endif /* O_BINARY */

#define BUFFER_SIZE (16 * 1024) /* 16kバッファを使用 */

int main(int argc, char *argv[])
{
    char    buffer[BUFFER_SIZE];        /* データ用バッファ         */
    int     in_file;                    /* 入力ファイル記述子       */
    int     out_file;                   /* 出力ファイル記述子       */
    int     read_size;                  /* 最後に読まれたバイト数   */

    if (argc != 3) {
        fprintf(stderr, "Error : Wrong number of argument\n");
        fprintf(stderr, "Usage : copy <from> <to>\n");
        exit(8);
    }

    // open input file
    in_file = open(argv[1], (O_RDONLY | O_BINARY));
    if (in_file < 0) {
        fprintf(stderr, "Error : Unable to open %s\n", argv[1]);
        exit(8);
    }

    // open output file
    out_file = open(argv[2], (O_WRONLY | O_TRUNC | O_CREAT | O_BINARY), 0666);
    if (out_file < 0) {
        fprintf(stderr, "Error : Unable to open %s\n", argv[2]);
        exit(8);
    }

    // copy input file to output file
    while (1) {
        read_size = read(in_file, buffer, sizeof(buffer));
        if (read_size == 0) {
            // EOF
            break;
        }

        if (read_size < 0) {
            fprintf(stderr, "Error : Read error\n");
            exit(8);
        }

        write(out_file, buffer, (unsigned int)read_size);
    }
    close(in_file);
    close(out_file);
    return 0;
}

