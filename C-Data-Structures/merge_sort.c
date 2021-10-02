#include <stdio.h>

void simple_merge(int a[], int f, int s, int t){
    int i=f, j=s, k=-1;
    int temp[20];
    while(i<=s-1 && j<=t){
        if(a[i]>a[j]){
            k++;
            temp[k] = a[j];
            j++;
        }
        else{
            k++;
            temp[k] = a[i];
            i++;
        }
    }
    if(i>s-1){
        for(int w=j; w<=t; w++){
            k++;
            temp[k] = a[w];
        }
    }else{
        for(int w=i; w<=s-1; w++){
            k++;
            temp[k] = a[w];
        }
    }
    for(int w=0; w<=k; w++){
        a[f+w] = temp[w];
    }
}


int merge_sort(int a[], int l, int r){
    int mid = (l+r)/2;
    if(l!=r){
        merge_sort(a, l, mid);
        merge_sort(a, mid+1, r);
        simple_merge(a, l, mid+1, r);
    }
}

void main(){
    int a[10] = {1, 8, 2, 9, 7, 5};
    // call merge sort
    // a, 0, n-1
    merge_sort(a, 0, 5);
    printf("Array: ");
    for(int i=0; i<6; i++){
        printf("%d ", a[i]);
    }
}
