#include <stdio.h>
#define MAX_SIZE 100

void insertElement(int arr[], int size);
void deleteElement(int arr[], int size);

int main()
{
    int arr[MAX_SIZE];
    int size, choice, i;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insertElement(arr, size);
                size++;
                break;
            case 2:
                deleteElement(arr, size);
                size--;
                break;
            case 3:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice!");
        }
    } while(choice != 3);

    return 0;
}

void insertElement(int arr[], int size)
{
    int position, element, i;

    printf("Enter the position where you want to insert the element: ");
    scanf("%d", &position);

    printf("Enter the element to be inserted: ");
    scanf("%d", &element);

    // Shift the elements to the right to make space for the new element
    for(i=size-1; i>=position-1; i--)
    {
        arr[i+1] = arr[i];
    }

    arr[position-1] = element;

    printf("Array after insertion: ");
    for(i=0; i<=size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void deleteElement(int arr[], int size)
{
    int position, i;

    printf("Enter the position of the element to be deleted: ");
    scanf("%d", &position);

    // Shift the elements to the left to fill the gap left by the deleted element
    for(i=position-1; i<size-1; i++)
    {
        arr[i] = arr[i+1];
    }

    printf("Array after deletion: ");
    for(i=0; i<size-1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
