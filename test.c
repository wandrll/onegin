#include <stdio.h>
#include <stdlib.h>
#include "unit.h"
/** \file */



/** \brief Вызов тестирующих функций
 */

int main(){
    
    //----------------------------------------------------------------------
    int count1 = 4;
 
    char from1[] = "unit_tests_read_and_write/1.txt";
    char to1[] = "unit_tests_read_and_write/1r.txt";
   
    for(int i = 1; i <= count1; i++){
        from1[26] = '0' + i;
        to1[26] = '0' + i;
        remove(to1);
        complex_test(from1, to1);
    }
    
    //----------------------------------------------------------------------

    int count2 = 8;

    char from2[] = "unit_tests_complex/1.txt";
    char to2[] = "unit_tests_complex/1r.txt";
       
    for(int i = 1; i <= count2; i++){
        from2[19] = '0' + i;
        to2[19] = '0' + i;
        remove(to2);
        complex_test(from2, to2);
    }
    


    return 0;
}