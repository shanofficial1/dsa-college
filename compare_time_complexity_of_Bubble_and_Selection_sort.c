#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define SIZE 10000

void generateRandom(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
    }
}

void copyArray(int source[], int dest[], int size) {
    for(int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

void SelectionSort(int arr[], int len){
    for(int i = 0; i < len - 1; i++){
        int min_idx = i;
        for(int j = i + 1; j < len; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

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

    int original[SIZE];
    int arr1[SIZE];
    int arr2[SIZE];

    srand(time(NULL));
    generateRandom(original, SIZE);

    copyArray(original, arr1, SIZE);
    copyArray(original, arr2, SIZE);

    struct timeval start, end;
    double time_taken;

    // Bubble Sort Timing
    gettimeofday(&start, NULL);
    BubbleSort(arr1, SIZE);
    gettimeofday(&end, NULL);

    time_taken =
        (end.tv_sec - start.tv_sec) +
        (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("Bubble Sort Time: %lf seconds\n", time_taken);

    // Selection Sort Timing
    gettimeofday(&start, NULL);
    SelectionSort(arr2, SIZE);
    gettimeofday(&end, NULL);

    time_taken =
        (end.tv_sec - start.tv_sec) +
        (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("Selection Sort Time: %lf seconds\n", time_taken);

    return 0;
}