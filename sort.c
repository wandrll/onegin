#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "sort.h"
/** \file */
const int max_possible_chars = 1000;

char* clean_string(char* line){
    assert(line != NULL);
    char* b = (char*)calloc(max_possible_chars, sizeof(char));
    int curr = 0;

    while( *line != 0){
        if(((*line >= 'A') && (*line <= 'Z')) ||
           ((*line >= 'a') && (*line <= 'z'))){
            
            if((*line >= 'A') && (*line <= 'Z')){
               *(b + curr) = *line + 32;
            } else {
                *(b + curr) = *line;
            }
            
            curr++;
        }
        line++;
    }
    *(b+curr) = 0;
    return b;
}

int string_compare(void* line1, void* line2){
    assert(line1 != NULL);
    assert(line2 != NULL);
    assert(line1 != line2);
    char* s1 = *(char**)line1;
    s1 = clean_string(s1);
    char* s2 = *(char**)line2;
    s2 = clean_string(s2);
    
    while((*s1 != 0) && (*s2 != 0)){
        if(*s1 == *s2){
            s1++;
            s2++;
        }else{
            if(*s1 < *s2){
                return 1;
            }else{
                return -11;
            }
        }
    }
    if(*s1 == 0){
        return 1;
    }else{
        return -10;
    }
    free(s1);
    free(s2);
    
}

typedef int (*comp_type)(void*, void*);

void bubble_sort(void* data, int start, int end, comp_type comp, size_t size){
    assert(data != NULL);
    assert(size != 0);
    
    for(int i = start; i <= end; i++){
        for(int j = 0; j <= end - i - 1; j++){
            if( comp( (char*)data + j*size, (char*)data + (j+1)*size ) < 0){
                void* temp = malloc(size);
                memcpy(temp, data + j*size, size);
                memcpy(data + j*size, data + (j+1)*size, size);
                memcpy(data + (j+1)*size, temp, size);
                free(temp);
            }
        }
    }
}
