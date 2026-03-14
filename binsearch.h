#ifndef BINSEARCH_H_INCLUDED
#define BINSEARCH_H_INCLUDED

#include <stddef.h>

// Тип функции сравнения
typedef int (*cmp_t)(const void *el1, const void *el2);

/*
 * Полиморфный бинарный поиск
 * array - указатель на массив
 * size - размер одного элемента
 * count - количество элементов в массиве
 * el - указатель на искомый элемент
 * cmp - функция сравнения
 */
int bin_search(const void *array, size_t size, size_t count,
               const void *el, cmp_t cmp);

#endif // BINSEARCH_H_INCLUDED
