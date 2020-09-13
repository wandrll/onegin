#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "data.h"
/** \file */


int lines_count(char* file){
    assert(file != NULL);
    char c = 0;
    int count = 0;
    FILE* fp = fopen(file, "r");

    assert(fp != NULL);
    while(c != EOF){
        c = getc(fp);
        if(c == '\n'){
            count++;
        }
    }
    fclose(fp);
    return count;
}


int file_size(char* file){
    assert(file != NULL);
    FILE* fb = fopen(file, "rb");
    assert(fb != NULL);

    fseek(fb, 0, SEEK_END);
    int size = ftell(fb);
    fclose(fb);
    return size;
}


struct strophe* data_mem_alloc(int count){
    struct strophe* data = (struct strophe*)calloc(count, sizeof(struct strophe));

    return data;
}


char* read_data(struct strophe* data, char* file){
    assert(data != NULL);
    assert(file != NULL);
    

    FILE* fb = fopen(file, "rb");
    assert(fb != NULL);
   
    size_t fsize = file_size(file);
    char* buffer_for_strings = (char*)calloc(fsize + 1, sizeof(char));
    buffer_for_strings[0] = 0;
    fread(buffer_for_strings + 1, sizeof(char), fsize, fb);

    char* to = buffer_for_strings + 1;
    int curr_count = 0;
    int curr_line = 0;
    
    for(int i = 1; i < fsize + 1; i++){
        if(buffer_for_strings[i] == '\n'){
            buffer_for_strings[i] = '\0';            
            data[curr_line].count = curr_count;
            data[curr_line].line = to;
        //    data[curr_line].original_pos = curr_line;
            curr_count = 0;
            curr_line++;
            to = buffer_for_strings + i + 1;
        }else{
            curr_count++;            
        }
    }
    
    fclose(fb);
    return buffer_for_strings;
}

void create_bin(const struct strophe* data, int n, char* file){
    assert(data != NULL);

    FILE* fp = fopen(file, "wb");
    putc('\0', fp);
    for(int i = 0; i < n; i++){
        fwrite(data[i].line, sizeof(char), data[i].count, fp);
        putc('\0', fp);
    }
    
    fclose(fp);
}



char* read_bin(struct strophe* data, int count, char* bin_file){
    assert(data != NULL);
    FILE* fb = fopen(bin_file, "rb");
    assert(fb != NULL);
    int fsize = file_size(bin_file);
    char* buffer_for_strings = (char*)calloc(fsize, sizeof(char));
    
    fread(buffer_for_strings, sizeof(char), fsize, fb);

    char* to = buffer_for_strings + 1;
    int curr_count = 0;
    int curr_line = 0;

    for(int i = 1; i < fsize; i++){
        if(buffer_for_strings[i] == '\0'){
            //printf("%d ",i);
            data[curr_line].count = curr_count;
            data[curr_line].line = to;
           // data[curr_line].original_pos = curr_line;
            curr_count = 0;
            curr_line++;
            to = buffer_for_strings + i + 1;
        }else{
            curr_count++;
        }
    }

    fclose(fb);
    return buffer_for_strings;
}




void save_line(const struct strophe* line, FILE* fp){
    assert(line != NULL);
    assert(fp != NULL);
    
    fwrite(line->line, sizeof(char), line->count, fp);
    putc('\n', fp);

}


void save_data(const struct strophe* data, int count, char* file){
    assert(data != NULL);
    assert(file != NULL);
    FILE* fp = fopen(file, "a");
    assert(fp != NULL);

    for(int i = 0; i < count; i++){
        save_line(&data[i], fp);
    }
    char* end = "\n------------\n\n"; // 15 символов
    fwrite(end, sizeof(char), 15, fp);
    fclose(fp);
}

void free_data(struct strophe* data, char* buffer_for_strings){
    assert(data != NULL);
    assert(buffer_for_strings != NULL);
    free(buffer_for_strings);
    free(data);
}

void recreate_data(struct strophe* data, const char* ptr_on_buff, int num_of_lines){
    assert(data != NULL);
    assert(ptr_on_buff != NULL);

    int currl = 0;
    const char* curr = ptr_on_buff + 1;
    const char* to = ptr_on_buff + 1;
    while(currl < num_of_lines){
        if(*curr == '\0'){
            data[currl].line = to;
            data[currl].count = curr - to;
            to = curr + 1;
            currl++;
        }
        curr++;
    }
}

