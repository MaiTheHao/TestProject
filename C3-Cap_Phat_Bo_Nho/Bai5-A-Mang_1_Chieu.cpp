/*
** Nhập và in mảng số nguyên **

* **Mô tả:**
    - Nhập từ bàn phím kích thước của một mảng số nguyên.
    - Cấp phát động bộ nhớ cho mảng.
    - Nhập giá trị cho từng phần tử của mảng.
    - In ra màn hình các phần tử của mảng.
    - Giải phóng bộ nhớ đã cấp phát.

* **Lưu ý:**
    - Sử dụng `new` để cấp phát động bộ nhớ cho mảng.
    - Sử dụng `delete[]` để giải phóng bộ nhớ khi không còn sử dụng.
    - **Nên kiểm tra xem phép cấp phát bộ nhớ có thành công hay không để tránh lỗi chương trình.**
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Hàm này chỉ phục vụ mục đích in ra các giá trị một cách tường minh, không cần thiết phải tìm hiểu.
void printValues(int *arr, int size)
{
    int format[2] = {10, 15}; // Khởi tạo giá trị xác định khoảng cách
    cout << setw(format[0]) << left << "Index"
         << setw(format[1]) << left << "Value" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << setw(format[0]) << left << i + 1
         << setw(format[1]) << left << arr[i] << endl;
    }
}

int main()
{
    int size = 0;
    cout << "Nhap kich thuoc mang: ";
    cin >> size; cin.ignore(256, '\n');

    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {   
        printf("Nhap phan tu thu %d: ", i + 1);
        cin >> arr[i];
        cin.ignore(256, '\n');
    }

    printValues(arr, size);

    delete[] arr;
    arr = nullptr;

    return 0;
}
