#include <iostream>
#include <string>
using namespace std;

int main() {
    string products[]= {"Apple", "Banana", "Orange", "Grapes", "Mango"};
    string target = "Grapes";
    for (int i = 0; i < 5; i++)\
     {
        if (products[i] == target)
         {
            cout << "Product Found at Position: " << i + 1;
            break;
         }
        }
            return 0;
        }