#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Step 2: Create Student Structure
struct Student
{
    int id;
    string name;
    string address;
    string phone;
    string mobile;
};

// Step 3: Declare Global Stack
stack<Student> students;

// Step 4: Add New Record
void addStudent()
{
    Student s;

    cout << "\nEnter Student ID : ";
    cin >> s.id;

    cin.ignore();

    cout << "Enter Name : ";
    getline(cin, s.name);

    cout << "Enter Address : ";
    getline(cin, s.address);

    cout << "Enter Phone : ";
    getline(cin, s.phone);

    cout << "Enter Mobile : ";
    getline(cin, s.mobile);

    students.push(s);

    cout << "\nRecord Added Successfully.\n";
}

// Step 5: Delete Top Record
void deleteTopRecord()
{
    if (students.empty())
    {
        cout << "\nStack is Empty.\n";
        return;
    }

    students.pop();

    cout << "\nTop Record Deleted Successfully.\n";
}

// Step 6: Display All Records
void displayAll()
{
    if (students.empty())
    {
        cout << "\nNo Records Found.\n";
        return;
    }

    stack<Student> temp = students;

    cout << "\n----- Student Records -----\n";

    while (!temp.empty())
    {
        Student s = temp.top();

        cout << "\nID      : " << s.id << endl;
        cout << "Name    : " << s.name << endl;
        cout << "Address : " << s.address << endl;
        cout << "Phone   : " << s.phone << endl;
        cout << "Mobile  : " << s.mobile << endl;
        cout << "--------------------------\n";

        temp.pop();
    }
}

// Step 7: Display Record By ID
void displayByID()
{
    if (students.empty())
    {
        cout << "\nNo Records Found.\n";
        return;
    }

    int id;

    cout << "\nEnter Student ID : ";
    cin >> id;

    stack<Student> temp = students;
    bool found = false;

    while (!temp.empty())
    {
        Student s = temp.top();

        if (s.id == id)
        {
            cout << "\nRecord Found\n";
            cout << "ID      : " << s.id << endl;
            cout << "Name    : " << s.name << endl;
            cout << "Address : " << s.address << endl;
            cout << "Phone   : " << s.phone << endl;
            cout << "Mobile  : " << s.mobile << endl;

            found = true;
            break;
        }

        temp.pop();
    }

    if (!found)
    {
        cout << "\nRecord Not Found.\n";
    }
}

// Step 8: Delete Record By ID
void deleteByID()
{
    if (students.empty())
    {
        cout << "\nNo Records Found.\n";
        return;
    }

    int id;

    cout << "\nEnter Student ID : ";
    cin >> id;

    stack<Student> temp;
    bool found = false;

    while (!students.empty())
    {
        Student s = students.top();
        students.pop();

        if (s.id == id)
        {
            found = true;
            continue;
        }

        temp.push(s);
    }

    while (!temp.empty())
    {
        students.push(temp.top());
        temp.pop();
    }

    if (found)
    {
        cout << "\nRecord Deleted Successfully.\n";
    }
    else
    {
        cout << "\nRecord Not Found.\n";
    }
}

// Step 9: Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n==============================";
        cout << "\n Student Management (Stack)";
        cout << "\n==============================";
        cout << "\n1. Add Student";
        cout << "\n2. Delete Top Record";
        cout << "\n3. Display All Records";
        cout << "\n4. Display By ID";
        cout << "\n5. Delete By ID";
        cout << "\n6. Exit";

        cout << "\n\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            deleteTopRecord();
            break;

        case 3:
            displayAll();
            break;

        case 4:
            displayByID();
            break;

        case 5:
            deleteByID();
            break;

        case 6:
            cout << "\nProgram Ended.\n";
            break;

        default:
            cout << "\nInvalid Choice.\n";
        }

    } while (choice != 6);

    return 0;
}