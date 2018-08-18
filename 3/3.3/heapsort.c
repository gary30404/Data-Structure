#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Swap(char *a, char *b);
void AdjustBottomUp(char *heap, int i, int n){
    int j = 2*i+1;     //左子點
    while(j <= n){
        if (j < n)
            if (heap[j] < heap[j+1])
                Swap(&heap[j], &heap[j+1]);
        if (heap[i] > heap[j]) 
            break;
        else{
            //printf("%d %d ij = %d %d\n", heap[j/2], heap[j], i, j);
            Swap(&heap[j/2], &heap[j]);
            j=j*2+1;
            i=(j-1)/2;
        }
    }
}


void HeapSort(char *heap){
    int n = strlen(heap);
    //build heap
    for (int i = n/2-1; i>=0; i--){ //i從最後一個父點開始
        AdjustBottomUp(heap, i, n-1);
    }
    
    for (int i = n-1;i>0;i--){
        Swap(&heap[0], &heap[i]);

        for (int j = i/2-1; j>=0; j--){
            AdjustBottomUp(heap, j, i-1);
        }
    }
}

void Swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}


int main(){
    char input[10] = {5, 9, 8, 2, 3, 6, 4, 7};
    HeapSort(input);
    //Merge(input, 0, 3, 7);
    //printf("Result: %d\n", BinarySearch(input, key));
    //printf("Result: %d\n", BinarySearch(input, key, 12, 0));
    
    int n = strlen(input);
    for (int i = 0; i<n; i++)
        printf("%d ", input[i]);
    printf("\n");
    
    return 0;
}