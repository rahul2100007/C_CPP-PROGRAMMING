#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class student_record
{
public:
    struct student
    {
        int Sid, semester;
        double coursefee;
        string Sname, Course, Branch;
    } s[5];

    void readData()
    {
        cout << "ENTER FOLLOWING DATA:" << endl;
        cout << "SID, NAME, COURSE, BRANCH, SEMESTER, COURSE_FEE" << endl;
        for (int i = 0; i < 5; i++)
        {
            cin >> s[i].Sid >> s[i].Sname >> s[i].Course >> s[i].Branch >> s[i].semester >> s[i].coursefee;
        }
    }

    void savedata()
    {
        ofstream file("student.txt", ios::out);
        if (file.is_open())
        {
            for (int i = 0; i < 5; i++)
            {
                file << s[i].Sid << " " << s[i].Sname << " " << s[i].Course << " "
                     << s[i].Branch << " " << s[i].semester << " " << s[i].coursefee << endl;
            }
            file.close();
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
    }
    void displaydata()
    {
        ifstream file("student.txt", ios::in);
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
    }
    void updatedata()
    {
        cout << "ENTER THE SID OF THE STUDENT WHOSE DATA YOU WANT TO UPDATE" << endl;
        int id;
        cin >> id;
        for (int i = 0; i < 5; i++)
        {
            if (s[i].Sid == id)
            {
                cout << "ENTER THE UPDATED DATA" << endl;
                cout << "SID, NAME, COURSE, BRANCH, SEMESTER, COURSE_FEE" << endl;
                cin >> s[i].Sid >> s[i].Sname >> s[i].Course >> s[i].Branch >> s[i].semester >> s[i].coursefee;
            }
        }
        savedata();
    }
    void deleteFromFile()
    {
        cout << "ENTER THE SID OF THE STUDENT WHOSE DATA YOU WANT TO DELETE FROM FILE" << endl;
        int id;
        cin >> id;

        ifstream mainfile("student.txt", ios::in);
        ofstream tempFile("temp.txt", ios::out);

        if (mainfile.is_open() &  tempFile.is_open())
        {
            string line;
            while (getline(mainfile, line))
            {
                int sid;
                stringstream ss(line);
                ss >> sid;
                if (sid != id)
                {
                    tempFile << line << endl;
                }
            }
            mainfile.close();
            tempFile.close();

            remove("student.txt");
            rename("temp.txt", "student.txt");
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
    }

    void search()
    {
        cout << "ENTER THE SID OF THE STUDENT WHOSE DATA YOU WANT TO SEARCH FROM FILE" << endl;
        int id;
        cin >> id;
        ifstream file("student.txt", ios::in);
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                int sid;
                stringstream ss(line);
                ss >> sid;
                if (sid == id)
                {
                    cout << line << endl;
                }
            }
            file.close();
        }
        else
        {
            cout << "Unable to open file." << endl;
        }
    }
};

int main()
{
    student_record obj;
    int choice;
    do
    {
        cout << "1. Enter data" << endl;
        cout << "2. Display data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Delete data" << endl;
        cout << "5. Search data" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.readData();
            obj.savedata();
            break;
        case 2:
            obj.displaydata();
            break;
        case 3:
            obj.updatedata();
            break;
        case 4:
            obj.deleteFromFile();
            break;
        case 5:
            obj.search();
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 6);
    return 0;
}