#include <iostream>
using namespace std;
void printPattern(int n) 
{ 
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++) 
        {
            cout << "*";
        }
        for (int j = 0; j < n - i - 1; j++) 
        {
            cout << " ";
        }
        cout << endl;
    }
}
int main() 
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n; 
    printPattern(n);   
    return 0; 
}
