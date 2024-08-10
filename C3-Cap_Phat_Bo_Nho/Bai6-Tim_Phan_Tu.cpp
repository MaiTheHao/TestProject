/*
** Tìm kiếm phần tử trong mảng **

* **Mô tả:** 
    - Nhập từ bàn phím một mảng số nguyên và một giá trị cần tìm.
    - Tìm vị trí đầu tiên của phần tử có giá trị bằng giá trị cần tìm trong mảng.
    - Trả về vị trí tìm thấy hoặc -1 nếu không tìm thấy.

* **Thuật toán:**
    - Duyệt tuần tự qua các phần tử của mảng.
    - Nếu tìm thấy phần tử có giá trị bằng giá trị cần tìm, trả về vị trí đó ngay lập tức.
    - Nếu duyệt hết mảng mà không tìm thấy, trả về -1.

* **Lưu ý:**
    - Hàm `search` sử dụng con trỏ để truyền tham số `z` nhằm thay đổi trực tiếp giá trị của biến `z` trong hàm `main`.
    - Giá trị `i` (vị trí phần tử tìm thấy) được gán cho `*z` để truyền kết quả về hàm gọi.
*/

#include <iostream>
using namespace std;

void search(int* z, int arr[], int size){
    for(int i = 0; i < size; i++){
        if(arr[i] == *z){
            *z = i;
            return;
        }
    }

    *z = -1;
}

int main()
{
    int size = 0;

    cout << "Nhap kich thuoc cua mang: ";

    cin >> size;cin.ignore(256, '\n');


    int* array = new int[size];

    for(int i = 0; i < size; i++){

        printf("Nhap phan tu thu %d: ", i+1);

        cin >> array[i];cin.ignore(256, '\n');

    }


    int z = 0;

    cout << "Nhap so can tim trong mang: ";

    cin >> z;cin.ignore(256, '\n');


    search(&z, array, size);

    delete[] array;

    array = nullptr;


    cout << z;


    return 0;
}

