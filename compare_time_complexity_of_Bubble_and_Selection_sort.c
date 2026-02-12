#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void BubbleSort(int arr[], int len){
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}



int main(){
    date();
    int arr[] = {1,43,2,3,97,32,34,2,13,435,76,23,45,67,89,90,12,34,56,78};
    int len = sizeof(arr) / sizeof(arr[0]);
    float date=  new Date();
    float start_time = Date();
    BubbleSort(arr, len);
    float end_time = clock();
    float time_taken = (end_time - start_time) / CLOCKS_PER_SEC;
    printf("Sorted array: ");
    for(int i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
    printf("\nTime taken: %f seconds\n", time_taken);
}