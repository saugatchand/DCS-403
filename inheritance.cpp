#include <iostream>
#include <string>
using namespace std;

// Base class
class Employee
{
protected:
    string empname;
    int employeeID;
    string phone;
    string address;
    string mobile;
    double salary;

public:
    void getBasicInfo()
    {
        cout << "Enter Employee Name: ";
        getline(cin, empname);

        cout << "Enter Employee ID: ";
        cin >> employeeID;
        cin.ignore();

        cout << "Enter Phone Number: ";
        getline(cin, phone);

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter Mobile Number: ";
        getline(cin, mobile);

        cout << "Enter Salary: ";
        cin >> salary;
        cin.ignore();
    }

    void displayBasicInfo()
    {
        cout << "\n========== BASIC INFORMATION ==========\n";
        cout << "Employee Name : " << empname << endl;
        cout << "Employee ID   : " << employeeID << endl;
        cout << "Phone Number  : " << phone << endl;
        cout << "Address       : " << address << endl;
        cout << "Mobile Number : " << mobile << endl;
        cout << "Salary        : " << salary << endl;
    }
};

// Derived class
class EmployeeDetails : public Employee
{
private:
    string department;
    double commission;
    string email;
    string nidNumber;

public:
    void getAdditionalInfo()
    {
        cout << "Enter Department: ";
        getline(cin, department);

        cout << "Enter Commission: ";
        cin >> commission;
        cin.ignore();

        cout << "Enter Email: ";
        getline(cin, email);

        cout << "Enter National ID No.: ";
        getline(cin, nidNumber);
    }

    double totalSalary()
    {
        return salary + commission;
    }

    void displayCompleteInfo()
    {
        displayBasicInfo();

        cout << "\n====== ADDITIONAL INFORMATION ======\n";
        cout << "Department     : " << department << endl;
        cout << "Commission     : " << commission << endl;
        cout << "Email          : " << email << endl;
        cout << "National ID No.: " << nidNumber << endl;
        cout << "Total Salary   : " << totalSalary() << endl;
    }
};

// Main function
int main()
{
    EmployeeDetails emp;

    cout << "======== EMPLOYEE INFORMATION SYSTEM ========\n\n";

    emp.getBasicInfo();

    cout << endl;

    emp.getAdditionalInfo();

    cout << "\n\n";

    emp.displayCompleteInfo();

    return 0;
}