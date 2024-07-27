#include <iostream>
#include <string>
using namespace std;
struct node
{
    string Hname, dept;
    int Hid, year, sem;
    float fees;
    struct node *next;
    struct node *prev;
} hosp;
node *create(node *head)
{
    {
        int num = 3;
        cout << "Enter the details of hospital: \n";
        cout << "=ID\tNAME\tDEPARTMENT\tYEAR\tSEMESTER\tFEES=" << endl;
        node *temp1 = nullptr;
        while (num != 0)
        {
            struct node *temp = new node;
            cin >> temp->Hid >> temp->Hname >> temp->dept >> temp->year >> temp->sem >> temp->fees;
            temp->prev = NULL;
            temp->next = NULL;
            if (head == NULL)
            {
                head = temp;
                temp1 = head;
            }
            else
            {
                while (temp1->next != NULL)
                {
                    temp1 = temp1->next;
                }
                temp1->next = temp;
                temp->prev = temp1;
            }
            num--;
        }
        return head;
    }
}
void display(node *head)
{
    node *ptr = head;
    cout << "==============OUTPUT OF HOSPITAL INFORMATION==============";
    cout << "=ID\tNAME\tDEPARTMENT\tYEAR\tSEMESTER\tFEES=" << endl;
    while (ptr != NULL)
    {
        cout << ptr->Hid << ptr->Hname << ptr->dept << ptr->year << ptr->sem << ptr->fees << "\n";
        ptr = ptr->next;
    }
}
node *updateinfo(node *head)
{
    int id;
    cout << "enter id for update record : ";
    cin >> id;
    node *ptr = nullptr;
    ptr = head;
    node *newdata = new node;
    while (ptr != nullptr && ptr->Hid != id)
    {
        ptr = ptr->next;
    }
    if (!ptr)
    {
        cout << "Record not found!" << endl;
        return head;
    }
    else
    {
        cout << "Enter new information:" << endl;
        cout << "=ID\tNAME\tDEPARTMENT\tYEAR\tSEMESTER\tFEES=" << endl;
        cin >> newdata->Hid >> newdata->Hname >> newdata->dept >> newdata->year >> newdata->sem >> newdata->fees;
        ptr = newdata;
        head = ptr;
    }
    return head;
}
node *updatename(node *head)
{
    string name;
    cout << "enter id for update record : ";
    cin >> name;
    node *ptr = nullptr;
    ptr = head;
    node *newdata = new node;
    while (ptr != nullptr && ptr->Hname != name)
    {
        ptr = ptr->next;
    }
    if (!ptr)
    {
        cout << "Record not found!" << endl;
        return head;
    }
    else
    {
        cout << "Enter new information:" << endl;
        cout << "=ID\tNAME\tDEPARTMENT\tYEAR\tSEMESTER\tFEES=" << endl;
        cin >> newdata->Hid >> newdata->Hname >> newdata->dept >> newdata->year >> newdata->sem >> newdata->fees;
        ptr = newdata;
        head = ptr;
    }
    return head;
}
int main()
{
    struct node *head = NULL;
    head = create(head);
    int choice;
    cout << "enter your choice:";
    cout << "1 for update by id\n2 for update by name\n3 for display";
    cin >> choice;
    head = updateinfo(head);
    // head= updatename(head);
    display(head);
    return 0;
}
