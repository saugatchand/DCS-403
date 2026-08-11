#include <iostream>
using namespace std;

int main() {
    int numbers[] = {5, 7, 11, 14, 20};

    // Using for loop
    cout << "--- Using for loop ---" << endl;
    for (int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl << endl;

    // Using while loop
    cout << "--- Using while loop ---" << endl;
    int i = 0;
    while (i < 5) {
        cout << numbers[i] << " ";
        i++;
    }
    cout << endl << endl;

    // Using do-while loop
    cout << "--- Using do-while loop ---" << endl;
    i = 0;
    do {
        cout << numbers[i] << " ";
        i++;
    } while (i < 5);
    cout << endl;

    return 0;
}