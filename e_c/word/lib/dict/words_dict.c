#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "words_dict.h"

typedef int _BOOL;
#define TRUE  1
#define FALSE 0

struct word_info_tag {
	char *word;
	int count;
	struct word_info_tag *next;
    struct word_info_tag *pre;
};

struct dict_tag {
    struct word_info_tag *head;
    struct word_info_tag *curr;
};

struct word_info_tag *_create_wordinfo(char *word, int word_len);
void _free_wordinfo(struct word_info_tag *winfo);

/*********************************************************
 * word_dict_create_context
 *
 *
 * @return 
 *********************************************************/
void *word_dict_create_context(void)
{
    struct dict_tag *dict;

    //if (headp != NULL) {
    //    word_dict_destroy_context();
    //}

    dict = (struct dict_tag *)malloc(sizeof(struct dict_tag));
    dict->head = NULL;
    dict->curr = NULL;

    return (void *)dict;
}

/*********************************************************
 * word_dict_destroy_context
 *
 *
 * @return 
 *********************************************************/
void word_dict_destroy_context(void *context)
{
    struct dict_tag *dict = (struct dict_tag *)context;
    struct word_info_tag *next, *curr;
    
    dict->curr = dict->head;

    while (dict->curr != NULL) {
        printf("-----\n");
        printf("  curr->word = %s\n", dict->curr->word);
        printf("  curr->count = %d\n", dict->curr->count);

        next = dict->curr->next;
        _free_wordinfo(dict->curr);
        dict->curr = next;
    }
}

/*********************************************************
 * word_dict_add
 *
 * ’PŒê‚ð“o˜^‚·‚éB
 * Šù‚É“o˜^Ï‚Ý‚Ì’PŒê‚Ìê‡‚ÍAƒJƒEƒ“ƒ^‚ð+1‚·‚éB
 *
 * @param [in]      *word   ’PŒê•¶Žš—ñ
 *********************************************************/
void word_dict_add(void *context, char *word, int word_len)
{
    struct dict_tag *dict = (struct dict_tag *)context;
    struct word_info_tag *winfo;

    if (word == NULL) {
        return;
    }
    
    //// word‚ð’T‚·
    //if (_serch(dictp, wordp) == FALSE) {
    //}

    // –³‚¯‚ê‚Î“o˜^
    winfo = _create_wordinfo(word, word_len);

    winfo->pre = dict->curr;
    if (dict->curr != NULL) {
        (dict->curr)->next = winfo;
    } else {
        dict->head = winfo;
    }
    dict->curr = winfo;
}

void word_dict_get_a_word(void *context, char **wordp, int *counter)
{
    struct dict_tag *dict = (struct dict_tag *)context;

    if (dict->curr != NULL) {
        *wordp = dict->curr->word;
        *counter = dict->curr->count;
    }
}

//=================================================================

struct word_info_tag *_create_wordinfo(char *word, int word_len)
{
    struct word_info_tag *wp;

    wp = (struct word_info_tag *)malloc(sizeof(struct word_info_tag));
    wp->word = (char *)malloc(word_len+1);
    
    memcpy(wp->word, word, word_len);
    wp->word[word_len] = '\0';

    wp->count = 0;
    wp->next = NULL;
    wp->pre = NULL;

    return wp;
}

void _free_wordinfo(struct word_info_tag *winfo)
{
    free((void *)winfo->word);
    free((void *)winfo);
}
