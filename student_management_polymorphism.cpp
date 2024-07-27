#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Student
{
public:
    string name;
    int rollNumber;
    float marks;
    Student(string name, int rollNumber, float marks) : name(name), rollNumber(rollNumber), marks(marks) {}

    virtual void readData() = 0;
    virtual void displayData() = 0;
    virtual void deleteData(int rollNumber) = 0;
    virtual void updateData(int rollNumber) = 0;
    virtual void searchData(int rollNumber) = 0;
    virtual void displayAllData(bool ascending) = 0;

    virtual ~Student()
    {
        cout << "" << endl;
    }
};

const int num_student = 5;

class StudentResult : public Student
{
private:
    Student *students[num_student];
    int count = 0;

public:
    StudentResult(string name, int rollNumber, float marks) : Student(name, rollNumber, marks) {}

    void readData()
    {
        string name;
        int rollNumber;
        float marks;

        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollNumber;
        cout << "Enter marks: ";
        cin >> marks;

        if (count < num_student)
        {
            students[count++] = new StudentResult(name, rollNumber, marks);
            cout << "Record added successfully!" << endl;
        }
        else
        {
            cout << "Maximum limit reached! Cannot add more records." << endl;
        }
    }

    void displayData()
    {
        for (int i = 0; i < count; ++i)
        {
            cout << "Name: " << students[i]->name << ", Roll Number: " << students[i]->rollNumber << ", Marks: " << students[i]->marks << endl;
        }
    }

    void deleteData(int rollNumber)
    {
        int index = -1;
        for (int i = 0; i < count; ++i)
        {
            if (students[i]->rollNumber == rollNumber)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            delete students[index];
            for (int i = index; i < count - 1; ++i)
            {
                students[i] = students[i + 1];
            }
            count--;
            cout << "Record deleted successfully!" << endl;
        }
        else
        {
            cout << "Record not found!" << endl;
        }
    }

    void updateData(int rollNumber)
    {
        for (int i = 0; i < count; ++i)
        {
            if (students[i]->rollNumber == rollNumber)
            {
                cout << "Enter new name: ";
                cin >> students[i]->name;
                cout << "Enter new marks: ";
                cin >> students[i]->marks;
                cout << "Record updated successfully!" << endl;
                return;
            }
        }
        cout << "Record not found!" << endl;
    }

    void searchData(int rollNumber)
    {
        for (int i = 0; i < count; ++i)
        {
            if (students[i]->rollNumber == rollNumber)
            {
                cout << "Name: " << students[i]->name << ", Roll Number: " << students[i]->rollNumber << ", Marks: " << students[i]->marks << endl;
                return;
            }
        }
        cout << "Record not found!" << endl;
    }

    void displayAllData(bool ascending)
    {
        if (ascending)
        {
            for (int i = 0; i < count - 1; ++i)
            {
                for (int j = 0; j < count - i - 1; ++j)
                {
                    if (students[j]->rollNumber > students[j + 1]->rollNumber)
                    {
                        swap(students[j], students[j + 1]);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < count - 1; ++i)
            {
                for (int j = 0; j < count - i - 1; ++j)
                {
                    if (students[j]->rollNumber < students[j + 1]->rollNumber)
                    {
                        swap(students[j], students[j + 1]);
                    }
                }
            }
        }

        cout << "Student Records:" << endl;
        displayData();
    }

    ~StudentResult()
    {
        for (int i = 0; i < count; ++i)
        {
            delete students[i];
        }
        cout << "" << endl;
    }

    void displayAllData(bool ascending, bool byName)
    {
        if (byName)
        {
            if (ascending)
            {
                for (int i = 0; i < count - 1; ++i)
                {
                    for (int j = 0; j < count - i - 1; ++j)
                    {
                        if (students[j]->name > students[j + 1]->name)
                        {
                            swap(students[j], students[j + 1]);
                        }
                    }
                }
            }
            else
            {
                for (int i = 0; i < count - 1; ++i)
                {
                    for (int j = 0; j < count - i - 1; ++j)
                    {
                        if (students[j]->name < students[j + 1]->name)
                        {
                            swap(students[j], students[j + 1]);
                        }
                    }
                }
            }
        }
        else
        {
            if (ascending)
            {
                for (int i = 0; i < count - 1; ++i)
                {
                    for (int j = 0; j < count - i - 1; ++j)
                    {
                        if (students[j]->rollNumber > students[j + 1]->rollNumber)
                        {
                            swap(students[j], students[j + 1]);
                        }
                    }
                }
            }
            else
            {
                for (int i = 0; i < count - 1; ++i)
                {
                    for (int j = 0; j < count - i - 1; ++j)
                    {
                        if (students[j]->rollNumber < students[j + 1]->rollNumber)
                        {
                            swap(students[j], students[j + 1]);
                        }
                    }
                }
            }
        }

        cout << "Student Records:" << endl;
        displayData();
    }
};

int main()
{
    StudentResult result("", 0, 0);
    int choice, rollNumber;

    do
    {
        cout << "\n1. Add Data\n2. Display Data\n3. Delete Data\n4. Update Data\n5. Search Data\n6. Display All Data (Ascending)\n7. Display All Data (Descending)\n8. Display All Data (Ascending by Name)\n9. Display All Data (Descending by Name)\n10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            result.readData();
            break;
        case 2:
            result.displayData();
            break;
        case 3:
            cout << "Enter roll number to delete: ";
            cin >> rollNumber;
            result.deleteData(rollNumber);
            break;
        case 4:
            cout << "Enter roll number to update: ";
            cin >> rollNumber;
            result.updateData(rollNumber);
            break;
        case 5:
            cout << "Enter roll number to search: ";
            cin >> rollNumber;
            result.searchData(rollNumber);
            break;
        case 6:
            result.displayAllData(true);
            break;
        case 7:
            result.displayAllData(false);
            break;
        case 8:
            result.displayAllData(true, true);
            break;
        case 9:
            result.displayAllData(false, true);
            break;
        case 10:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 10);

    return 0;
}
