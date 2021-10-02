#include <stdio.h>

int partition(int a[], int l, int r){
    int i =l, j= r, x=a[l], temp;
    while(i<j){
        while(a[i]<=x && i<=r){
            i++;
        }
        while(a[j]>x){
            j--;
        }
        if(i<j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}

int quick_sort(int a[], int l, int r){
    if(l!=r){
        int p = partition(a, l, r);
        quick_sort(a, l, p-1);
        quick_sort(a, p+1, r);
    }
    
}

void main(){
    int a[10] = {1, 8, 2, 9, 7, 5};
    // call quick sort
    // 0, l, r
    quick_sort(a, 0, 5);
    printf("Array: ");
    for(int i=0; i<6; i++){
        printf("%d ", a[i]);
    }
}
