#include <iostream>
#include <fstream>
using namespace std;

class fileka
{
public:
    int id;
    string name, address, salary;

    void getdata()
    {
        ofstream ofs;
        ofs.open("employee.txt");
        if (!ofs.is_open())
        {
            cout << "Error opening file!" << endl;
            return;
        }

        cout << "    ================================" << endl;
        cout << "  ====                            ====" << endl;
        cout << "====== ENTER DATA FOR 5 EMPLOYEES ======" << endl;
        cout << "  ====                            ====" << endl;
        cout << "    ================================" << endl;
        cout << "    ================================" << endl;
        cout << "  == ID\tNAME\tADDRESS\tSALARY ==" << endl;
        cout << "    ================================" << endl;
        for (int i = 0; i < 5; i++)
        {
            cout << "== ENTER DATA FOR EMPLOYEE " << i + 1 << " ==" << endl;
            cin >> id >> name >> address >> salary;
            ofs << id << "\t" << name << "\t" << address << "\t" << salary << endl;
        }
        ofs.close();
    }

    void readdata()
    {
        ifstream ifs;
        ifs.open("employee.txt");
        if (!ifs.is_open())
        {
            cout << "Error opening file!" << endl;
            return;
        }

        cout << "\nData read from file:" << endl;
        cout << "    ================================" << endl;
        cout << "  == ID\tNAME\tADDRESS\tSALARY ==" << endl;
        cout << "    ================================" << endl;
        while (ifs >> id >> name >> address >> salary)
        {
            cout << id << "\t" << name << "\t" << address << "\t" << salary << endl;
        }
        ifs.close();
    }

    void searchById()
    {
        int id;
        cout << "\nEnter the ID of the employee you want to search: ";
        cin >> id;

        ifstream ifs;
        ifs.open("employee.txt");
        if (!ifs.is_open())
        {
            cout << "Error opening file!" << endl;
            return;
        }

        bool found = false;
        cout << "\nSearching for employee with ID " << id << ":" << endl;
        cout << "    ================================" << endl;
        cout << "  == ID\tNAME\tADDRESS\tSALARY ==" << endl;
        cout << "    ================================" << endl;
        while (ifs >> this->id >> name >> address >> salary)
        {
            if (this->id == id)
            {
                found = true;
                cout << this->id << "\t" << name << "\t" << address << "\t" << salary << endl;
            }
        }
        if (!found)
        {
            cout << "Employee with ID " << id << " not found." << endl;
        }
        ifs.close();
    }

    void editData()
    {
        int id;
        cout << "\nEnter the ID of the employee whose data you want to edit: ";
        cin >> id;

        ifstream file("employee.txt");
        if (!file.good())
        {
            cout << "Error opening file!" << endl;
            return;
        }

        bool found = false;
        fileka temp;
        ofstream tempFile("temp.txt");
        if (!tempFile.good())
        {
            cout << "Error creating temporary file!" << endl;
            return;
        }

        while (file >> temp.id >> temp.name >> temp.address >> temp.salary)
        {
            if (temp.id == id)
            {
                found = true;
                cout << "== ENTER NEW DATA FOR EMPLOYEE WITH ID " << id << " ==" << endl;
                cout << "Name: ";
                cin >> temp.name;
                cout << "Address: ";
                cin >> temp.address;
                cout << "Salary: ";
                cin >> temp.salary;
                tempFile << temp.id << "\t" << temp.name << "\t" << temp.address << "\t" << temp.salary << endl;
                cout << "Data for employee with ID " << id << " has been updated." << endl;
            }
            else
            {
                tempFile << temp.id << "\t" << temp.name << "\t" << temp.address << "\t" << temp.salary << endl;
            }
        }

        if (!found)
        {
            cout << "Employee with ID " << id << " not found." << endl;
        }

        file.close();
        tempFile.close();
        remove("employee.txt");
        rename("temp.txt", "employee.txt");
    }

    void deleteData()
    {
        int id;
        cout << "\nEnter the ID of the employee whose data you want to delete: ";
        cin >> id;

        ifstream file("employee.txt");
        if (!file.good())
        {
            cout << "Error opening file!" << endl;
            return;
        }

        bool found = false;
        fileka temp;
        ofstream tempFile("temp.txt");
        if (!tempFile.good())
        {
            cout << "Error creating temporary file!" << endl;
            return;
        }

        while (file >> temp.id >> temp.name >> temp.address >> temp.salary)
        {
            if (temp.id == id)
            {
                found = true;
                cout << "Data for employee with ID " << id << " has been deleted." << endl;
            }
            else
            {
                tempFile << temp.id << "\t" << temp.name << "\t" << temp.address << "\t" << temp.salary << endl;
            }
        }

        if (!found)
        {
            cout << "Employee with ID " << id << " not found." << endl;
        }

        file.close();
        tempFile.close();
        remove("employee.txt");
        rename("temp.txt", "employee.txt");
    }ss
};

int main()
{
    fileka obj;
    int choice;
    do
    {
        cout << "\n============================" << endl;
        cout << "1. Enter Employee Data" << endl;
        cout << "2. Read Employee Data" << endl;
        cout << "3. Search Employee by ID" << endl;
        cout << "4. Edit Employee Data by ID" << endl;
        cout << "5. Delete Employee Data by ID" << endl;
        cout << "6. Exit" << endl;
        cout << "============================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.getdata();
            break;
        case 2:
            obj.readdata();
            break;
        case 3:
            obj.searchById();
            break;
        case 4:
            obj.editData();
            break;
        case 5:
            obj.deleteData();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}
