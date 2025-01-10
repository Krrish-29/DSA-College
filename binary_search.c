#include <stdio.h>
// RECURSIVE BINARY SEARCH
// int binary_search(int array[],int left,int right,int target){
//     int middle=left+(right-left)/2;
//     if(left<=right){
//         if(array[middle]==target){
//             return middle;
//         }
//         else if(array[middle]>target){
//             return binary_search(array,left,middle-1,target);
//         }
//         else if(array[middle]<target){
//             return binary_search(array,middle+1,right,target);
//         }
//     }
//     return -1;
// }


// BETTER BINARY SEARCH
int binary__search(int array[],int size,int target){
    int low=0,high=size-1;
    while(low<=high){
        int middle=low+(high-low)/2;
        if(array[middle]==target){
            return middle;
        }
        else if(array[middle]>target){
            high=middle-1;
        }
        else if(array[middle]<target){
            low=middle+1;
        }
    }
    return -1;
}
int main(){
    int array[]={3,4,5,8,10,45,75,95,123},target;
    printf("Enter the target element:");
    scanf("%d",&target);
    // int index=binary_search(array,0,sizeof(array)/sizeof(array[0]),target);
    int index=binary__search(array,sizeof(array)/sizeof(array[0]),target);
    index==-1?printf("Not present in the array"):printf("%d",index);
    return 0;
}