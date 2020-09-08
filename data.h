#include <stdio.h>
#include <stdlib.h>
/** \brief уменьшает размер выделенной памяти под строку 
 *  \param line указатель на строку
 *  \param size количество элементов
 *  \return указатель на новую строку, с меньшим объемом выделенной памяти
 */

char* reduce_size(char* line, int size);

/** \brief считывает одну строку из файла
 *  \param line указатель на строку куда записать считанную строку
 *  \param fp указатель на файл
 *  \return количество элементов в строке
 */
int get_line(char* line, FILE* fp);

/** \brief находит количество переходов на новую строку
 *  \param file имя файла откуда считывать
 *  \return количество переходов на новую строку в файле
 */
int lines_count(char* file);

/** \brief считывает все строки из файла
 *  \param data указатель на массив указателей
 *  \param file имя файла
 *  \return количество не пустых строк в файле
 */
int read_data(char** data, char* file);

/** \brief печатает все строки
 *  \param data указатель на массив указателей
 *  \param count количество строй
 */
void print_data(char** data, int count);

/** \brief сохраняет ровно одну строку в файл
 *  \param line указатель на строку
 *  \param fp указатель на файл
 */
void save_line(char* line, FILE* fp);

/** \brief сохраняет все строки из массива указателей в файл
 *  \param data указатель на массив указателей
 *  \param count количество строк
 *  \param file имя файла
 */
void save_data(char** data, int count, char* file);