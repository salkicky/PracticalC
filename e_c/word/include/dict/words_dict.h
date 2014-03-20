#ifndef _WORDS_DICT_H_
#define _WORDS_DICT_H_

#include "type.h"

struct _DICT_T;
typedef struct _DICT_T DICT_T;

/*********************************************************
 * word_dict_create_context
 * 
 * 実行用のコンテキストを生成する。
 * 利用終了後は必ず word_dict_destroy_context()で解放すること。
 *
 * @param [out] 実行用コンテキストへの pointer to pointer
 * @return B_TRUE   正常終了
 * @return B_FALSE  異常終了
 *********************************************************/
_BOOL word_dict_create_context(DICT_T **contextp);

/*********************************************************
 * word_dict_destroy_context
 *
 * 確保した実行用コンテキストを解放する。
 *
 * @param [in]      *context 実行用コンテキスト
 *********************************************************/
void word_dict_destroy_context(DICT_T *context);

/*********************************************************
 * word_dict_register
 *
 * 単語を登録する。
 * 既に登録済みの単語の場合は、カウンタを+1する。
 *
 * @param [in]      *context    実行用コンテキスト
 * @param [in]      *word       単語文字列
 * @param [in]      word_len    登録する単語の文字数
 *********************************************************/
void word_dict_register(DICT_T *context, char *word, int word_len);

/*********************************************************
 * word_dict_move_head
 *
 * 辞書を先頭に戻す
 *
 * @param [in]      *context    実行用コンテキスト
 *********************************************************/
void word_dict_move_head(DICT_T *context);

/*********************************************************
 * word_dict_get_a_word
 *
 * 単語を一つ取り出す
 *
 * @param [in]      *context    実行用コンテキスト
 * @param [out]     *word       単語文字列
 * @param [out]     counter     登録した回数
 * @return B_TRUE      取りだし成功
 * @return B_FALSE     取りだし失敗
 *********************************************************/
_BOOL word_dict_get_a_word(DICT_T *context, char **wordp, int *counter);

_BOOL word_dict_get_word_count(DICT_T *context, char *wordp, int *counter);

#endif //_WORDS_DICT_H_
