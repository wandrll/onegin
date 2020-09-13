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
    assert(argc >= 4);
    int num_of_lines = lines_count(argv[1]);    
    struct strophe* data = data_mem_alloc(num_of_lines);
    char* ptr_on_buff = read_bin(data, num_of_lines, argv[3]);
    
    merge_sort(data, num_of_lines, sort_strophe_compare_straight, sizeof(data[0]));
    save_data(data,num_of_lines, argv[2]);
    
    merge_sort(data, num_of_lines, sort_strophe_compare_reversed, sizeof(data[0]));
    save_data(data,num_of_lines, argv[2]);

        recreate_data(data, ptr_on_buff, num_of_lines);

    //merge_sort(data, num_of_lines, reset_original_order, sizeof(data[0]));
    save_data(data,num_of_lines, argv[2]);

    //save_buffer(ptr_on_buff, num_of_lines);

    free_data(data, ptr_on_buff);

    return 0;
}