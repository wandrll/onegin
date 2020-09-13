#include <stdio.h>
/** \file */






/** \brief - старая добрая сортировка пузырьком, но уже для любых типов
  
    \param data - указатель на начало массива который нужно сортировать
    \param start - с какого эл-та сортировать
    \param end - по какой элемент сортировать
    \param comp - функция сравнения двух элементов
    \param size - размер одного элемента
 */
void bubble_sort(void* data, int start, int end,  int(*comp)(const void*, const void*), size_t size);


/** \brief - прямое сравнение строк
  
    \return число > или < 0, в зависимости от результата сравнения
 */
int string_compare_straight(const char* a, const char* b);


/** \brief - обертка для сравнения двух строк 
  
    \return число > или < 0, в зависимости от результата сравнения
 */
int sort_strophe_compare_straight(const void* string1,const void* string2);


/** \brief - обратное двух строк 
  
    \return число > или < 0, в зависимости от результата сравнения
 */
int string_compare_reversed(const char* a, int len1, const char* b, int len2);


/** \brief - обертка для сравнения двух строк 
  
    \return число > или < 0, в зависимости от результата сравнения
 */
int sort_strophe_compare_reversed(const void* string1, const void* string2);


/** \brief - сортировка слиянием
    \param data - указатель на начало массива который нужно сортировать
    \param count - количество элементов
    \param comp - функция сравнения двух элементов
    \param size - размер одного элемента
 */
void merge_sort(void* data, int count, int(*comp)(const void*, const void*), size_t size);
