#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int BinarySearch(char *str, char key){

    int high = strlen(str);
    int low = 0;
    int mid;
    while(low <= high){
        mid = (low + high)/2;
        if (key == str[mid]) return mid;
        if (key > str[mid]) low = mid + 1;
        if (key < str[mid]) high = mid - 1;
    }
    return -1;
}*/

int BinarySearch(char *str, char key, int high, int low){

    int mid = (low + high)/2;
    if (key == str[mid]) return mid;
    if (key > str[mid]) return BinarySearch(str, key, high, mid + 1);
    if (key < str[mid]) return BinarySearch(str, key, mid - 1, low);
    return -1;
}


int main(){
    char input[12] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'};
    char key = 'f';
    //printf("Result: %d\n", BinarySearch(input, key));
    printf("Result: %d\n", BinarySearch(input, key, 12, 0));
    return 0;
}