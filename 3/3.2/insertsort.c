#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Insert(char *arr, int index){
    int former = index-1;
    int insert = arr[index];
    while (insert < arr[former]){
        //printf("%d %d %d\n", i, target, arr[i]);
        arr[former+1] = arr[former];
        former--;
    }
    arr[former+1] = insert;
}

void Sort(char *arr){

    int n = strlen(arr);
    for (int i = 1; i < n; i++){
        printf("=%d %d %d\n", i, arr[i-1], arr[i]);
        Insert(arr, i);
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