#include <iostream>
using namespace std;

int main() {
    int amount = 93;
    int coins[] = {50, 20, 10, 5, 2, 1};

    cout << "Coins Used: ";

    for (int coin : coins) {
        while (amount >= coin) {
            cout << coin << " ";
            amount -= coin;
        }
    }

    return 0;
}