#include <iostream>
#include <unistd.h>
#include <iomanip>
using namespace std;

int num;
int &referNum = num;
int *pointer_to_num = &num;

void check_variables()
{
    system("cls");
    cout << setfill(' ') << setw(20) << left << "VARIABLES:"
         << setw(30) << left << "num"
         << setw(30) << left << "referNum"
         << setw(30) << left << "pointer_to_num" << endl;

    cout << setw(20) << left << "VALUES:"
         << setw(30) << left << referNum
         << setw(30) << left << num
         << setw(30) << left << pointer_to_num << endl;

    cout << setw(20) << left << "MEMORY ADDRESSES:"
         << setw(30) << left << &referNum
         << setw(30) << left << &num
         << setw(30) << left << &pointer_to_num << endl;
    
    cout << setfill('#') << setw(20 + 30 * 3) << left << "" << endl;
}

int main()
{
    num = 206512;

    for(int i = 100; i > 0; i--){
        num -= num/5;

        check_variables();
        usleep(250000);
    }

    return 0;
}