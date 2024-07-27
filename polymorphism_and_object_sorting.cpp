#include <iostream>
#include <string>
using namespace std;
class polymor
{

public:
    string name;
    int num1, num2;
    string str1, str2;
    polymor()
    {
    }
    void getdata(int num, int numx)
    {
        cout << "THE SUM OF TWO NUMBER IS:" << num + numx << endl;
    }

    void getdata(string str, string strx)
    {
        cout << "STRING CONCATENATION IS : " << str << " " << strx << endl;
    }

    void getdata(polymor object1[], polymor object2[])
    {
        cout << "NAME OF OBJECT 1:" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << object1[i].name << endl;
        }
        cout << "NAME OF OBJECT 2:" << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << object2[j].name << endl;
        }
    }
    polymor operator+(polymor &other)
    {
        polymor result;
        result.getdata(num1, other.num1);
        return result;
    }
    polymor operator-(polymor &other)
    {
        polymor result;
        result.getdata(str1, other.str1);
        return result;
    }
    bool operator>(polymor &other)
    {
        return name > other.name;
    }
    bool operator<(polymor &other)
    {
        return name < other.name;
    }
    ~polymor() {}
};

void asce_obj1(polymor object1[])
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (object1[i] > object1[j])
            {
                swap(object1[i], object1[j]);
            }
        }
    }
}

void display(polymor object1[])
{
    cout << "data in ascending order:";
    for (int i = 0; i < 5; i++)
    {
        cout << object1[i].name << endl;
    }
}
void display2(polymor object1[])
{
    cout << "data in descending order:";
    for (int i = 0; i < 5; i++)
    {
        cout << object1[4 - i].name << endl;
    }
}

int main()
{
    polymor obj1, obj2, object, object1[5], object2[5];

    cout << "ENTER NUMBER 1:";
    cin >> obj1.num1;
    cout << "ENTER NUMBER 2:";
    cin >> obj2.num1;
    obj1 + obj2;
    cout << "ENTER NAME 1:";
    cin >> obj1.str1;
    cout << "ENTER NAME 2:";
    cin >> obj2.str1;
    obj1 - obj2;
    cout << "ENTER 5 NAMES FOR OBJECT1:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". NAME: ";
        cin >> object1[i].name;
    }

    cout << "ENTER 5 NAMES FOR OBJECT2:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". NAME: ";
        cin >> object2[i].name;
    }

    for (int i = 0; i < 5; i++)
    {
        if (object1[i] > object2[i])
        {
            cout << "The greater name is: " << object1[i].name << endl;
        }
        else if (object2[i] > object1[i])
        {
            cout << "The greater name is: " << object2[i].name << endl;
        }
        else
        {
            cout << "The names are equal: " << object1[i].name << endl;
        }
    }
    int ch;
    while (1)
    {
        cout << "ENTER YOUR CHOICE \n <1> FOR DISPLAY DATA OF OBJECT 1 OBJECT 2 \n <2> FOR DISPLAY DATA IN ASCENMDING ORDER \n <3> FOR DESCENDING ORDER \n <4> FOR DISPLAY DATA IN ASCENMDING ORDER OF OBJECT 2 \n <5> FOR DESCENDING ORDER OF OBJECT 2:";
        cin >> ch;

        switch (ch)
        {
        case 1:
            object.getdata(object1, object2);
            break;
        case 2:
            asce_obj1(object1);
            display(object1);
            break;
        case 3:
            display2(object1);
            break;
        case 4:
            asce_obj1(object2);
            display(object2);
            break;
        case 5:
            display2(object2);
            break;
        default:
            cout << "INVALID CHOICE";
            break;
        }
    }
    object.~polymor();

    return 0;
}