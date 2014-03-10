#include "unity_fixture.h"
#include <stdio.h>

static void RunAllTests(void)
{
    RUN_TEST_GROUP(WordDictionary);
}

int main(int argc, char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
