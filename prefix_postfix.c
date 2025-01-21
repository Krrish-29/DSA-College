#include<stdio.h>
#include<string.h>
#define buffer 1000
char operator_stack[buffer];//+-*/
int x=-1;
int operand_stack[buffer];//123456789
int y=-1;

void operator_push(char data){
    if(x>=buffer-1){
        printf("Overflow");
        return;
    }
    operator_stack[++x]=data;
}
void operand_push(int data){
    if(x>=buffer-1){
        printf("Overflow");
        return;
    }
    operand_stack[++x]=data;

}
// int 
// char
//evaluate
int parse(char expression[buffer]){
    int n1=0,n2=0;
    for(int i=0;i<strlen(expression)-1;i++){
        if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'||expression[i]=='/'||expression[i]=='%'){
            operator_push(expression[i]);
        }
        else if( (((int)(expression[i])==32) && (i+1<strlen(expression)-1)) && () ){

        }
    }
}




int main(){
    char expression[buffer];
    printf("Please enter the Prefix or poatfix expression needed to be evaluated");
    fgets(expression,buffer,stdin);
    if(expression[0]=='+'||expression[0]=='-'||expression[0]=='*'||expression[0]=='/'||expression[0]=='%'){
        printf("The expression is Prefix");
    }
    else{
        strrev(expression);
        printf("The expression is Postfix");
    }
    int result=parse(expression);
    printf("The result of the expression is %d",result);
}