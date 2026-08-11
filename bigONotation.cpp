#include <iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50,60,70,80,90,100};
    int key= 50;
    for(int i=0;i<5;i++)
    {
        if(arr[i]==key)
        {
            cout<<"Found";
            break;
        }
    }
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    int smallest = arr[0];

    for(int i=1;i<5;i++)
    {
        if(arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    cout<<"Smallest value: "<<smallest;
    return 0;
}

#include <iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    int n = 5;

    // Sort the array first (needed to find median correctly)
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Find median
    if(n % 2 != 0)
    {
        cout<<"Median: "<<arr[n/2];
    }
    else
    {
        cout<<"Median: "<<(arr[n/2 - 1] + arr[n/2]) / 2.0;
    }

    return 0;
}