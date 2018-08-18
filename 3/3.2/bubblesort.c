#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void Sort(char *arr){

    int n = strlen(arr);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            printf("%d ", j);
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printf("\n");
    }

    for (int i = 0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main(){
    char input[5] = {5, 3, 8, 2, 6};
    Sort(input);
    //printf("Result: %d\n", BinarySearch(input, key));
    //printf("Result: %d\n", BinarySearch(input, key, 12, 0));
    return 0;
}