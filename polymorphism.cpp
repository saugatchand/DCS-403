#include <iostream>
using namespace std;
// ===== Base class =====
class Employee
{
    public:
    virtual void calaculateSalary(){
        cout <<"Employee Salary" << endl;
    }
    virtual ~Employee(){} 
};
// ===== Permanent Employee =====
class PermanentEmployee : public Employee
{
    double basic = 50000;
    double hra = 12000;
    public:
    void calaculateSalary() override
     {
        cout << "Permanent Employee Salary = "
                << basic + hra << endl;
     }
};

// ===== Contract Employee =====
class ContractEmployee : public Employee
{
    double hourlyRate = 500;
    int hours = 160;
    public:
    void calaculateSalary() override
     {
        cout << "Contract Employee Salary = "
                << hourlyRate * hours << endl;
     }
    };

    //======Sales Employee =====
class SalesEmployee : public Employee
{
    double basic = 300000;
    double commission = 15000;
    public:
    void calaculateSalary() override
     {
        cout << "Sales Employee Salary = "
                << basic + commission << endl;
     }
};
    