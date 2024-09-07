// Hãy tự tìm hiểu thêm về class trong C++, trong chương này t chỉ làm bài tập :3

#include <iostream>

using namespace std;

class Car
{
    // Các thuộc tính của một chiếc xe
    string brand;
    unsigned long int price;

public:
    // Các hàm thành viên (member function)
    // Hàm khởi tạo mặc định: Khởi tạo một chiếc xe với các thuộc tính mặc định
    Car()
    {
        cout << "A car was created!" << endl;
    }

    // Hàm khởi tạo có đối số: Khởi tạo một chiếc xe với các thuộc tính được truyền vào
    Car(string brand, unsigned long int price)
    {
        this->brand = brand;
        this->price = price;
    }
    // Cách thức thực hiện khởi tạo nâng cao hơn là sử dụng danh sách khởi tạo
    /*
    Car(string brand, unsigned long int price) : brand (brand), price (price) {}

    Bạn nên tìm hiểu về cách hoạt động của cách này, vì nó thường được sử dụng vì tính tiện lợi và hiệu quả.
    */

    // Các hàm getter và setter để truy cập và cập nhật giá trị của các thuộc tính
    string getBrand()
    {
        return brand;
    }

    unsigned long int getPrice()
    {
        return price;
    }

    void setBrand(string newBrand)
    {
        brand = newBrand;
    }

    void setPrice(unsigned long int newPrice)
    {
        price = newPrice;
    }

    // Hàm để hiển thị thông tin của một chiếc xe
    void displayInfo()
    {
        cout << "Brand: " << brand << endl;
        cout << "Price: " << price << endl;
    }
};

int main()
{
    // Tạo các đối tượng của lớp Car
    Car car1;
    Car car2("Toyota", 50000);

    // Sử dụng các hàm thành viên để truy cập và cập nhật dữ liệu
    car1.setBrand("Honda");
    car1.setPrice(40000);

    // Hiển thị thông tin của các chiếc xe
    car1.displayInfo();
    car2.displayInfo();

    return 0;
}