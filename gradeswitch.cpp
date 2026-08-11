#include <iostream>
using namespace std;

// Function using switch statement
void gradeUsingSwitch(int marks) {
    cout << "\n--- Using switch ---\n";
    cout << "Marks: " << marks << " => Grade: ";

    // Convert marks into grade band
    int band = marks / 10;

    switch (band) {
        case 10:
        case 9:
            cout << "A+ (Outstanding)";
            break;
        case 8:
            cout << "A (Excellent)";
            break;
        case 7:
            cout << "B+ (Very Good)";
            break;
        case 6:
            cout << "B (Good)";
            break;
        case 5:
            cout << "C+ (Above Average)";
            break;
        case 4:
            cout << "C (Average)";
            break;
        case 3:
            cout << "D (Pass)";
            break;
        case 2:
        case 1:
        case 0:
            cout << "F (Fail)";
            break;
        default:
            cout << "Invalid marks entered!";
    }

    cout << endl;
}

int main() {
    int marks;

    cout << "Enter marks (0-100): ";
    cin >> marks;

    gradeUsingSwitch(marks);

    return 0;
}