#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int Pid;
    char Pname[20];
    int Pqty;
    float Pprice;
    float Tprice;
    struct Node *next;
};

void print(struct Node *head)
{
    struct Node *ptr = head;
    printf("==============PRODUCT DATA===============\n");
    printf("PID\tPNAME\tPQUANTITY   PPrice   TPrice\n");
    while (ptr != NULL)
    {
        printf("%d\t%s\t%d\t%.2f\t%.2f\n", ptr->Pid, ptr->Pname, ptr->Pqty, ptr->Pprice, ptr->Tprice);
        ptr = ptr->next;
    }
}

struct Node *create(struct Node *head)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("=============ENTER PRODUCT DATA==============\n");
    printf("PID\tPNAME\tPQUANTITY\tPPrice:\n");
    scanf("%d %s %d %f", &temp->Pid, temp->Pname, &temp->Pqty, &temp->Pprice);
    temp->Tprice = temp->Pqty * temp->Pprice;

    head=temp;
    temp->next=NULL;
}
struct Node serch_record(struct Node *head)
{
    struct Node *ptr = head;
    int id;
    char name[20];
    int choice;
    printf("enter your choice search by id or search by name\n <1> for by id <2> for by name: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("enter id:");
        scanf("%d", &id);

        while (ptr->Pid != id)
        {
            ptr = ptr->next;
        }
        if (ptr->Pid != id)
        {
            printf("record not found:(");
        }
        printf("%d\t%s\t%d\t%.2f\t%.2f\n", ptr->Pid, ptr->Pname, ptr->Pqty, ptr->Pprice, ptr->Tprice);
        break;
    case 2:
        printf("enter name:");
        scanf("%s", name);

        while (strcmp(ptr->Pname, name) != 0)
        {
            ptr = ptr->next;
        }
        if (strcmp(ptr->Pname, name) != 0)
        {
            printf("record not found:(");
        }
        printf("%d\t%s\t%d\t%.2f\t%.2f\n", ptr->Pid, ptr->Pname, ptr->Pqty, ptr->Pprice, ptr->Tprice);
        break;
    }
}
struct Node *delete_data(struct Node *head)
{
    struct Node *ptr = head;
    struct Node *prev = NULL;
    int id;
    char name[20];
    int choice;
    printf("enter your choice delete by id or delete by name\n <1> for by id <2> for by name: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("enter id:");
        scanf("%d", &id);

        while (ptr != NULL)
        {
            if (ptr->Pid == id)
            {
                if (prev == NULL)
                {
                    head = ptr->next;
                }
                else
                {
                    prev->next = ptr->next;
                }
                free(ptr);
                printf("Record deleted successfully.\n");
                return head;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        printf("Record not found.\n");
        break;
    case 2:
        printf("enter name:");
        scanf("%s", name);

        while (ptr != NULL)
        {
            if (strcmp(ptr->Pname, name) == 0)
            {
                if (prev == NULL)
                {
                    head = ptr->next;
                }
                else
                {
                    prev->next = ptr->next;
                }
                printf("\nRecord deleted successfully.\n");
                return head;
            }
            prev = ptr;
            ptr = ptr->next;
        }
        printf("Record not found.\n");
        break;
    default:
        printf("Invalid choice.\n");
    }
    return head;
}
struct Node *add_data(struct Node *head)
{
    struct Node *temp = head;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    printf("=============ENTER PRODUCT DATA==============\n");
    printf("PID\tPNAME\tPQUANTITY\tPPrice\n");
    scanf("%d %s %d %f", &newnode->Pid, newnode->Pname, &newnode->Pqty, &newnode->Pprice);
    newnode->Tprice = newnode->Pqty * newnode->Pprice;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    return head;
}

int main()
{
    
    struct Node *head = NULL;
    head = create(head);
    do
    {
        int choice;
        printf("Enter choice: 1 for display, 2 for add data, 3 for search record,4 for delete record, 0 for exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            print(head);
            break;
        case 2:
            head = add_data(head);
            break;
        case 3:
            serch_record(head);
            break;
        case 4:
            delete_data(head);
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}
