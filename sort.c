#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "sort.h"
#include "data.h"
/** \file */

//----------------------------------------------------------------------
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//----------------------------------------------------------------------



int isletter_RUS(const unsigned char c){
    if(c >= 192){ //В кодировке CP1251 русские буквы начинаются с 192 и идут до 255
        return 1;
    }else{
        return 0;
    }
}



int string_compare_straight_RUS(const unsigned char* line1, const unsigned char* line2){
    assert(line1 != NULL);
    assert(line2 != NULL);
    assert(line1 != line2);

    while(!isletter_RUS(*line1) && *line1 != 0){
        line1++;
    }
    while(!isletter_RUS(*line2) && *line2 != 0){
        line2++;
    }


    while((*line1 == *line2) && (*line1 != 0) && (*line2 != 0)){
        line1++;
        line2++;

        while(!isletter_RUS(*line1) && *line1 != 0){
            line1++;
        }
        while(!isletter_RUS(*line2) && *line2 != 0){
            line2++;
        }
        
    }
    
    return *line1 - *line2;    
}


int sort_strophe_compare_straight_RUS(const void* string1, const void* string2){
    assert(string1 != NULL);
    assert(string2 != NULL);
    assert(string1 != string2);
    return string_compare_straight_RUS(((struct strophe*)string1)->line, ((struct strophe*)string2)->line);   
}


//----------------------------------------------------------------------


int string_compare_reversed_RUS(const unsigned char* line1, int len1, const unsigned char* line2, int len2){
    assert(line1 != NULL);
    assert(line2 != NULL);
    assert(line1 != line2);
    line1 = line1 + len1 - 1;
    line2 = line2 + len2 - 1;

    while(!isletter_RUS(*line1) && *line1 != 0){
        line1--;
    }
    while(!isletter_RUS(*line2) && *line2 != 0){
        line2--;
    }


    while((*line1 == *line2) && (*line1 != 0) && (*line2 != 0)){
        line1--;
        line2--;

        while(!isletter_RUS(*line1) && *line1 != 0){
            line1--;
        }
        while(!isletter_RUS(*line2) && *line2 != 0){
            line2--;
        }
        
    }
    
    return *line1 - *line2;    
}

int sort_strophe_compare_reversed_RUS(const void* string1, const  void* string2){
    assert(string1 != NULL);
    assert(string2 != NULL);
    assert(string1 != string2);
    return string_compare_reversed_RUS(((struct strophe*)string1)->line, ((struct strophe*)string1)->count,
                                   ((struct strophe*)string2)->line, ((struct strophe*)string2)->count);   
}



//----------------------------------------------------------------------
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//----------------------------------------------------------------------

int isletter_ENG(const unsigned char c){
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
        return 1;
    }else{
        return 0;
    }
}



int string_compare_straight_ENG(const unsigned char* line1, const unsigned char* line2){
    assert(line1 != NULL);
    assert(line2 != NULL);
    assert(line1 != line2);

    while(!isletter_ENG(*line1) && *line1 != 0){
        line1++;
    }
    while(!isletter_ENG(*line2) && *line2 != 0){
        line2++;
    }


    while((*line1 == *line2) && (*line1 != 0) && (*line2 != 0)){
        line1++;
        line2++;

        while(!isletter_ENG(*line1) && *line1 != 0){
            line1++;
        }
        while(!isletter_ENG(*line2) && *line2 != 0){
            line2++;
        }
        
    }
    
    return *line1 - *line2;    
}


int sort_strophe_compare_straight_ENG(const void* string1, const void* string2){
    assert(string1 != NULL);
    assert(string2 != NULL);
    assert(string1 != string2);
    return string_compare_straight_ENG(((struct strophe*)string1)->line, ((struct strophe*)string2)->line);   
}


//----------------------------------------------------------------------


int string_compare_reversed_ENG(const unsigned char* line1, int len1, const unsigned char* line2, int len2){
    assert(line1 != NULL);
    assert(line2 != NULL);
    assert(line1 != line2);
    line1 = line1 + len1 - 1;
    line2 = line2 + len2 - 1;

    while(!isletter_ENG(*line1) && *line1 != 0){
        line1--;
    }
    while(!isletter_ENG(*line2) && *line2 != 0){
        line2--;
    }


    while((*line1 == *line2) && (*line1 != 0) && (*line2 != 0)){
        line1--;
        line2--;

        while(!isletter_ENG(*line1) && *line1 != 0){
            line1--;
        }
        while(!isletter_ENG(*line2) && *line2 != 0){
            line2--;
        }
        
    }
    
    return *line1 - *line2;    
}

int sort_strophe_compare_reversed_ENG(const void* string1, const  void* string2){
    assert(string1 != NULL);
    assert(string2 != NULL);
    assert(string1 != string2);
    return string_compare_reversed_ENG(((struct strophe*)string1)->line, ((struct strophe*)string1)->count,
                                   ((struct strophe*)string2)->line, ((struct strophe*)string2)->count);   
}


//----------------------------------------------------------------------
//----------------------------------------------------------------------
//----------------------------------------------------------------------
//----------------------------------------------------------------------



void bubble_sort(void* data, int start, int end, int(*comp)(const void*, const void*), size_t size){
    assert(data != NULL);
    assert(size != 0);
    void* ptr1 = 0;
    void* ptr2 = 0;
    for(size_t i = start; i <= end; i++){
        for(size_t j = 0; j <= end - i - 1; j++){
            if( comp(((char*)data + j*size), ((char*)data + (j+1)*size)) > 0){
                void* temp = malloc(size);
                memcpy(temp, data + j*size, size);
                memcpy(data + j*size, data + (j+1)*size, size);
                memcpy(data + (j+1)*size, temp, size);
                free(temp);
            }
        }
    }
}

void merge_sort(void* data, size_t count, int(*comp)(const void*, const void*), size_t size){
    if(count > 1){
        size_t count1 = count / 2;
        size_t count2 = count / 2 + count % 2;

        merge_sort(data, count1, comp, size);
        merge_sort(((char*)data + count1*size), count2, comp, size);
        
        void* b = (void *)calloc(count, size);
        size_t currf = 0;
        size_t currs = count1;
        size_t c = 0;
        
        while(currf < count1 && currs < count){
            if(comp((char*)data + currf*size, (char*)data + currs*size) < 0){
                memcpy((char*)b + c*size, (char*)data + currf*size, size);
                currf++;
            }else{
                memcpy((char*)b + c*size, (char*)data + currs*size, size);
                currs++;    
            }
            c++;
        }
        
        while(currf < count1 ){
            memcpy((char*)b + c*size, (char*)data + currf*size, size);
            currf++;
            c++  ;      
        }
        
        while(currs < count ){
            memcpy((char*)b + c*size, (char*)data + currs*size, size);
            currs++;
            c++;        
        }
        memcpy(data, b, count*size);        
        free(b);
    }
}
