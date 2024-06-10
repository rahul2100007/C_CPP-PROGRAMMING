#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int roll_no;
    char name[50];
    char class_name[20];
    int semester;
    char subject[50];
    int exam_fee;
};

void printfun(struct student *students, int num_students)
{
    printf("\nStudent Records:\n");
    printf("Roll No\tName\tClass\tSemester\tSubject\tExam Fee\n");
    for (int j = 0; j < num_students; j++)
    {
        printf("%d\t%s\t%s\t%d\t\t%s\t%d\n", students[j].roll_no, students[j].name, students[j].class_name, students[j].semester, students[j].subject, students[j].exam_fee);
    }
}

void deleteRecord(struct student *students, int *num_students)
{
    int rollno;
    printf("Enter Roll No to delete: ");
    scanf("%d", &rollno);
    for (int i = 0; i < *num_students; i++)
    {
        if (students[i].roll_no == rollno)
        {
            for (int j = i; j < *num_students - 1; j++)
            {
                students[j] = students[j + 1];
            }
            (*num_students)--;
            printf("Record deleted successfully!\n");
            printf("updated record is following:)");
            printf("Roll No\tName\tClass\tSemester\tSubject\tExam Fee\n");
            for (int k = 0; k < *num_students; k++)
            {
                printf("%d\t%s\t%s\t%d\t\t%s\t%d\n", students[k].roll_no, students[k].name, students[k].class_name, students[k].semester, students[k].subject, students[k].exam_fee);
            }
            break;
        }
    }
}

void modify_data(struct student *students, int num_students)
{
    int choice;
    printf("which through you want to modify data by name or roll no:\n<press 1> for by roll no\n<press 2> for by name:");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("enter roll no which's student data you want to change:");
        int rolno;
        scanf("%d", &rolno);
        for (int i = 0; i < num_students; i++)
        {
            if (students[i].roll_no == rolno)
            {
                printf("\nEnter details for student :\n");
                printf("Roll No: ");
                scanf("%d", &students[i].roll_no);
                printf("Name: ");
                scanf("%s", students[i].name);
                printf("Class: ");
                scanf("%s", students[i].class_name);
                printf("Semester: ");
                scanf("%d", &students[i].semester);
                printf("Subject: ");
                scanf("%s", students[i].subject);
                printf("Exam Fee: ");
                scanf("%d", &students[i].exam_fee);
            }
        }
        break;
    case 2:
        printf("enter name who's student data you want to change:");
        char name[50];
        scanf("%s", name);
        for (int i = 0; i < num_students; i++)
        {
            if (strcmp(name, students[i].name) == 0)
            {
                printf("\nEnter details for student :\n");
                printf("Roll No: ");
                scanf("%d", &students[i].roll_no);
                printf("Name: ");
                scanf("%s", students[i].name);
                printf("Class: ");
                scanf("%s", students[i].class_name);
                printf("Semester: ");
                scanf("%d", &students[i].semester);
                printf("Subject: ");
                scanf("%s", students[i].subject);
                printf("Exam Fee: ");
                scanf("%d", &students[i].exam_fee);
            }
        }
        break;
    default:
        printf("Invalid choice!\n");
        break;
    }
    printf("Roll No\tName\tClass\tSemester\tSubject\tExam Fee\n");
    for (int j = 0; j < num_students; j++)
    {
        printf("%d\t%s\t%s\t%d\t\t%s\t%d\n", students[j].roll_no, students[j].name, students[j].class_name, students[j].semester, students[j].subject, students[j].exam_fee);
    }
}

void search_id(struct student *students, int num_students)
{
    int id;
    printf("ENTER ROLL NO WHICH YOU WANT TO SEARCH: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < num_students; i++)
    {
        if (id == students[i].roll_no)
        {
            printf("||Roll No||\t||Name||\t||Class||\t||Semester||\t||Subject||\t||Exam Fee||\n");
            printf("|\t%d|\t|%s|\t|%s|\t|%d|\t\t|%s\t|%d|\n", students[i].roll_no, students[i].name, students[i].class_name, students[i].semester, students[i].subject, students[i].exam_fee);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Record not found :(\n");
    }
}

void search_name(struct student *students, int num_students)
{
    char name[50];
    printf("ENTER A NAME WHICH YOU WANT TO SEARCH: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_students; i++)
    {
        if (strcmp(name, students[i].name) == 0)
        {
            printf("Roll No\tName\tClass\tSemester\tSubject\tExam Fee\n");
            printf("\t%d\t%s\t%s\t%d\t\t%s\t%d\n", students[i].roll_no, students[i].name, students[i].class_name, students[i].semester, students[i].subject, students[i].exam_fee);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Record not found :(\n");
    }
}

int main()
{
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    struct student *students = (struct student *)malloc(num_students * sizeof(struct student));
    for (int i = 0; i < num_students; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Class: ");
        scanf("%s", students[i].class_name);
        printf("Semester: ");
        scanf("%d", &students[i].semester);
        printf("Subject: ");
        scanf("%s", students[i].subject);
        printf("Exam Fee: ");
        scanf("%d", &students[i].exam_fee);
    }
    printf("\nStudent Records:\n");
    printf("Roll No\tName\tClass\tSemester\tSubject\tExam Fee\n");
    for (int j = 0; j < num_students; j++)
    {
        printf("%d\t%s\t%s\t%d\t\t%s\t%d\n", students[j].roll_no, students[j].name, students[j].class_name, students[j].semester, students[j].subject, students[j].exam_fee);
    }
    int choice;
    printf("Enter which option to perform operation:\n<1> for BY ROLL NO.\n<2> for BY NAME.\n<3> for delete record.\n<4> for MODIFY\n<5> for print data\n<0> for exit program:");
    scanf("%d", &choice);
    while (choice != 0)
    {
        switch (choice)
        {
        case 1:
            search_id(students, num_students);
            break;
        case 2:
            search_name(students, num_students);
            break;
        case 3:
            deleteRecord(students, &num_students);
          //  realloc(num_students-1,sizeof(struct student));
            break;
        case 4:
            modify_data(students, num_students);
            break;
        case 5:
            printfun(students, num_students);
            break;
        case 0:
            exit(0);
        default:
            printf("Invalid input :(\n");
            break;
        }
        printf("Enter which option to find record:\n<1> for BY ROLL NO.\n<2> for BY NAME.\n<3> for BY delete record.\n<4> for MODIFY\n<5> for print data\n<0> for exit program:");
        scanf("%d", &choice);
    }
    free(students);
    return 0;
}
