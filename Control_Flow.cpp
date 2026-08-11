#include <iostream>
using namespace std;

int main() {
    int n, choice;

    cout << "Enter a number (to print 1 to n): ";
    cin >> n;

    cout << "\nChoose a loop:\n";
    cout << "1. For Loop\n";
    cout << "2. While Loop\n";
    cout << "3. Do-While Loop\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "\n--- Using for loop ---\n";
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            break;

        case 2: {
            cout << "\n--- Using while loop ---\n";
            int i = 1;
            while (i <= n) {
                cout << i << " ";
                i++;
            }
            break;
        }

        case 3: {
            cout << "\n--- Using do-while loop ---\n";
            int i = 1;
            do {
                cout << i << " ";
                i++;
            } while (i <= n);
            break;
        }

        default:
            cout << "Invalid choice!";
    }

    cout << endl;
    return 0;
}