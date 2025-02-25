// Write a program to calculate gcd of two numbers using recursion.
#include<stdio.h>
int gcd(int a,int b){
    if(a==0){
        return b;
    }
    return gcd(b%a,a);
}
int main(){
    int a,b;
    printf("Enter a 1st number: ");
    scanf("%d",&a);
    printf("Enter a 2nd number: ");
    scanf("%d",&b);
    printf("The greatest common divider is %d",gcd(a,b));
}