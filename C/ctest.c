#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define max 100
char stack[max];int top = -1;
void push(char item){
    stack[++top] = item;
}
char pop(){
    return stack[top--];
}
int getPrecedence(char symbol){
    switch(symbol){
        case '+' :
        case '-' :
        return 1;
        case '*' :
        case '/' :
        return 2;
        case '^' :
        return 3;
    }
    return 0;
}
int isOperator(char symbol){
    switch(symbol){
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        return 1;
    }
    return 0;
}
char *infixToPrefix(char *infix){
   int i ,j;
   char item;
   char *postfix = (char *)malloc(max);
   memset(postfix,0,max);
   for(i = 0,j =0;i<strlen(infix);i++){
        item = infix[i];
        if(isdigit(item)){
            postfix[j++] = item;
        }
        else if(item == '('){
            push(item);
        }
        else if(isOperator(item)){
            while(top != -1 && stack[top]!= ')' && getPrecedence(stack[top]) >= getPrecedence(item))
                postfix[j++] = pop();
            push(item);    
        }
        else if(item == ')'){
            while(stack[top]!= '(')
                postfix[j++] = pop();    
            pop();
        }
   }
   while(top != -1){
        postfix[j++] = pop();
   }
   postfix[j] = '\0';
   return postfix;
}
int main(){
    char infix[max];
    printf("enter an infix expression ");
    scanf("%s",infix);
    char *postfix = infixToPrefix(infix);
    printf("postfix expression : %s \n",postfix);
    return 0;
}