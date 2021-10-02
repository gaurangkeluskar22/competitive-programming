#include<stdio.h>

int selection_sort(int a[], int n){
    int i, j, temp, min, p;
    for(i=0; i<=n-2; i++){
        min = a[i], p=i;
        for(j=i+1; j<=n-1; j++){
            if(a[j]<min){
                min = a[j];
                p = j;
            }
        }
        temp = a[i];
        a[i] = a[p];
        a[p] = temp;
    }
}

void main(){
    int a[10] = {1, 8, 2, 9, 7, 5};
    selection_sort(a, 6);
    printf("Array: ");
    for(int i=0; i<6; i++){
        printf("%d ", a[i]);
    }
}
