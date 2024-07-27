#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

struct User {
    int id;
    string name;
    int age;
};

class FileHandler {
private:
    ofstream outputFile;
    ifstream inputFile;
    vector<User> users;
    string File = "c:/Users/Nisarg/OneDrive/Desktop/C_Projects/Practicals/Prac 14.txt";

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
    enterId:
        cout << "Enter user ID: ";
        cin >> newUser.id;

        if (find_if(users.begin(), users.end(), [&](const User &u) { return u.id == newUser.id; }) != users.end()) {
            cout << "User with the same ID already exists. Please enter a unique ID." << endl;
            goto enterId;
        }

        cin.ignore();
        cout << "Enter user name: ";
        getline(cin, newUser.name);
        cout << "Enter user age: ";
        cin >> newUser.age;
        users.push_back(newUser);
        cout << "User information added successfully." << endl;
    }

    void displayInfo() {
        cout << "Stored user information:" << endl;
        for (const auto &user: users) {
            cout << "ID: " << user.id << ", Name: " << user.name << ", Age: " << user.age << endl;
        }
    }

    void editInfo() {
        int id;
        cout << "Enter the ID of the user to edit: ";
        cin >> id;
        for (auto &user: users) {
            if (user.id == id) {
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
            if (user.id == id) {
                cout << "User found - ID: " << user.id << ", Name: " << user.name << ", Age: " << user.age << endl;
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
            if (it->id == id) {
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
            return a.id < b.id;
        });
        for (const auto &user: users) {
            cout << "ID: " << user.id << ", Name: " << user.name << ", Age: " << user.age << endl;
        }
    }

    void showDataInDescOrder() {
        cout << "User information in descending order by ID:" << endl;
        sort(users.begin(), users.end(), [](const User &a, const User &b) {
            return a.id > b.id;
        });
        for (const auto &user: users) {
            cout << "ID: " << user.id << ", Name: " << user.name << ", Age: " << user.age << endl;
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
            outputFile << user.id << " " << user.name << " " << user.age << endl;
        }
        outputFile.close();
        inputFile.close();
        cout << "Exiting the program." << endl;
    }

    bool isOpen() {
        return outputFile.is_open() && inputFile.is_open();
    }
};

int main() {
    FileHandler fileHandler;
    if (!fileHandler.isOpen()) {
        return 1;
    }

    int choice;
    do {
        cout << endl;
        cout << " _____  _             _              ___  ___                    \n";
        cout << "/  __ \\| |           (_)             |  \\/  |                    \n";
        cout << "| /  \\/| |__    ___   _   ___   ___  | .  . |  ___  _ __   _   _ \n";
        cout << "| |    | '_ \\  / _ \\ | | / _| / _ \\ | |\\/| | / _ \\| ' \\ | | | |\n";
        cout << "| \\/\\| | | || () || || (_ |  _/ | |  | ||  __/| | | || || |\n";
        cout << " \\/|| || \\/ || \\| \\| \\|  |/ \\||| || \\,|\n";
        cout << "                                                                 \n";
        cout << "\n==============Options=============\n";
        cout << "Press <1> to Add user information\n"
                << "Press <2> to Display user information\n"
                << "Press <3> to Edit user information\n"
                << "Press <4> to Search user information\n"
                << "Press <5> to Delete user information\n"
                << "Press <6> to Show user information in ascending order by ID\n"
                << "Press <7> to Show user information in descending order by ID\n"
                << "Press <0> to Exit\n"
                << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                fileHandler.addInfo();
                break;
            case 2:
                fileHandler.displayInfo();
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
            case 0:
                fileHandler.exit();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}