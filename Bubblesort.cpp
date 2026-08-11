#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};

    // Bubble Sort
    for(int i = 0; i < arr.size() - 1; i++)
    {
        for(int j = 0; j < arr.size() - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    // Print sorted array
    for(int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}