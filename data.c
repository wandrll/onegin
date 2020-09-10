#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/** \file */
const int max_possible_size = 300;
char* line;

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



/*
char *sausage = calloc();
fread(sausage, file_size, 1, )
char *from = sausage, *to = sausage;
for (int i = 0; i < file_size; ++i){
    if (isCapable((*from))) {
        *to = *from;
        to++;
    }
    from++;
    
    
}
to - sausage //ЭТО нужный размер бинарника
*/



int file_size(char* file){
    assert(file != NULL);

    FILE* fb = fopen(file, "rb");
    assert(fb != NULL);

    fseek(fb, 0, SEEK_END);
    int size = ftell(fb);
    fclose(fb);
    return size;
}

int is_possible_to_add(char* to, char from){
    assert(to != NULL);
    if(*(to - 1) != 0){
        return 1;
    }else{
        if(from == '\n'){
            return 0;
        }else{
            return 1;
        }
    }
}


void read_data_and_create_bin(char* file){
    assert(file != NULL);
    FILE* fb = fopen(file, "r");
    FILE* fd = fopen("temp.bin", "wb");
    assert(fb != NULL);

    char* buffer = (char*)calloc(file_size(file), sizeof(char));
    char* to = buffer;
    char from = getc(fb);
    
    *to = from;
    to++;
    int count = 1;
    
    while(from != EOF){
        from = getc(fb);
        if(from == EOF){
            break;
        }
        if(is_possible_to_add(to, from)){
            if(from == '\n'){
                *to == 0;
            } else {
                *to = from;
            }
            to++;
            count++;
        }
    }
    if(*(to-1) != 0){
        *to = 0;
        count++;
    }

    fwrite(buffer, sizeof(char), count, fd);
    free(buffer);
    fclose(fd);
    fclose(fb);
}

int read_bin(char** data){
    assert(data != NULL);
    FILE* fb = fopen("temp.bin", "rb");
    assert(fb != NULL);
    int count = 0;

    count = file_size("temp.bin");

    line = (char*)calloc(count, sizeof(char));
    fread(line, sizeof(char), count, fb);
    data[0] = line;
    int lines_count = 1;
    for(int i = 0; i < count; i++){
        if(line[i] == '\0'){
            data[lines_count] = (line + i + 1);
            lines_count++;
        }
    }    
    fclose(fb);
    return lines_count;
    
    return 0;
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



void free_data(){
    free(line);
}

int old_read_data(char** data, char* file, int count){
    assert(data != NULL);
    assert(file != NULL);
    char* buffer = (char*)calloc(max_possible_size, sizeof(char));
    int n = 1;
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
            i++;
        }
    }
    free(buffer);
    fclose(fp);
    return count;
}
