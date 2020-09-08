#include <stdio.h>
/** \file */

/** \brief - очистка строки от мусора(цифры, знаки препинания и др.)
  
   \param line - указатель на строку которую нужно очистить
   \return указатель на новую очищенную строку(Старая остается неизменной)
 */
char* clean_string(char* line);

/** \file */

/** \brief - сравнение двух строк
  
    \return число > или < 0, в зависимости от результата сравнения
 */
int string_compare(void* a, void* b);

typedef int (*comp_type)(void*, void*);

/** \brief - старая добрая сортировка пузырьком, но уже для любых типов
  
    \param data - указатель на начало массива который нужно сортировать
    \param start - с какого эл-та сортировать
    \param end - по какой элемент сортировать
    \param comp - функция сравнения двух элементов
    \param size - размер одного элемента
 */

void bubble_sort(void* data, int start, int end, comp_type comp, size_t size);