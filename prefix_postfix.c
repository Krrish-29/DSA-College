#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define buffer 1000
char operator_stack[buffer];
int operand_stack[buffer],operand_count=-1,operator_count=-1,left_parenthesis=0,right_parenthesis=0,base_case_operand_count=0;
void operator_push(char data){
    operator_stack[++operator_count]=data;
}
void operand_push(int data){
    operand_stack[++operand_count]=data;
}
int operand_pop(){
    return operand_stack[operand_count--];
}
char operator_pop(){
    return operator_stack[operator_count--];
}
char operator_peek(){
    return operator_stack[operator_count];
}
void calculator(char operator){
    int op2=operand_pop(),op1=operand_pop();
    switch(operator){
        case '-':
            operand_push(op1-op2);
            break;
        case '+':
            operand_push(op1+op2);
            break;
        case '*':
            operand_push(op1*op2);
            break;
        case '/':
            operand_push(op1/op2);
            break;
        case '%':
            operand_push(op1%op2);
            break;
        case '^':
            operand_push((int)pow(op1,op2));
            break;
    }
}
int infix_evaluation(char expression[]){
    operand_count=-1,operator_count=-1;
    for(int i=strlen(expression)-2;i>=0;i--){
        char new_expression[buffer];
        if(expression[i]>='0'&&expression[i]<='9'){
               
        }
        else if(expression[i]=='-'||expression[i]=='+'||expression[i]=='*'||expression[i]=='/'||expression[i]=='^'){

        }
    }
}
int prefix_evaluation(char expression[]){
    operand_count=-1,operator_count=-1;
    for(int i=strlen(expression)-2;i>=0;i--){
        if(expression[i]>='0'&&expression[i]<='9'){
            int temp[buffer],tempcount=0,number=0,sign=1;
            for(i;(expression[i]>='0'&&expression[i]<='9')&&(i>=0);i--){
                temp[tempcount++]=expression[i]-48;
            }
            for(int j=tempcount-1;j>=0;j--){
                number=number*10+temp[j];
            }
            if(expression[i]=='-'){
                sign=-1;
                i--;
            }
            operand_push(number*sign);
            if(operator_count==-1){
                base_case_operand_count++;
            }
        }
        else if((expression[i]=='-'||expression[i]=='+'||expression[i]=='*'||expression[i]=='/'||expression[i]=='^'||expression[i]=='('||expression[i]==')')&&(base_case_operand_count>=2)){
            if(expression[i]=='-'||expression[i]=='+'||expression[i]=='*'||expression[i]=='/'||expression[i]=='^')
                calculator(expression[i]);
            i--;
        } 
        else{
            printf("Inavlid Expression");
            exit(1);
        }   
    }
    return operand_pop();
}
int postfix_evaluation(char expression[]){
    operand_count=-1,operator_count=-1;
    for(int i=0;i<=strlen(expression)-2;i++){
        if((expression[i]>='0'&&expression[i]<='9')||((expression[i]=='-'&&i+1<=strlen(expression)-2)&&(expression[i+1]>='0'&&expression[i+1]<='9'))){
            int temp[buffer],tempcount=0,number=0,sign=1;
            if(expression[i]=='-'){
                sign=-1;
                i++;
            }
            for(i;(expression[i]>='0'&&expression[i]<='9')&&(i<=strlen(expression)-2);i++){
                temp[tempcount++]=expression[i]-48;
            }
            for(int j=0;j<tempcount;j++){
                number=number*10+temp[j];
            }
            operand_push(number*sign);
            if(operator_count==-1){
                base_case_operand_count++;
            }
        }
        else if((expression[i]=='-'||expression[i]=='+'||expression[i]=='*'||expression[i]=='/'||expression[i]=='^'||expression[i]=='('||expression[i]==')')&&(base_case_operand_count>=2)){
            if(expression[i]=='-'||expression[i]=='+'||expression[i]=='*'||expression[i]=='/'||expression[i]=='^')
                calculator(expression[i]);
            i++;
        } 
        else{
            printf("Invalid Expression");
            exit(1);
        }   
    }
    return operand_pop();
}
//parse check for operator ,operand ,parenthesis ,empty string,typing errors .
void parse(char expression[]){  
    for(int i=0;i<=strlen(expression)-2;i++){
        if((expression[i]>='0'&&expression[i]<='9')||((expression[i]<='-'&&i+1<=strlen(expression)-2)&&(expression[i+1]>='0'&&expression[i+1]<='9'))){
            if(expression[i]<='-'){
                i++;
            }
            for(i;(expression[i]>='0'&&expression[i]<='9')&&(i<=strlen(expression)-2);i++){
            }
            operand_count++;
        }
        else if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'||expression[i]=='/'||expression[i]=='%'||expression[i]=='^'){
            operator_count++;
            i++;
        } 
        else if((expression[i]=='('||expression[i]==')')&&(left_parenthesis>=right_parenthesis)){
            if(expression[i]=='(')
                left_parenthesis++;
            if(expression[i]==')')
                right_parenthesis++;
            i++;
        }
        else{
            printf("Invaild Expression");
            exit(1);
        }
    }
}
int evalutaion(char expression[]){
    int result =0;
    parse(expression);
    if((operand_count-operator_count)==1&&(left_parenthesis-right_parenthesis==0)&&(strlen(expression)>=2)){
        if(expression[strlen(expression)-2]=='+'||expression[strlen(expression)-2]=='-'||expression[strlen(expression)-2]=='*'||expression[strlen(expression)-2]=='/'||expression[strlen(expression)-2]=='%'){
            result=postfix_evaluation(expression);
            printf("The expression is Postfix\n");
            printf("The result of expression: %d",result); 
        }
        else if(expression[0]=='+'||(expression[0]=='-'&&(!((1<=strlen(expression)-2)&&(expression[1]>='0'&&expression[1]<='9'))))||expression[0]=='*'||expression[0]=='/'||expression[0]=='%'){
            result=prefix_evaluation(expression);
            printf("The expression is Prefix\n");
            printf("The result of expression: %d",result);
        }
        else{
            result=infix_evaluation(expression);
            printf("The expression is Infix\n");
            printf("The result of expression: %d",result);
        }
    }
    else{
        printf("Invaild Expression");
        exit(1);
    }
    return result;
}
int main(){
    char expression[buffer];
    printf("Please enter the expression needed to be evaluated:\n");
    fgets(expression,buffer,stdin);
    printf("The result of expression is :%d",evalutaion(expression));
    return 0;
}