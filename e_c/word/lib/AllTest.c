#include "unity_fixture.h"
#include <stdio.h>

static void RunAllTests(void)
{
}

int main(int argc, char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}
