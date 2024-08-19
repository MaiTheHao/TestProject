#include <iostream>
#include <iomanip>
using namespace std;

// Cấu trúc số thập phân
struct decimal{
    int tuso;
    int mauso;
};

void print_decimal(decimal number){
    cout << number.tuso << "/" << number.mauso << endl;
}

int main(){

    decimal number1; // Cách khai báo 1 (Không khai báo giá trị thuộc tính)
    struct decimal number2; // Cách khai báo 2 (Không khai báo giá trị thuộc tính)
    decimal number3 = {5, 7}; // Cách khai báo có giá trị thuộc tính ban đầu

    // Cách truy cập giá trị thuộc tính thông thường
    number1.tuso = 2; 
    number1.mauso = 3;
    number2.tuso = 4;
    number2.mauso = 2;

    // Cách truy cập giá trị thuộc tính bằng con trỏ
    decimal *ptr = nullptr; // Khai báo con trỏ trỏ tới struct decimal

    ptr = &number1; // Gắn địa chỉ của struct number1 vào con trỏ ptr

    cout << (*ptr).tuso << endl; // Cách truy cập vào thuộc tính 1
    cout << ptr->mauso << endl; // Cách truy cập vào thuộc tính 2

    print_decimal(number2);
    print_decimal(number3);
    
    return 0;
}