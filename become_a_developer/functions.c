/**
 *  Become a developer test
 *  Library of functions used in main
 */


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "functions.h"

/**
 *  Global counter of numbers
 */
long long amount_of_nums = 0;

/**
 * Loads in memory a dynamic array of long long numbers from text file
 * Takes string with text file name as an argument
 * Returns a pointer to array with loaded data
 */
long long* load(const char* name_of_file) {
    // Open text file and check for error
    FILE* numbers_txt = fopen(name_of_file, "r");
    if (!numbers_txt) {
        printf("Unable to open your file (maybe it doesn't exist)\n");
        return NULL;
    }

    // Preparation for loading
    char *buffer = malloc(sizeof(char)*LONG_LONG_MAX_LENGTH);
    long long* loaded = NULL;

    // Get numbers string by string
    while (fgets(buffer, LONG_LONG_MAX_LENGTH, numbers_txt)) {

        // Reallocate memory
        if (!loaded){
            loaded = malloc(sizeof(long long));
        } else {
            loaded = realloc(loaded, (amount_of_nums+1)*sizeof(long long));
        }

        // Get integer from string and assign it to current element of array
        *(loaded+amount_of_nums) = atoi(buffer);
        amount_of_nums++;
    }

    free(buffer);
    return loaded;
}

/**
 * Returns size of loaded array;
 */
long long size (void) {
    return amount_of_nums;
}

void quick_sort(long long *s_arr, long long first, long long last)
{
    if (first < last)
    {
        int left = first, right = last, middle = s_arr[(left + right) / 2];
        do
        {
            while (s_arr[left] < middle) left++;
            while (s_arr[right] > middle) right--;
            if (left <= right)
            {
                int tmp = s_arr[left];
                s_arr[left] = s_arr[right];
                s_arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        quick_sort(s_arr, first, right);
        quick_sort(s_arr, left, last);
    }
}

/**
 * Swaps two elements
 */
void swap (long long *a, long long *b) {
    long long temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/**
 *  Returns average value of array
 */
long long find_average(long long array[], long long arr_size) {
    long long sum = 0;
    for (int i = 0; i < arr_size; i++) {
        sum += array[i];
    }

    return sum/arr_size;
}

/**
 *  Returns median of array
 */
long long find_median (long long array[], long long arr_size) {
    if ( arr_size%2 ) {
        return array[arr_size/2];
    } else {
        return ( array[arr_size/2 - 1] + array[arr_size/2] )/2 ;
    }
}

/**
 * Моя реализация квиксорта, не работает с большими массивами (почему-то)
 * делал по этому видео https://www.youtube.com/watch?v=MZaf_9IZCrc
 * Если массив сортирован этой ф-ей, значение min, max, median выдает правильно
 * Если подскажете почему буду очень благодарен :)
 */
/*
void quick_sort(long long array[], long long first, long long last) {
    long long wall = first-1, pivot = last;

    // Do nothing if amount of elements 1 or 0
    if (last-first > 0) {
        while ()
        for(long long i = first; i < last; i++) {
            if ( array[i] < array[pivot] ) {
                wall++;
                swap(&array[wall], &array[i]);
            }
        }
        swap(&array[pivot], &array[wall+1]);

         COMMENT THIS
         **
         * If there was no swaps everything is sorted
         * Выдаёт SEGFAULT если нет этого условия
         * Работает отлично с маленькими массивами без него
         * Откуда сегфолт не понятно
         *
         COMMENT THIS

        if(wall != first-1){
            quick_sort(array, first, wall);
            quick_sort(array, wall+1, last);
        }
    }
}
*/
