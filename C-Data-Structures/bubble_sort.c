#include <stdio.h>

int bubble_sort(int a[], int l){
    for(int i=l-2; i>=0; i--){
        for(int j=0; j<=i; j++){
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void main(){
    int a[10] = {1, 8, 2, 9, 7, 5};
    // call bubble sort
    bubble_sort(a, 6);
    printf("Array: ");
    for(int i=0; i<6; i++){
        printf("%d ", a[i]);
    }
}
