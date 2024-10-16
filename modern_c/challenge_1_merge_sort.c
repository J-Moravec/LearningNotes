#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void print_array(size_t const len, double const arr[len]){
    for(size_t i = 0; i < len; i++){
        printf("[%zu]=%f\n", i, arr[i]);
        }
    }


void merge(
    size_t const left_start,
    size_t const left_len,
    size_t const right_start,
    size_t const right_len,
    double arr[left_len + right_len]
    ){
    size_t li = 0;
    size_t ri = 0;
    size_t i = 0;

    double left[left_len];
    memcpy(left, arr + left_start, sizeof(arr[0])*left_len);

    double right[right_len];
    memcpy(right, arr + right_start, sizeof(arr[0])*right_len);
    memset(arr, 0, sizeof(arr[0]) * (left_len + right_len));


    while( (li < left_len) & (ri < right_len) ){

        if(left[li] < right[ri]){
            arr[i] = left[li];
            li++;
            } else {
            arr[i] = right[ri];
            ri++;
            }
        i++;
        }

    while(li < left_len){
        arr[i] = left[li];
        li++;
        i++;
        }

    while(ri < right_len){
        arr[i] = right[ri];
        ri++;
        i++;
        }
    }


void merge_sort(size_t const len, double arr[len]){
    if(len < 2)
        return;

    size_t half = len / 2;

    merge_sort(half, arr);
    merge_sort(len - half, arr + half);
    merge((size_t) 0, half, half, len - half, arr);
    }


void sort_check(size_t const len, double arr[len]){
    printf("Checking is array is sorted ...\n");
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

    merge_sort(argc - 1, arr);
    sort_check(argc - 1, arr);
    printf("Your array is:\n");
    print_array(argc - 1, arr);
    }
