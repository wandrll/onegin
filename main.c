/** \file \brief В данном файле идет считывание строк из файла, их сортировка, запись в другой файл. Имена файлов подаются как аргументы командной строки
 */

/** \mainpage Я не знаю что здесь написать. 
 * *Что-то написано*
 * 
 * 
 */


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "data.h"
#include "sort.h"
/** \brief Вызов разных функций 
 */

int main(int argc, char** argv){
    assert(argc >= 3);
    int num_of_lines = lines_count(argv[1]);

    char** data = (char**)calloc(num_of_lines, sizeof(char*));
    int lines_count = read_data(data, argv[1], num_of_lines);
    bubble_sort(data, 0, lines_count-1, string_compare, sizeof(data[0]));
    save_data(data,lines_count, argv[2]);

    free_data(data, lines_count);

    return 0;
}