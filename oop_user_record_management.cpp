#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class UserBase {

public:
    int id;
    string name;
    int age;
    UserBase() {}

    UserBase(int _id, string _name, int _age) : id(_id), name(_name), age(_age) {}

    virtual void displayInfo() const = 0;

    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
};

class User : public UserBase {
public:
    User() {}

    User(int _id, string _name, int _age) : UserBase(_id, _name, _age) {}

    void displayInfo() const override {
        cout << "ID: " << id << ", Name: " << name << ", Age: " << age << endl;
    }
};

class FileHandler {
private:
    ofstream outputFile;
    ifstream inputFile;
    vector<User> users;
    string File = "user_info.txt";

public:
    FileHandler() {
        outputFile.open(File, ios::out | ios::app);
        inputFile.open(File, ios::in);

        if (!outputFile.is_open() || !inputFile.is_open()) {
            cout << "Failed to open the file." << endl;
            return;
        }

        User user;
        while (inputFile >> user.id >> user.name >> user.age) {
            users.push_back(user);
        }
    }

    void addInfo() {
        User newUser;
        bool uniqueId = false;
        while (!uniqueId) {
            cout << "Enter user ID: ";
            cin >> newUser.id;

            if (cin.fail() || newUser.id < 0) {
                cout << "Invalid ID. Please enter a positive integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (find_if(users.begin(), users.end(), [&](const User &u) { return u.getId() == newUser.id; }) != users.end()) {
                cout << "User with the same ID already exists. Please enter a unique ID." << endl;
            } else {
                uniqueId = true;
            }
        }

        cin.ignore();
        cout << "Enter user name: ";
        getline(cin, newUser.name);

        bool validAge = false;
        while (!validAge) {
            cout << "Enter user age: ";
            cin >> newUser.age;

            if (cin.fail() || newUser.age < 0) {
                cout << "Invalid age. Please enter a positive integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                validAge = true;
            }
        }

        users.push_back(newUser);
        cout << "User information added successfully." << endl;
    }

    void displayInfo() const {
        cout << "Stored user information:" << endl;
        for (const auto &user: users) {
            user.displayInfo();
        }
    }

    void editInfo() {
        int id;
        cout << "Enter the ID of the user to edit: ";
        cin >> id;
        for (auto &user: users) {
            if (user.getId() == id) {
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, user.name);
                cout << "Enter new age: ";
                cin >> user.age;
                cout << "User information edited successfully." << endl;
                return;
            }
        }
        cout << "User not found." << endl;
    }

    void searchInfo() {
        int id;
        cout << "Enter the ID to search: ";
        cin >> id;
        for (const auto &user: users) {
            if (user.getId() == id) {
                cout << "User found - ";
                user.displayInfo();
                return;
            }
        }
        cout << "User not found." << endl;
    }

    void deleteInfo() {
        int id;
        cout << "Enter the ID of the user to delete: ";
        cin >> id;
        for (auto it = users.begin(); it != users.end(); ++it) {
            if (it->getId() == id) {
                users.erase(it);
                cout << "User deleted successfully." << endl;
                return;
            }
        }
        cout << "User not found." << endl;
    }

    void showDataInAscOrder() {
        cout << "User information in ascending order by ID:" << endl;
        sort(users.begin(), users.end(), [](const User &a, const User &b) {
            return a.getId() < b.getId();
        });
        for (const auto &user: users) {
            user.displayInfo();
        }
    }

    void showDataInDescOrder() {
        cout << "User information in descending order by ID:" << endl;
        sort(users.begin(), users.end(), [](const User &a, const User &b) {
            return a.getId() > b.getId();
        });
        for (const auto &user: users) {
            user.displayInfo();
        }
    }

    void exit() {
        outputFile.close();
        outputFile.open(File, ios::out);
        if (!outputFile.is_open()) {
            cout << "Failed to open the file." << endl;
            return;
        }
        inputFile.clear();
        outputFile.seekp(0, ios::beg);
        for (const auto &user: users) {
            outputFile << user.getId() << " " << user.getName() << " " << user.getAge() << endl;
        }
        outputFile.close();
        inputFile.close();
        cout << "Exiting the program." << endl;
    }

    bool isOpen() {
        return outputFile.is_open() && inputFile.is_open();
    }
};

template<typename T>
void displayInfo(const T &data) {
    data.displayInfo();
}

int main() {
    FileHandler fileHandler;
    if (!fileHandler.isOpen()) {
        return 1;
    }

    int choice;
    do {
        cout << endl;
        cout << " =============================\n";
        cout << "       User Information       \n";
        cout << " =============================\n";
        cout << "1. Add user information\n"
                << "2. Display user information\n"
                << "3. Edit user information\n"
                << "4. Search user information\n"
                << "5. Delete user information\n"
                << "6. Show user information in ascending order by ID\n"
                << "7. Show user information in descending order by ID\n"
                << "8. Exit\n"
                << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                fileHandler.addInfo();
                break;
            case 2:
                displayInfo(fileHandler);
                break;
            case 3:
                fileHandler.editInfo();
                break;
            case 4:
                fileHandler.searchInfo();
                break;
            case 5:
                fileHandler.deleteInfo();
                break;
            case 6:
                fileHandler.showDataInAscOrder();
                break;
            case 7:
                fileHandler.showDataInDescOrder();
                break;
            case 8:
                fileHandler.exit();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}
