/*
    Employee Record Management System
    ----------------------------------
    Demonstrates the use of POINTERS in C++ for:
    1. Add Employee
    2. Update Employee
    3. Delete Employee
    4. View All Employees
    5. View Employee by EmpID

    Author: Expert C++ Demo
*/

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

const int MAX_EMPLOYEES = 100;

// ------------------- DATA MODEL -------------------
struct Employee {
    int EmpID;
    char Name[50];
    char Address[100];
    char Department[50];
    double Salary;
    bool isActive;   // tells whether this record slot is in use
};

// ------------------- GLOBALS -------------------
Employee empList[MAX_EMPLOYEES];   // array of employees (accessed via pointers)
int empCount = 0;                  // number of slots currently used (including deleted/inactive)

// ------------------- FUNCTION PROTOTYPES -------------------
void addEmployee(Employee *arr, int &count);
void updateEmployee(Employee *arr, int count);
void deleteEmployee(Employee *arr, int count);
void viewAllEmployees(const Employee *arr, int count);
void viewEmployeeByID(const Employee *arr, int count);
Employee* findEmployeeByID(Employee *arr, int count, int id);
void showMenu();

// ------------------- MAIN -------------------
int main() {
    int choice;

    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee(empList, empCount);
                break;
            case 2:
                updateEmployee(empList, empCount);
                break;
            case 3:
                deleteEmployee(empList, empCount);
                break;
            case 4:
                viewAllEmployees(empList, empCount);
                break;
            case 5:
                viewEmployeeByID(empList, empCount);
                break;
            case 0:
                cout << "\nExiting the program. Goodbye!\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}

// ------------------- MENU -------------------
void showMenu() {
    cout << "\n==========================================\n";
    cout << "     EMPLOYEE RECORD MANAGEMENT SYSTEM\n";
    cout << "==========================================\n";
    cout << "1. Add Employee\n";
    cout << "2. Update Employee\n";
    cout << "3. Delete Employee\n";
    cout << "4. View All Employees\n";
    cout << "5. View Employee by EmpID\n";
    cout << "0. Exit\n";
    cout << "==========================================\n";
}

// ------------------- ADD EMPLOYEE -------------------
void addEmployee(Employee *arr, int &count) {
    if (count >= MAX_EMPLOYEES) {
        cout << "\nEmployee list is full! Cannot add more records.\n";
        return;
    }

    // pointer to the next free slot
    Employee *newEmp = arr + count;

    cout << "\n--- Add New Employee ---\n";
    cout << "Enter Employee ID: ";
    cin >> newEmp->EmpID;

    // check for duplicate ID
    if (findEmployeeByID(arr, count, newEmp->EmpID) != nullptr) {
        cout << "An employee with this ID already exists!\n";
        return;
    }

    cin.ignore();
    cout << "Enter Name: ";
    cin.getline(newEmp->Name, 50);

    cout << "Enter Address: ";
    cin.getline(newEmp->Address, 100);

    cout << "Enter Department: ";
    cin.getline(newEmp->Department, 50);

    cout << "Enter Salary: ";
    cin >> newEmp->Salary;

    newEmp->isActive = true;
    count++;

    cout << "\nEmployee added successfully!\n";
}

// ------------------- FIND EMPLOYEE (helper, returns pointer) -------------------
Employee* findEmployeeByID(Employee *arr, int count, int id) {
    for (int i = 0; i < count; i++) {
        Employee *cur = arr + i;   // pointer arithmetic
        if (cur->isActive && cur->EmpID == id) {
            return cur;
        }
    }
    return nullptr;
}

// ------------------- UPDATE EMPLOYEE -------------------
void updateEmployee(Employee *arr, int count) {
    int id;
    cout << "\n--- Update Employee ---\n";
    cout << "Enter Employee ID to update: ";
    cin >> id;

    Employee *emp = findEmployeeByID(arr, count, id);

    if (emp == nullptr) {
        cout << "Employee with ID " << id << " not found!\n";
        return;
    }

    cin.ignore();
    cout << "Enter new Name: ";
    cin.getline(emp->Name, 50);

    cout << "Enter new Address: ";
    cin.getline(emp->Address, 100);

    cout << "Enter new Department: ";
    cin.getline(emp->Department, 50);

    cout << "Enter new Salary: ";
    cin >> emp->Salary;

    cout << "\nEmployee record updated successfully!\n";
}

// ------------------- DELETE EMPLOYEE -------------------
void deleteEmployee(Employee *arr, int count) {
    int id;
    cout << "\n--- Delete Employee ---\n";
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    Employee *emp = findEmployeeByID(arr, count, id);

    if (emp == nullptr) {
        cout << "Employee with ID " << id << " not found!\n";
        return;
    }

    emp->isActive = false;   // soft delete via pointer
    cout << "\nEmployee record deleted successfully!\n";
}

// ------------------- VIEW ALL EMPLOYEES -------------------
void viewAllEmployees(const Employee *arr, int count) {
    cout << "\n--- All Employees ---\n";

    bool found = false;
    for (int i = 0; i < count; i++) {
        const Employee *cur = arr + i;
        if (cur->isActive) {
            found = true;
            cout << "----------------------------------------\n";
            cout << "EmpID      : " << cur->EmpID << "\n";
            cout << "Name       : " << cur->Name << "\n";
            cout << "Address    : " << cur->Address << "\n";
            cout << "Department : " << cur->Department << "\n";
            cout << "Salary     : " << fixed << setprecision(2) << cur->Salary << "\n";
        }
    }

    if (!found) {
        cout << "No employee records found.\n";
    }
    cout << "----------------------------------------\n";
}

// ------------------- VIEW EMPLOYEE BY EMPID -------------------
void viewEmployeeByID(const Employee *arr, int count) {
    int id;
    cout << "\n--- View Employee by EmpID ---\n";
    cout << "Enter Employee ID: ";
    cin >> id;

    const Employee *emp = findEmployeeByID(const_cast<Employee*>(arr), count, id);

    if (emp == nullptr) {
        cout << "Employee with ID " << id << " not found!\n";
        return;
    }

    cout << "----------------------------------------\n";
    cout << "EmpID      : " << emp->EmpID << "\n";
    cout << "Name       : " << emp->Name << "\n";
    cout << "Address    : " << emp->Address << "\n";
    cout << "Department : " << emp->Department << "\n";
    cout << "Salary     : " << fixed << setprecision(2) << emp->Salary << "\n";
    cout << "----------------------------------------\n";
}
