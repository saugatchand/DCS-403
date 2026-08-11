#include <iostream>
#include <string>
using namespace std;

// Structure Definition
struct Employee {
    int id;
    string Name;
    string Address;
    string Phone;
    string Department;
    double salary;
    string Remarks;
};

// Function Prototypes
void disp();
void AddNewEmployee();

int main() {
    cout << "===== Existing Employee =====" << endl;
    disp();

    cout << "\n===== Add New Employee =====" << endl;
    AddNewEmployee();

    return 0;
}

void disp() {
    Employee emp1;

    emp1.id = 101;
    emp1.Name = "Prasun";
    emp1.Address = "Harisiddhi, Lalitpur";
    emp1.Phone = "9848900000";
    emp1.Department = "Sales";
    emp1.salary = 50000.0;
    emp1.Remarks = "Excellent performance";

    cout << "Employee ID: " << emp1.id << endl;
    cout << "Employee Name: " << emp1.Name << endl;
    cout << "Employee Address: " << emp1.Address << endl;
    cout << "Employee Phone: " << emp1.Phone << endl;
    cout << "Employee Department: " << emp1.Department << endl;
    cout << "Employee Salary: " << emp1.salary << endl;
    cout << "Employee Remarks: " << emp1.Remarks << endl;
}

// Function to add a new employee
void AddNewEmployee() {
    Employee emp2;

    cout << "Enter Employee ID: ";
    cin >> emp2.id;
    cin.ignore();

    cout << "Enter Employee Name: ";
    getline(cin, emp2.Name);

    cout << "Enter Employee Address: ";
    getline(cin, emp2.Address);

    cout << "Enter Employee Phone: ";
    getline(cin, emp2.Phone);

    cout << "Enter Employee Department: ";
    getline(cin, emp2.Department);

    cout << "Enter Employee Salary: ";
    cin >> emp2.salary;
    cin.ignore();

    cout << "Enter Employee Remarks: ";
    getline(cin, emp2.Remarks);

    cout << "\n===== New Employee Details =====" << endl;
    cout << "Employee ID: " << emp2.id << endl;
    cout << "Employee Name: " << emp2.Name << endl;
    cout << "Employee Address: " << emp2.Address << endl;
    cout << "Employee Phone: " << emp2.Phone << endl;
    cout << "Employee Department: " << emp2.Department << endl;
    cout << "Employee Salary: " << emp2.salary << endl;
    cout << "Employee Remarks: " << emp2.Remarks << endl;
}
