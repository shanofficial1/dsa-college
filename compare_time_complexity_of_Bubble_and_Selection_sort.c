#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define SIZE 10000

// Function to generate random numbers (0 - 99999)
void generateRandom(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100000;
    }
}

// Bubble Sort Function
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

    // Seed random generator
    srand(time(NULL));

    // Generate 10,000 random numbers
    generateRandom(arr, SIZE);

    struct timeval start, end;

    // Start time
    gettimeofday(&start, NULL);

    // Sort
    BubbleSort(arr, SIZE);

    // End time
    gettimeofday(&end, NULL);

    // Calculate microseconds
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    long total_time = (seconds * 1000000) + microseconds;

    printf("First 10 sorted numbers:\n");
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }

    printf("\nTime taken: %ld microseconds\n", total_time);

    return 0;
}