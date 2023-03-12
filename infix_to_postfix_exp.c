#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 10

float stack[STACK_SIZE];
int top = -1;
int i = 0;
char exp1[10];

void push(float val)
{
    if (top < STACK_SIZE - 1)
    {
        top++;
        stack[top] = val;
    }
    else
    {
        printf("Error: Stack overflow\n");
        exit(1);
    }
}

float pop()
{
    if (top >= 0)
    {
        float val1 = stack[top];
        top--;
        return val1;
    }
    else
    {
        printf("Error: Stack underflow\n");
        exit(1);
    }
}

float compute(float op1, float op2, char symbol)
{
    float res = 0.0;
    switch (symbol)
    {
    case '+':
        res = op1 + op2;
        break;
    case '-':
        res = op1 - op2;
        break;
    case '*':
        res = op1 * op2;
        break;
    case '/':
        if (op2 == 0)
        {
            printf("Error: Division by zero\n");
            exit(1);
        }
        res = op1 / op2;
        break;
    default:
        printf("Error: Invalid operator\n");
        exit(1);
    }
    return res;
}

int main()
{
    printf("Enter the expression in Postfix: ");
    scanf("%s", exp1);
    while (exp1[i] != '\0')
    {
        if (isalnum(exp1[i]))
        {
            float val = exp1[i] - '0';
            push(val);
        }
        else
        {
            float op2 = pop();
            float op1 = pop();
            char symbol = exp1[i];
            float res = compute(op1, op2, symbol);
            push(res);
        }
        i++;
    }
    printf("Result is %f\n", pop());
    return 0;
}
