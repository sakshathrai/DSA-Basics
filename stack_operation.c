#include <stdio.h>
#define SIZE 5
int stack[SIZE], top = -1, i, ele, ch;
void push(int ele)
{
    if (top == SIZE - 1)
        printf("Stack Overflow");
    else
    {
        top++;
        stack[top] = ele;
    }
}

void pop()
{
    if (top == -1)
        printf("Stack Underflow");
    else
    {
        printf("Popped element is %d", stack[top]);
        top--;
    }
}

void display()
{
    if (top == -1)
        printf("Stack Underflow");
    else
    {
        printf("The elements of the stacks are:");
        for (i = top; i >= 0; i--)
        {
            printf("%d\t", stack[i]);
        }
    }
}

int main()
{printf("********** Stack Operation **********");
    printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
    while (1)
    {
        printf("Select the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the Element to push: ");
            scanf("%d", &ele);
            push(ele);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Enter a valid choice");
        }
    }
}
