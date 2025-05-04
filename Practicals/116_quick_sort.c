#include<stdio.h>
int partition(int array[],int left,int right){
    int pivot=array[right];int i=left-1;
    for(int j=left;j<right;j++){
        if(array[j]<=pivot){i++;int temp=array[j];
            array[j]=array[i];array[i]=temp;}}
    i++;int temp=array[i];array [i]=array[right];
    array[right]=temp;return i;}
void QuickSort(int array[],int left,int right){
    if(left<right){
        int pivotIndex=partition(array,left,right);
        QuickSort(array,left,pivotIndex-1);
        QuickSort(array,pivotIndex+1,right);}}
void printArray(int array[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }printf("\n");}
int main(){
    int array[]={10,9,8,7,6,5,4,3,2,1}, size=sizeof(array)/sizeof(array[0]);
    printf("Unsorted Array: ");printArray(array,size);
    QuickSort(array,0,size-1);
    printf("Sorted Array: ");printArray(array,size);
}