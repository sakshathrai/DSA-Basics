#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *root = NULL;

void insert(int d)
{
    struct node *t, *p, *parent;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    p = root;
    if (root == NULL)
    {
        root = t;
    }
    else
    {
        struct node *curr;
        curr = root;
        while (curr)
        {
            parent = curr;
            if (curr->data < t->data)
                curr = curr->right;
            else
                curr = curr->left;
        }
        if (t->data > parent->data)
            parent->right = t;
        else
            parent->left = t;
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

int main()
{
    int data, choice, i, n;
    printf("********** Binary Search Tree **********");
    printf("\n1. Insert\n2.Inorder\n3. Preorder\n4. Postorder\n5. Exit\n");
    while (1)
    {
        printf("\nEnter the Option:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the no. of data to insert: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("Enter the data value: ");
                scanf("%d", &data);
                insert(data);
            }
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            return 0;
            break;
        default:
            printf("\nInvalid option\n");
            break;
        }
    }
}
