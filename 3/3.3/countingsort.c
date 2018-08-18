#include <stdio.h>
#include <stdlib.h>
#include <string.h>





void Sort(char *arr){
    int max = 0;
    int n = strlen(arr);
    char output[n];
    // find max
    for (int i = 0;i<n;i++)
        if (arr[i]>max) 
            max = arr[i];
    // counting 
    char count[max];
    char start[max];
    for (int i = 0; i<n; i++)
        count[i] = 0;
    for (int i = 0; i<n; i++)
        count[arr[i]-1]++;
    // start
    start[0]=1;
    for (int i = 1; i<max; i++)
        start[i] = start[i-1]+count[i-1];
    // 
    for (int i = 0; i<n; i++){
        output[start[arr[i]-1]-1] = arr[i];
        start[arr[i]-1]++;
    }

    strncpy(arr, output, n);

}


int main(){
    char input[10] = {5, 9, 8, 2, 3, 6, 4, 7};
    Sort(input);
    //Merge(input, 0, 3, 7);
    //printf("Result: %d\n", BinarySearch(input, key));
    //printf("Result: %d\n", BinarySearch(input, key, 12, 0));
    
    int n = strlen(input);
    for (int i = 0; i<n; i++)
        printf("%d ", input[i]);
    printf("\n");
    
    return 0;
}