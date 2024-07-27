#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class User
{
protected:
    string id;

public:
    string name;
    User(string name, string id) : name(name), id(id) {}
    virtual void displayDetails() = 0;
    virtual char getType() = 0;
    string getID() { return id; }
};

class Employee : public User
{
private:
    string employeeID;

public:
    Employee(string name, string id, string employeeID) : User(name, id), employeeID(employeeID) {}
    void displayDetails()
    {
        cout << "Name: " << name << "\nID: " << id << "\nEmployee ID: " << employeeID << endl;
    }
    char getType() { return 'E'; }
};

class Attendance
{
public:
    vector<bool> isPresent;
    Attendance(int numEmployees)
{
    isPresent = std::vector<bool>(numEmployees, false);
}


    void markAttendance(int index)
    {
        isPresent[index] = true;
    }

    void displayA(const vector<User *> &users)
    {
        cout << "Attendance:\n";
        for (int i = 0; i < users.size(); ++i)
        {
            cout << "ID: " << users[i]->getID() << " - " << (isPresent[i] ? "Present" : "Absent") << endl;
        }
    }
};

class onattendsys
{
private:
    vector<User *> users;
    Attendance *attendance;
    string filehai;
    string username;
    string password;
    bool islogin;

public:
    onattendsys(string filehai) : filehai(filehai), islogin(false)
    {
        ifstream file(filehai);
        string name, id, employeeID;
        char userType;
        while (file >> userType >> name >> id >> employeeID)
        {
            if (userType == 'E')
            {
                users.push_back(new Employee(name, id, employeeID));
            }
        }
        file.close();
        attendance = new Attendance(users.size());
    }
    ~onattendsys()
    {
        for (vector<User *>::iterator it = users.begin(); it != users.end(); ++it)
        {
            delete *it;
        }
        delete attendance;
    }

    bool login()
    {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        if (username == "admin" && password == "admin")
        {
            islogin = true;
            return true;
        }
        else
        {
            cout << "Invalid username or password!\n";
            return false;
        }
    }

    void displayUsers()
    {
        if (!islogin)
        {
            cout << "You need to login first!\n";
            return;
        }
        cout << "Users:\n";
        for (vector<User *>::const_iterator it = users.begin(); it != users.end(); ++it)
        {
            (*it)->displayDetails();
            cout << endl;
        }
    }

    void displayA()
    {
        if (!islogin)
        {
            cout << "You need to login first!\n";
            return;
        }
        attendance->displayA(users);
    }

    void displayAllData()
    {
        if (!islogin)
        {
            cout << "You need to login first!\n";
            return;
        }
        cout << "Users:\n";
        for (size_t i = 0; i < users.size(); ++i)
        {
            users[i]->displayDetails();
            cout << "Attendance: " << (attendance->isPresent[i] ? "Present" : "Absent") << endl;
            cout << endl;
        }
    }

    void MARKA(int index)
    {
        if (!islogin)
        {
            cout << "You need to login first!\n";
            return;
        }
        if (index >= 0 && index < users.size())
        {
            attendance->markAttendance(index);
        }
        else
        {
            cout << "Invalid user index!\n";
        }
    }

    void saveAttendance()
    {
        if (!islogin)
        {
            cout << "You need to login first!\n";
            return;
        }
        ofstream file(filehai);
        if (!file)
        {
            cerr << "Error: Could not open the file " << filehai << " for writing.\n";
            return;
        }
        for (int i = 0; i < users.size(); ++i)
        {
            file << " " << users[i]->name << " " << users[i]->getID() << " " << (attendance->isPresent[i] ? '1' : '0') << endl;
        }
        file.close();
        cout << "Attendance saved to file.\n";
    }

    void addEmployee()
    {
        if (!islogin)
        {
            cout << "You need to login first!\n";
            return;
        }
        string name, id, employeeID;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter employee ID: ";
        cin >> employeeID;
        users.push_back(new Employee(name, id, employeeID));
        attendance->markAttendance(users.size() - 1);
        cout << "Employee added successfully.\n";
    }

    void REMOVEEMP()
    {
        if (!islogin)
        {
            cout << "You need to login first!\n";
            return;
        }
        string id;
        cout << "Enter ID of the employee to be removed: ";
        cin >> id;
        for (int i = 0; i < users.size(); ++i)
        {
            if (users[i]->getID() == id)
            {
                delete users[i];
                users.erase(users.begin() + i);
                attendance->isPresent.erase(attendance->isPresent.begin() + i);
                cout << "Employee removed successfully.\n";
                return;
            }
        }
        cout << "Employee not found.\n";
    }

    void searchEmployee()
    {
        if (!islogin)
        {
            cout << "You need to login first!\n";
            return;
        }
        string id;
        cout << "Enter ID of the employee to search: ";
        cin >> id;
        for (int i = 0; i < users.size(); ++i)
        {
            if (users[i]->getID() == id)
            {
                cout << "Employee found:\n";
                users[i]->displayDetails();
                cout << "Attendance: " << (attendance->isPresent[i] ? "Present" : "Absent") << endl;
                return;
            }
        }
        cout << "Employee not found.\n";
    }
};

int main()
{
    onattendsys system("attendance.txt");

    while (!system.login())
    {
    }
    cout << " =============================\n";
    cout << "       Attendence System       \n";
    cout << " =============================\n";
    int choice;
    do
    {

        cout << "\n1. Display employees\n2. Add employee\n3. Remove employee\n4. Mark attendance\n5. Display attendance\n6. Display all data\n7. Save attendance\n8. Search employee\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            system.displayUsers();
            break;
        case 2:
            system.addEmployee();
            break;
        case 3:
            system.REMOVEEMP();
            break;
        case 4:
        {
            int index;
            cout << "Enter employee index to mark attendance: ";
            cin >> index;
            system.MARKA(index - 1);
            cout << "Attendance marked.\n";
            break;
        }
        case 5:
            system.displayA();
            break;
        case 6:
            system.displayAllData();
            break;
        case 7:
            system.saveAttendance();
            break;
        case 8:
            system.searchEmployee();
            break;
        case 9:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 9);


    return 0;
}
