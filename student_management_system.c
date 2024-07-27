#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int rollNo;
    char name[50];
    char course[50];
    char branch[50];
    int semester;
    float fees;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int rollNo, char name[], char course[], char branch[], int semester, float fees) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->rollNo = rollNo;
    strcpy(newNode->name, name);
    strcpy(newNode->course, course);
    strcpy(newNode->branch, branch);
    newNode->semester = semester;
    newNode->fees = fees;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int rollNo, char name[], char course[], char branch[], int semester, float fees) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->rollNo = rollNo;
    strcpy(newNode->name, name);
    strcpy(newNode->course, course);
    strcpy(newNode->branch, branch);
    newNode->semester = semester;
    newNode->fees = fees;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(int rollNo, char name[], char course[], char branch[], int semester, float fees, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->rollNo = rollNo;
    strcpy(newNode->name, name);
    strcpy(newNode->course, course);
    strcpy(newNode->branch, branch);
    newNode->semester = semester;
    newNode->fees = fees;
    newNode->next = NULL;
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    for (int i = 0; i < position - 2; i++) {
        temp = temp->next;
        if (temp == NULL) return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteFromEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteFromPosition(int position) {
    if (head == NULL) return;
    struct Node* temp = head;
    if (position == 1) {
        head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < position - 2; i++) {
        temp = temp->next;
        if (temp == NULL) return;
    }
    struct Node* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

void searchNode(int rollNo) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            printf("Student found at position %d\n", position);
            printf("Roll No: %d\n", temp->rollNo);
            printf("Name: %s\n", temp->name);
            printf("Course: %s\n", temp->course);
            printf("Branch: %s\n", temp->branch);
            printf("Semester: %d\n", temp->semester);
            printf("Fees: %.2f\n", temp->fees);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Student with Roll No %d not found in the list.\n", rollNo);
}

void displayList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Roll No: %d\n", temp->rollNo);
        printf("Name: %s\n", temp->name);
        printf("Course: %s\n", temp->course);
        printf("Branch: %s\n", temp->branch);
        printf("Semester: %d\n", temp->semester);
        printf("Fees: %.2f\n", temp->fees);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, rollNo, semester, position;
    float fees;
    char name[50], course[50], branch[50];

    while (1) {
        printf("\n*********Main Menu*********\n");
        printf("Choose one option from the following list ...\n");
        printf("1. Insert student at the beginning of list\n");
        printf("2. Insert student at the end of list\n");
        printf("3. Insert student at specified position in the list\n");
        printf("4. Delete student from beginning of list\n");
        printf("5. Delete student from end of list\n");
        printf("6. Delete student from the specified position\n");
        printf("7. Search student from the list\n");
        printf("8. Display list of students\n");
        printf("9. Exit from the terminal\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll No: ");
                scanf("%d", &rollNo);
                printf("Enter Name: ");
                getchar(); // to consume the newline character
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // remove newline character
                printf("Enter Course: ");
                fgets(course, sizeof(course), stdin);
                course[strcspn(course, "\n")] = 0; // remove newline character
                printf("Enter Branch: ");
                fgets(branch, sizeof(branch), stdin);
                branch[strcspn(branch, "\n")] = 0; // remove newline character
                printf("Enter Semester: ");
                scanf("%d", &semester);
                printf("Enter Fees: ");
                scanf("%f", &fees);
                insertAtBeginning(rollNo, name, course, branch, semester, fees);
                break;
            case 2:
                printf("Enter Roll No: ");
                scanf("%d", &rollNo);
                printf("Enter Name: ");
                getchar(); // to consume the newline character
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // remove newline character
                printf("Enter Course: ");
                fgets(course, sizeof(course), stdin);
                course[strcspn(course, "\n")] = 0; // remove newline character
                printf("Enter Branch: ");
                fgets(branch, sizeof(branch), stdin);
                branch[strcspn(branch, "\n")] = 0; // remove newline character
                printf("Enter Semester: ");
                scanf("%d", &semester);
                printf("Enter Fees: ");
                scanf("%f", &fees);
                insertAtEnd(rollNo, name, course, branch, semester, fees);
                break;
            case 3:
                printf("Enter Roll No: ");
                scanf("%d", &rollNo);
                printf("Enter Name: ");
                getchar(); // to consume the newline character
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // remove newline character
                printf("Enter Course: ");
                fgets(course, sizeof(course), stdin);
                course[strcspn(course, "\n")] = 0; // remove newline character
                printf("Enter Branch: ");
                fgets(branch, sizeof(branch), stdin);
                branch[strcspn(branch, "\n")] = 0; // remove newline character
                printf("Enter Semester: ");
                scanf("%d", &semester);
                printf("Enter Fees: ");
                scanf("%f", &fees);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertAtPosition(rollNo, name, course, branch, semester, fees, position);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(position);
                break;
            case 7:
                printf("Enter Roll No to search: ");
                scanf("%d", &rollNo);
                searchNode(rollNo);
                break;
            case 8:
                displayList();
                break;
            case 9:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
0