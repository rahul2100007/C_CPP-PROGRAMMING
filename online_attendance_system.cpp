#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class User {
protected:
    string name;
    string id;

public:
    User(string name, string id) : name(name), id(id) {}
    virtual void displayDetails() = 0;
    virtual char getType() = 0;
    string getID() const { return id; }
    string getName() const { return name; }
};

class Employee : public User {
private:
    string employeeID;

public:
    Employee(string name, string id, string employeeID) : User(name, id), employeeID(employeeID) {}
    void displayDetails() override {
        cout << "Name: " << name << "\nID: " << id << "\nEmployee ID: " << employeeID << endl;
    }
    char getType() override { return 'E'; }
    string displayEmployeeDetails() {
        return name + " " + id + " " + employeeID;
    }
};

class Attendance {
public:
    vector<bool> isPresent;
    Attendance(int numEmployees) : isPresent(numEmployees, false) {}

    void markAttendance(int index) {
        isPresent[index] = true;
    }

    void displayAttendance(const vector<User*>& users) {
        cout << "Attendance:\n";
        for (int i = 0; i < users.size(); ++i) {
            cout << "Name: " << users[i]->getName() << " - ID: " << users[i]->getID() << " - " << (isPresent[i] ? "Present" : "Absent") << endl;
        }
    }

    void clearAttendance() {
        fill(isPresent.begin(), isPresent.end(), false);
    }
};

class OnlineAttendanceSystem {
private:
    vector<User*> users;
    Attendance* attendance;
    string filename;
    string username;
    string password;
    bool isLoggedIn;

public:
    OnlineAttendanceSystem(string filename) : filename(filename), isLoggedIn(false) {
        ifstream file(filename);
        string name, id, employeeID;
        char userType;
        if (file.is_open()) {
            while (file >> userType >> name >> id >> employeeID) {
                if (userType == 'E') {
                    users.push_back(new Employee(name, id, employeeID));
                }
            }
            file.close();
        }
        attendance = new Attendance(users.size());
    }

    ~OnlineAttendanceSystem() {
        // Clean up allocated memory
        for (auto user : users) {
            delete user;
        }
        delete attendance;
    }

    bool login() {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        // Simple check for demonstration purposes
        if (username == "admin" && password == "admin") {
            isLoggedIn = true;
            return true;
        } else {
            cout << "Invalid username or password!\n";
            return false;
        }
    }

    void displayUsers() {
        if (!isLoggedIn) {
            cout << "You need to login first!\n";
            return;
        }
        cout << "Users:\n";
        for (auto user : users) {
            user->displayDetails();
            cout << endl;
        }
    }

    void displayAttendance() {
        if (!isLoggedIn) {
            cout << "You need to login first!\n";
            return;
        }
        attendance->displayAttendance(users);
    }

    void markUserAttendance(int index) {
        if (!isLoggedIn) {
            cout << "You need to login first!\n";
            return;
        }
        if (index >= 0 && index < users.size()) {
            attendance->markAttendance(index);
        } else {
            cout << "Invalid user index!\n";
        }
    }

    void saveAttendance() {
        if (!isLoggedIn) {
            cout << "You need to login first!\n";
            return;
        }
        ofstream file(filename);
        for (int i = 0; i < users.size(); ++i) {
            file << users[i]->getType() << " " << static_cast<Employee*>(users[i])->displayEmployeeDetails() << " " << (attendance->isPresent[i] ? '1' : '0') << endl;
        }
        file.close();
        cout << "Attendance saved to file.\n";
    }

    void clearAttendance() {
        if (!isLoggedIn) {
            cout << "You need to login first!\n";
            return;
        }
        attendance->clearAttendance();
        cout << "Attendance data cleared.\n";
    }

    void addEmployee() {
        if (!isLoggedIn) {
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

    void removeEmployee() {
        if (!isLoggedIn) {
            cout << "You need to login first!\n";
            return;
        }
        string id;
        cout << "Enter ID of the employee to be removed: ";
        cin >> id;
        for (int i = 0; i < users.size(); ++i) {
            if (users[i]->getID() == id) {
                delete users[i];
                users.erase(users.begin() + i);
                attendance->isPresent.erase(attendance->isPresent.begin() + i);
                cout << "Employee removed successfully.\n";
                return;
            }
        }
        cout << "Employee not found.\n";
    }

    void searchEmployee() {
        if (!isLoggedIn) {
            cout << "You need to login first!\n";
            return;
        }
        string id;
        cout << "Enter ID of the employee to search: ";
        cin >> id;
        for (int i = 0; i < users.size(); ++i) {
            if (users[i]->getID() == id) {
                cout << "Employee found:\n";
                users[i]->displayDetails();
                cout << "Attendance: " << (attendance->isPresent[i] ? "Present" : "Absent") << endl;
                return;
            }
        }
        cout << "Employee not found.\n";
    }
};

int main() {
    OnlineAttendanceSystem system("attendance.txt");

    while (!system.login()) {}

    int choice;
    do {
        cout << "\n1. Display employees\n2. Add employee\n3. Remove employee\n4. Mark attendance\n5. Display attendance\n6. Save attendance\n7. Clear attendance\n8. Search employee\n9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                system.displayUsers();
                break;
            case 2:
                system.addEmployee();
                break;
            case 3:
                system.removeEmployee();
                break;
            case 4: {
                int index;
                cout << "Enter employee index to mark attendance: ";
                cin >> index;
                system.markUserAttendance(index - 1);
                cout << "Attendance marked.\n";
                break;
            }
            case 5:
                system.displayAttendance();
                break;
            case 6:
                system.saveAttendance();
                break;
            case 7:
                system.clearAttendance();
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
