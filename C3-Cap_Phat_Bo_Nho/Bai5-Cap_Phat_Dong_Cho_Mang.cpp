/*
** Nhập và in mảng số nguyên **

* **Mô tả:** 
    - Nhập từ bàn phím kích thước của một mảng số nguyên.
    - Cấp phát động bộ nhớ cho mảng.
    - Nhập giá trị cho từng phần tử của mảng.
    - In ra màn hình các phần tử của mảng, cách nhau bởi một khoảng trắng.
    - Giải phóng bộ nhớ đã cấp phát.

* **Lưu ý:**
    - Sử dụng `new` để cấp phát động bộ nhớ cho mảng.
    - Sử dụng `delete[]` để giải phóng bộ nhớ khi không còn sử dụng.
    - **Nên kiểm tra xem phép cấp phát bộ nhớ có thành công hay không để tránh lỗi chương trình.**
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
