#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "test.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    run_all_tests();
    return 0;
}
