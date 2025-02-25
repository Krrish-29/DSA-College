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
linkedlist* matrix_multiplication(linkedlist*list1,int row1,int column1,linkedlist*list2,int row2,int column2){
    linkedlist*list=createsparselist();
    sparse_matrix *ptr1,*ptr2;
    int value;
    for(int x=0;x<row1;x++){
        for(int y=0;y<column2;y++){
            ptr1=list1->head;
            value=0;
            while(ptr1!=NULL){
                if(ptr1->row==x){
                    ptr2=list2->head;
                    while(ptr2!=NULL){
                        if(ptr1->column==ptr2->row&&y==ptr2->column){
                            value+=(ptr1->value)*(ptr2->value);
                        }
                        ptr2=ptr2->next;
                    }
                    ptr1=ptr1->next;
                }
                if(value!=0){
                    insertAtTail(list,value,x,y);
                }
            }
        }
    }
    return list;   
}
void printlist(linkedlist*list){
    sparse_matrix*current=list->head;
    while(current!=NULL){
        printf("value:%d row:%d column:%d\n",current->value,current->row,current->column);
        current=current->next;
    }
}
int main(){
    int matrix_number,value;
    printf("Enter the number of Matrix required:");
    scanf("%d", &matrix_number);
    linkedlist* array[matrix_number];
    for(int x=0;x<matrix_number;x++){
        array[x]=createsparselist();
    }
    int row[matrix_number],column[matrix_number],k=0;
    for(k;k<matrix_number;k++){
        printf("Enter the number of rows for Matrix %d:",k+1);
        scanf("%d",&row[k]);
        if(k>0 &&(column[k-1]!=row[k])){
            printf("Matrices cannot be Multiplied");
            exit(0);
        }
        printf("Enter the number of column for Matrix %d:",k+1);
        scanf("%d",&column[k]);
        printf("Matrix %d:\n",k+1);
        for(int i=0;i<row[k];i++){
            for(int j=0;j<column[k];j++){
                printf("Enter the value of index (%d,%d) of Matrix %d : ",i,j,k+1);
                scanf("%d",&value);
                if(value!=0){
                    insertAtTail(array[k],value,i,j);
                }       
            }
        }
        if(k>=1){
            printf("Matrix multiply");
            array[k-1]=matrix_multiplication(array[k-1],row[k-1],column[k-1],array[k],row[k],column[k]);
            row[k]=row[k-1];
        }
    }
    // for(int y=0;y<matrix_number;y++){
    //     printlist(array[y]);
    // }
    printf("\n");
    printf("The Sparse Matrix multiplication of given Matrices is:\n");
    printlist(array[k]);
}