#include<stdio.h>
#include<stdlib.h>

void linklist(int);
void printLinkList();
void insertAtBegining();
void insertAtEnd();
void insertAtlocation();
void reverseLinklist();
//void printLinkListUsingRecursion(int *);
void delete();

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node *head,*temp,*ptr;

int main()
{
    head = NULL;
    
    while(1)
    {
        printf("Enter 1 for Insert element in begining of linklist\n");
        printf("Enter 2 for Insert element in end of linklist\n");
        printf("Enter 3 for Insert element at particular location\n");
        printf("Enter 4 Delete element from linklist\n");
        printf("Enter 5 for print all the elements in Linklist\n");
        printf("Enter 6 for reverse the linklist\n");
        printf("Enter 7 for print the linklist using recusion\n");
        printf("Enter 8 for reverse the linklist using recursion\n");
        printf("Enter 9 for exit\n");
        int option;
        scanf("%d",&option);
        linklist(option);
    }
    
    
    return 0;
}

void linklist(int option)
{
    switch(option)
    {
            
            
        case 1:
            
            insertAtBegining();
            break;
            
        case 2:
            
            insertAtEnd();
            break;
            
        case 3:
            insertAtlocation();
            
            
            break;
            
        case 4:
            delete();
            break;
            
        case 5:
            printLinkList();
            break;
            
        case 6:
            reverseLinklist();
            break;
          
        case 7:
         //   printLinkListUsingRecursion(head);
            
            
            break;
        case 8:
            //   printLinkListUsingRecursion(head);
            
            
            break;

            
        case 9:
            exit(1);
            break;
            
        default:
            printf("Invalid Option\n");
            break;
            
            
    }
    
    
}

void insertAtBegining()
{
    printf("Enter the Number");
    int variable;
    scanf("%d",&variable);
    temp = (Node *)malloc(sizeof(Node));
    if(temp)
    {
        temp->data = variable;
        temp->next = head;
        head = temp;
        
        
    }
    else
    {
        printf("Memory Allocation failure");
        
    }
    printf("List is\n");
    printLinkList();

}

void insertAtEnd()
{
    ptr = NULL;
    ptr = head;
    printf("Enter the Number");
    int variable;
    scanf("%d",&variable);
    temp = NULL;
    temp = (Node *)malloc(sizeof(Node));
    
    if(temp)
    {
        temp->data = variable;
        temp->next = NULL;
        
        if(ptr == NULL)
        {
            ptr = temp;
        }
        else
        {
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
        printf("List is:\n");
        printLinkList();
    }
    
}

void insertAtlocation()
{
    printf("List is:\n");
    printLinkList();
    int location,count = 0;
    printf("Enter the location");
    scanf("%d",&location);
    int number;
    printf("Enter the number\n");
    scanf("%d",&number);
    temp = NULL;
    temp = (Node *)malloc(sizeof(Node));
    if(temp)
    {
        temp->data = number;
        ptr = NULL;
        ptr = head;
        if(ptr == NULL)
        {
            printf("List is empty");
        }
        else
        {
            while (ptr != NULL)
            {
                ptr = ptr->next;
                count++;
                
            }
            
            if(location <= count+1 && location > 0)
            {
                ptr = NULL;
                ptr = head;
                
                int var = 0;
                while (var < location)
                {
                    
                    ptr = ptr->next;
                    var++;
                }
                temp->next = ptr;
                var = 0;
                ptr = NULL;
                ptr = head;
                while (var < location-1)
                {
                    
                    ptr = ptr->next;
                    var++;
                }
                ptr->next = temp;
                
                printf("list is:\n");
                printLinkList();
                
            }
            else
            {
                printf("Invalid Location");
            }
            
        }

    }
    else
    {
        printf("Memory allocation failed");
    }
    
    
}

void delete()
{
    printf("List is:\n");
    printLinkList();
    
    int location;
    printf("Enter the location\n");
    scanf("%d",&location);
    
    if(location == 0)
    {
        printf("Error location");
    }
    else
    {
        ptr = NULL;
        ptr = head;
        int count = 0;
        if(ptr == NULL)
        {
            printf("List is empty\n");
        }
        else
        {
            while (ptr != NULL)
            {
                ptr = ptr->next;
                count++;
                
            }
            if(location <= count && location > 0)
            {
                ptr = NULL;
                ptr = head;
                
                int var = 1;
                
                while (var < location)
                {
                    ptr = ptr->next;
                    var++;
                }
                
                var = 1;
               Node  *ptr2 = NULL;
                ptr2 = head;
                while (var < location-1)
                {
                    ptr2 = ptr2->next;
                    var++;
                }
                
                ptr2->next = ptr->next;
            }
            else
            {
                printf("Error in location\n");
            }
            
        }

    }
    
}

void reverseLinklist()
{
    ptr = NULL;
    ptr = head;
    Node *next,*prev;
    prev = NULL;
    if(ptr == NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while (ptr != NULL)
        {
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
            
        }
        head = prev;
    }
    
    
}

void printLinkListUsingRecursion(Node *ptr)
{
    if(ptr == NULL) return;
    
    printf("%d",ptr->data);
    printLinkListUsingRecursion(ptr->next);
}

void printReverseLinkListUsingRecursion(Node *ptr)
{
    if(ptr == NULL) return;
    printReverseLinkListUsingRecursion(ptr->next);
    printf("%d",ptr->data);
}

void reverseLinkListUsingRecusrion(Node *ptr)
{
    if(ptr->next == NULL)
    {
        head = ptr;
        return;
    }
    reverseLinkListUsingRecusrion(ptr->next);
}

void printLinkList()
{
    ptr = NULL;
    ptr = head;
    if(ptr == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d\t\n",ptr->data);
            ptr = ptr->next;
            
        }
    }
    
}
