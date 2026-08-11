#include<iostream>
using namespace std;
 int main()
 {
    int studentID[]= {101, 102, 103, 104, 105};
    int target = 105;
    bool found = false;
    for(int i=0;i<5;i++)
    {
        if(studentID[i]==target)
        {
            cout<<"Student Found at Position"<<i+1<<endl;
            found = true;
            break;
        }
    }
    if(!found)
    
        cout<<"Student Not Found";
        return 0;
    
 }