
#include "unity_fixture.h"

TEST_GROUP_RUNNER(WordDictionary)
{
    RUN_TEST_CASE(WordDictionary, CreateContextTest);
    RUN_TEST_CASE(WordDictionary, RegisterOneWord);
}
