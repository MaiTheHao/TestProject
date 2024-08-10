#include <iostream>
#include <string> // Sử dụng thư viện string để làm việc với chuỗi dễ dàng hơn

using namespace std;

int main()
{
    // Cấp phát tĩnh
    int age = 30;                   // Biến age được cấp phát tĩnh, kích thước cố định
    char name[20] = "Nguyen Van A"; // Mảng name được cấp phát tĩnh, kích thước cố định

    cout << "Tuoi: " << age << endl;
    cout << "Ten: " << name << endl;

    // Cấp phát động
    cout << "Nhap do dai cua cau: ";
    int length;
    cin >> length;

    // Cấp phát động một mảng ký tự có độ dài linh hoạt
    char *sentence = new char[length + 1]; // Cộng thêm 1 để lưu ký tự null '\0' ở cuối chuỗi

    cout << "Nhap cau cua ban: ";
    cin.ignore(256,'\n'); // Bỏ qua ký tự xuống dòng còn sót lại sau khi nhập length
    cin.getline(sentence, length + 1);

    cout << "Cau cua ban la: " << sentence << endl;

    // Giải phóng bộ nhớ đã cấp phát động
    delete[] sentence;

    // Bảng so sánh cấp phát tĩnh và động
    cout << "\nBang so sanh:\n";
    cout << "|--------------------\n";
    cout << "| Thuoc tinh   | Cap phat tinh   | Cap phat dong  |\n";
    cout << "|--------------|-----------------|----------------|\n";
    cout << "| Thoi diem    | Bien dich       | Thoi gian chay |\n";
    cout << "| Kich thuoc   | Co dinh         | Linh hoat      |\n";
    cout << "| Quan ly      | Tren ngan xep   | Tren heap      |\n";
    cout << "|--------------------\n";

    return 0;
}

/*
Giới thiệu
Trong C++, chúng ta có thể cấp phát bộ nhớ theo 2 cách sau:

Cấp phát tĩnh
Cấp phát động

-Trong cấp phát tĩnh:
    Một lượng bộ nhớ cố định sẽ được cấp phát cho các biến hoặc mảng trước khi chương trình 
     được thực thi (trong thời gian biên dịch), và chúng ta không thể yêu cầu thêm bộ nhớ trong khi chương trình thực thi.
    -Khi cấp phát bộ nhớ tĩnh:
        Chúng ta phải biết kích thước của một mảng hoặc biến trong thời gian biên dịch.
        Bộ nhớ được cấp phát và thu hồi cho các biến bởi trình biên dịch.
        Đôi khi bạn sẽ gặp phải trường hợp không biết trước dung lượng bộ nhớ cần thiết để lưu trữ dữ liệu. Do đó, cấp 
         phát động là điều cần thiết.

-Trong cấp phát bộ nhớ động:

    Chúng ta có thể nhận được bao nhiêu bộ nhớ tùy ý trong quá trình thực thi chương trình.
    Bộ nhớ được cấp phát và phân bổ bởi lập trình viên trong thời gian thực thi.
*/

/*
Chương trình này minh họa cách sử dụng cấp phát bộ nhớ tĩnh và động trong C++.

* Cấp phát tĩnh:
    - Bộ nhớ được cấp phát tại thời điểm biên dịch.
    - Kích thước cố định.
    - Ví dụ: Biến nguyên, mảng có kích thước cố định.

* Cấp phát động:
    - Bộ nhớ được cấp phát tại thời điểm chạy chương trình.
    - Kích thước linh hoạt.
    - Sử dụng toán tử new và delete để cấp phát và giải phóng bộ nhớ.
    - Ví dụ: Mảng có kích thước thay đổi theo dữ liệu nhập vào.
*/