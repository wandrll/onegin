/** \file \brief В данном файле идет считывание строк из файла, их сортировка, запись в другой файл. Имена файлов подаются как аргументы командной строки
 */

/** \mainpage Я не знаю что здесь написать. 
 * *Что-то написано*
 * 
 * 
 */


#include <stdio.h>
#include <assert.h>
#include <locale.h>
#include <stdlib.h>
#include "../data.h"

/** \brief Вызов разных функций 
 */

int isLetter(char c){
    if((c >= (char)'A'&& c <= (char)'Z') || (c >= (char)'a' && c <= (char)'z')){
        return 1;
    }else{
        return 0;
    }
}


int is_allowed(struct strophe* strophe){
    if(strophe->count == 0){
        return 0;
    }else{
        
        int letters = 0;
        for(int i = 0; i < strophe->count; i++){
            if(isLetter(strophe->line[i])){
                letters++;
            }
        }
        return letters;
    }
}

char* read_data_and_create_formated_text(struct strophe* data, char* file, char* save_file){
    assert(data != NULL);
    assert(file != NULL);
    assert(save_file != NULL);

    FILE* fb = fopen(file, "rb");
    assert(fb != NULL);
   
    size_t fsize = file_size(file);
    char* buffer_for_strings = (char*)calloc(fsize, sizeof(char));
    fread(buffer_for_strings, sizeof(char), fsize, fb);

    char* to = buffer_for_strings;
    int curr_count = 0;
    int curr_line = 0;
    
    for(int i = 0; i < fsize; i++){
        if(buffer_for_strings[i] == '\n'){
            buffer_for_strings[i] = '\0';
            data[curr_line].count = curr_count;
            data[curr_line].line = to;
            curr_count = 0;
            curr_line++;
            to = buffer_for_strings + i + 1;
        }else{
            curr_count++;
        }
    }
    FILE* fd = fopen(save_file, "w");
    assert(fd != NULL);
    for(int i = 0; i < curr_line; i++){
        if(is_allowed(&data[i])){
            fwrite(data[i].line, sizeof(char), data[i].count, fd);
            putc('\n', fd);
        }
    }

    fclose(fd);
    fclose(fb);
    return buffer_for_strings;
}





int main(int argc, char** argv){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    assert(argc >= 3);

    int num_of_lines = lines_count(argv[1]);

    struct strophe* data = data_mem_alloc(num_of_lines);
    char* ptr_on_buff = read_data_and_create_formated_text(data, argv[1], argv[2]);
    
    free_data(data, ptr_on_buff);

    return 0;
}