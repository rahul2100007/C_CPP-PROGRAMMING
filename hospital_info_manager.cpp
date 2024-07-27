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
        int num_data;
        cout << "Enter how many items you want to add: ";
        cin >> num_data;
        cout << "Enter the details of hospital: \n";
        cout << "=ID\tNAME\tDEPARTMENT\tYEAR\tSEMESTER\tFEES=" << endl;
        node *temp1 = nullptr;
        for (int i = 0; i < num_data; i++)
        {
            struct node *temp = new node;
            cin >> temp->hosp.Hid >> temp->hosp.Hname >> temp->hosp.year >> temp->hosp.sem >> temp->hosp.fees;
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
        cout << temp->hosp.Hid << temp->hosp.Hname << temp->hosp.year << temp->hosp.sem << temp->hosp.fees;
    }
}
node *updateinfo(node *head)
{
    int id;
    cout << "enter id for update record : ";
    cin >> id;
    node *ptr = nullptr;
    node *ptr = head;
    node *newdata = new node;
    while (ptr != nullptr && ptr->hosp.Hid != id)
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
        cin >> newdata->hosp.Hid >> newdata->hosp.Hname >> newdata->hosp.year >> newdata->hosp.sem >> newdata->hosp.fees;
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
    node *ptr = head;
    node *newdata = new node;
    while (ptr != nullptr && ptr->hosp.Hname != name)
    {
        ptr = ptr->next;
    }
    if (!ptr)
    {
        cout << "Record not found!" << endl;
        return head;
    }
    elseif(ptr->hosp.Hname == name)
    {
        cout << "Enter new information:" << endl;
        cout << "=ID\tNAME\tDEPARTMENT\tYEAR\tSEMESTER\tFEES=" << endl;
        cin >> newdata->hosp.Hid >> newdata->hosp.Hname >> newdata->hosp.year >> newdata->hosp.sem >> newdata->hosp.fees;
        ptr = newdata;
        head = ptr;
    }
    return head;
}
int main()
{
    struct node *head = NULL;
    int choice;
    cout<<"enter your choice:";
    cout<<"1 for create\n2 for update by id\n3 for update by name\n4 for display";cin>>choice;
    switch (choice)
    {
    case 1:
        head = create(head);
        break;
    case 2:
        head = updateinfo(head);
        break;
    case 3:
        head= updatename(head);
        break;
    case 4:
    display(head);
        break;
    }
return 0;
}
