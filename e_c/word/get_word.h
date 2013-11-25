#ifndef _GET_WORD_H_
#define _GET_WORD_H_

#include <stdio.h>

/*********************************************************
 * get_word
 *
 * ストリームから単語を1文字取り出す。
 * '_'で連結された英数字は合わせて1単語とする。
 * EOFまたは英数字以外の文字を検出した場合は、単語区切り
 * と判断して終了する。
 *
 * @param [in,out]  bufp    単語取得用バッファ
 * @param [in]      size    単語取得用バッファサイズ
 * @param [in,out]  fp      ファイルストリーム
 *
 * @return 単語の文字数（EOFを検出した場合は-1を返す）
 *********************************************************/
int get_word(char *bufp, int size, FILE *fp);


#endif // _GET_WORD_H_
