//==============Using Pointers======================

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

// -------------------- DATA MODEL --------------------
struct Employee {
    int EmpID;
    char Name[50];
    char Address[100];
    char Phone[15];
    char Department[30];
    double Salary;
    char Remarks[100];
};

// -------------------- MANAGER CLASS --------------------

class EmployeeManager {
private:
    Employee* empArray[MAX_EMPLOYEES];  // Array of POINTERS to Employee records
    int count;                          // Number of records currently stored

public:
    EmployeeManager() : count(0) {
        for (int i = 0; i < MAX_EMPLOYEES; i++)
            empArray[i] = nullptr;      // Initialize all pointers to null
    }

    // Destructor: free every heap-allocated record to avoid memory leaks
    ~EmployeeManager() {
        for (int i = 0; i < count; i++) {
            delete empArray[i];
        }
    }

    // -------------------- 1. ADD EMPLOYEE (using pointer) --------------------
    void AddEmployee(int id, const char* name, const char* address,
                      const char* phone, const char* dept, double salary,
                      const char* remarks) 
    {
        if (count >= MAX_EMPLOYEES) {
            cout << "Employee storage full!\n";
            return;
        }

        Employee* newEmp = new Employee();   // Dynamically allocate on heap
        newEmp->EmpID = id;
        strcpy(newEmp->Name, name);
        strcpy(newEmp->Address, address);
        strcpy(newEmp->Phone, phone);
        strcpy(newEmp->Department, dept);
        newEmp->Salary = salary;
        strcpy(newEmp->Remarks, remarks);

        empArray[count] = newEmp;            // Store the pointer
        count++;

        cout << "[ADD] Employee " << id << " added successfully.\n";
    }

    // Helper: find and return a POINTER to the matching employee record
    Employee* FindEmployee(int id) {
        for (int i = 0; i < count; i++) {
            if (empArray[i]->EmpID == id) {
                return empArray[i];          // Return pointer, not a copy
            }
        }
        return nullptr;                      // Not found
    }

    // -------------------- 2. UPDATE EMPLOYEE (using pointer) --------------------
    void UpdateEmployee(int id, double newSalary, const char* newRemarks) {
        Employee* emp = FindEmployee(id);    // Get pointer to the record
        if (emp == nullptr) {
            cout << "[UPDATE] Employee ID " << id << " not found.\n";
            return;
        }
        emp->Salary = newSalary;             // Modify directly via pointer
        strcpy(emp->Remarks, newRemarks);
        cout << "[UPDATE] Employee " << id << " updated successfully.\n";
    }

    // -------------------- 3. DELETE EMPLOYEE (using pointer) --------------------
    void DeleteEmployee(int id) {
        int index = -1;
        for (int i = 0; i < count; i++) {
            if (empArray[i]->EmpID == id) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "[DELETE] Employee ID " << id << " not found.\n";
            return;
        }

        delete empArray[index];              // Free heap memory
        empArray[index] = nullptr;

        // Shift remaining pointers left to close the gap
        for (int i = index; i < count - 1; i++) {
            empArray[i] = empArray[i + 1];
        }
        empArray[count - 1] = nullptr;
        count--;

        cout << "[DELETE] Employee " << id << " deleted successfully.\n";
    }

    // -------------------- 4. VIEW ALL EMPLOYEES (using pointer) --------------------
    void ViewAllEmployees() {
        if (count == 0) {
            cout << "No employee records found.\n";
            return;
        }

        cout << "\n" << left
             << setw(8)  << "EmpID"
             << setw(16) << "Name"
             << setw(20) << "Address"
             << setw(14) << "Phone"
             << setw(12) << "Department"
             << setw(10) << "Salary"
             << setw(20) << "Remarks" << "\n";
        cout << string(100, '-') << "\n";

        for (int i = 0; i < count; i++) {
            Employee* p = empArray[i];       // Pointer to current record
            cout << left
                 << setw(8)  << p->EmpID
                 << setw(16) << p->Name
                 << setw(20) << p->Address
                 << setw(14) << p->Phone
                 << setw(12) << p->Department
                 << setw(10) << p->Salary
                 << setw(20) << p->Remarks << "\n";
        }
    }

    // -------------------- 5. VIEW EMPLOYEE BY EMPID (using pointer) --------------------
    void ViewEmployeeByID(int id) {
        Employee* emp = FindEmployee(id);    // Pointer to the found record
        if (emp == nullptr) {
            cout << "[VIEW] Employee ID " << id << " not found.\n";
            return;
        }

        cout << "\n--- Employee Details (ID: " << id << ") ---\n";
        cout << "EmpID      : " << emp->EmpID << "\n";
        cout << "Name       : " << emp->Name << "\n";
        cout << "Address    : " << emp->Address << "\n";
        cout << "Phone      : " << emp->Phone << "\n";
        cout << "Department : " << emp->Department << "\n";
        cout << "Salary     : " << emp->Salary << "\n";
        cout << "Remarks    : " << emp->Remarks << "\n";
    }
};

// -------------------- MAIN: DUMMY DATA DEMONSTRATION --------------------
int main() {
    EmployeeManager manager;

    cout << "=== Adding Dummy Employees ===\n";
    manager.AddEmployee(101, "Rajesh Sharma", "Kathmandu", "9800000001", "IT", 55000, "Good performer");
    manager.AddEmployee(102, "Sita Koirala", "Pokhara", "9800000002", "HR", 48000, "Punctual");
    manager.AddEmployee(103, "Anil Gurung", "Lalitpur", "9800000003", "Finance", 62000, "Needs training");
    manager.AddEmployee(104, "Maya Tamang", "Bhaktapur", "9800000004", "IT", 51000, "Reliable");

    cout << "\n=== View All Employees ===\n";
    manager.ViewAllEmployees();

    cout << "\n=== View Employee by ID (102) ===\n";
    manager.ViewEmployeeByID(102);

    cout << "\n=== Update Employee (102) ===\n";
    manager.UpdateEmployee(102, 52000, "Promoted to Senior HR");
    manager.ViewEmployeeByID(102);

    cout << "\n=== Delete Employee (101) ===\n";
    manager.DeleteEmployee(101);

    cout << "\n=== View All Employees After Deletion ===\n";
    manager.ViewAllEmployees();

    cout << "\n=== Attempt to View Deleted Employee (101) ===\n";
    manager.ViewEmployeeByID(101);

    return 0;
}