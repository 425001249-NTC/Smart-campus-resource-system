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

// POSITION 3: MEMORY & POINTER DEVELOPER
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

// POSITION 4: MATRIX & ALGORITHM DEVELOPER
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


// POSITION 5: DOCUMENTATION & QA LEAD -- validate menu choice

// POSITION 5: DOCUMENTATION & QA LEAD -- validate student ID format

// POSITION 5: DOCUMENTATION & QA LEAD -- duplicate check

// POSITION 5: DOCUMENTATION & QA LEAD -- empty-field check

// POSITION 5: DOCUMENTATION & QA LEAD -- numeric input validation

// POSITION 5: DOCUMENTATION & QA LEAD -- validation wrapper

// POSITION 1: PROJECT LEAD / SYSTEM INTEGRATOR -- menu display

// POSITION 1: PROJECT LEAD / SYSTEM INTEGRATOR -- report generation

// POSITION 1: PROJECT LEAD / SYSTEM INTEGRATOR -- main() + menu loop
