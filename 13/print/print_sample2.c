/***********************************************************
 * 13.8
 *      例13-12直前のコマンドラインオプション検索の方法が
 *      見た目にわかりにくいコードだったため、パッと見て
 *      わかるように書き直した。
 ***********************************************************/
#include <stdio.h>

/*-------------------------------------------------------
 * main -- コマンドライン引数を印字する
 *-------------------------------------------------------*/
int main(int argc, char *argv[])
{
    int i;
    char *program_name_ptr;

    /* プログラム名を取得 */
    program_name_ptr = argv[0];
    printf("program name = %s\n", program_name_ptr);

    /* コマンドライン引数を順に解析 */
    for (i=1; i < argc; i++) {
        printf("%d %s\n", i, argv[i]);

        if (argv[i][0] == '-') {
            /* コマンドラインオプションの解析 */
            switch (argv[i][1]) {
                case 'o':
                    /* -o */
                    printf("  get '-o' option.\n");
                    i++;
                    printf("     %s\n", argv[i]);
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}
