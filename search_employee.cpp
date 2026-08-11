#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream file("Student.txt");

    if (!file)
    {
        cout << "File not found!" << endl;
        return 0;
    }

    int searchID;
    cout << "Enter Student ID: ";
    cin >> searchID;

    string line;
    bool found = false;

    while (getline(file, line))
    {
        // Find the ID line
        if (line.find("ID:") != string::npos)
        {
            int id = stoi(line.substr(line.find(":") + 1));

            // Read the next lines
            string name, phone, course, fee, remarks;

            getline(file, name);
            getline(file, phone);
            getline(file, course);
            getline(file, fee);
            getline(file, remarks);

            if (id == searchID)
            {
                found = true;

                cout << "\n===== STUDENT FOUND =====\n";
                cout << "ID: " << id << endl;
                cout << name << endl;
                cout << phone << endl;
                cout << course << endl;
                cout << fee << endl;
                cout << remarks << endl;

                break;
            }
        }
    }

    if (!found)
    {
        cout << "Student not found." << endl;
    }

    file.close();

    return 0;
}