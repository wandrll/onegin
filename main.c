/** \file \brief В данном файле идет считывание строк из файла, их сортировка, запись в другой файл. Имена файлов подаются как аргументы командной строки
 */

/** \mainpage Заголовок. 
 * *Сортировка текста по строкам. Исходники и руководство по запуску лежат тут https://github.com/wandrll/onegin/tree/gh-pages*
 * 
 * 
 */


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "data.h"
#include "sort.h"

/** \brief Основная программа
 * \param argc количество введеных аргументов командной строки
 * \param argv названия файлов откуда брать данные и куда записывать результат. Если ничего не ввести программа работать не будет!!!!!!!!!!!!!!!
 */
int main(int argc, char** argv){

    assert(argc >= 3); //Проверка, что введены имя входного и выходного файла
    
    size_t num_of_lines = 0;  
    char* from = argv[1];
    char* to = argv[2];
    remove(to);


    char* ptr_on_buff = read_raw_data(from, &num_of_lines);
    struct strophe* data = data_adaptation(ptr_on_buff, num_of_lines);
    
    merge_sort(data, num_of_lines, sort_strophe_compare_straight_RUS, sizeof(data[0]));
    save_data(data,num_of_lines, to);
    
    qsort(data, num_of_lines, sizeof(data[0]), sort_strophe_compare_reversed_RUS);
    save_data(data,num_of_lines, to);

    recreate_data(data, ptr_on_buff, num_of_lines);
    save_data(data,num_of_lines, to);

    free_data(data, ptr_on_buff);

    return 0;
}