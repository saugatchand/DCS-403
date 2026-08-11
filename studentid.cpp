#include <iostream>
#include <iomanip>
using namespace std;

class Node
{
public:
    int studentID;
    string studentName;
    float grade;
    Node *next;

    Node(int id, string name, float g)
    {
        studentID = id;
        studentName = name;
        grade = g;
        next = NULL;
    }
};

//step 2
class StudentList
{
private:
    Node *head;

public:
    StudentList()
    {
        head = NULL;
    }

    void insertStudent(int id, string name, float grade);

    void displayStudents();

    void searchStudent(int id);

    void averageGrade();
};

//step 3 Step 3: Insert a New Student (Insert at End)
void StudentList::insertStudent(int id, string name, float grade)
{
    Node *newNode = new Node(id, name, grade);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

///Step 4: Display All Students

void StudentList::displayStudents()
{
    if(head == NULL)
    {
        cout << "\nNo student records available.\n";
        return;
    }

    Node *temp = head;



    cout << "\n----------------------------------------------\n";
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Grade" << endl;
    cout << "----------------------------------------------\n";

    while(temp != NULL)
    {
        cout << left
             << setw(10) << temp->studentID
             << setw(20) << temp->studentName
             << setw(10) << temp->grade << endl;

        temp = temp->next;
    }
}
//Step 5: Search a Student

void StudentList::searchStudent(int id)
{
    Node *temp = head;

    while(temp != NULL)
    {
        if(temp->studentID == id)
        {
            cout << "\nStudent Found\n";
            cout << "ID    : " << temp->studentID << endl;
            cout << "Name  : " << temp->studentName << endl;
            cout << "Grade : " << temp->grade << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "\nStudent Not Found.\n";
}
////Step 6: Calculate Average Grade

void StudentList::averageGrade()
{
    if(head == NULL)
    {
        cout << "\nNo records.\n";
        return;
    }

    Node *temp = head;

    float sum = 0;
    int count = 0;

    while(temp != NULL)
    {
        sum += temp->grade;
        count++;

        temp = temp->next;
    }

    cout << "\nAverage Grade = "
         << sum / count << endl;
}

////////Step 7: Main Function

int main()
{
    StudentList students;

    students.insertStudent(101, "Alice", 88.5);
    students.insertStudent(102, "Bob", 75.0);
    students.insertStudent(103, "Charlie", 91.5);
    students.insertStudent(104, "David", 82.0);

    students.displayStudents();

    students.searchStudent(103);

    students.averageGrade();

    return 0;
}