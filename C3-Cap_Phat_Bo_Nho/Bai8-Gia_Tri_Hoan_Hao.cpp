/*
Để hiểu rõ vai trò của dòng code này, chúng ta cần quay lại với định nghĩa về "giá trị hoàn hảo" trong bài toán.

Giá trị hoàn hảo của một phần tử: Là tổng của một dãy con liên tiếp bắt đầu từ phần tử đó, với độ dài của dãy con tăng dần qua từng bước (1, 2, 3, ...).
Giới hạn của dãy con: Độ dài tối đa của dãy con phụ thuộc vào vị trí bắt đầu và tổng số phần tử của mảng.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int max = -2147483648;
    // Cấp phát vùng nhớ động cho mảng 1 chiều các con trỏ kiểu int*
    int *arr = new int[n];

    // Nhập dữ liệu cho các phần tử trong mảng
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        int size = n - i;
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            count += j;
            if (count > size)
            {
                count -= j;
                break;
            }
        }
        for (int k = i; k < count + i; k++)
        {
            sum += arr[k];
        }
        if (sum > max)
        {
            max = sum;
        }
    }
    cout << max << endl;
    // Giải phóng bộ nhớ cho mảng các con trỏ
    delete[] arr;
    return 0;
}