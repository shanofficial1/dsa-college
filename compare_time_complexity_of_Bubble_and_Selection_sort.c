#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int arr[], int len){
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){

    int arr[] = {1,43,2,3,97,32,34,2,13,435,76,23,45,67,89,90,12,34,56,78};
    int len = sizeof(arr) / sizeof(arr[0]);

    time_t start_time = time(NULL);

    BubbleSort(arr, len);

    time_t end_time = time(NULL);

    double time_taken = difftime(end_time, start_time);

    printf("Sorted array: ");
    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %.0f seconds\n", time_taken);

    return 0;
}