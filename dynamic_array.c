// condition - elements should be greater than zero.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int *ptr;
int len=0,capacity=1;
void add(int element){
    if(len+1>capacity){
        capacity*=2;
        ptr=realloc(ptr,capacity*sizeof(int));
    }
    ptr[len]=element;
    len++;
}
void clear(){
    free(ptr);
    ptr=calloc(capacity,sizeof(int));
    len=0;
}
void set(int index,int element){
    ptr[index]=element;
}
int size(){
    return len;
}
bool isEmpty(){
    if(len==0){
        return true;
    }
    return false;
}
bool contains (int target){
    for(int i=0;i<len;i++){
        if(ptr[i]==target){
            return true;
            break;
        }
    }
    return false;
}
int get(int index){
    if(index>len){
        return -1;
    }
    return ptr[index];
}
void printfarray(){
    for(int i=0;i<len;i++){
        printf("%d\n",ptr[i]);
    }
}
int remove_element (int element){
    if(len==0){
        return -1;
    }
    for(int i=0;i<len;i++){
        if(ptr[i]==element){
            int temp=ptr[i];
            ptr[i]=0;
            return temp;
        }
    }
    return -1;
}
int remove_at (int index){
    if(len>index){
        int  temp=ptr[index];
        ptr[index]=0;
        return temp;
    }
    else{
        return -1;
    }
    
}
int main(){
    ptr=(int*)calloc(1,sizeof (int));  
  /*

  remove at
  remove
  */
    add(1);
    add(8);
    add(2);
    add(7);
    printf("Size of array:%d\n",size());
    add(100);
    add(89);
    add(67);
    printfarray();
    printf("%d\n",contains(45));
    printf("%d\n",contains(7));
    printf("%d\n",get(6));
    printf("%d\n",isEmpty());
    set(1,9);
    printf("Size of array:%d\n",size());
    printfarray();
    printf("%d\n",remove_element(100));
    printf("%d\n",remove_element(85));
    printf("%d\n",remove_at(5));
    printf("%d\n",remove_at(15));
    printfarray();    
    clear();
}