#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student
{
    int SID;
    string Name;
    string Phone;
    string course;
    double Fee;
    string Remarks;
};

int main()
{
    int n;
    cout << "How many students? ";
    cin >> n;

    ofstream file("Student.txt");

    if (!file)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }

    Student s;

    for (int i = 1; i <= n; i++)
    {
        cout << "\nEnter details for Student " << i << endl;

        cout << "ID: ";
        cin >> s.SID;

        cin.ignore(); // to clear buffer

        cout << "Name: ";
        getline(cin, s.Name);

        cout << "Phone: ";
        getline(cin, s.Phone);

        cout << "Course: ";
        getline(cin, s.course);

        cout << "Fee: ";
        cin >> s.Fee;

        cin.ignore();

        cout << "Remarks: ";
        getline(cin, s.Remarks);

        // Writing to file
        file << "Student " << i << endl;
        file << "ID: " << s.SID << endl;
        file << "Name: " << s.Name << endl;
        file << "Phone: " << s.Phone << endl;
        file << "Course: " << s.course << endl;
        file << "Fee: " << s.Fee << endl;
        file << "Remarks: " << s.Remarks << endl;
        file << "------------------------" << endl;
    }

    file.close();
  
    cout << "\nData saved successfully in Student.txt" << endl;

    return 0;
}