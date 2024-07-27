#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int college_ID;
    char College_name[50];
    char course_stream[40];
    int Year;
    int sem;
    char subject_group[25];
    double fee_struct;
    struct Node *prev;
    struct Node *next;
    
};
void print(struct Node *head) {
    struct Node *ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    printf("=============OUTPUT OF STUDENT DATA==============\n");
     printf("college_ID\tCollege_name\tCourse_stream\tYear\tSemester\tsubject_group\t\tfee_struct\n");
    while (ptr != NULL) {
        printf("%d\t\t %s\t\t %s\t\t %d\t\t %d\t\t %s\t\t %lf\n", ptr->college_ID, ptr->College_name, ptr->course_stream,ptr->Year,ptr->sem, ptr->subject_group, ptr->fee_struct);
        ptr = ptr->prev;
    }
}
struct Node *create(struct Node *head)
{
    int num_stu;
    printf("Enter how many data you want to add: ");
    scanf("%d", &num_stu);
    struct Node *temp = head;
    printf("=============ENTER DATA==============\n");
    printf("college_ID\tCollege_name\tCourse_stream\t\tYear\tSemester\tsubject_group\tfee_struct\n");
    for (int i = 0; i < num_stu; i++)
    {
        struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            exit(0);
        }
        printf("Enter college data %d:\n", i + 1);
        scanf("%d %s %s %d %d %s %lf", &newnode->college_ID, newnode->College_name,newnode->course_stream, &newnode->Year, &newnode->sem, newnode->subject_group, &newnode->fee_struct);

        newnode->prev = NULL;
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
            newnode->prev = temp;
        }
        temp = head;
    }
    return head;
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

        while (ptr->college_ID != id)
        {
            ptr = ptr->next;
        }
        if (ptr->college_ID != id)
        {
            printf("record not found:(");
        }
        printf("%d %s %s %d %d %s %lf\n", ptr->college_ID, ptr->College_name, ptr->course_stream,ptr->Year,ptr->sem, ptr->subject_group, ptr->fee_struct);
        break;
    case 2:
        printf("enter name:");
        scanf("%s", name);

        while (strcmp(ptr->College_name, name) != 0)
        {
            ptr = ptr->next;
        }
        if (strcmp(ptr->College_name, name) != 0)
        {
            printf("record not found:(");
        }
        printf("%d %s %s %d %d %s %lf\n", ptr->college_ID, ptr->College_name, ptr->course_stream,ptr->Year,ptr->sem, ptr->subject_group, ptr->fee_struct);
        break;
    }
}
int main()
{
    int choice;
    struct Node *head = NULL;
    head = create(head);
    do
    {
        printf("Enter choice: 1 for display, 2 for add data, 3 for search record, 0 for exit: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            print(head);
            break;
        case 2:
            head = create(head);
            break;
        case 3:
            serch_record(head);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice != 0);
    free(head);

    return 0;
}
