#include <stdio.h>
#include <stdlib.h>

/** \brief структура хранящая одну строфу 
 *  \param line указатель на строку
 *  \param count количество байтов выделенных на строку (русс. символы занимаю 2 байта)
 */
struct strophe{
    const char* line;
    int count;
};


/** \brief выделение памяти для массива строф 
 *  \param count количество 
 */
struct strophe* data_mem_alloc(int count);



/** \brief находит количество переходов на новую строку
 *  \param file имя файла откуда считывать
 *  \return количество переходов на новую строку в файле
 */
int lines_count(char* file);


/** \brief считывает все строки из файла и сохраняет их в файл temp.bin в формате "количество символов, строка"
 *  \param data указатель на массив строф
 *  \param file имя файла
 *  \return указатель на буфер содержащий все данные 
 */
char* read_data(struct strophe* data, char* file);


/** \brief сохраняет ровно одну строку в файл
 *  \param line указатель на строку
 *  \param fp указатель на файл
 */
void save_line(const struct strophe* line, FILE* fp);


/** \brief сохраняет все строки из массива указателей в файл
 *  \param data указатель на массив строф
 *  \param count количество
 *  \param file имя файла
 */
void save_data(const struct strophe* data, int count, char* file);


/** \brief очищает память выделенную для data 
 *  \param data указатель на массив строф
 *  \param buffer_for_strings указатель на начало буфера
 */
void free_data(struct strophe* data, char* buffer_for_strings);


/** \brief считывает строки из файла .bin 
 *  \param data указатель на массив строф
 *  \param count количество строк
 *  \param bin_file имя бинарника
 *  \return количество считанных строк
 */
char* read_bin(struct strophe* data, int count, char* bin_file);


/** \brief сохраняет строфы в  .bin 
 *  \param data указатель на массив строф
 *  \param n количество строк
 *  \param file имя бинарника
 */
void create_bin(const struct strophe* data, int n, char* file);


/** \brief воссоздает массив строф по буферу
 *  \param data указатель на массив строф
 *  \param ptr_on_buff указатель на буфер
 *  \param num_of_lines количество строк
 *  \return количество считанных строк
 */
void recreate_data(struct strophe* data, const char* ptr_on_buff, int num_of_lines);


/** \brief возвращает размер файла
 *  \param file имя файла
 *  \return количество байт в файле
 */
int file_size(char* file);