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

// POSITION 2: DATA STRUCTURE DEVELOPER -- update

// POSITION 2: DATA STRUCTURE DEVELOPER -- deletion (shift-left)

// POSITION 3: MEMORY & POINTER DEVELOPER -- ADT (CampusResource struct)

// POSITION 3: MEMORY & POINTER DEVELOPER -- pointer declaration

// POSITION 3: MEMORY & POINTER DEVELOPER -- dynamic allocation (new)

// POSITION 3: MEMORY & POINTER DEVELOPER -- access via pointer

// POSITION 3: MEMORY & POINTER DEVELOPER -- display via pointer arithmetic

// POSITION 3: MEMORY & POINTER DEVELOPER -- deallocation (delete, memory-leak prevention)

// POSITION 4: MATRIX & ALGORITHM DEVELOPER -- 2D array declaration

// POSITION 4: MATRIX & ALGORITHM DEVELOPER -- matrix init with sample data

// POSITION 4: MATRIX & ALGORITHM DEVELOPER -- matrix operation: display

// POSITION 4: MATRIX & ALGORITHM DEVELOPER -- matrix operation: row totals (O(n^2))

// POSITION 4: MATRIX & ALGORITHM DEVELOPER -- matrix operation: column totals

// POSITION 5: DOCUMENTATION & QA LEAD -- validate menu choice

// POSITION 5: DOCUMENTATION & QA LEAD -- validate student ID format

// POSITION 5: DOCUMENTATION & QA LEAD -- duplicate check

// POSITION 5: DOCUMENTATION & QA LEAD -- empty-field check

// POSITION 5: DOCUMENTATION & QA LEAD -- numeric input validation

// POSITION 5: DOCUMENTATION & QA LEAD -- validation wrapper

// POSITION 1: PROJECT LEAD / SYSTEM INTEGRATOR -- menu display

// POSITION 1: PROJECT LEAD / SYSTEM INTEGRATOR -- report generation

// POSITION 1: PROJECT LEAD / SYSTEM INTEGRATOR -- main() + menu loop
