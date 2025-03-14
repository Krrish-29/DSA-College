#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>// condition - elements should be greater than zero.
int *dynamicarray;
int len=0,capacity=1;
void add(int );
int remove_element (int );
int remove_at (int );
void clear();
void set(int ,int );
bool isEmpty();
bool contains (int );
int get(int );
int size();
void printfarray();
void add(int element){
    if(len>=capacity){
        capacity*=2;
        dynamicarray=realloc(dynamicarray,capacity*sizeof(int));
        if (!dynamicarray) { 
            fprintf(stderr, "Memory allocation failed\n"); 
            exit(1); 
        }
    }
    dynamicarray[len]=element;
    len++;
}
int remove_element (int element){
    if(len==0){
        return -1;
    }
    for(int i=0;i<len;i++){
        if(dynamicarray[i]==element){
            int temp=dynamicarray[i];
            for(int j=i;j<len-1;j++){
                dynamicarray[j]=dynamicarray[j+1];
            }
            len--;
            return temp;
        }
    }
    return -1;
}
int remove_at (int index){
    if(len>index){
        int temp=dynamicarray[index];
        for(int i=index;i<len-1;i++){
            dynamicarray[i]=dynamicarray[i+1];
        }
        len--;
        return temp;
    }
    else{
        return -1;
    }
}
void clear(){
    free(dynamicarray);
    capacity=1;
    len=0;
    dynamicarray=(int*)calloc(capacity,sizeof(int));
    if (!dynamicarray) { 
        fprintf(stderr, "Memory allocation failed\n"); 
        exit(1); 
    }
}
void set(int index,int element){
    if(index<len){
        dynamicarray[index]=element;
    }
}
bool isEmpty(){
    if(len==0){
        return true;
    }
    return false;
}
bool contains (int target){
    for(int i=0;i<len;i++){
        if(dynamicarray[i]==target){
            return true;
        }
    }
    return false;
}
int get(int index){
    if(index<len){
        return dynamicarray[index];
    }
    return -1;
}
int size(){
    return len;
}
void printfarray(){
    for(int i=0;i<len;i++){
        printf("%d\n",dynamicarray[i]);
    }
}
int main(){
    dynamicarray=(int*)calloc(1,sizeof (int));  
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