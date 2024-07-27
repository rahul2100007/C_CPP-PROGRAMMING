#include <stdio.h>
#include <stdlib.h>

struct employee
{
    int id;
    char name[20];
    int age;
    int salary;
    struct employee *next;
    struct employee *prev;
};

struct employee *start = NULL, *end = NULL;

void create()
{
    struct employee *newnode = (struct employee *)malloc(sizeof(struct employee));
    printf("Enter ID, Name, Age, Salary: ");
    scanf("%d %s %d %d", &newnode->id, newnode->name, &newnode->age, &newnode->salary);
    newnode->next = NULL;
    newnode->prev = NULL;

    if (start == NULL)
    {
        start = newnode;
        end = newnode;
    }
    else
    {
        end->next = newnode;
        newnode->prev = end;
        end = newnode;
    }
}

void display()
{
    struct employee *disp = start;
    if (start == NULL)
    {
        printf("No employees to display.\n");
    }
    else
    {
        while (disp != NULL)
        {
            printf("ID: %d, Name: %s, Age: %d, Salary: %d\n", disp->id, disp->name, disp->age, disp->salary);
            disp = disp->next;
        }
    }
}

void dele()
{
    struct employee *current = start;
    while (current != NULL)
    {
        struct employee *temp = current;
        current = current->next;
        free(temp);
    }
    start = NULL;
    end = NULL;
}
void update()
{
    int empId;
    printf("Enter the ID of the employee to update: ");
    scanf("%d", &empId);

    struct employee *current = start;
    while (current != NULL)
    {
        if (current->id == empId)
        {
            printf("Enter the updated Name, Age, Salary: ");
            scanf("%s %d %d", current->name, &current->age, &current->salary);
            printf("Employee data updated successfully.\n");
            return;
        }
        current = current->next;
    }

    printf("Employee with ID %d not found.\n", empId);
}

int main()
{
    int choice;
    for (int i = 0; i < 4; i++)
    {
        printf("Enter your choice (1: Create, 2: Display, 3: Delete,4: Update, 4: Exit): ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            dele();
            break;
        case 4:
            update();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
