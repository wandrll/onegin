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
    *(b + curr) = 0;
    return b;
}

int string_compare(void* line1, void* line2){
    assert(line1 != NULL);
    assert(line2 != NULL);
    assert(line1 != line2);
    char* l1 = *(char**)line1;
    char* l2 = *(char**)line2;
    while((*l1 == *l2) && (*l1 != 0)){
        l1++;
        l2++;
    }
    return *l1 - *l2;
    
}

typedef int (*comp_type)(void*, void*);

void bubble_sort(void* data, int start, int end, comp_type comp, size_t size){
    assert(data != NULL);
    assert(size != 0);
    
    for(int i = start; i <= end; i++){
        for(int j = 0; j <= end - i - 1; j++){

            if( comp( (char*)data + j*size, (char*)data + (j+1)*size ) > 0){
                
                void* temp = malloc(size);
                memcpy(temp, data + j*size, size);
                memcpy(data + j*size, data + (j+1)*size, size);
                memcpy(data + (j+1)*size, temp, size);
                free(temp);
            }
        }
    }
}
