#include <iostream>
#include <cstring>
using namespace std;

const int MAX_STUDENTS = 50;
const int MAX_RESOURCES = 5;
const int NUM_DEPARTMENTS = 4;
const int NUM_RESOURCES = 4;

struct StudentRecord {
    int studentID;
    char name[50];
    char section[10];
    char yearLevel[15];
    bool isActive;
};

StudentRecord studentArray[MAX_STUDENTS];
int studentCount = 0;

void initializeArray() {
    studentCount = 0;
    for (int i = 0; i < MAX_STUDENTS; i++) {
        studentArray[i].studentID = 0;
        strcpy(studentArray[i].name, "");
        strcpy(studentArray[i].section, "");
        strcpy(studentArray[i].yearLevel, "");
        studentArray[i].isActive = false;
    }
}

bool hasCapacity() {
    return studentCount < MAX_STUDENTS;
}

bool addStudentToArray(int id, const char* name, const char* section, const char* yearLevel) {
    if (!hasCapacity()) {
        cout << "Error: Student array is full (capacity " << MAX_STUDENTS << ").\n";
        return false;
    }
    if (studentCount < 0 || studentCount >= MAX_STUDENTS) {
        cout << "Error: Invalid array index.\n";
        return false;
    }
    studentArray[studentCount].studentID = id;
    strncpy(studentArray[studentCount].name, name, 49);
    strncpy(studentArray[studentCount].section, section, 9);
    strncpy(studentArray[studentCount].yearLevel, yearLevel, 14);
    studentArray[studentCount].isActive = true;
    studentCount++;
    return true;
}

void traverseStudentArray() {
    if (studentCount == 0) {
        cout << "No student records to display.\n";
        return;
    }
    cout << "ID    | Name                 | Section | Year Level\n";
    cout << "-----------------------------------------------------\n";
    for (int i = 0; i < studentCount; i++) {
        if (studentArray[i].isActive) {
            cout << studentArray[i].studentID << " | "
                 << studentArray[i].name << " | "
                 << studentArray[i].section << " | "
                 << studentArray[i].yearLevel << "\n";
        }
    }
}

int findStudentIndexByID(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (studentArray[i].studentID == id && studentArray[i].isActive) {
            return i;
        }
    }
    return -1;
}

bool updateStudentInArray(int id, const char* newSection, const char* newYearLevel) {
    int idx = findStudentIndexByID(id);
    if (idx == -1) {
        cout << "Error: Student ID not found.\n";
        return false;
    }
    strncpy(studentArray[idx].section, newSection, 9);
    strncpy(studentArray[idx].yearLevel, newYearLevel, 14);
    return true;
}

bool deleteStudentFromArray(int id) {
    int idx = findStudentIndexByID(id);
    if (idx == -1) {
        cout << "Error: Student ID not found.\n";
        return false;
    }
    for (int i = idx; i < studentCount - 1; i++) {
        studentArray[i] = studentArray[i + 1];
    }
    studentCount--;
    return true;
}

// MEMORY & POINTER
struct CampusResource {
    char resourceID[10];
    char resourceName[50];
    char category[30];
    int capacity;
};

CampusResource* resourcePtr = nullptr;

void allocateResourceMemory() {
    if (resourcePtr != nullptr) {
        cout << "Resource memory is already allocated.\n";
        return;
    }

    resourcePtr = new CampusResource[MAX_RESOURCES];
    for (int i = 0; i < MAX_RESOURCES; i++) {

        strcpy(resourcePtr[i].resourceID, "");
        strcpy(resourcePtr[i].resourceName, "");
        strcpy(resourcePtr[i].category, "");
        resourcePtr[i].capacity = 0;
    }

    cout << "Dynamic memory allocated for "
         << MAX_RESOURCES
         << " campus resources.\n";
}

void initializeResources() {
    if (resourcePtr == nullptr) {
        cout << "Error: Resource memory has not been allocated.\n";
        return;
    }

    strcpy(resourcePtr[0].resourceID, "R-01");
    strcpy(resourcePtr[0].resourceName, "Computer Laboratory 1");
    strcpy(resourcePtr[0].category, "Laboratory");
    resourcePtr[0].capacity = 50;

    strcpy(resourcePtr[1].resourceID, "R-02");
    strcpy(resourcePtr[1].resourceName, "Conference Room");
    strcpy(resourcePtr[1].category, "Meeting Space");
    resourcePtr[1].capacity = 20;

    strcpy(resourcePtr[2].resourceID, "R-03");
    strcpy(resourcePtr[2].resourceName, "Library Study Hub");
    strcpy(resourcePtr[2].category, "Study Area");
    resourcePtr[2].capacity = 60;

    strcpy(resourcePtr[3].resourceID, "R-04");
    strcpy(resourcePtr[3].resourceName, "Robotics Lab");
    strcpy(resourcePtr[3].category, "Laboratory");
    resourcePtr[3].capacity = 20;

    strcpy(resourcePtr[4].resourceID, "R-05");
    strcpy(resourcePtr[4].resourceName, "Multimedia Room");
    strcpy(resourcePtr[4].category, "Laboratory");
    resourcePtr[4].capacity = 25;
}

void displayResourcesUsingPointer() {
    if (resourcePtr == nullptr) {
        cout << "Error: Resource memory has not been allocated.\n";
        return;
    }
    cout << "\n===== CAMPUS RESOURCES =====\n";
    cout << "ID | Resource Name | Category | Capacity\n";
    cout << "-----------------------------------------------------\n";

    for (int i = 0; i < MAX_RESOURCES; i++) {

        CampusResource* current = resourcePtr + i;

        cout << current->resourceID << " | "
             << current->resourceName << " | "
             << current->category << " | "
             << current->capacity << "\n";
    }
}

void displayResourceAddresses() {
    if (resourcePtr == nullptr) {

        cout << "Error: Resource memory has not been allocated.\n";
        return;
    }

    cout << "\n===== MEMORY ADDRESSES =====\n";

    for (int i = 0; i < MAX_RESOURCES; i++) {

        CampusResource* current = resourcePtr + i;

        cout << "Resource " << i + 1
             << " address: " << current << "\n";
    }
}

void deallocateResourceMemory() {
    if (resourcePtr != nullptr) {
        delete[] resourcePtr;
        resourcePtr = nullptr;

        cout << "Dynamic resource memory released successfully.\n";
    }
}

// MATRIX & ALGORITHM
int studentMatrix[NUM_DEPARTMENTS][NUM_RESOURCES];

void initializeMatrix() {
    int sampleData[NUM_DEPARTMENTS][NUM_RESOURCES] = {
        {30, 25, 20, 15},
        {28, 22, 18, 12},
        {25, 20, 15, 10},
        {35, 30, 25, 20}
    };

    for (int i = 0; i < NUM_DEPARTMENTS; i++) {
        for (int j = 0; j < NUM_RESOURCES; j++) {
            studentMatrix[i][j] = sampleData[i][j];
        }
    }
}

void displayMatrix() {
    cout << "\n===== STUDENT MATRIX =====\n";
    cout << "Department | Year 1 | Year 2 | Year 3 | Year 4\n";
    cout << "------------------------------------------------\n";

    for (int i = 0; i < NUM_DEPARTMENTS; i++) {
        cout << "Department " << i + 1 << " | ";

        for (int j = 0; j < NUM_RESOURCES; j++) {
            cout << studentMatrix[i][j] << "      ";
        }

        cout << "\n";
    }
}

void displayRowTotals() {
    cout << "\n===== ROW TOTALS =====\n";

    for (int i = 0; i < NUM_DEPARTMENTS; i++) {
        int total = 0;

        for (int j = 0; j < NUM_RESOURCES; j++) {
            total += studentMatrix[i][j];
        }

        cout << "Department " << i + 1
             << " total students: " << total << "\n";
    }
}

void displayColumnTotals() {
    cout << "\n===== COLUMN TOTALS =====\n";

    for (int j = 0; j < NUM_RESOURCES; j++) {
        int total = 0;

        for (int i = 0; i < NUM_DEPARTMENTS; i++) {
            total += studentMatrix[i][j];
        }

        cout << "Year " << j + 1
             << " total students: " << total << "\n";
    }
}


// VALIDATION FUNCTIONS
bool validateMenuChoice(int choice, int minChoice, int maxChoice) {
    if (choice < minChoice || choice > maxChoice) {
        cout << "Error: Invalid menu choice. "
             << "Please enter a number from "
             << minChoice << " to " << maxChoice << ".\n";
        return false;
    }

    return true;
}

bool validateStudentID(int id) {
    if (id <= 0) {
        cout << "Error: Student ID must be a positive number.\n";
        return false;
    }

    if (id > 999999999) {
        cout << "Error: Student ID is too long.\n";
        return false;
    }

    return true;
}

bool isDuplicateStudentID(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (studentArray[i].studentID == id &&
            studentArray[i].isActive) {

            cout << "Error: Student ID " << id
                 << " already exists.\n";

            return true;
        }
    }

    return false;
}

bool isEmptyField(const char* field, const char* fieldName) {
    if (field == nullptr || strlen(field) == 0) {
        cout << "Error: " << fieldName
             << " cannot be empty.\n";
        return true;
    }

    return false;
}

bool validateNumericInput(const char* input) {
    if (input == nullptr || strlen(input) == 0) {
        cout << "Error: Input cannot be empty.\n";
        return false;
    }

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] < '0' || input[i] > '9') {
            cout << "Error: Please enter numbers only.\n";
            return false;
        }
    }
    return true;
}

bool validateStudentData(
    int id,
    const char* name,
    const char* section,
    const char* yearLevel
) {
    if (!validateStudentID(id)) {
        return false;
    }

    if (isDuplicateStudentID(id)) {
        return false;
    }

    if (isEmptyField(name, "Student name")) {
        return false;
    }

    if (isEmptyField(section, "Section")) {
        return false;
    }

    if (isEmptyField(yearLevel, "Year level")) {
        return false;
    }

    if (!hasCapacity()) {
        cout << "Error: Cannot add student. "
             << "Student array is full.\n";
        return false;
    }

    return true;
}

bool validateStudentUpdate(
    int id,
    const char* newSection,
    const char* newYearLevel
) {
    if (!validateStudentID(id)) {
        return false;
    }

    if (findStudentIndexByID(id) == -1) {
        cout << "Error: Student ID not found.\n";
        return false;
    }

    if (isEmptyField(newSection, "Section")) {
        return false;
    }

    if (isEmptyField(newYearLevel, "Year level")) {
        return false;
    }
    return true;
}

bool validateStudentDeletion(int id) {
    if (!validateStudentID(id)) {
        return false;
    }

    if (findStudentIndexByID(id) == -1) {
        cout << "Error: Student ID not found.\n";
        return false;
    }
    return true;
}



// INT MAIN FUNCTION AND DISPLAY
void displayMainMenu() {
    cout << "\n========================================\n";
    cout << "       CAMPUS MANAGEMENT SYSTEM\n";
    cout << "========================================\n";
    cout << "1. Add Student\n";
    cout << "2. Display Students\n";
    cout << "3. Update Student\n";
    cout << "4. Delete Student\n";
    cout << "5. Allocate Resource Memory\n";
    cout << "6. Initialize Resources\n";
    cout << "7. Display Resources\n";
    cout << "8. Display Resource Addresses\n";
    cout << "9. Display Student Matrix\n";
    cout << "10. Display Department Totals\n";
    cout << "11. Display Year Totals\n";
    cout << "12. Generate System Report\n";
    cout << "13. Deallocate Resource Memory\n";
    cout << "0. Exit\n";
    cout << "========================================\n";
    cout << "Enter your choice: ";
}

  void generateSystemReport() {
    cout << "\n============================================\n";
    cout << "             SYSTEM REPORT\n";
    cout << "============================================\n";
    cout << "\n===== STUDENT SUMMARY =====\n";
    cout << "Total active students: "
         << studentCount << "\n";
    cout << "Available student slots: "
         << MAX_STUDENTS - studentCount << "\n";
    cout << "\n===== STUDENT RECORDS =====\n";

    if (studentCount == 0) {
        cout << "No student records available.\n";
    } else {
        for (int i = 0; i < studentCount; i++) {
            if (studentArray[i].isActive) {
                cout << "ID: "
                     << studentArray[i].studentID
                     << " | Name: "
                     << studentArray[i].name
                     << " | Section: "
                     << studentArray[i].section
                     << " | Year Level: "
                     << studentArray[i].yearLevel
                     << "\n";
            }
        }
    }
    cout << "\n===== RESOURCE SUMMARY =====\n";

    if (resourcePtr == nullptr) {
        cout << "Resource memory has not been allocated.\n";
    } else {
        int totalCapacity = 0;

        for (int i = 0; i < MAX_RESOURCES; i++) {
            totalCapacity += resourcePtr[i].capacity;
        }

        cout << "Total resources: "
             << MAX_RESOURCES << "\n";

        cout << "Total resource capacity: "
             << totalCapacity << "\n";
    }
    cout << "\n===== STUDENT MATRIX SUMMARY =====\n";

    int grandTotal = 0;
    for (int i = 0; i < NUM_DEPARTMENTS; i++) {
        int rowTotal = 0;

        for (int j = 0; j < NUM_RESOURCES; j++) {
            rowTotal += studentMatrix[i][j];
        }

        cout << "Department " << i + 1
             << " total: "
             << rowTotal
             << " students\n";

        grandTotal += rowTotal;
    }

    cout << "Grand total in matrix: "
         << grandTotal
         << " students\n";


}

int main() {
    initializeArray();
    initializeMatrix();

    int choice;
    do {
        displayMainMenu();
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Error: Please enter a valid number.\n";
            continue;
        }

        cin.ignore(1000, '\n');

        if (choice == 0) {
            deallocateResourceMemory();

            cout << "\nThank you for using the "
                 << "Campus Management System.\n";

            cout << "Program terminated successfully.\n";

            break;
        }

        if (!validateMenuChoice(choice, 1, 13)) {
            continue;
        }

        switch (choice) {
                case 1: {
                int id;
                char name[50];
                char section[10];
                char yearLevel[15];

                cout << "\n===== ADD STUDENT =====\n";

                cout << "Enter Student ID: ";
                cin >> id;
                cin.ignore(1000, '\n');

                cout << "Enter Student Name: ";
                cin.getline(name, 50);

                cout << "Enter Section: ";
                cin.getline(section, 10);

                cout << "Enter Year Level: ";
                cin.getline(yearLevel, 15);

                if (validateStudentData(
                        id,
                        name,
                        section,
                        yearLevel)) {

                    if (addStudentToArray(
                            id,
                            name,
                            section,
                            yearLevel)) {

                        cout << "Student added successfully.\n";
                    }
                }

                break;
            }
            case 2: {
                cout << "\n===== STUDENT RECORDS =====\n";

                traverseStudentArray();

                break;
            }
            case 3: {
                int id;
                char newSection[10];
                char newYearLevel[15];

                cout << "\n===== UPDATE STUDENT =====\n";

                cout << "Enter Student ID: ";
                cin >> id;
                cin.ignore(1000, '\n');

                cout << "Enter New Section: ";
                cin.getline(newSection, 10);

                cout << "Enter New Year Level: ";
                cin.getline(newYearLevel, 15);

                if (validateStudentUpdate(
                        id,
                        newSection,
                        newYearLevel)) {

                    if (updateStudentInArray(
                            id,
                            newSection,
                            newYearLevel)) {

                        cout << "Student updated successfully.\n";
                    }
                }

                break;
            }
            case 4: {
                int id;

                cout << "\n===== DELETE STUDENT =====\n";

                cout << "Enter Student ID: ";
                cin >> id;
                cin.ignore(1000, '\n');

                if (validateStudentDeletion(id)) {

                    if (deleteStudentFromArray(id)) {
                        cout << "Student deleted successfully.\n";
                    }
                }

                break;
            }
            case 5: {
                cout << "\n===== ALLOCATE RESOURCE MEMORY =====\n";

                allocateResourceMemory();

                break;
            }
            case 6: {
                cout << "\n===== INITIALIZE RESOURCES =====\n";

                initializeResources();

                break;
            }
            case 7: {
                displayResourcesUsingPointer();

                break;
            }
            case 8: {
                displayResourceAddresses();

                break;
            }
            case 9: {
                displayMatrix();

                break;
            }
            case 10: {
                displayRowTotals();

                break;
            }
            case 11: {
                displayColumnTotals();

                break;
            }
            case 12: {
                generateSystemReport();

                break;
            }
            case 13: {
                deallocateResourceMemory();

                break;
            }
            default:
                cout << "Error: Invalid menu choice.\n";
                break;
        }

    } while (choice != 0);
    return 0;
}
