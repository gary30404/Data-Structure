#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void Sort(char *arr){

    int n = strlen(arr);
    int min;
    for (int i = 0; i < n; i++){
        min = i;
        for (int j=i; j < n; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
        if (min != i) {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
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