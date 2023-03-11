#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int data;
struct sll
{
    int data;
    struct sll *link;
};

struct sll *top = NULL;
void create_sll(int data)
{
    struct sll *temp;
    temp = (struct sll *)malloc(sizeof(struct sll));
    temp->data = data;
    temp->link = top;
    top = temp;
}

void pop_sll()
{
    struct sll *temp;
    if (top == NULL)
        printf("Stack is empty");

    else
    {
        temp = top;
        printf("Popped data is %d", temp->data);
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

void display_sll()
{
    struct sll *temp;
    if (top == NULL)
        printf("Stack is empty");

    else
    {
        temp = top;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
    }
}

int main()
{
    int choice;
    printf("********** Singly Linked List using stack **********");
    printf("\n1. Create SLL\n2. POP\n3. Display SLL\n4. Exit\n");
    while (1)
    {
        printf("\nEnter the Option:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter integer data: ");
            scanf("%d", &data);
            create_sll(data);
            break;
        case 2:
            pop_sll();
            break;
        case 3:
            display_sll();
            break;
        case 4:
            return 0;
        }
    }
}