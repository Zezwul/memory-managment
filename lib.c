#include "lib.h"
#include <stdlib.h>

void freeInt(uint64_t **intToFree)
{
    free(*intToFree);
}

uint32_t compare(const void* first, const void* second)
{
    uint64_t _first = *(uint64_t*)first;
    uint64_t _second = *(uint64_t*)second;

    if(_first < _second)
    {
        return -1;
    }
    else if (_first == _second)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void swap(uint64_t* first, uint64_t* second)
{
    uint64_t temp = *first;
    *first = *second;
    *second = temp;
}

void bubbleSort(uint64_t arr[], uint64_t numberOfElements)
{
    for (uint64_t i = 0; i < numberOfElements - 1; i++)
    {
        for (uint64_t j = 0; j < numberOfElements - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void randomizeArray(uint64_t* array, uint64_t sizeOfArray)
{
    for (uint64_t i = 0; i < sizeOfArray; ++i)
    {
        array[i] = rand() % sizeOfArray;
    }
}
