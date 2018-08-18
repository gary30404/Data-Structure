#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void Sort(char *arr, int l, int u){

    //int n = strlen(arr);
    if (l >= u) return;
    int pk = arr[l];
    int i = l;
    int j = u ;
    int temp;
    while (i<j){
        while (arr[i]<pk) i++;
        while (arr[j]>pk) j--;
        if (i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[l];
    arr[l] = arr[j];
    arr[l] = temp;
    Sort(arr, l, j-1);
    Sort(arr, j+1, u);
}


int main(){
    char input[10] = {5, 9, 8, 2, 3, 6, 4, 7};
    Sort(input, 0, 7);
    //printf("Result: %d\n", BinarySearch(input, key));
    //printf("Result: %d\n", BinarySearch(input, key, 12, 0));
    int n = strlen(input);
    for (int i = 0; i<n; i++)
        printf("%d ", input[i]);
    printf("\n");
    return 0;
}