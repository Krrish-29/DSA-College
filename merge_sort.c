#include<stdio.h>
void merge(int arr[],int left,int middle,int right){
    int i=0,j=0,k=left,n1=middle-left+1,n2=right-middle,L[n1],R[n2];
    for(i=0;i<n1;i++){
        L[i]=arr[i+left];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[j+middle+1];
    }
    i=0;j=0;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            k++;
            i++;
        }
        else{
            arr[k]=R[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        arr[k]=L[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=R[j];
        k++;
        j++;
    }
}
void sort(int arr[],int left,int right){
    if(left<right){
        int middle=left+(right-left)/2;
        sort(arr,left,middle);
        sort(arr,middle+1,right);
        merge(arr,left,middle,right);
    }
}
int main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}