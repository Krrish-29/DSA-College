# include<stdio.h>
# include<stdlib.h>
void matrix_addition(int **array1,int **array2,int row,int column){
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            array2[i][j]+=array1[i][j];
        }
    }
}
int main(){
    int matrix_number,row,column;
    printf("Enter the number of Matrix required:");
    scanf("%d", &matrix_number);
    int***array=(int***)calloc(matrix_number,sizeof(int**));
    printf("Enter the number of rows:");
    scanf("%d",&row);
    printf("Enter the number of column:");
    scanf("%d",&column);
    for(int a=0;a<matrix_number;a++){
        array[a]=(int**)calloc(row,sizeof(int*));
        for(int b=0;b<row;b++){
            array[a][b]=(int*)calloc(column,sizeof(int*));
        }
    }
    for(int k=0;k<matrix_number;k++){
        printf("The number of matrix_number:%d\n",k+1);
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                printf("Enter the value of index (%d,%d) of Matrix %d : ",i,j,k+1);
                scanf("%d",&array[k][i][j]);       
            }
        }
    }
    for(int k=0;k<matrix_number-1;k++){
        matrix_addition(array[k],array[k+1],row,column);
    }
    printf("The matrix addition of the matrices is:\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<column;j++){
            printf("%d ",array[matrix_number-1][i][j]);
        }
        printf("\n");
    }
}