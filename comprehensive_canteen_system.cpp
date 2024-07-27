#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Canteen
{
public:
    friend last_chars(Canteen obj);
    friend void firstlast(Canteen obj);

    struct Node
    {
        int Pid;
        string Pname;
        int Pqty;
        float Pprice;
        float Tprice;

        Node *next;
    };
    Canteen(Node *head) // parameteraized contructor
    {
        struct Node *ptr = head;
        cout << "===================================WELCOME TO GANPAT UNIVERSITY ===================================\n ";
        cout << "===========================================CANTEEN MENU===========================================\n ";
        cout
            << "PRODUCT_ID"
            << "\t"
            << "PRODUCT_NAME"
            << "\t\t"
            << "PRICE\n"
            << endl;
        while (ptr != NULL)
        {
            cout << ptr->Pid << "\t" << ptr->Pname << "\t\t" << ptr->Pprice << endl;
            ptr = ptr->next;
        }
    }
    Canteen() // default constructor
    {
        string uname = "admin", pass_wd = "admin";
        string username, passwd;
        cout << "USERNAME:";
        cin >> username;
        fflush(stdin);
        cout << "PASSWORD:";
        cin >> passwd;
        fflush(stdin);
    }
    Node *create(Node *head)
    {
        int num_data;

        cout << "Enter how many items you want to add: ";
        cin >> num_data;
        cout << "=============ENTER PRODUCT DATA==============\n";
        cout << "PRODUCT_ID"
             << "\t"
             << "PRODUCT_NAME"
             << "\t\t"
             << "PRICE" << endl;
        Node *temp = nullptr;
        for (int i = 0; i < num_data; i++)
        {
            Node *newnode = new Node;
            cin >> newnode->Pid >> newnode->Pname >> newnode->Pprice;
            newnode->next = NULL;
            if (head == NULL)
            {
                head = newnode;
                temp = head;
            }
            else
            {
                Node *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
        }
        return head;
    }
    Canteen(Canteen &obj, struct Node *head) // copy constructor
    {
        int item;
        struct Node *purchsd = NULL;
        struct Node *ptr = head;
        int num_data, qty;
        cout << "how many item you want to buy";
        cin >> num_data;
        bool found = false;
        for (int i = 0; i < num_data; i++)
        {
            struct Node *newnode = new struct Node;
            cout << "ENTER ID OF ITEM WHICH YOU WANT TO BUY:";
            cin >> item >> qty;
            while (ptr->Pid != item)
            {
                ptr = ptr->next;
            }
            if (ptr->Pid != item)
            {
                cout << "record not found:(";
            }
            if (ptr->Pid == item)
            {
                ptr->Tprice = ptr->Pprice * qty;
                found = true;
                if (found == true)
                {
                    if (purchsd == NULL)
                    {

                        purchsd = ptr;
                    }
                    else
                    {
                        while (ptr->next != NULL)
                        {
                            ptr = ptr->next;
                        }
                        ptr->next = newnode;
                    }
                    ptr = purchsd;
                }
            }
        }
        char choice;
        cout << "PRESS 'Y' or 'y' FOR PRINT BILL:";
        cin >> choice;
        if (choice == 'Y' || choice == 'y')
        {
            cout << "===================================-THANK YOU FOR USING THIS PROGRAM:)===================================\n";
            cout << "===========================================:YOUR BILL IS HERE:===========================================\n";

            cout << "PRODUCT_ID"
                 << "\t"
                 << "PRODUCT_NAME"
                 << "\t\t"
                 << "TOTAL_PRICE" << endl;
            struct Node *ptr = purchsd;
            while (ptr->Pid == item)
            {
                cout << ptr->Pid << "\t" << ptr->Pname << "\t\t" << ptr->Tprice <<

                    endl;

                ptr = ptr->next;
            }
            cout << "=========================================:KHAO OR KHILATE RAHO : =========================================\n ";
        }
    }
    Node *serch_record(struct Node *head)
    {
        struct Node *ptr = head;
        int id;
        string name;
        int choice;
        cout << "enter your choice search by id or search by name\n <1> for by id <2> for by name: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter id:";
            cin >> id;
            while (ptr->Pid != id)
            {
                ptr = ptr->next;
            }
            if (ptr->Pid != id)

            {
                cout << "record not found:(";
            }
            cout << ptr->Pid << "\t" << ptr->Pname << "\t\t" << ptr->Pprice;
            break;
        case 2:
            cout << "enter name:";
            cin >> name;
            while (name.compare(ptr->Pname) != 0)
            {
                if (name.compare(ptr->Pname) == 0)
                {
                    cout << "string  match found:" << endl;
                    cout << ptr->Pid << "\t" << ptr->Pname << "\t\t" << ptr->Pprice;
                }
                ptr = ptr->next;
            }
            if (ptr->Pname != name)
            {
                cout << "record not found:(";
            }

            break;
        }
    }
    Node *delete_data(struct Node *head)
    {
        struct Node *ptr = head;
        struct Node *prev = NULL;
        int id;
        char name[20];
        int choice;
        cout << "enter your choice delete by id or delete by name\n <1> for by id <2> for by name: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter id:";
            cin >> id;
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
                    delete ptr;
                    cout << "Record deleted successfully.\n";
                    return head;
                }
                prev = ptr;
                ptr = ptr->next;
            }
            cout << "Record not found.\n";
            break;
        case 2:
            cout << "enter name:";
            cin >> name;
            while (ptr != NULL)

            {
                if (ptr->Pname == name)
                {
                    if (prev == NULL)
                    {
                        head = ptr->next;
                    }
                    else
                    {
                        prev->next = ptr->next;
                    }
                    cout << "\nRecord deleted successfully.\n";
                    return head;
                }
                prev = ptr;
                ptr = ptr->next;
            }
            cout << "Record not found.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
        return head;
    }
    void print(struct Node *head)
    {
        // friend last_chars(Canteen obj);
        struct Node *ptr = head;
        string datahai, namehai;
        string mainbaat;
        cout << "===================================WELCOME TO GANPAT UNIVERSITY==================================\n ";
        cout << "===========================================CANTEEN MENU===========================================\n ";
        cout
            << "PRODUCT_ID"
            << "\t"
            << "PRODUCT_NAME"
            << "\t\t"
            << "PRICE";
        while (ptr != NULL)
        {
            // cout << ptr->Pid << "\t" << ptr->Pname << "\t\t" << ptr->Pprice << endl;
            mainbaat = to_string(ptr->Pid) + "\t" + ptr->Pname + "\t" + to_string(ptr->Pprice);
            datahai += mainbaat + "\n";
            namehai.append(ptr->Pname);
            namehai.append(" ");
            ptr = ptr->next;
        }

        cout << "This is string appended data:) \n"
             << datahai << endl;
        cout << "This is size of data:" << datahai.size() << "\t\n";
        cout << "This is extracted substring:\n" << namehai;
    }
    void sortNames(Node *head)
    {
        Node *current;
        bool swapped;

        do
        {
            swapped = false;
            current = head;

            while (current->next != nullptr)
            {

                if (current->Pname.compare(current->next->Pname) > 0)
                {
                    current->Pname.swap(current->next->Pname);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }
    void sortrev(Node *head){
        Node *current;
    bool swapped;

    do {
        swapped = false;
        current = head;

        while (current->next != nullptr) {
            if (current->Pname.compare(current->next->Pname) < 0) { // Change comparison to descending order
                current->Pname.swap(current->next->Pname);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
    }

    void printList(Node *head)
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            exit(0);
        }
        Node *current = head;
        cout << "PRODUCT_ID"
             << "\t"
             << "PRODUCT_NAME"
             << "\t\t"
             << "PRICE" << endl;

        while (current!=nullptr)
        {
            cout << current->Pid << "\t\t" << current->Pname << "\t\t" << current->Pprice << endl;
            current = current->next;
        }
    }
    last_chars(Node *head)
{
    struct Node *ptr=head;
    cout << "enter which string's last character you want to show and how many character:- \n";
    string word;
    int nums;
    cin >> word >> nums;
    while (ptr->Pname != word)
    {
        ptr = ptr->next;
    }
    if (ptr->Pname != word)
    {
        cout << "sorry bhai idhar nahi hai";
    }
    else if (ptr->Pname == word)
    {
        string las = word.substr(word.length() - nums, nums);
        cout << las;
    }
}
void firstlast(Node *head)
{
    struct Node *ptr=head;
    string hahahi;
    string temp;
    while (ptr->next != NULL)
    {
        string str1, str2;
        str1 = *(ptr->Pname.begin());
        str2 = *(ptr->Pname.end() - 1);
        hahahi = hahahi + str1 + " " + str2 + "\n";
        ptr = ptr->next;
    }
    cout << "\nfirst and last characters are:\n" + hahahi;
}

    ~Canteen()
    {
    }
};

int main()
{
    Canteen::Node *head = NULL;
    int choice;
    do
    {
        cout << "ENTER YOUR CHOICE:<enter password> for ADMIN \n <enter 'pass'> for CUSTOMER\n<e> EXIT : ";
        string code = "admin";
        string choice;
        cin >> choice;
        if (code.compare(choice) == 0)
        {
            Canteen obj;
            int choice1;

            cout << "==WELCOME TO ADMINISTRATOR==\n";
            do
            {
                cout << "PRESS <1> FOR CREATE\n"
                     << "\t"
                     << "<2> FOR ADD ITEM\n"
                     << "\t"
                     << "<3> FOR DELETE ITEM\n"
                     << "<0> FOR EXIT:";
                cin >> choice1;
                switch (choice1)
                {
                case 1:
                    head = obj.create(head);
                    break;
                case 2:
                    head = obj.create(head);
                    break;
                case 3:
                    obj.delete_data(head);
                    break;
                case 4:
                    Canteen obj2(head);
                    break;
                }
            } while (choice1 != 0);
        }
        else if (choice == "pass")
        {
            int choice1;
            cout << "IF YOU ARE CUSTOMER THEN FILL 'Y' IN BOTH ENTRY\n";
            Canteen objc;
            objc.print(head);
            do
            {
                cout << "\nENTER YOUR CHOICE:\n<1> FOR SEARCH ITEM\n<2> FOR PURCHASE AN ITEM\n<3> FOR SEE MENU\n<4> FOR ASCENDING\n<5> FOR LAST CHARACTERS FIND\n<6> FOR FIRST AND LAST CHAR READ\n<7> FOR DESCENDING ORDER: ";
                cin >> choice1;
                switch (choice1)
                {
                case 1:
                    objc.serch_record(head);
                    break;
                case 3:
                    objc.print(head);
                    break;
                case 4:
                    objc.sortNames(head);
                    cout << "Sorted list in ascending order:" << endl;
                    objc.printList(head);
                    break;
                case 7:
                    objc.sortrev(head);
                     cout << "Sorted list in descending order:" << endl;
                    objc.printList(head);
                    break;
                case 5:
                    objc.last_chars(head);
                    break;
                case 6:
                    objc.firstlast(head);
                    break;
                case 2:
                    Canteen objp(objc, head);
                    break;
                }
            } while (choice1 != 0);
        }
        else if (choice == "e" || choice == "E")
        {
            exit(0);
        }
    } while (choice != 0);
    delete head;
    return 0;
}