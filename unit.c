#include "unit.h"
#include "data.h"
#include "sort.h"
/** \file */

void unit_test_read_and_write(char* from, char* to){

    size_t num_of_lines = lines_count(from);   

    remove(to);


    char* ptr_on_buff = read_raw_data(from);

    struct strophe* data = data_adaptation(ptr_on_buff, num_of_lines);
    
    save_data(data,num_of_lines, to);



    free_data(data, ptr_on_buff);
    
}



void complex_test(char* from, char* to){

    size_t num_of_lines = lines_count(from);   
 
    remove(to);


    char* ptr_on_buff = read_raw_data(from);

    struct strophe* data = data_adaptation(ptr_on_buff, num_of_lines);

    merge_sort(data, num_of_lines, sort_strophe_compare_straight_RUS, sizeof(data[0]));
    save_data(data,num_of_lines, to);
    
    merge_sort(data, num_of_lines, sort_strophe_compare_reversed_RUS, sizeof(data[0]));
    save_data(data,num_of_lines, to);

    recreate_data(data, ptr_on_buff, num_of_lines);

    save_data(data,num_of_lines, to);



    free_data(data, ptr_on_buff);
}