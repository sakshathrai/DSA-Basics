#include<stdio.h>
#include<stdlib.h>
int a[20];
int choice,size,i=0,pos;
void create_array(){
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    scanf("%d",&a[i]);
}
void display_array(){
printf("\nThe array: ");
    for(i=0;i<size;i++)
    printf("%d\t",a[i]);
}
void insert(){
    int ele;
    printf("Enter the element: ");
    scanf("%d",&ele);
    printf("Enter the Position to insert %d: ",ele);
    scanf("%d",&pos);
    size++;
    for(i=size-1;i>=pos;i--)
    a[i]=a[i-1];
    a[pos-1]=ele;
    
}
void delete(){
    printf("Enter the Position to Delete: ");
    scanf("%d",&pos);
    for(i=pos-1;i<size;i++)
    a[i]=a[i+1];
    size--;
    
}

int main(){
    printf("********** Array Operation **********");
    printf("\n1. Create a array\n2. Display Array\n3. Insert Element\n4. Delete\n5. Exit\n");
    while(1){
        printf("\nEnter the Option:");
        scanf("%d",&choice);
        switch(choice){
            case 1: create_array();
                    break;
            case 2: display_array();
                    break;
            case 3: insert();
                    break;
            case 4: delete();
                    break;        
            case 5: return 0;
        }

    }
}
