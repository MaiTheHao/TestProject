/*
Cấp phát động cho mảng
Xây dựng chương trình in ra một mảng được nhập vào từ bàn phím

Người dùng nhập vào số phần tử của mảng
Cấp phát vùng nhớ đủ cho mảng, sau đó người dùng nhập vào các phần tử mảng là các số nguyên
In mảng ra màn hình (sau mỗi phần tử là một khoảng trắng), sau đó xoá vùng nhớ.
*/

#include <iostream>
using namespace std;

int main()
{
    int size = 0;
    cin >> size;

    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}
