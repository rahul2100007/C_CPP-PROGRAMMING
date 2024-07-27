#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
struct node
{
    int ID;
    char Name[20];
    int Qty;
    float price;
    float tprice;
    struct node *next1;
};
void create()
{
    struct node *data;
    struct node *temp;
    struct node *end;

    temp = (struct node *)malloc(sizeof(struct node));
    printf("id name qty price tprice:");
    scanf("%d %s %d %f %f ", &temp->ID, &temp->Name, &temp->Qty, &temp->price, &temp->tprice);
    if (data == NULL)
    {
        temp->next1 = NULL;
        data = temp;
        end = temp;
    }
    else
    {
        end->next1 = temp;
        end = temp;
        end->next1 = NULL
    }
}
int main()
{
    create();
    return 0;
}