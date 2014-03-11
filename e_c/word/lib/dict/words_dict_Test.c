
#include "unity_fixture.h"
#include <stdlib.h>
#include "words_dict.h"

TEST_GROUP(WordDictionary);

/* set up */
TEST_SETUP(WordDictionary)
{
    // do nothing
}

/* tear down */
TEST_TEAR_DOWN(WordDictionary)
{
    // do nothing
}


TEST(WordDictionary, OkTest)
{
    TEST_ASSERT_EQUAL(1,1);
}


TEST(WordDictionary, NgTest)
{
    TEST_ASSERT_EQUAL(1,0);
}
