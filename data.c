#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/** \file */
const int max_possible_size = 100;

char* reduce_size(char* line, int size){
    assert(line != NULL);
    
    char* copy_line = line;
    char* new_line = (char*)calloc(size + 1, sizeof(char));
    char* copy_new_line = new_line;

    while(*copy_line != 0){
        *copy_new_line = *copy_line;
        copy_new_line++;
        copy_line++;
    }

    *copy_new_line = 0;
    free(line);
    return(new_line);
}


int lines_count(char* file){
    assert(file != NULL);
    char c = 0;
    int count = 0;
    FILE* fp = fopen(file, "r");

    while(c != EOF){
        c = getc(fp);
        if(c == '\n'){
            count++;
        }
    }
    fclose(fp);
    return count;
}


int get_line(char* line, FILE* fp){
    assert(line != NULL);
    assert(fp != NULL);
    
    char c = 0;
    int curr = 0;
    
    while(c != '\n'){
        c = getc(fp);
        line[curr] = c;
        curr++;
    }

    line[curr-1] = 0;
    return curr - 1;
}


int read_data(char** data, char* file){
    assert(data != NULL);
    assert(file != NULL);
    
    int n = 1;
    int count = lines_count(file);
    //int count = 1;
    FILE* fp = fopen(file, "r");
    int i = 0;
    while(i < count){
        data[i] = (char*)calloc(max_possible_size, sizeof(char));
        n = get_line(data[i], fp);
        if(n == 0){
            free(data[i]);
            count--;
        }else{
            data[i] = reduce_size(data[i], n);
            i++;
        }
    }
    
    fclose(fp);
    return count;
}


void print_data(char** data, int count){
    assert(data != NULL);
    
    for(int i = 0; i < count; i++){
        printf("%s\n", data[i]);
    }
}


void save_line(char* line, FILE* fp){
    assert(line != NULL);
    assert(fp != NULL);
    
    while(*line != 0){
        putc(*line, fp);
        line++;
    }
    putc('\n', fp);
}

void save_data(char** data, int count, char* file){
    assert(data != NULL);
    assert(file != NULL);

    FILE* fp = fopen(file, "w");
    for(int i =0; i < count; i++){
        save_line(data[i], fp);
    }
    fclose(fp);
}
