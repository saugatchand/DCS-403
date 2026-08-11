#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNo;
    string name;
    double balance;

public:
    void createAccount()
    {
        accountNo = 123456;
        name = "Riya Ojha";
        balance = 25000.0;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient Balance!" << endl;
    }

    void display()
    {
        cout << "Account No: " << accountNo << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount customer;

    customer.createAccount();
    customer.deposit(2000);
    customer.withdraw(1000);

    customer.display();

    return 0;
}