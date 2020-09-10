#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/** \file */
const int max_possible_size = 300;


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


int read_data_and_create_bin(char** data, char* file, int count){
    assert(data != NULL);
    assert(file != NULL);
    char* buffer = (char*)calloc(max_possible_size, sizeof(char));
    int n = 1;
    FILE* fb = fopen("temp.bin", "wb");
    FILE* fp = fopen(file, "r");
    assert(fp != NULL);

    int i = 0;
    while(i < count){
        n = get_line(buffer, fp);
        if(n == 0){
            count--;
        }else{
            data[i] = (char*)calloc(n + 1, sizeof(char));
            for(int j = 0; j < n; j++){
                data[i][j] = buffer[j];
            }
            data[i][n] = 0;
            fwrite(&n, sizeof(int), 1, fb);
            fwrite(data[i], sizeof(char), n+1, fb);
            i++;
        }
    }
    free(buffer);
    fclose(fp);
    fclose(fb);
    return count;
}

int read_bin(char** data){
    assert(data != NULL);
    FILE* fb = fopen("temp.bin", "rb");
    assert(fb != NULL);
    int n = 0;
    int i = 0;
    size_t flag = 1;

    while(flag != 0){
        flag = fread(&n, sizeof(int), 1, fb);
        if(flag != 0){
            data[i] = (char*)calloc(n + 1, sizeof(char));
            fread(data[i], sizeof(char), n + 1, fb);
            i++;
        }
    }
    fclose(fb);
    return i;
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
    assert(fp != NULL);

    for(int i =0; i < count; i++){
        save_line(data[i], fp);
    }
    fclose(fp);
}



void free_data(char** data, int lines_count){
    for(int i = 0; i < lines_count; i++){
        free(data[i]);
    }
    free(data);
}

