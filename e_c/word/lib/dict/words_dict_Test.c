
#include <stdlib.h>
#include <string.h>

#include "unity_fixture.h"
#include "words_dict.h"
#include "inner_words_dict.h"

// ----------------------------

// =========================
// local
// =========================
static struct DictionaryContext_tag *cp;

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

// ===================================================
// Test Helper
// ===================================================

