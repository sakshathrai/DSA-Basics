#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int stack[10], top = -1, i = 0;
char exp1[10];
float res;

void push(int val)
{
    top++;
    stack[top] = val;
}

int pop()
{
    int val1 = stack[top];
    top--;
    return val1;
}

float compute(float op1, float op2, char symbol)
{
    float res = 0.0;
    switch (symbol)
    {
    case '+':
        res = (op1 - 48) + (op2 - 48);
        break;

    case '-':
        res = (op1 - 48) - (op2 - 48);
        break;

    case '*':
        res = (op1 - 48) * (op2 - 48);
        break;

    case '/':
        res = (op1 - 48) / (op2 - 48);
        break;
    }
    return res + 48;
}

int main()
{
    printf("Enter the expression in Infix: ");
    scanf("%s", exp1);
    while (exp1[i] != '\0')
    {
        if (isdigit(exp1[i]))
            push(exp1[i]);
        else
        {
            float op2 = pop();
            float op1 = pop();
            char symbol = exp1[i];
            res = compute(op1, op2, symbol);
            push(res);
        }
        i++;
    }
    printf("Result is %f\n", res - 48);
    return 0;
}
