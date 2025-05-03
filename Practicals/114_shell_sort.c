#include<stdio.h>
void shell_sort(int array[],int size){
    int gap=1;
    while(gap<size/3){
        gap=(3*gap+1);
    }
    while(gap>0){
        for(int i=gap;i<size;i++){
            int j=i,temp=array[i];
            while(j>=gap&&array[j-gap]>temp){
                array[j]=array[j-gap];
                j-=gap;
            }
            array[j]=temp;
        }
        gap/=3;
    }
}
int main(){
    int array[]={10,9,8,7,6,5,4,3,2,1},size=sizeof(array)/sizeof(array[0]);
    shell_sort(array,size);
    for(int i=0;i<size;i++){
        printf("%d ",array[i]);
    }
}