#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_EXPR_LEN 100

int stack[MAX_EXPR_LEN];
int top = -1;

void push(int item)
{
    stack[++top] = item;
}

int pop()
{
    return stack[top--];
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

int perform_operation(int operand1, int operand2, char operator)
{
    switch (operator)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    case '^':
        return operand1 ^ operand2;
    }
    return 0;
}

int evaluate_postfix(char *postfix)
{
    int i, operand1, operand2, result;
    char item;
    for (i = 0; i < strlen(postfix); i++)
    {
        item = postfix[i];
        if (isdigit(item))
            push(item - '0');
        else if (is_operator(item))
        {
            operand2 = pop();
            operand1 = pop();
            result = perform_operation(operand1, operand2, item);
            push(result);
        }
    }
    return pop();
}

int main()
{
    char postfix[MAX_EXPR_LEN];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    int result = evaluate_postfix(postfix);
    printf("Result: %d\n", result);
    return 0;
}
