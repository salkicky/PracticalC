#ifndef _WORDS_DICT_H_
#define _WORDS_DICT_H_

struct DictionaryContext_tag;

/*********************************************************
 * word_dict_create_context
 * 
 * 実行用のコンテキストを生成する。
 * 利用終了後は必ず word_dict_destroy_context()で解放すること。
 *
 * @return 実行用コンテキストへのポインタ
 *********************************************************/
void *word_dict_create_context(void);

/*********************************************************
 * word_dict_destroy_context
 *
 * 確保した実行用コンテキストを解放する。
 *
 * @param [in]      *context 実行用コンテキスト
 *********************************************************/
void word_dict_destroy_context(struct DictionaryContext_tag *context);

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
void word_dict_register(struct DictionaryContext_tag *context, char *word, int word_len);

/*********************************************************
 * word_dict_get_a_word
 *
 * 単語を一つ取り出す
 *
 * @param [in]      *context    実行用コンテキスト
 * @param [out]     *word       単語文字列
 * @param [out]     counter     登録した回数
 *********************************************************/
void word_dict_get_a_word(struct DictionaryContext_tag *context, char **wordp, int *counter);


#endif //_WORDS_DICT_H_
