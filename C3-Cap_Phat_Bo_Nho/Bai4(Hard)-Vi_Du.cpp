#include <iostream>
#include <memory>

int main() {
    // Sử dụng std::unique_ptr
    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    std::cout << *ptr << std::endl; // Output: 42

    // Sử dụng std::shared_ptr
    std::shared_ptr<std::string> str_ptr = std::make_shared<std::string>("Hello");
    std::cout << *str_ptr << std::endl; // Output: Hello

    // Sử dụng std::weak_ptr
    std::shared_ptr<int> shared_ptr_int = std::make_shared<int>(100);
    std::weak_ptr<int> weak_ptr_int = shared_ptr_int;

    // Kiểm tra xem weak_ptr còn hợp lệ không
    if (std::shared_ptr<int> lock = weak_ptr_int.lock()) {
        std::cout << *lock << std::endl; // Output: 100
    } else {
        std::cout << "weak_ptr không còn hợp lệ" << std::endl;
    }

    // shared_ptr hết scope, weak_ptr cũng không còn hợp lệ
}