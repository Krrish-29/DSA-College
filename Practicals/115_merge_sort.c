#include<stdio.h>
void merge(int array[],int left,int middle,int right){
    int n1=middle-left+1,n2=right-middle,L[n1],R[n2],i,j,k=left;
    for(i=0;i<n1;i++){L[i]=array[left+i];}
    for(j=0;j<n2;j++){R[j]=array[middle+j+1];}
    for(i=0,j=0;i<n1&&j<n2;k++){
        if(L[i]<=R[j]){array[k]=L[i];i++;}
        else{array[k]=R[j];j++;}    }
    while(i<n1){array[k]=L[i];i++;k++;}
    while(j<n2){array[k]=R[j];j++;k++;}
}
void mergeSort(int array[],int left,int right){
    if(left<right){int middle=left+(right-left)/2;
        mergeSort(array,left,middle);
        mergeSort(array,middle+1,right);
        merge(array,left,middle,right);}}
void printArray(int array[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }printf("\n");}
int main(){
    int array[]={10,9,8,7,6,5,4,3,2,1}, size=sizeof(array)/sizeof(array[0]);
    printf("Unsorted Array: ");printArray(array,size);
    mergeSort(array,0,size-1);
    printf("Sorted Array: ");printArray(array,size);
}