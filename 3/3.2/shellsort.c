#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void Sort(char *arr){

    int n = strlen(arr);
    int span = n/2;
    int flag = 0;
    while(span >= 1){
        while(flag != n-span){
            flag = n - span;
            for (int i = 0; i < n-span; i++){
                if (arr[i] > arr[i+span]){
                    int temp = arr[i];
                    arr[i] = arr[i+span];
                    arr[i+span] = temp;
                    flag--;
                }
            }
        }
        span/=2;
    }
    for (int i = 0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main(){
    char input[10] = {5, 7, 8, 9, 3, 1, 4, 2};
    Sort(input);
    //printf("Result: %d\n", BinarySearch(input, key));
    //printf("Result: %d\n", BinarySearch(input, key, 12, 0));
    return 0;
}