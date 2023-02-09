#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_EXPR_LEN 100

char stack[MAX_EXPR_LEN];
int top = -1;

void push(char item)
{
    stack[++top] = item;
}

char pop()
{
    return stack[top--];
}

int get_precedence(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return 0;
}

int is_operator(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return 1;
    }
    return 0;
}

char *infix_to_postfix(char *infix)
{
    int i, j;
    char item;
    char *postfix = (char *)malloc(MAX_EXPR_LEN);
    memset(postfix, 0, MAX_EXPR_LEN);
    for (i = 0, j = 0; i < strlen(infix); i++)
    {
        item = infix[i];
        if (isdigit(item))
            postfix[j++] = item;
        else if (item == '(')
            push(item);
        else if (is_operator(item))
        {
            while (top != -1 && stack[top] != '(' && get_precedence(stack[top]) >= get_precedence(item))
                postfix[j++] = pop();
            push(item);
        }
        else if (item == ')')
        {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[MAX_EXPR_LEN];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    char *postfix = infix_to_postfix(infix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
