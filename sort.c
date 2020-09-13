#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include "sort.h"
#include "data.h"
/** \file */

/** \brief some magic numbers для работы с русскими буквами.(я знаю что это просто ужасно, но по-другому русские буквы у меня не работают)
 * 
 * 
 */
int normalize(const char* letter){
    if(*(letter - 1) == 0){
        return 0;
    }else{
        return 64 * (48 + *(letter-1)) + *letter + 250;      
    }
}

//----------------------------------------------------------------------

int string_compare_straight(const char* line1, const char* line2){
    assert(line1 != NULL);
    assert(line2 != NULL);
    assert(line1 != line2);
    int a = 0;
    int b = 0;
    while(*line1 != -48 && *line1 != -47 && *line1 != 0){
        line1++;
    }
    while(*line2 != -48 && *line2 != -47 && *line2 != 0){
        line2++;
    }
    line1++;
    line2++;

    a = normalize(line1);
    b = normalize(line2);

    while((a == b) && (a != 0) && (b != 0)){
        while(*line1 != -48 && *line1 != -47 && *line1 != 0){
            line1++;
        }
        while(*line2 != -48 && *line2 != -47 && *line2 != 0){
            line2++;
        }
        line1++;
        line2++;
        a = normalize(line1);
        b = normalize(line2);
    }
    
    return a - b;    
}


int sort_strophe_compare_straight(const void* string1, const void* string2){
    assert(string1 != NULL);
    assert(string2 != NULL);
    assert(string1 != string2);
    return string_compare_straight(((struct strophe*)string1)->line, ((struct strophe*)string2)->line);   
}


//----------------------------------------------------------------------


int string_compare_reversed(const char* line1, int len1, const char* line2, int len2){
    assert(line1 != NULL);
    assert(line2 != NULL);
    assert(line1 != line2);
    line1 = line1 + len1 - 1;
    line2 = line2 + len2 - 1;
    
    int a = 0;
    int b = 0;
    while(*line1 != -48 && *line1 != -47 && *line1 != 0){
        line1--;
    }
    while(*line2 != -48 && *line2 != -47 && *line2 != 0){
        line2--;
    }
    line1++;
    line2++;
    a = normalize(line1);
    b = normalize(line2);
    line1 -= 2;
    line2 -= 2;
    
    while((a == b) && (a != 0) && (b != 0)){    
        while(*line1 != -48 && *line1 != -47 && *line1 != 0){
            line1--;
        }
        while(*line2 != -48 && *line2 != -47 && *line2 != 0){
            line2--;
        }
        line1++;
        line2++;
        a = normalize(line1);
        b = normalize(line2);
        
        line1 -= 2;
        line2 -= 2;
    }
    
    return a - b;    
}

int sort_strophe_compare_reversed(const void* string1, const  void* string2){
    assert(string1 != NULL);
    assert(string2 != NULL);
    assert(string1 != string2);
    return string_compare_reversed(((struct strophe*)string1)->line, ((struct strophe*)string1)->count,
                                   ((struct strophe*)string2)->line, ((struct strophe*)string2)->count);   
}


//----------------------------------------------------------------------

/*
int reset_original_order(const void* string1, const  void* string2){
    assert(string1 != NULL);
    assert(string2 != NULL);
    assert(string1 != string2);
    return ((struct strophe*)string1)->original_pos - ((struct strophe*)string2)->original_pos;   
}
*/



//----------------------------------------------------------------------



void bubble_sort(void* data, int start, int end, int(*comp)(const void*, const void*), size_t size){
    assert(data != NULL);
    assert(size != 0);
    void* ptr1 = 0;
    void* ptr2 = 0;
    for(int i = start; i <= end; i++){
        for(int j = 0; j <= end - i - 1; j++){
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

void merge_sort(void* data, int count, int(*comp)(const void*, const void*), size_t size){
    if(count != 1){
        int count1 = count / 2;
        int count2 = count / 2 + count % 2;
        merge_sort(data, count1, comp, size);
        merge_sort(((char*)data + count1*size), count2, comp, size);
        
        void* b = (void *)calloc(count, size);
        int currf = 0;
        int currs = count1;
        int c = 0;
        while(currf < count1 && currs < count){
            if(comp((char*)data + currf*size, (char*)data + currs*size) < 0){
                memcpy(b + c*size, data + currf*size, size);
                currf++;
            }else{
                memcpy(b + c*size, data + currs*size, size);
                currs++;    
            }
            c++;
        }
        
        while(currf < count1 ){
            memcpy(b + c*size, data + currf*size, size);
            currf++;
            c++  ;      
        }
        
        while(currs < count ){
            memcpy(b + c*size, data + currs*size, size);
            currs++;
            c++;        
        }
        memcpy(data, b, count*size);        
        free(b);
    }
}
