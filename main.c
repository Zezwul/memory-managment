#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void foo(uint32_t numbernOfElements)
{
    uint32_t array[numbernOfElements];
    (void)array;
}

int main(void)
{
    //created only for memory layout in memory section
    static int staticVariable;
    static int staticArray[100];
    (void)staticVariable;
    (void)staticArray;

    clock_t start, stop;
    double cpuTimeUsed;
    srand(time(NULL));

    uint64_t numberOfAllocations = 1000000000;
    uint64_t exampleValue = 100;

    const uint64_t numberOfElements = 10000;
    RAII(freeInt) uint64_t* arrayOnHeap = malloc(sizeof(uint64_t) * numberOfElements);
    randomizeArray(arrayOnHeap, numberOfElements);

    uint64_t arrayOnStack[numberOfElements];
    randomizeArray(arrayOnStack, numberOfElements);

    printf("bubble sort on heap----");
    BUBBLE_SORT_MEASURE_TIME(arrayOnHeap, numberOfElements);
    randomizeArray(arrayOnHeap, numberOfElements);

    printf("bubble sort on stack---");
    BUBBLE_SORT_MEASURE_TIME(arrayOnStack, numberOfElements);
    randomizeArray(arrayOnStack, numberOfElements);

    printf("qsort on heap----------");
    QSORT_MEASURE_TIME(arrayOnHeap, numberOfElements);
    randomizeArray(arrayOnHeap, numberOfElements);

    printf("qsort on stack---------");
    QSORT_MEASURE_TIME(arrayOnStack, numberOfElements);
    randomizeArray(arrayOnStack, numberOfElements);

    printf("\n");

    start = clock();
    stop = clock() - start;
    foo(numberOfElements);
    cpuTimeUsed = ((double)stop) / CLOCKS_PER_SEC;
    printf("stack allocation time--%f[s]\n", cpuTimeUsed);

    start = clock();
    for (uint64_t i = 0; i < numberOfAllocations; ++i)
    {
        RAII(freeInt) uint64_t* hvalue = malloc(sizeof(uint64_t));
        *hvalue = exampleValue;
    }
    stop = clock() - start;
    cpuTimeUsed = ((double)stop) / CLOCKS_PER_SEC;
    printf("heap allocation time---%f[s]\n", cpuTimeUsed);

    printf("\n");

    char* string1 = "string1"; //read-only (literal is constant)
    printf("%s\n", string1);

    char string2[7] = "string2"; //buffer allocated on the stack, filled with literals
    printf("%s\n", string2);

    string2[4] = 'T';
    printf("%s\n", string2);

    string1[4] = 'T'; //segmentation fault due to try of changing read-only memory block
    printf("%s\n", string1);
}
