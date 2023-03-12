#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size, ht[20], i, j;
    printf("Enter the size of HashTable: ");
    scanf("%d", &size);
    printf("\nInitializing the HashTable: ");
    for (i = 0; i < size; i++)
        ht[i] = -1;
    int flag = 1;
    while (flag)
    {
        int data;
        printf("\nEnter the data to be entered: ");
        scanf("%d", &data);
        int key = data % size;
        if (ht[key] == -1)
        {
            ht[key] = data;
            printf("\nThe data has been entered");
        }
        else
        {
            printf("\nCollision has been occured");
            for (i = key; i < size; i++)
            {
                if (ht[i] == -1)
                {
                    ht[i] = data;
                    printf("\nThe Collision has been solved using linear probing technique");
                    printf("\nThe data has been entered");
                    break;
                }
            }
            if (i == size)
            {
                for (j = 0; j < i; j++)
                {
                    if (ht[j] == -1)
                    {
                        ht[j] = data;
                        printf("\nThe Collision has been solved using linear probing technique");
                        printf("\nThe data has been entered");
                        break;
                    }
                }
                if (j == i)
                    printf("\nFuture data cannot be entered\n");
            }
        }
        printf("\n\nenter 1 to continue 0 to end: ");
        scanf("%d", &flag);
    }
    printf("\nThe Filtered HashTable:\n");
    for (i = 0; i < size; i++)
    {
        if (ht[i] == -1)
            continue;
        else
            printf("[%d] %d\n", i, ht[i]);
    }
    printf("\nThe UnFiltered HashTable:\n");
    for (i = 0; i < size; i++)
        printf("[%d] %d\n", i, ht[i]);
}