/**
 *  Become a developer test
 *  Header file
 */

/**
 *  Max length of string with long long number
 *  −9 223 372 036 854 775 807
 */
#define LONG_LONG_MAX_LENGTH 20

/**
 * Loads in memory a dynamic array of long long numbers from text file
 * Takes string with text file name as an argument
 * Returns a pointer to array with loaded data
 */
long long* load(const char*);

/**
 * Returns size of loaded array;
 */
long long size ();

/**
 *  Quick sort algorithm
 *  Taken from: https://bit.ly/2UO0mLu
 *  Got my own implementation, see functions.c
 */
void quick_sort(long long[], long long, long long);

/**
 * Swaps two elements
 */
void swap (long long*, long long*);

/**
 *  Returns average value of array
 */
long long find_average (long long[], long long);

/**
 *  Returns median of array
 */
long long find_median (long long[], long long);
