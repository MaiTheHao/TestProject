#include <iostream>

using namespace std;

// Hàm đệ quy tính giai thừa
unsigned long long int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

// Hàm main
int main()
{
    int n;
    cout << "Nhap so n (0-65): ";
    cin >> n;
    cin.ignore(256, '\n');
    unsigned long long int result = factorial(n);

    cout << result << endl;
}