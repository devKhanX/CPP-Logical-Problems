#include <iostream>
#include <string>
using namespace std;
int main()
{
    string string1, string2;
    string1 = "abcd";
    string2 = "ef";
    cout<<string1.size()<<" "<<string2.size()<<endl;
    cout << string1 + string2 << endl;
    swap(string1[0], string2[0]);
    cout<<string1<< " " <<string2<<endl;
    return 0;
}
