// Đoạn code này minh họa sự khác biệt giữa biến tham chiếu và con trỏ trong C++.
//
// - num: Biến số nguyên gốc.
// - referNum: Biến tham chiếu trỏ đến num. Bất kỳ thay đổi nào ở referNum cũng ảnh hưởng đến num.
// - pointer_to_num: Con trỏ trỏ đến địa chỉ của num.
//
// Hàm check_variables() dùng để hiển thị thông tin chi tiết về các biến, bao gồm:
// - Tên biến
// - Giá trị
// - Địa chỉ bộ nhớ
//
// Vòng lặp giúp quan sát sự thay đổi giá trị của các biến theo thời gian.
//
// Qua đoạn code này, ta thấy:
// - Biến tham chiếu và biến gốc có cùng địa chỉ bộ nhớ.
// - Con trỏ có địa chỉ riêng.
// - Thay đổi giá trị của biến tham chiếu sẽ ảnh hưởng đến biến gốc.

#include <iostream>
#include <unistd.h>
#include <iomanip>
using namespace std;

int num;
int &referNum = num;        // Biến tham chiếu referNum tham chiếu đến biến num
int *pointer_to_num = &num; // Con trỏ pointer_to_num trỏ đến địa chỉ của biến num

// Hàm này chủ yếu để IN ra giá trị, nên không nhất thiết tìm hiểu về các phương thức định dạng của thư viện iomanip (setfill, setw, left, right, ...)
void check_variables()
{
    system("cls"); // Xóa màn hình console
    cout << setfill(' ') << setw(20) << left << "VARIABLES:"
         << setw(30) << left << "num"
         << setw(30) << left << "referNum"
         << setw(30) << left << "pointer_to_num" << endl;

    cout << setw(20) << left << "VALUES:"
         << setw(30) << left << referNum // Giá trị của biến num (qua tham chiếu)
         << setw(30) << left << num
         << setw(30) << left << pointer_to_num << endl; // Địa chỉ của biến num

    cout << setw(20) << left << "MEMORY ADDRESSES:"
         << setw(30) << left << &referNum // Địa chỉ của biến num (qua tham chiếu)
         << setw(30) << left << &num
         << setw(30) << left << &pointer_to_num << endl;

    cout << setfill('#') << setw(20 + 30 * 3) << left << "" << endl;
}

int main()
{
    num = 206512;

    for (int i = 5; i > 0; i--)
    {
        num -= num / 5; // Giảm giá trị của num đi 1/5

        check_variables(); // Gọi hàm để hiển thị thông tin các biến
        usleep(1000000);   // Gián đoạn chương trình trong 250ms
    }

    return 0;
}
