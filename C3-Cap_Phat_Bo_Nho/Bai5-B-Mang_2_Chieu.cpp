#include <iostream>
#include <iomanip>
using namespace std;

// Hàm này chỉ phục vụ mục đích in ra các giá trị một cách tường minh, không cần thiết phải tìm hiểu.
void printValues(int **arr, int size)
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
    int rows, columns;
    cout << "Nhap so hang cua mang: ";
    cin >> rows;
    cin.ignore(256, '\n');
    cout << "Nhap so cot cua mang: ";
    cin >> columns;
    cin.ignore(256, '\n');

    int *(*arr) = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[columns];
    }
    // Cấp phát bộ nhớ cho một mảng đa chiều (ex: 2 chiều):
    /*
     * Dòng 1:
     *   - Khai báo một con trỏ `arr` trỏ tới một mảng các con trỏ kiểu int.
     *   - `new int*[rows]` cấp phát một mảng có `rows` phần tử, mỗi phần tử là một con trỏ int.
     *   - `arr` sẽ chứa địa chỉ của phần tử đầu tiên trong mảng các con trỏ này.
     *
     * Vòng lặp:
     *   - Mỗi lần lặp, cấp phát một mảng một chiều có `columns` phần tử kiểu int.
     *   - Địa chỉ của mảng một chiều này được gán cho phần tử tương ứng của `arr`.
     *   - Như vậy, `arr[i]` sẽ trỏ tới một mảng một chiều có `columns` phần tử.
     *
     * Tóm lại:
     *   - `arr` là một mảng các con trỏ.
     *   - Mỗi phần tử của `arr` lại là một con trỏ trỏ tới một mảng một chiều.
     *   - Cấu trúc này tạo thành một mảng hai chiều.
     *
     * Ví dụ:
     *   - Để truy cập phần tử ở hàng thứ 2, cột thứ 3, ta dùng: arr[1][2]
     *   - Điều này tương đương với việc truy cập phần tử thứ 3 của mảng một chiều mà arr[1] đang trỏ tới.
     */

    // Vì là con trỏ trỏ tới mảng các con trỏ nên giá trị khi truy cập arr[i] sẽ là địa chỉ bộ nhớ thay vì giá trị số nguyên
    printValues(arr, rows);



    /// Giải phóng bộ nhớ cho mảng hai chiều
    //
    // Mảng hai chiều được cấp phát động gồm nhiều mảng con. Để giải phóng hoàn toàn bộ nhớ,
    // chúng ta cần giải phóng từng mảng con trước, sau đó mới giải phóng mảng cha.
    //
    // Hình dung mảng hai chiều như một tòa nhà nhiều tầng, mỗi tầng là một mảng con.
    // Khi phá dỡ tòa nhà, chúng ta phải phá từng tầng trước, sau đó mới phá móng (mảng cha).
    //
    // - Vòng lặp đầu tiên: Duyệt qua từng mảng con và giải phóng bộ nhớ bằng delete[].
    // - Vòng lặp thứ hai: Giải phóng bộ nhớ cho mảng cha.
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i]; // Giải phóng mảng con thứ i
    }
    delete[] arr; // Giải phóng mảng cha
}
