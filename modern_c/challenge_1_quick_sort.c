#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void print_array(size_t const len, double const arr[len]){
    for(size_t i = 0; i < len; i++){
        printf("%.2f ", arr[i]);
        }
    printf("\n");
    }

void swap(double* x, double* y){
    double tmp = *x;
    *x = *y;
    *y = tmp;
    }

// Implementation of Hoare's partitioning scheme
size_t hoare_partition(size_t const len, double arr[len]){
    double pivot = arr[len / 2];

    size_t low = 0;
    size_t high = len - 1;

    while(1){
        while(arr[low] < pivot){
            low++;
            }

        while(arr[high] > pivot){
            high--;
            }

        if(low >= high)
            return high;

        swap(&arr[low], &arr[high]);

        low++;
        high--;
        }
    }


void quicksort(size_t const len, double arr[len]){
    // No need to sort singletons
    if(len < 2) return;

    size_t pivot_index = hoare_partition(len, arr);

    // Array is already sorted
    if(pivot_index == len - 1) return;

    quicksort(pivot_index + 1, arr);
    quicksort(len - pivot_index - 1, arr + pivot_index + 1);
    }


void sort_check(size_t const len, double arr[len]){
    printf("Checking if array is sorted ...\n");
    for(size_t i = 0; i < len - 1; i++){
        if(arr[i] > arr[i + 1]){
            printf("Array is NOT correctly sorted!\n");
            return;
            }
        }
    printf("All good!\n");
    }


int main(int argc, char* argv[argc + 1]){
    double arr[argc - 1];
    for(size_t i = 0; i < argc - 1; i++){
        arr[i] = strtod(argv[i + 1], 0);
        }

    quicksort(argc - 1, arr);
    sort_check(argc - 1, arr);
    printf("Your array is:\n");
    print_array(argc - 1, arr);
    }
