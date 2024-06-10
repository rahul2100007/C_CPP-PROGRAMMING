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
void checkvalidate(struct student *students, int num_students)
{
    for (int i = 0; i < num_students; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (students[i].roll_no == students[j].roll_no)
            {
                printf("this roll number is already exist:(");
                printf("enter another roll no:");
                scanf("%d", &students[i].roll_no);
                break;
            }
        }
    }
}
void search_id(struct student *students, int num_students)
{
    int id;
    printf("ENTER ROLL NO WHICH YOU WANT TO SEARCH: ");
    scanf("%d", &id);
    for (int i = 0; i < num_students; i++)
    {
        if (id == students[i].roll_no)
        {
            printf("Roll No\tName\tClass\tSemester\tSubject\tExam Fee\n");
            printf("\t%d\t%s\t%s\t%d\t\t%s\t%d\n", students[i].roll_no, students[i].name, students[i].class_name, students[i].semester, students[i].subject, students[i].exam_fee);
            break;
        }
        else
        {
            printf("Record not found :(\n");
        }
    }
}
void search_name(struct student *students, int num_students)
{
    char name[50];
    printf("ENTER A NAME WHICH YOU WANT TO SEARCH: ");
    scanf("%s", name);
    for (int i = 0; i < num_students; i++)
    {
        if (strcmp(name, students[i].name) == 0)
        {
            printf("Roll No\tName\tClass\tSemester\tSubject\tExam Fee\n");
            printf("\t%d\t%s\t%s\t%d\t\t%s\t%d\n", students[i].roll_no, students[i].name, students[i].class_name, students[i].semester, students[i].subject, students[i].exam_fee);
        }
        else
        {
            printf("Record not found :(\n");
        }
    }
}
void search_class(struct student *students, int num_students)
{
    char class_name[20];
    printf("ENTER A CLASS WHICH YOU WANT TO SEARCH: ");
    scanf("%s", class_name);
    for (int i = 0; i < num_students; i++)
    {
        if (strcmp(class_name, students[i].class_name) == 0)
        {
            printf("Roll No\tName\tClass\tSemester\tSubject\tExam Fee\n");
            printf("\t%d\t%s\t%s\t%d\t\t%s\t%d\n", students[i].roll_no, students[i].name, students[i].class_name, students[i].semester, students[i].subject, students[i].exam_fee);
        }
        else
        {
            printf("Record not found :(\n");
        }
    }
}
int main()
{
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    struct student *students = (struct student *)malloc(num_students * (struct student));
    for (int i = 0; i < num_students; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &students[i].roll_no);
        checkvalidate(students, i + 1);
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
    printf("Enter which option to find record:\n<1> for BY ROLL NO.\n<2> for BY NAME.\n<3> for BY CLASS.\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        search_id(students, num_students);
        break;
    case 2:
        search_name(students, num_students);
        break;
    case 3:
        search_class(students, num_students);
        break;
    default:
        printf("Invalid input :(\n");
        break;
    }
    free(students);

    return 0;
}