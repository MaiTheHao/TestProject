/*
Tính tổng hai ô cấp phát
Bài toán đặt ra
Viết chương trình in ra tổng của 2 số thực kiểu double là p và q được nhập từ bàn phím bằng cách cấp phát động một ô nhớ, sau khi in ra màn hình thì xoá 2 ô nhớ vừa cấp phát.
*/

#include <iostream>
using namespace std;

int main()
{
    double *p = nullptr, *q = nullptr;

    p = new double;
    q = new double;

    cin >> *p >> *q;

    cout << *p + *q;

    delete p;
    p = nullptr;
    delete q;
    q = nullptr;
    // delete được thiết kế để xóa từng con trỏ nên không thể "delete p, q;""
    // Nếu muốn thuận tiện trong việc kiểm soát nhiều con trỏ bạn nên tạo hàm để thực thi
    // Ví dụ hàm delete_pointer được khởi tạo dưới cùng, template bạn nên tìm hiểu ở mục Con trỏ và Tham chiếu. Có thể chọn kiểu dữ liệu xác định thay cho template

    return 0;
}

template <typename T>
void delete_pointer(T *ptr)
{
    if (ptr != nullptr)
    {
        delete ptr;
        ptr = nullptr;
    }
}