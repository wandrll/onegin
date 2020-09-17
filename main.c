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
#include <locale.h>
#include "data.h"
#include "sort.h"

/** \brief Вызов разных функций 
 */

int main(int argc, char** argv){
    setlocale(LC_ALL, "CP1251");
    assert(argc >= 3);
    size_t num_of_lines = lines_count(argv[1]);   
    char* from = argv[1];
    char* to = argv[2];
    remove(to);

    struct strophe* data = data_mem_alloc(num_of_lines);
    char* ptr_on_buff = read_data(data, from);
    //create_bin(data, num_of_lines, argv[3]);
    //char* ptr_on_buff = read_bin(data, num_of_lines, argv[3]);
    merge_sort(data, num_of_lines, sort_strophe_compare_straight_RUS, sizeof(data[0]));
    save_data(data,num_of_lines, to);
    
    merge_sort(data, num_of_lines, sort_strophe_compare_reversed_RUS, sizeof(data[0]));
    save_data(data,num_of_lines, to);

    recreate_data(data, ptr_on_buff, num_of_lines);

    save_data(data,num_of_lines, to);



    free_data(data, ptr_on_buff);

    return 0;
}