#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define buffer 1000
char operator_stack[buffer];
int operand_count=-1,operator_count=-1,base_case_operand_count=0;
void operator_push(char data){ operator_stack[++operator_count]=data;}
char operator_pop(){if(operator_count==-1) return '\0'; return operator_stack[operator_count--];}
char operator_peek(){if(operator_count==-1) return '\0'; return operator_stack[operator_count];}
void infix_evaluation(char expression[]){
    operand_count=-1,operator_count=-1; char exp[buffer],expcount=0;
    for(int i=0;i<=strlen(expression)-2;i++){
        char new_expression[buffer];
        if((expression[i]>='0'&&expression[i]<='9')||((expression[i]=='-'&&i+1<=strlen(expression)-2)&&(expression[i+1]>='0'&&expression[i+1]<='9'))){
            if(expression[i]=='-'){
                exp[expcount++]='-';
                i++;
            }
            for(i;(expression[i]>='0'&&expression[i]<='9')&&(i<=strlen(expression)-2);i++){
                exp[expcount++]=expression[i];   
            }
            exp[expcount++]=' ';
            base_case_operand_count++;
        }
        else{
            if(operator_peek()=='\0'){
                operator_push(expression[i]);
                if(operator_peek()=='*'||operator_peek()=='/'||operator_peek()=='-'||operator_peek()=='+'){
                    base_case_operand_count--;
                }
            }
            else if(expression[i]=='*'||expression[i]=='/'){
                base_case_operand_count--;
                if(operator_peek()=='*'||operator_peek()=='/'){
                    exp[expcount++]=operator_pop();
                    exp[expcount++]=' ';
                    operator_push(expression[i]);  
                }
                else{
                    operator_push(expression[i]);
                }
            }
            else if(expression[i]=='-'||expression[i]=='+'){
                base_case_operand_count--;
                if(operator_peek()=='*'||operator_peek()=='/'||operator_peek()=='-'||operator_peek()=='+'){
                    exp[expcount++]=operator_pop();
                    exp[expcount++]=' ';
                    operator_push(expression[i]);  
                }
                else{
                    operator_push(expression[i]);   
                }
            }
            else if(expression[i]=='('||expression[i]==')'){
                if(expression[i]=='('){
                    operator_push(expression[i]);
                }
                else{
                    while(operator_peek()!='('){
                        exp[expcount++]=operator_pop();
                        exp[expcount++]=' ';
                    }
                    operator_pop();
                }
            }
            i++;
        }
        if(base_case_operand_count!=1&&base_case_operand_count!=0){
            printf("Invaild Expression");
            exit(1);
        }
    }
    while(operator_peek()!='\0'){
        exp[expcount++]=operator_pop();
        exp[expcount++]=' ';
    }
    exp[expcount++]=operator_pop();
    printf("The converted expression is :%s",(exp));
}
int main(){
    char expression[buffer];
    printf("Please enter the infix expression needed to be converted to postfix:\n");
    fgets(expression,buffer,stdin);
    infix_evaluation(expression);
    return 0;
}