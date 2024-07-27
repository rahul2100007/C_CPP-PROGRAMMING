#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_RECORDS = 100;
const string FILENAME = "D:\\college_records.txt";

class College {
public:
    int college_ID;
    string college_Name;
    string student_Name;
    string course;
    int year;
    int semester;
    int fee_structure;

    void displayInfo() {
        cout << "College ID: " << college_ID << endl;
        cout << "College Name: " << college_Name << endl;
        cout << "Student Name: " << student_Name << endl;
        cout << "Course: " << course << endl;
        cout << "Year: " << year << endl;
        cout << "Semester: " << semester << endl;
        cout << "Fee Structure: " << fee_structure << endl;
    }

    void saveToFile(ofstream& outFile) {
        outFile << "College ID: " <<  college_ID << endl;
        outFile << "College Name: " <<  college_Name << endl;
        outFile << "Student Name: " <<  student_Name << endl;
        outFile << "Course: "  <<  course << endl;
        outFile << "Year: " <<  year << endl;
        outFile << "Semester: " <<  semester << endl;
        outFile << "Fee Structure: " <<  fee_structure << endl;
    }

    void loadFromFile(ifstream& inFile) {
        inFile >> college_ID;
        inFile.ignore();
        getline(inFile, college_Name);
        getline(inFile, student_Name);
        getline(inFile, course);
        inFile >> year;
        inFile >> semester;
        inFile >> fee_structure;
        inFile.ignore();
    }
};

class CollegeList {
private:
    College records[MAX_RECORDS];
    int count;

public:
    CollegeList() : count(0) {
        loadFromFile();
    }

    ~CollegeList() {
        saveToFile();
    }

    void insertEnd(const College& newRecord) {
        if (count < MAX_RECORDS) {
            records[count] = newRecord;
            count++;
        } else {
            cout << "Maximum record limit reached." << endl;
        }
    }

    void display() {
        cout << "===================== Output of college information =========================" << endl;
        for (int i = 0; i < count; ++i) {
            records[i].displayInfo();
            cout << endl;
        }
        cout << "===========================================================================\n";
    }

    void searchByID(int id) {
        for (int i = 0; i < count; ++i) {
            if (records[i].college_ID == id) {
                records[i].displayInfo();
                return;
            }
        }
        cout << "College with ID " << id << " not found." << endl;
    }

    void searchByName(const string& name) {
        for (int i = 0; i < count; ++i) {
            if (records[i].college_Name == name) {
                records[i].displayInfo();
                return;
            }
        }
        cout << "College with Name " << name << " not found." << endl;
    }

    void updateByID(int id) {
        for (int i = 0; i < count; ++i) {
            if (records[i].college_ID == id) {
                cout << "Enter the new college ID: ";
                cin >> records[i].college_ID;
                cout << "Enter the new college Name: ";
                cin.ignore();
                getline(cin, records[i].college_Name);
                cout << "Enter the new student Name: ";
                getline(cin, records[i].student_Name);
                cout << "Enter the new course: ";
                getline(cin, records[i].course);
                cout << "Enter the new year: ";
                cin >> records[i].year;
                cout << "Enter the new semester: ";
                cin >> records[i].semester;
                cout << "Enter the new fee structure: ";
                cin >> records[i].fee_structure;
                return;
            }
        }
        cout << "Record not found.\n";
    }

    void deleteByID(int id) {
        for (int i = 0; i < count; ++i) {
            if (records[i].college_ID == id) {
                for (int j = i; j < count - 1; ++j) {
                    records[j] = records[j + 1];
                }
                count--;
                return;
            }
        }
        cout << "Record not found.\n";
    }

private:
    void saveToFile() {
        ofstream outFile( FILENAME );
        if (outFile.is_open()) {
            for (int i = 0; i < count; ++i) {
                records[i].saveToFile(outFile);
            }
            outFile.close();
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void loadFromFile() {
        ifstream inFile(FILENAME);
        if (inFile.is_open()) {
            College record;
            while (count < MAX_RECORDS && inFile.peek() != EOF) {
                record.loadFromFile(inFile);
                records[count++] = record;
            }
            inFile.close();
        } else {
            cout << "Unable to open file for reading." << endl;
        }
    }
};

int main() {
    CollegeList list;
    int num_records;

    cout << "Enter the number of college information: ";
    cin >> num_records;
    cin.ignore();

    for (int i = 0; i < num_records; ++i) {
        College newRecord;
        cout << "ENTER RECORD " << i + 1 << endl;
        cout << "College ID: ";
        cin >> newRecord.college_ID;
        cin.ignore();
        cout << "College Name: ";
        getline(cin, newRecord.college_Name);
        cout << "Student Name: ";
        getline(cin, newRecord.student_Name);
        cout << "Course: ";
        getline(cin, newRecord.course);
        cout << "Year: ";
        cin >> newRecord.year;
        cout << "Semester: ";
        cin >> newRecord.semester;
        cout << "Fee Structure: ";
        cin >> newRecord.fee_structure;
        cin.ignore();

        list.insertEnd(newRecord);
    }

    list.display();

    char choice;
    do {
        cout << "Do you want to find college information (y/n)? ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            int searchChoice;
            cout << "How do you want to find information by ID or Name? (Press <1> for By ID or press <2> for By Name): ";
            cin >> searchChoice;
            if (searchChoice == 1) {
                int id;
                cout << "Enter the college ID: \n";
                cin >> id;
                list.searchByID(id);
            } else if (searchChoice == 2) {
                string name;
                cout << "Enter the college name: \n";
                cin.ignore();
                getline(cin, name);
                list.searchByName(name);
            } else {
                cout << "Invalid choice!\n";
            }
        }
    } while (choice == 'y' || choice == 'Y');

    int option;
      do {
        cout << "\nEnter your choice:\n";
        cout << "1. Record minimum five students information\n";
        cout << "2. Display student records\n";
        cout << "3. Update student records\n";
        cout << "4. Delete student records\n";
        cout << "5. Search student records\n";
        cout << "6. Exit the program\n";
        cout << "Option: ";
        cin >> option;

        switch (option) {
            case 1:
                for (int i = 0; i < 5; ++i) {
                    College newRecord;
                    cout << "\nENTER RECORD " << i + 1 << endl;
                    cout << "College ID: ";
                    cin >> newRecord.college_ID;
                    cin.ignore();
                    cout << "College Name: ";
                    getline(cin, newRecord.college_Name);
                    cout << "Student Name: ";
                    getline(cin, newRecord.student_Name);
                    cout << "Course: ";
                    getline(cin, newRecord.course);
                    cout << "Year: ";
                    cin >> newRecord.year;
                    cout << "Semester: ";
                    cin >> newRecord.semester;
                    cout << "Fee Structure: ";
                    cin >> newRecord.fee_structure;
                    cin.ignore();

                    list.insertEnd(newRecord);
                }
                break;
            case 2:
                list.display();
                break;
            case 3:
                int updateID;
                cout << "Enter the ID of the record to update: ";
                cin >> updateID;
                list.updateByID(updateID);
                break;
            case 4:
                int deleteID;
                cout << "Enter the ID of the record to delete: ";
                cin >> deleteID;
                list.deleteByID(deleteID);
                break;
            case 5:
                int searchID;
                cout << "Enter the ID of the record to search: ";
                cin >> searchID;
                list.searchByID(searchID);
                break;
            case 6:
                cout << "=================== Thank You =====================\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    } while (true);

    return 0;
}