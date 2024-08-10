#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x, y, z, i;
    x = y = z = "hello";
    i += x[1];
    i += y[2];
    i += z[0];
    cout << "A = " << i << endl;
    const int number = 60;
    cout << "N =" << number << endl;
    int a, b, sum;
    cout << "____________________________________________________________________________________________________________________" << endl;
    cout << "Type a number: ";
    cin >> a; cin.ignore(256, '\n');
    cout << "Type another number: ";
    cin >> b; cin.ignore(256, '\n');
    sum = a + b;
    cout << "The sum is: " << sum << endl;

    return 0;
}
