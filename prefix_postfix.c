#include<stdio.h>
#include<string.h>
#define buffer 1000
char operator_stack[buffer];
int operand_stack[buffer],operand_count=-1,operator_count=-1;
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
int infix_evaluation(char expression[]){
    
}
int prefix_evaluation(char expression[]){
    operand_count=-1,operator_count=-1;
    for(int i=strlen(expression)-2;i>=0;i--){
        if(expression[i]>='0'&&expression[i]<='9'){
            int temp[buffer],tempcount=0,number=0,sign=1;
            for(i;(expression[i]>='0'&&expression[i]<='9')&&(i>=0);i--){
                temp[tempcount++]=expression[i]-48;
            }
            if(expression[i]=='-'){
                sign=-1;
                i--;
            }
            for(int j=tempcount-1;j>=0;j--){
                number=number*10+temp[j];
            }
            printf("%d\n",number);
            operand_push(number*sign);
        }
        else{
            int op2=operand_pop(),op1=operand_pop();
            switch(expression[i]){
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
            }
            i--;
        }    
    }
    return operand_pop();
}
int postfix_evaluation(char expression[]){
    operand_count=-1,operator_count=-1;
    for(int i=0;i<strlen(expression)-1;i++){
        if((expression[i]>='0'&&expression[i]<='9')||((expression[i]<='-'&&i+1<=strlen(expression)-2)&&(expression[i+1]>='0'&&expression[i+1]<='9'))){
            int temp[buffer],tempcount=0,number=0,sign=1;
            if(expression[i]<='-'){
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
        }
        else{
            int op2=operand_pop(),op1=operand_pop();
            switch(expression[i]){
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
            }
            i++;
        }    
    }
    return operand_pop();
}
void parse(char expression[]){  
    for(int i=0;i<strlen(expression)-1;i++){
        if((expression[i]>='0'&&expression[i]<='9')||((expression[i]<='-'&&i+1<=strlen(expression)-2)&&(expression[i+1]>='0'&&expression[i+1]<='9'))){
            int temp[buffer],tempcount=0,number=0,sign=1;
            if(expression[i]<='-'){
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
        }
        else{
            operator_push(expression[i]);
            i++;
        } 
    }
}
int main(){
    char expression[buffer];
    printf("Please enter the expression needed to be evaluated:\n");
    restart:
    fgets(expression,buffer,stdin); 
    parse(expression);
    if((operand_count-operator_count)==1){
        if (expression[strlen(expression)-2]=='+'||expression[strlen(expression)-2]=='-'||expression[strlen(expression)-2]=='*'||expression[strlen(expression)-2]=='/'||expression[strlen(expression)-2]=='%'){
            printf("The expression is Postfix\n");
            printf("The result of expression: %d",postfix_evaluation(expression)); 
        }
        else if(expression[0]=='+'||(expression[0]=='-'&&(!((1<=strlen(expression)-2)&&(expression[1]>='0'&&expression[1]<='9'))))||expression[0]=='*'||expression[0]=='/'||expression[0]=='%'){
            printf("The expression is Prefix\n");
            printf("The result of expression: %d",prefix_evaluation(expression));
        }
        else{
            printf("The expression is Infix\n");
            printf("The result of expression: %d",infix_evaluation(expression));
        }
    }
    else{
        printf("Invaild Expression\nEnter a valid expression:\n");
        goto restart;
    }
}