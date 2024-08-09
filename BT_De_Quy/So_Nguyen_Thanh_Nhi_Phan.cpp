#include <iostream>
using namespace std;

/*Hàm chuyển số hệ thập phân thành hệ nhị phân
-
1. Sử dụng đệ quy.
2. Dùng nguyên tắc chia lấy dư cho 2 luôn cho số dư là 0 hoặc 1.
*/
int to_binary(int n)
{
    // Điều kiện dừng: Khi n <= 0, quá trình đệ quy kết thúc
    if (n <= 0)
    {
        cout << "Pass!" << endl;
        return 0; // Trả về 0 khi kết thúc đệ quy
    }
    else
    {
        cout << "Start!" << endl;
        // Lấy phần dư khi chia n cho 2 (sẽ là 0 hoặc 1)
        // Đây là chữ số nhị phân cuối cùng
        int last_digit = n % 2;
        // Gọi đệ quy để xử lý phần còn lại của số
        int remaining_binary = to_binary(n / 2);
        // Kết hợp chữ số cuối cùng với phần còn lại
        // Nhân với 10 để dịch chuyển các chữ số nhị phân sang trái
        return last_digit + remaining_binary * 10;
    }
}

int main()
{
    long int n;
    cout << "Type a number: ";
    cin >> n;
    cin.ignore(256, '\n');
    cout << to_binary(n);
    return 0;
}