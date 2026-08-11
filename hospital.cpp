#include <iostream>
#include <vector>
using namespace std;

//----------------------------------------------------------
// Item Information
//----------------------------------------------------------
vector<int> weight = {4, 5, 3, 2, 6};
vector<int> profit = {500, 600, 350, 200, 700};

int n = weight.size();

//----------------------------------------------------------
// Memoization Table
// memo[item][capacity]
// -1 means "Not Computed Yet"
//----------------------------------------------------------
vector<vector<int>> memo;

//----------------------------------------------------------
// Recursive Knapsack with Memoization
//----------------------------------------------------------
int knapsack(int item, int remainingCapacity)
{
    cout << "\nCall -> knapsack("
         << item << ", "
         << remainingCapacity << ")";

    //------------------------------------------------------
    // Base Case
    //------------------------------------------------------
    if (item == n || remainingCapacity == 0)
    {
        cout << " --> Base Case\n";
        return 0;
    }

    //------------------------------------------------------
    // Cache Hit
    //------------------------------------------------------

    if (memo[item][remainingCapacity] != -1)
    {
        cout << "\n*** CACHE HIT ***\n";
        cout << "Returning previously computed value = "
             << memo[item][remainingCapacity] << endl;

        return memo[item][remainingCapacity];
    }

    //------------------------------------------------------
    // First Time Computation
    //------------------------------------------------------
    cout << "\nComputing State (Item="
         << item
         << ", Capacity="
         << remainingCapacity
         << ")\n";

    //------------------------------------------------------
    // Option 1 : Skip current item
    //------------------------------------------------------
    int skip =
        knapsack(item + 1, remainingCapacity);

    //------------------------------------------------------
    // Option 2 : Take current item
    //------------------------------------------------------
    int take = 0;

    if (weight[item] <= remainingCapacity)
    {
        take =
            profit[item] +
            knapsack(item + 1,
                     remainingCapacity - weight[item]);
    }

    //------------------------------------------------------
    // Store Best Result
    //------------------------------------------------------
    memo[item][remainingCapacity] =
        max(skip, take);

    cout << "Stored memo["
         << item
         << "]["
         << remainingCapacity
         << "] = "
         << memo[item][remainingCapacity]
         << endl;

    return memo[item][remainingCapacity];
}

//----------------------------------------------------------
// Driver
//----------------------------------------------------------
int main()
{
    int capacity = 10;

    memo.assign(n,
                vector<int>(capacity + 1, -1));

    cout << "==============================\n";
    cout << " Delivery Drone Optimization\n";
    cout << "==============================\n\n";

    cout << "Drone Capacity : "
         << capacity
         << " kg\n\n";

    cout << "Items Available\n\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Item "
             << i
             << "  Weight="
             << weight[i]
             << "kg"
             << "  Profit=£"
             << profit[i]
             << endl;
    }

    cout << "\n========== Program Execution ==========\n";

    int answer =
        knapsack(0, capacity);

    cout << "\n=======================================\n";
    cout << "Maximum Profit = £"
         << answer
         << endl;

    //------------------------------------------------------
    // Print Memo Table
    //------------------------------------------------------
    cout << "\nMemoization Table\n\n";

    for (int i = 0; i < n; i++)
    {
        for (int c = 0; c <= capacity; c++)
        {
            if (memo[i][c] == -1)
                cout << "  - ";
            else
                cout << memo[i][c] << " ";
        }

        cout << endl;
    }

    return 0;
}