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

// POSITION 2: DATA STRUCTURE DEVELOPER -- array init

// POSITION 2: DATA STRUCTURE DEVELOPER -- bounds check helper

// POSITION 2: DATA STRUCTURE DEVELOPER -- insertion

// POSITION 2: DATA STRUCTURE DEVELOPER -- traversal (O(n))

// POSITION 2: DATA STRUCTURE DEVELOPER -- linear search (Requirement 4, O(n))

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
