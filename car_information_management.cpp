#include <iostream>
#include <limits>
using namespace std;

class cars
{
public:
    struct info
    {
        char model[60];
        char brand[15];
        int mfgyear;
        char color[60];
        double price;
    } jems[5];

    void getinfo()
    {
        cout<<"ENTER DATA OF 5 CARS";
        for (int i = 0; i < 1; i++)
        {
            cout << "MODEL:";
            cin.getline(jems[i].model, 60);
            cout << "BRAND:";
            cin.getline(jems[i].brand, 15);
            cout << "MANUFACTURE YEAR:";
            cin >> jems[i].mfgyear;
           // cin.ignore();
            fflush(stdin);
            cout << "COLOR:";
            cin.getline(jems[i].color, 60);
            cout << "PRICE($):";
            cin >> jems[i].price;
           // fflush(stdin);
        }
    }

    void display()
    {
        cout << "========data of 5 cars========\n";
        cout << "=model\tbrand\tmanfact.year\tcolor\tprice=\n";
        for (int i = 0; i < 5; i++)
        {
            cout << jems[i].model << "\t" << jems[i].brand << "\t" << jems[i].mfgyear << "\t" << jems[i].color << "\t" << "$"<<jems[i].price << endl;
        }
    }

    void findexcar()
    {
        double maxPrice = jems[0].price;
        int maxIndex = 0;

        for (int i = 1; i < 5; i++)
        {
            if (jems[i].price > maxPrice)
            {
                maxPrice = jems[i].price;
                maxIndex = i;
            }
        }

        cout << "\nThe most expensive car is:\n";
        cout << "= model\tbrand\tmanfact.year\tcolor\tprice =\n";
        cout << jems[maxIndex].model << "\t" << jems[maxIndex].brand << "\t" << jems[maxIndex].mfgyear << "\t" << jems[maxIndex].color << "\t" <<"$"<< jems[maxIndex].price << endl;
    }

    void findchpcar()
    {
        double minPrice = jems[0].price;
        int minIndex = 0;

        for (int i = 1; i < 5; i++)
        {
            if (jems[i].price < minPrice)
            {
                minPrice = jems[i].price;
                minIndex = i;
            }
        }
        cout << "\nThe most cheapest car is:\n";
        cout << "= model\tbrand\tmanfact.year\tcolor\tprice =\n";
        cout << jems[minIndex].model << "\t" << jems[minIndex].brand << "\t" << jems[minIndex].mfgyear << "\t" << jems[minIndex].color << "\t" << "$"<<jems[minIndex].price << endl;
    }

    void aseorder()
    {
        info temp;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4 - i; j++)
            {
                if (jems[j].price > jems[j + 1].price)
                {
                    temp = jems[j];
                    jems[j] = jems[j + 1];
                    jems[j + 1] = temp;
                }
            }
        }
        cout << "Data in ascending order:\n";
        display();
    }

    void desorder()
    {
        info temp;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4 - i; j++)
            {
                if (jems[j].price < jems[j + 1].price)
                {
                    temp = jems[j];
                    jems[j] = jems[j + 1];
                    jems[j + 1] = temp;
                }
            }
        }
        cout << "Data in descending order:\n";
        display();
    }

    void inbudget()
    {
        double bjt;
        cout << "ENTER YOUR BUDGET:";
        cin >> bjt;

        bool found = false;
        cout << "Cars within your budget:\n";
        for (int i = 0; i < 5; i++)
        {
            if (jems[i].price <= bjt)
            {
                cout << jems[i].model << "\t" << jems[i].brand << "\t" << jems[i].mfgyear << "\t" << jems[i].color << "\t" << "$" <<jems[i].price << endl;
                found = true;
            }
        }

        if (!found)
        {
            cout << "No cars available within your budget.\n";
        }
    }
};

int main()
{
    cars obj;
    obj.getinfo();
    int choice;
    do
    {
        cout << "\nENTER YOUR CHOICE:\n <1> DISPLAY\n<2> MOST EXPENSIVE CAR\n<3> MOST CHEAPEST CAR\n<4> SEE CAR IN BUDGET\n <5> DISPLAY IN ASCENDING ORDER \n <6> DISPLAY IN DESCENDING ORDER\n <0> for exit:\n: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.display();
            break;
        case 2:
            obj.findexcar();
            break;
        case 3:
            obj.findchpcar();
            break;
        case 4:
            obj.inbudget();
            break;
        case 5:
            obj.aseorder();
            break;
        case 6:
            obj.desorder();
            break;
        case 0:
            exit(2);
        }
    } while (choice != 0);

    return 0;
}
