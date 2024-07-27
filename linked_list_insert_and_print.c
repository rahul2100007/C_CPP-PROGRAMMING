#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *next;
};
int insertvalue(struct node *first, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data; 
    ptr->next = first;
    return ptr;
}
void print(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    typedef struct node rahul;
    rahul *first,*second,*third;
    first = (rahul *)malloc(sizeof(struct node));
    second = (rahul *)malloc(sizeof(struct node));
    third = (rahul *)malloc(sizeof(struct node));

    third->data = 30;
    third->next = NULL;
    second->data = 40;
    second->next = third;
    first->data = 10;
    first->next = second;
    print(first);
    first = insertvalue(first, 321);
    first = insertvalue(first, 391);
    print(first);
    return 0;
}