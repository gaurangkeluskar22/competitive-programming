#include <stdio.h>

int insertion_sort(int a[], int n){
    for(int i=0; i<=n-1; i++){
        int j = i;
        int x = a[i];
        while(j>0 && a[j-1]>x){
            a[j] = a[j-1];
            j--;
        }
        a[j] = x;
    }
}

void main(){
    int a[10] = {1, 8, 2, 9, 7, 5};
    // call insertion sort
    insertion_sort(a, 6);
    printf("Array: ");
    for(int i=0; i<6; i++){
        printf("%d ", a[i]);
    }
}
