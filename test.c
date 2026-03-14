#include "test.h"
#include "binsearch.h"
#include "comparators.h"
#include "locale.h"
#include <stdio.h>
#include <string.h>

// Вспомогательная функция для вывода массива целых чисел
void print_int_array(const int* arr, size_t count) {
    printf("[");
    for (size_t i = 0; i < count; i++) {
        printf("%d", arr[i]);
        if (i < count - 1) printf(", ");
    }
    printf("]");
}

// Вспомогательная функция для вывода массива вещественных чисел
void print_double_array(const double* arr, size_t count) {
    printf("[");
    for (size_t i = 0; i < count; i++) {
        printf("%.1f", arr[i]);
        if (i < count - 1) printf(", ");
    }
    printf("]");
}

// Вспомогательная функция для вывода массива строк
void print_string_array(const char* arr[], size_t count) {
    printf("[");
    for (size_t i = 0; i < count; i++) {
        printf("\"%s\"", arr[i]);
        if (i < count - 1) printf(", ");
    }
    printf("]");
}

void run_test(const char* description, int result, int expected,
              const void* array, void (*print_func)(), size_t count,
              const char* search_str) {
    int passed = (result == expected);

    printf("  %s\n", description);
    printf("    Массив: ");
    print_func(array, count);
    printf("\n");
    printf("    Искомое: %s\n", search_str);
    printf("    Результат: %s (ожидалось: %s)\n",
           result ? "НАЙДЕН" : "НЕ НАЙДЕН",
           expected ? "НАЙДЕН" : "НЕ НАЙДЕН");
    printf("    Статус: %s\n", passed ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    printf("\n");
}

void test_int_array(void) {
    printf("\n Массив целых чисел \n");

    int arr[] = {1, 3, 6, 7, 9, 11, 13};
    size_t count = sizeof(arr) / sizeof(arr[0]);


    int val1 = 5;
    int result1 = bin_search(arr, sizeof(int), count, &val1, cmp_int);
    run_test("- элемент 5", result1, 0,
             arr, (void (*)())print_int_array, count, "5");


    int val2 = 1;
    int result2 = bin_search(arr, sizeof(int), count, &val2, cmp_int);
    run_test("- элемент 1", result2, 1,
             arr, (void (*)())print_int_array, count, "1");


    int val3 = 13;
    int result3 = bin_search(arr, sizeof(int), count, &val3, cmp_int);
    run_test("- элемент 13", result3, 1,
             arr, (void (*)())print_int_array, count, "13");

    // элемент отсутствует
    int val4 = 4;
    int result4 = bin_search(arr, sizeof(int), count, &val4, cmp_int);
    run_test("- элемент 4", result4, 0,
             arr, (void (*)())print_int_array, count, "4");

    // меньше минимального
    int val5 = -5;
    int result5 = bin_search(arr, sizeof(int), count, &val5, cmp_int);
    run_test("- элемент -5", result5, 0,
             arr, (void (*)())print_int_array, count, "-5");

    // больше максимального
    int val6 = 20;
    int result6 = bin_search(arr, sizeof(int), count, &val6, cmp_int);
    run_test("- элемент 20", result6, 0,
             arr, (void (*)())print_int_array, count, "20");
}

void test_double_array(void) {
    printf("\n Массив вещественных чисел \n");

    double arr[] = {1.5, 2.7, 3.8, 4.2, 5.9, 6.1};
    size_t count = sizeof(arr) / sizeof(arr[0]);


    double val1 = 3.8;
    int result1 = bin_search(arr, sizeof(double), count, &val1, cmp_double);
    run_test("- элемент 3.8", result1, 1,
             arr, (void (*)())print_double_array, count, "3.8");


    double val2 = 1.5;
    int result2 = bin_search(arr, sizeof(double), count, &val2, cmp_double);
    run_test("- элемент 1.5", result2, 1,
             arr, (void (*)())print_double_array, count, "1.5");


    double val3 = 6.1;
    int result3 = bin_search(arr, sizeof(double), count, &val3, cmp_double);
    run_test("- элемент 6.1", result3, 1,
             arr, (void (*)())print_double_array, count, "6.1");

    // элемент отсутствует
    double val4 = 4.0;
    int result4 = bin_search(arr, sizeof(double), count, &val4, cmp_double);
    run_test("- элемент 4.0", result4, 0,
             arr, (void (*)())print_double_array, count, "4.0");

    // меньше минимального
    double val5 = 0.5;
    int result5 = bin_search(arr, sizeof(double), count, &val5, cmp_double);
    run_test("- элемент 0.5", result5, 0,
             arr, (void (*)())print_double_array, count, "0.5");

    // больше максимального
    double val6 = 10.0;
    int result6 = bin_search(arr, sizeof(double), count, &val6, cmp_double);
    run_test("- элемент 10.0", result6, 0,
             arr, (void (*)())print_double_array, count, "10.0");
}

void test_string_array(void) {
    printf("\n Массив строк \n");

    const char *arr[] = {"blue", "green", "violet", "grape", "yellow"};
    size_t count = sizeof(arr) / sizeof(arr[0]);


    const char *val1 = "violet";
    int result1 = bin_search(arr, sizeof(const char *), count, &val1, cmp_str);
    run_test("- строка \"violet\"", result1, 1,
             arr, (void (*)())print_string_array, count, "\"violet\"");


    const char *val2 = "blue";
    int result2 = bin_search(arr, sizeof(const char *), count, &val2, cmp_str);
    run_test("- строка \"blue\"", result2, 1,
             arr, (void (*)())print_string_array, count, "\"blue\"");


    const char *val3 = "yellow";
    int result3 = bin_search(arr, sizeof(const char *), count, &val3, cmp_str);
    run_test("- строка \"yellow\"", result3, 1,
             arr, (void (*)())print_string_array, count, "\"yellow\"");

    // строка отсутствует
    const char *val4 = "grey";
    int result4 = bin_search(arr, sizeof(const char *), count, &val4, cmp_str);
    run_test("- строка \"grey\"", result4, 0,
             arr, (void (*)())print_string_array, count, "\"grey\"");

    // меньше минимального
    const char *val5 = "aaa";
    int result5 = bin_search(arr, sizeof(const char *), count, &val5, cmp_str);
    run_test("- строка \"aaa\"", result5, 0,
             arr, (void (*)())print_string_array, count, "\"aaa\"");

    // больше максимального
    const char *val6 = "turquoise";
    int result6 = bin_search(arr, sizeof(const char *), count, &val6, cmp_str);
    run_test("- строка \"turquoise\"", result6, 0,
             arr, (void (*)())print_string_array, count, "\"turquoise\"");
}

void run_all_tests(void) {
    setlocale(LC_ALL, "Russian");

    printf("         ТЕСТИРОВАНИЕ БИНАРНОГО ПОИСКА\n");


    test_int_array();
    test_double_array();
    test_string_array();

    printf("\n         ВСЕ ТЕСТЫ ВЫПОЛНЕНЫ\n");

}
