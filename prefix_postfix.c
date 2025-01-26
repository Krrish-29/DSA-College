#include<stdio.h>
#include<string.h>
#define buffer 1000
char operator_stack[buffer];
int total_operator_count=-1,operand_stack[buffer],total_operand_count=-1,operator_count=-1;
void operator_push(char data){
    if(total_operator_count>=buffer-1){
        printf("Overflow");
        return;
    }
    operator_stack[++total_operator_count]=data;
}
void operand_push(int data){
    if(total_operand_count>=buffer-1){
        printf("Overflow");
        return;
    }
    operand_stack[++total_operand_count]=data;
}
int operand_pop(){
    if(total_operator_count==-1){
        printf("UnderFlow");
    }
}
char operator_pop(){

}
int evaluate(){

}
void parse(char expression[]){  
    int numcount=-1;
    for(int i=0;i<strlen(expression)-1;i++){
        if(((i+1<=strlen(expression)-2)&&(expression[i]=='-'))&&(expression[i+1]>='0'&&expression[i+1]<='9')){
            int temp[buffer],tempcount=0,num=0;
            for(i;(expression[i+1]>='0'&&expression[i+1]<='9')&&(i+1<=strlen(expression)-2);i++){
                temp[tempcount++]=expression[i+1]-48;
            }
            for(int j=0;j<tempcount;j++){
                num=num*10+temp[j];
            }
            operand_push(num*(-1));
            numcount++;
        }
        else if (expression[i]>='0'&&expression[i]<='9'){
            int temp[buffer],tempcount=0,num=0;
            for(i;(expression[i]>='0'&&expression[i]<='9')&&(i+1<=strlen(expression)-2);i++){
                temp[tempcount++]=expression[i]-48;
            }
            for(int j=0;j<tempcount;j++) {
                num=num*10+temp[j];
            }
            operand_push(num);
            numcount++;
        }
        else{
            for(numcount;numcount>=0;numcount--){
                operator_push(' ');
            }
            operator_push(expression[i]);
            operator_count++;
            numcount=-1;
            i++;
        }    
    }
}
int expression_identification(char expression[]){
    parse(expression);
    printf("%d %d ",total_operand_count,operator_count);
    if((total_operand_count-operator_count)!=1&&total_operand_count>operator_count)
        return 0;
    if (expression[strlen(expression)-2]=='+'||expression[strlen(expression)-2]=='-'||expression[strlen(expression)-2]=='*'||expression[strlen(expression)-2]=='/'||expression[strlen(expression)-2]=='%'){
        printf("The expression is Postfix\n");     
    }
    else if(expression[0]=='+'||(expression[0]=='-'&&(!((1<=strlen(expression)-2)&&(expression[1]>='0'&&expression[1]<='9'))))||expression[0]=='*'||expression[0]=='/'||expression[0]=='%'){
        printf("The expression is Prefix\n");
    }
    else{
        printf("The expression is Infix\n");
    }
    return 1;
}
int main(){
    char expression[buffer];
    printf("Please enter the expression needed to be evaluated:\n");
    restart:
    fgets(expression,buffer,stdin); 
    if(expression_identification(expression)){
        printf("%d",evaluate());
    }
    else{
        printf("Invaild Expression\nEnter a valid expression:\n");
        goto restart;
    }
}