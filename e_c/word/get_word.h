#ifndef _GET_WORD_H_
#define _GET_WORD_H_

#include <stdio.h>

/*********************************************************
 * get_word
 *
 * ストリームから単語を1つ取り出す。
 * 単語の区切りは、EOFまたは英数字以外とする。
 * //単語の区切りは、EOFまたはスペース、改行、タブ文字とする。
 *
 * @param [in,out]  wordp   単語格納用バッファ
 * @param [in]      size    単語格納用バッファサイズ
 * @param [in,out]  fp      ファイルストリーム
 *
 * @return 単語の文字数（EOFを検出した場合は-1を返す）
 *********************************************************/
int get_word(char *wordp, int size, FILE *fp);


#endif // _GET_WORD_H_
