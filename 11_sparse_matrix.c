# include<stdio.h>
# include<stdlib.h>
typedef struct sparse_matrix{
    int value;
    int row;
    int column;
    struct sparse_matrix * next;
} sparse_matrix;
typedef struct linkedlist{
    sparse_matrix *head;
}linkedlist;
linkedlist *createsparselist(){
   linkedlist*list=(linkedlist*)calloc(1,sizeof(linkedlist));
   list->head=NULL;
   return list; 
}
int getSize(linkedlist*list){
    sparse_matrix*current=list->head;
    int count=0;
    while(current!=NULL){
        count++;
        current=current->next;
    }
    return count;
}
void insertAtIndex(linkedlist*list,int index,int value,int row,int column){
    if(index<=getSize(list)&&index>=0){
        sparse_matrix*newNode=(sparse_matrix*)calloc(1,sizeof(sparse_matrix));
        newNode->value=value;
        newNode->row=row;
        newNode->column=column;
        if(index==0){
            newNode->next=list->head;
            list->head=newNode;
        }
        else{
            sparse_matrix*current=list->head;
            while(current!=NULL&&--index>0){
                current=current->next;
            }
            if (current != NULL) {
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }
}
void insertAtTail(linkedlist*list,int value,int row,int column){
    sparse_matrix*newNode=(sparse_matrix*)calloc(1,sizeof(sparse_matrix));
    newNode->value=value;
    newNode->row=row;
    newNode->column=column;
    newNode->next=NULL;
    if(list->head==NULL){
        list->head=newNode;
    }
    else{
        sparse_matrix*current=list->head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newNode;
    }
}
void matrix_addition(linkedlist*list1,linkedlist*list2,int row,int column){
    sparse_matrix *ptr1=list1->head,*ptr2=list2->head;
    int Size1=getSize(list1) ,Size2=getSize(list2);
    int a=0;
    while(ptr1!=NULL&&ptr2!=NULL){
        if(ptr1->row==ptr2->row&&ptr1->column==ptr2->column){
            ptr1->value+=ptr2->value;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        else if(ptr1->row>ptr2->row||(ptr1->row==ptr2->row&&ptr1->column>ptr2->column)){
            insertAtIndex(list1,a,ptr2->value,ptr2->row,ptr2->column);
            ptr2=ptr2->next;
        }
        else{
            ptr1=ptr1->next;
        }
        a++;
    } 
    while(ptr2!=NULL){
        insertAtTail(list1,ptr2->value,ptr2->row,ptr2->column);
        ptr2=ptr2->next;
    }    
}
void printlist(linkedlist*list){
    sparse_matrix*current=list->head;
    while(current!=NULL){
        printf("value:%d row:%d column:%d\n",current->value,current->row,current->column);
        current=current->next;
    }
}
int main(){
    int matrix_number,row,column,value;
    printf("Enter the number of Matrix required:");
    scanf("%d", &matrix_number);
    linkedlist* array[matrix_number];
    for(int x=0;x<matrix_number;x++){
        array[x]=createsparselist();
    }
    printf("Enter the number of rows:");
    scanf("%d",&row);
    printf("Enter the number of column:");
    scanf("%d",&column);
    for(int k=0;k<matrix_number;k++){
        printf("Matrix %d:\n",k+1);
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                printf("Enter the value of index (%d,%d) of Matrix %d : ",i,j,k+1);
                scanf("%d",&value);
                if(value!=0){
                    insertAtTail(array[k],value,i,j);
                }       
            }
        }
    }
    for(int y=0;y<matrix_number;y++){
        printlist(array[y]);
    }
    printf("\n");
    for(int z=1;z<matrix_number;z++){
        matrix_addition(array[0],array[z],row,column);
    }
    printf("The Sparse Matrix addition of given Matrices is:\n");
    printlist(array[0]);
}