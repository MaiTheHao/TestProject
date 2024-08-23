#include <iostream>
using namespace std;

struct Complex {
    double real;
    double imaginary;
};

int main( )
{
    Complex x, y, z;
    cin >> x.real;
    cin >> x.imaginary;
    cin >> y.real;
    cin >> y.imaginary;

    z.real = x.real - y.real;
    z.imaginary = x.imaginary - y.imaginary;

    cout << z.real << " + " << z.imaginary << "i";

    return 0;
}