/*
Bài toán đặt ra
Viết chương trình khai báo kiểu dữ liệu SinhVien với các thuộc tính string ten, int tuoi, int diem. 
Sau đó bạn hãy nhập từ bàn phím mảng n phần tử các SinhVien (mảng này được cấp phát động) và hiển thị ra màn hình thông tin của sinh viên có điểm cao nhất
*/

#include <iostream>

using namespace std;

struct Student
{
    string ten;
    int tuoi;
    int diem;
};

int main()
{
    int n;
    cin >> n;
    Student *students = new Student[n];
    for (int i = 0; i < n; i++)
    {
        cin >> students[i].ten >> students[i].tuoi >> students[i].diem;
    }

    Student s = students[0];
    for (int i = 1; i < n; i++)
    {
        if (s.diem < students[i].diem)
        {
            s = students[i];
        }
    }

    cout << "Ten: " << s.ten << endl;
    cout << "Tuoi: " << s.tuoi << endl;
    cout << "Diem: " << s.diem;

    delete[] students;
    return 0;
}