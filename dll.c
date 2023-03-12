#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dll
{
    char fid[10],name[10],branch[10],aos[10];
    struct dll *prev ,*nxt;
};

struct dll *top = NULL,*end=NULL;

void create_dll()
{

    struct dll *temp;
    temp = (struct dll *)malloc(sizeof(struct dll));
    temp->prev=NULL;
    temp->nxt=NULL;
    printf("\nEnter the Facaulty \nID: ");
    scanf("%s",temp->fid);
    printf("\nName: ");
    scanf("%s",temp->name);
    printf("\nBranch: ");
    scanf("%s",temp->branch);
    printf("\nArea of Specialization: ");
    scanf("%s",temp->aos);

    if(top==NULL){
        top=temp;
        end=temp;
    }
    else{
        temp->nxt=top;
        top->prev=temp;
        top=temp;
    }
}


void pop_dll()
{
    struct dll *temp;
    temp=top;
    if (top == NULL)
        printf("Stack is empty");

    else if( top==end)
    {
        printf("Popped data is %s", temp->fid);
        top=NULL;
        end=NULL;
        free(temp);   
    }
    else{
        printf("Popped data is %s", temp->fid);
        top=top->nxt;
        top->prev=NULL;
        free(temp);

    }
}

void display_dll()
{
    struct dll *temp;
    temp=top;
    int count=0;
    if (top == NULL)
        printf("Stack is empty");

    else
    {
        printf("\nFaculty Details:\n ");
        printf("\nFaculty ID\tName\tBranch\tArea of Specialization\n");
        while (temp != NULL)
        {
            count++;
            printf("%s\t%s\t%s\t%s\t", temp->fid,temp->name,temp->branch,temp->aos);
            temp = temp->nxt;
        }
        printf("\nFaculty Count is %d",count);
    }
}

int main()
{
    int choice;
    printf("********** Doubly Linked List using stack **********");
    printf("\n1. Create DLL\n2. POP\n3. Display DLL\n4. Exit\n");
    while (1)
    {
        printf("\nEnter the Option:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create_dll();
            break;
        case 2:
            pop_dll();
            break;
        case 3:
            display_dll();
            break;
        case 4:
            return 0;
        }
    }
}

