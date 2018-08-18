#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void Merge(char *arr, int front, int mid, int end){
    
    char LeftSubArray[mid-front+1];
    char RightSubArray[end-mid+1];
    strncpy(LeftSubArray, arr+front, mid-front+1);
    strncpy(RightSubArray, arr+mid+1, end-mid);

    
    int MAX = 100;
    LeftSubArray[mid-front+1] = MAX;
    RightSubArray[end-mid] = MAX;

    int idxLeft = 0, idxRight = 0;

    for (int i = front; i <= end; i++) {

        if (LeftSubArray[idxLeft] <= RightSubArray[idxRight]) {
            arr[i] = LeftSubArray[idxLeft];
            idxLeft++;
        }
        else{
            arr[i] = RightSubArray[idxRight];
            idxRight++;
        }

    }
    
}

void Sort(char *arr, int front, int end){

    if (front < end) {
        int mid = (front+end)/2;
        Sort(arr, front, mid);
        Sort(arr, mid+1, end);
        Merge(arr, front, mid, end);
    }
}


int main(){
    char input[10] = {5, 9, 8, 2, 3, 6, 4, 7};
    Sort(input, 0, 7);
    //Merge(input, 0, 3, 7);
    //printf("Result: %d\n", BinarySearch(input, key));
    //printf("Result: %d\n", BinarySearch(input, key, 12, 0));
    
    int n = strlen(input);
    for (int i = 0; i<n; i++)
        printf("%d ", input[i]);
    printf("\n");
    
    return 0;
}