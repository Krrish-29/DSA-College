# include<stdio.h>
# include<stdlib.h>
int main(){
    int matrix_number,row,column,value;
    printf("Enter the number of Matrix required:");
    scanf("%d", &matrix_number);
    printf("Enter the number of rows:");
    scanf("%d",&row);
    printf("Enter the number of column:");
    scanf("%d",&column);
    for(int k=0;k<matrix_number;k++){
        printf("the number of matrix_number:%d\n",k+1);
        for(int j=0;j<column;j++){
            for(int i=0;i<row;i++){
                printf("Enter the value of index (%d,%d) of Matrix %d : ",i,j,k+1);
                scanf("%d",&value);       
            }
        }
    }
}