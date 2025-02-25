# include<stdio.h>
# include<stdlib.h>
int** matrix_multiplication(int **array1,int row1,int column1,int **array2,int row2,int column2){
    int **array=(int**)calloc(row1,sizeof(int*)),i=0;
    for(int a=0;a<=row1;a++){
        array[a]=(int*)calloc(column2,sizeof(int));
    }
    for(int j=0;j<column2&&i<row1;j++){
        for(int k=0;k<row2;k++){
            array[i][j]+=array1[i][k]*array2[k][j];
        }
        if(j==column2-1){
            i++;
            j=-1;
        }
    }
    return array;
}
int main(){
    int matrix_number;
    printf("Enter the number of Matrix required:");
    scanf("%d", &matrix_number);
    int***array=(int***)calloc(matrix_number,sizeof(int**));
    int row[matrix_number],column[matrix_number];    
    for(int k=0;k<matrix_number;k++){
        printf("Enter the number of rows for Matrix %d:",k+1);
        scanf("%d",&row[k]);
        printf("Enter the number of column for Matrix %d:",k+1);
        scanf("%d",&column[k]);
        if(k>0&&row[k]!=column[k-1]){
            printf("Invalid Matrices cannot be multiplied.");
            exit(1);
        }
        for(int a=k;a<matrix_number;a++){
            array[a]=(int**)calloc(row[k],sizeof(int*));
            for(int b=0;b<row[k];b++){
                array[a][b]=(int*)calloc(column[k],sizeof(int*));
            }
        }
        printf("Matrix:%d\n",k+1);
        for(int i=0;i<row[k];i++){
            for(int j=0;j<column[k];j++){
                printf("Enter the value of index (%d,%d) of Matrix %d : ",i,j,k+1);
                scanf("%d",&array[k][i][j]);       
            }
        }
    }
    for(int k=0;k<matrix_number-1;k++){
        array[k+1]=matrix_multiplication(array[k],row[k],column[k],array[k+1],row[k+1],column[k+1]);
        row[k+1]=row[k];
    }
    printf("The matrix multiplication of the matrices is:\n");
    for(int i=0;i<row[matrix_number-1];i++){
        for(int j=0;j<column[matrix_number-1];j++){
            printf("%d ",array[matrix_number-1][i][j]);
        }
        printf("\n");
    }
}