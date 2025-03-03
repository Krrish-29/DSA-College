#include <stdio.h>
void heapify(int array[], int n, int i){
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < n && array[left] > array[largest]){
        largest = left;
    }
    if (right < n && array[right] > array[largest]){
        largest = right;
    }
    if (largest != i){
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        heapify(array, n, largest);
    }
}
void heapsort(int array[], int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(array,n,i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i, 0);
    }
}
void print(int array[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
}
int main(){
    int array[]={9,5,4,7,8,6,1,2,3};
    heapsort(array,sizeof(array)/sizeof(array[0]));
    print(array,sizeof(array)/sizeof(array[0]));
}