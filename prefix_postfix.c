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
    operand_stack[++y]=data;

}
// int 
// char
//evaluate
int parse(char expression[buffer]){
    for(int i=0;i<strlen(expression)-1;i++){
        if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'||expression[i]=='/'||expression[i]=='%'||expression[0]=='('||expression[0]==')'){
            operator_push(expression[i]);
            i++;
        }
        else{// if((i+1<strlen(expression)-1) && (expression[i]!='+'||expression[i]!='-'||expression[i]!='*'||expression[i]!='/'||expression[i]!='%')){
            int n1=0,n2=0,temp[buffer];
            for(i;expression[i]!='\n'||expression[0]==' ';i++){
                temp[n1];
            }
        }
        
    }
}
void expression_identification(char expression[]){
    if(expression[0]=='+'||expression[0]=='-'||expression[0]=='*'||expression[0]=='/'||expression[0]=='%'){
        printf("The expression is Prefix");
    }
    else if (expression[strlen(expression)-2]=='+'||expression[strlen(expression)-2]=='-'||expression[strlen(expression)-2]=='*'||expression[strlen(expression)-2]=='/'||expression[strlen(expression)-2]=='%'){
        printf("The expression is Postfix");
    }
    else{
        printf("The expression is Infix");
    }
}
int main(){
    char expression[buffer];
    printf("Please enter the Prefix or poatfix expression needed to be evaluated");
    fgets(expression,buffer,stdin);
    expression_identification(expression);
    // int result=parse(expression);
    // printf("The result of the expression is %d",result);
}