#include <stdio.h>
#include <stdlib.h>

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

/** \brief считывает все строки из файла и сохраняет их в файл temp.bin в формате "количество символов, строка"
 *  \param data указатель на массив указателей
 *  \param file имя файла
 *  \param count количество переходов на новую строку в файле "file"
 *  \return количество не пустых строк в файле
 */
int old_read_data(char** data, char* file, int count);

int read_data_and_create_bin(char* file);

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

/** \brief очищает память выделенную для data 
 *  \param data указатель на массив указателей
 *  \param lines_count количество ненулевых строк
 */
void free_data();

/** \brief считывает строки из файла temp.bin 
 *  \param data указатель на массив указателей
 *  \return количество считанных строк
 */
int read_bin(char** data);
int file_size(char* file);