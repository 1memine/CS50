/**
 *  Become a developer test
 *  Performs task described in "task.txt"
 *  ilya.mikhailov4@gmail.com
 */


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "functions.h"

int main(int argc, char* argv[]){
    if (argc != 2) {
        printf("Usage: ./main FILE_NAME.txt\n");
        return 1;
    }

    long long *nums = NULL, average, median;
    clock_t begin, end;

    // Load numbers to array and check taken time
    begin = clock();
    nums = load(argv[1]);
    if (!nums) {
        return 2;
    }
    clock_t end_load = clock();
    double time_load = (double) (end_load - begin) / CLOCKS_PER_SEC;

    // Get size of loaded array
    const long long N = size();

    // Sort array and check taken time
    clock_t begin_sort = clock();
    quick_sort(nums, 0, N-1);
    clock_t end_sort = clock();
    double time_sort = (double) (end_sort - begin_sort) / CLOCKS_PER_SEC;

    // Find average value and check taken time
    clock_t begin_average = clock();
    average = find_average(nums, N);
    clock_t end_average = clock();
    double time_average = (double)(end_average-begin_average) / CLOCKS_PER_SEC;

    // Find median and check taken time
    clock_t begin_median = clock();
    median = find_median(nums, N);
    end = clock();
    double time_median = (double)(end-begin_median) / CLOCKS_PER_SEC;

    // Print results
    printf("Min: %lld\nMax: %lld\n", *nums, *(nums+N-1) );
    printf("Average: %lld\n", average);
    printf("Median: %lld\n", median);

    // Report benchmarks
    printf ("\nTIME IN load: %.2fs\n", time_load);
    printf ("TIME IN sort: %.2fs\n", time_sort);
    printf ("TIME IN find_average: %.2fs\n", time_average);
    printf ("TIME IN find_median: %.2fs\n", time_median);
    printf ("TOTAL TIME: %.2fs\n", (double)(end-begin)/CLOCKS_PER_SEC );
    free(nums);
}
