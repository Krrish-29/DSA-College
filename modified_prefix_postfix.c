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
int prefix_evaluation(char expression[]) {
    operand_count = -1, operator_count = -1;
    char *token = strtok(expression, " ");
    while (token != NULL) {
        if (token[0] >= '0' && token[0] <= '9') {
            int number = atoi(token);
            operand_push(number);
            if (operator_count == -1) {
                base_case_operand_count++;
            }
        } 
        else if (token[0] == '-' || token[0] == '+' || token[0] == '*' || token[0] == '/' || token[0] == '^' ||
            token[0] == '(' || token[0] == ')') {
            if (base_case_operand_count >= 2 && (token[0] == '-' || token[0] == '+' || token[0] == '*' || token[0] == '/' || token[0] == '^')) {
                calculator(token[0]);
            }
        } 
        else {
            printf("Invalid Expression");
            exit(1);
        }
        token = strtok(NULL, " ");
    }
    return operand_pop();
}
int postfix_evaluation(char expression[]) {
    operand_count = -1, operator_count = -1;
    char *token = strtok(expression, " ");
    while (token != NULL) {
        if ((token[0] >= '0' && token[0] <= '9') || (token[0] == '-' && token[1] >= '0' && token[1] <= '9')) {
            int number = atoi(token);
            operand_push(number);
            if (operator_count == -1) {
                base_case_operand_count++;
            }
        } 
        else if (token[0] == '-' || token[0] == '+' || token[0] == '*' || token[0] == '/' || token[0] == '^' ||token[0] == '(' || token[0] == ')') {
            if (base_case_operand_count >= 2 && (token[0] == '-' || token[0] == '+' || token[0] == '*' || token[0] == '/' || token[0] == '^')) {
                calculator(token[0]);
            }
        } 
        else {
            printf("Invalid Expression");
            exit(1);
        }
        token = strtok(NULL, " ");
    }
    return operand_pop();
}
void parse(char expression[]) {
    operand_count = -1, operator_count = -1, left_parenthesis = right_parenthesis = 0;
    char *token = strtok(expression, " ");
    while (token != NULL) {
        if ((token[0] >= '0' && token[0] <= '9') || (token[0] == '-' && token[1] >= '0' && token[1] <= '9')) {
            operand_count++;
        } 
        else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/' || token[0] == '%' || token[0] == '^') {
            operator_count++;
        } 
        else if (token[0] == '(') {
            left_parenthesis++;
        } 
        else if (token[0] == ')') {
            right_parenthesis++;
        } 
        else {
            printf("Invalid Expression");
            exit(1);
        }
        token = strtok(NULL, " ");
    }
}
int main(){
    char expression[buffer];
    printf("Please enter the expression needed to be evaluated:\n");
    fgets(expression,buffer,stdin); 
    int result=0;
    parse(expression);
    if((operand_count-operator_count)==1&&(left_parenthesis-right_parenthesis==0)){
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
            // result=infix_evaluation(expression);
            printf("The expression is Infix\n");
            printf("The result of expression: %d",result);
        }
    }
    else{
        printf("Invaild Expression");
        exit(1);
    }
    return 0;
}