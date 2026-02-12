#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {

    srand(time(NULL));

    for(int n = 10000; n <= 100000; n += 10000) {

        int *arr = (int*)malloc(n * sizeof(int));

        // Generate random numbers
        for(int i = 0; i < n; i++) {
            arr[i] = rand() % 100000;
        }

        // Sort array (required for binary search)
        qsort(arr, n, sizeof(int), compare);

        int key = arr[rand() % n];

        struct timeval start, end;

        volatile int found = 0;   // volatile prevents optimization

        gettimeofday(&start, NULL);

        // Repeat many times for measurable time
        for(int repeat = 0; repeat < 1000000; repeat++) {

            int left = 0, right = n - 1;

            while(left <= right) {
                int mid = left + (right - left) / 2;

                if(arr[mid] == key) {
                    found = 1;
                    break;
                }
                else if(arr[mid] < key)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        gettimeofday(&end, NULL);

        double time_taken =
            (end.tv_sec - start.tv_sec) +
            (end.tv_usec - start.tv_usec) / 1000000.0;

        printf("Time taken for binary search in array of size %d: %.6f seconds\n",
               n, time_taken);

        free(arr);
    }

    return 0;
}