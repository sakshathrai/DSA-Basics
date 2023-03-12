#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int data;
struct qsll
{
    int rno, sem;
    char name[10];
    float cgpa;
    struct qsll *link;
};

struct qsll *front = NULL, *rear = NULL;
struct qsll *temp;
void create_qsll(int r, char n[10], int s, float c)
{
    temp = (struct qsll *)malloc(sizeof(struct qsll));
    temp->rno = r;
    strcpy(temp->name, n);
    temp->cgpa = c;
    temp->sem = s;
    temp->link = NULL;

    if (rear == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

void display_qsll()
{
    temp = front;
    while (temp != NULL)
    {
        printf("%d\n%s\n%d\n%f\n\n", temp->rno, temp->name, temp->sem, temp->cgpa);
        temp = temp->link;
    }
}

void linear_search(int key)
{
    temp = front;
    while (temp->rno != key)
    {
        temp = temp->link;
    }
    printf("Details of Roll No. %d\n", key);
    printf("%d\n%s\n%d\n%f\n\n", temp->rno, temp->name, temp->sem, temp->cgpa);
}
int main()
{
    int choice, key, rno, sem;
    float cgpa;
    char name[10];
    printf("********** Queue Linked List for Students List **********");
    printf("\n1. Create Sll Queue \n2. Display SLL Queue\n3. Linear Search a Roll No.\n4. Exit\n");
    while (1)
    {
        printf("\nEnter the Option:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the Roll No., Name, Semester, CGPA : ");
            scanf("%d %s %d %f", &rno, name, &sem, &cgpa);
            create_qsll(rno, name, sem, cgpa);
            break;
        case 2:
            display_qsll();
            break;
        case 3:
            printf("Enter the Roll no. to be searched: ");
            scanf("%d", &key);
            linear_search(key);
            break;
        case 4:
            return 0;
        }
    }
}
