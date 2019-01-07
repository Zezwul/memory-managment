#ifndef LIB_H_
#define LIB_H_

#include <time.h>

#define BUBBLE_SORT_MEASURE_TIME(ARRAY, NUMBER_OF_ELEMENTS)\
    start = clock();\
    bubbleSort(ARRAY, NUMBER_OF_ELEMENTS);\
    stop = clock() - start;\
    cpuTimeUsed = ((double)stop) / CLOCKS_PER_SEC;\
    printf("%f[s]\n", cpuTimeUsed);

#define QSORT_MEASURE_TIME(ARRAY, NUMBER_OF_ELEMENTS)\
    start = clock();\
    qsort(ARRAY, NUMBER_OF_ELEMENTS, sizeof(uint64_t), (__compar_fn_t)compare);\
    stop = clock() - start;\
    cpuTimeUsed = ((double)stop) / CLOCKS_PER_SEC;\
    printf("%f[s]\n", cpuTimeUsed);

#define RAII(free_func) __attribute__((cleanup (free_func)))

#include <inttypes.h>

void freeInt(uint64_t **i);
uint32_t compare(const void * first, const void * second);
void swap(uint64_t* first, uint64_t* second);
void bubbleSort(uint64_t arr[], uint64_t numberOfElements);
void randomizeArray(uint64_t* array, uint64_t sizeOfArray);

#endif /*LIB_H_*/
