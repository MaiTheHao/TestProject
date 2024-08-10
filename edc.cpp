#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name = "test";
    string* ptr = &name;

    cout << (*ptr).length();
}