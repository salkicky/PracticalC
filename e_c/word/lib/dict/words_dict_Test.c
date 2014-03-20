
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "unity_fixture.h"
#include "words_dict.h"
#include "words_dict_inner.h"

// ----------------------------

// =========================
// local
// =========================
static DICT_T *cp;

// ===================================================
// ===================================================
TEST_GROUP(WordDictionary);

// set up
TEST_SETUP(WordDictionary)
{
    // do nothing
    (void)word_dict_create_context(&cp);
}

// tear down
TEST_TEAR_DOWN(WordDictionary)
{
    // do nothing
    word_dict_destroy_context(cp);
}

// ===================================================
// TEST CODE
// ===================================================
TEST(WordDictionary, CreateContextTest)
{
    TEST_ASSERT_TRUE( cp != NULL );
    TEST_ASSERT_TRUE( cp->curr == NULL );
    TEST_ASSERT_TRUE( cp->head == NULL );
}

TEST(WordDictionary, RegisterOneWord)
{
    char* word = "orange";

    word_dict_register(cp, word, strlen(word));

    TEST_ASSERT_TRUE( cp->curr != NULL );
    TEST_ASSERT_TRUE( cp->head == cp->curr );
    TEST_ASSERT_TRUE( strcmp(cp->curr->word, word) == 0);
    TEST_ASSERT_TRUE( cp->curr->count == 1 );
    TEST_ASSERT_TRUE( cp->curr->bp == NULL );
    TEST_ASSERT_TRUE( cp->curr->np == NULL );
}

TEST(WordDictionary, TestMain)
{
    char *words[] = {
        "orange", "apple", "orange", "peach", "pine", "pine", "peach",
        "apples", "apple", "apples","apple", "apples","apple", "apples" 
    };
    int array_size;
    int i;
    int ret;
    char *registered_word;  // “o˜^‚µ‚½’PŒê
    int counter;            // ’PŒê“o˜^‰ñ”

    printf("\n------\n");

    // ’PŒê‚Ì“o˜^
    array_size = sizeof(words) / sizeof(words[0]);
    
    for (i = 0; i < array_size; i++) {
        printf("register ... %s\n", words[i]);
        word_dict_register(cp, words[i], strlen(words[i]));
    }
    fflush(stdout);

    printf("\n------\n");

    // ’PŒê‚Ìæ‚èo‚µ
    word_dict_move_head(cp);

    while (1) {
        ret = word_dict_get_a_word(cp, &registered_word, &counter);
        if (ret == B_FALSE) {
            break;
        }

        printf(" registered word = %s,\t counter = %d\n", registered_word, counter);
    }

    for (i = 0; i < array_size; i++) {
        ret = word_dict_get_word_count(cp, words[i], &counter);
        if (ret == B_FALSE) {
            break;
        }
        printf(" %s is registered %d times\n", words[i], counter);
    }
   

}

// ===================================================
// Test Helper
// ===================================================

