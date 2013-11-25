#include <ctype.h>
#include "get_word.h"

/*********************************************************
 * get_word
 *
 * ストリームから単語を1文字取り出す。
 * EOFまたは英数字以外の文字を検出した場合は、単語区切り
 * と判断して終了する。
 *
 * @param [in,out]  bufp    単語取得用バッファ
 * @param [in]      size    単語取得用バッファサイズ
 * @param [in,out]  fp      ファイルストリーム
 *
 * @return 単語の文字数（EOFを検出した場合は-1を返す）
 *********************************************************/
int get_word(char *bufp, int size, FILE *fp)
{
    int ch;
    int len;

    len = 0;

    while (1) {
        ch = getc(fp);
        if (ch == EOF) {
            break;
        }

        if (isalnum(ch)) {
            // 英数字なら
            bufp[len] = ch;
            len++;
        }
        else {
            if (len != 0) {
                // すでに文字取得済みなら単語区切りと判断して終了
                break;
            }
        }
    }

    if (ch == EOF) {
        return -1;
    }

    bufp[len] = '\0';
    return len;
}
