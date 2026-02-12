#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define SIZE 10000

// Generate 10,000 random numbers
void generateRandom(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
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

// Bubble Sort
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

    int arr[SIZE];

    srand(time(NULL));
    generateRandom(arr, SIZE);

    struct timeval start, end;

    // Start time
    gettimeofday(&start, NULL);

    BubbleSort(arr, SIZE);

    // End time
    gettimeofday(&end, NULL);

    // Convert to seconds
    double time_taken = 
        (end.tv_sec - start.tv_sec) + 
        (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("Bubble sort Time taken: %lf seconds\n", time_taken);


    gettimeofday(&start, NULL);
    SelectionSort(arr, SIZE);
    gettimeofday(&end, NULL);
    time_taken = 
        (end.tv_sec - start.tv_sec) + 
        (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Selection sort Time taken: %lf seconds\n", time_taken);
    return 0;
}