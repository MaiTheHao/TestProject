#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class zombie {
private:
    int hp, damage; // Điểm sức khỏe và sát thương của zombie (riêng tư, chỉ truy cập bên trong lớp)

public:
    zombie() {
        // Khởi tạo ngẫu nhiên điểm sức khỏe từ 10 đến 50
        hp = (rand() % 5 + 1) * 10;
        // Khởi tạo ngẫu nhiên sát thương từ 5 đến 10
        damage = 5 + (rand() % 6);

        // In thông báo zombie được tạo
        cout << "ZOMBIE CREATED:\n-HP: " << hp << "\n-Damage: " << damage << endl;
    }

    ~zombie() {
        // In thông báo zombie chết
        cout << "Zombie died" << endl;
    }
};

class zombie_public {
private:
    int size; // Số lượng zombie trong nhóm
    zombie* list; // Con trỏ đến mảng các zombie

    void spawn_zombie(); // Hàm riêng để tạo các zombie

public:
    zombie_public(int size) {
        // Gán số lượng zombie cho nhóm
        this->size = size;
        // Cấp phát bộ nhớ cho mảng zombie
        this->list = new zombie[size];
        // In thông báo tạo nhóm zombie
        cout << "A GROUP OF ZOMBIES WERE SPAWNED WITH " << size << " ZOMBIES." << endl;
    }

    ~zombie_public() {
        // Giải phóng bộ nhớ đã cấp phát cho mảng zombie
        delete[] list;
        // In thông báo xóa nhóm zombie
        cout << "A GROUP OF ZOMBIES WITH " << size << " ZOMBIES WERE DELETED." << endl;
    }
};

int main() {
    // Khởi tạo bộ tạo số ngẫu nhiên
    srand(time(0));

    // Nhập số lượng zombie từ người dùng
    int number_of_zombies;
    cout << "Number of zombies: ";
    cin >> number_of_zombies;

    // Tạo một nhóm zombie với số lượng đã nhập
    zombie_public group_a(number_of_zombies);

    return 0;
}

void zombie_public::spawn_zombie() {
    // Tạo từng zombie trong nhóm
    for (int i = 0; i < size; i++) {
        list[i] = zombie();
    }
}