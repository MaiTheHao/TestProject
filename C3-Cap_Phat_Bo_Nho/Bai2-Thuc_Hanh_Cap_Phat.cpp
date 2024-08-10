#include <iostream>
using namespace std;

int main()
{
    double *ptr = new double;
    cin >> *ptr;
    cout << *ptr;

    // Khi sử dụng new để cấp phát động một vùng nhớ, chúng ta có trách nhiệm giải phóng nó bằng delete khi không còn sử dụng nữa.
    // Nếu không, sẽ xảy ra tình trạng rò rỉ bộ nhớ, dẫn đến chương trình tiêu tốn ngày càng nhiều tài nguyên và có thể gây ra các lỗi khó lường.
    delete ptr;

    // Dòng 'ptr=nullptr;' dưới đây được khuyến khích nếu còn tái sử dụng con trỏ, vì sau khi delete thì con trỏ vẫn còn tồn tại
    // Sau khi thực hiện delete ptr, con trỏ ptr vẫn còn tồn tại trong bộ nhớ, nhưng nó sẽ trở thành một con trỏ treo (dangling pointer).
    // Nếu cố tình sử dụng con trỏ này để truy cập vào vùng nhớ đã được giải phóng, chương trình sẽ gặp lỗi nghiêm trọng.
    // Việc gán ptr = nullptr giúp chúng ta tránh được tình huống này và giúp cho code trở nên rõ ràng hơn.
    ptr = nullptr;

    return 0;
}

/*
    Trong một số trường hợp, đặc biệt là trong các ngôn ngữ lập trình hiện đại có tính năng quản lý bộ nhớ tự động (garbage collection),
    việc gán nullptr cho con trỏ sau khi delete có thể không thực sự cần thiết, vì bộ nhớ sẽ được tự động thu hồi. Tuy nhiên, trong C++,
    việc này là một thực hành tốt để đảm bảo an toàn và tránh các lỗi tiềm ẩn.

    Nguyên tắc trong Quản lý Con trỏ Thủ công
    1. Luôn Khởi Tạo Con Trỏ
        -Trước khi sử dụng, mọi con trỏ phải được khởi tạo bằng một địa chỉ hợp lệ (thường là bằng nullptr hoặc địa chỉ của một đối tượng đã được cấp phát).
        -Không bao giờ sử dụng con trỏ chưa được khởi tạo.
    2. Kiểm Tra Con Trỏ Trước Khi Sử Dụng
        -Luôn kiểm tra xem con trỏ có khác nullptr trước khi thực hiện các phép toán đọc hoặc ghi dữ liệu qua con trỏ.
        -Điều này giúp tránh lỗi truy xuất trái phép.
    3. Cấp Phát và Giải Phóng Bộ Nhớ Đúng Cách
        -Sử dụng new để cấp phát bộ nhớ động cho một đối tượng.
        -Sử dụng delete để giải phóng bộ nhớ khi không còn sử dụng đối tượng đó nữa.
        -Mỗi lần cấp phát bằng new phải có một lần delete tương ứng để tránh rò rỉ bộ nhớ.
    4. Tránh Rò Rỉ Bộ Nhớ
        -Giải phóng bộ nhớ ngay khi không còn cần đến đối tượng.
        -Tránh tạo vòng tròn tham chiếu giữa các đối tượng, có thể dẫn đến việc không thể giải phóng bộ nhớ.
    5. Xử Lý Lỗi Cấp Phát Bộ Nhớ
        -Kiểm tra xem new có thành công hay không. Nếu thất bại, new sẽ trả về nullptr.
        -Xử lý trường hợp thất bại một cách thích hợp, ví dụ như in ra thông báo lỗi hoặc thoát chương trình.
    6. Cẩn Thận với Con Trỏ Đến Đối Tượng Tự Do
        -Khi một đối tượng bị giải phóng, con trỏ trỏ đến đối tượng đó trở thành dangling pointer.
        -Không bao giờ sử dụng dangling pointer, vì nó có thể dẫn đến hành vi không xác định.
    7. Sử dụng Smart Pointer (Hard)
        -Smart pointer (unique_ptr, shared_ptr, weak_ptr) tự động quản lý việc giải phóng bộ nhớ, giúp giảm thiểu rủi ro rò rỉ bộ nhớ và các lỗi liên quan đến con trỏ.
        -Nên ưu tiên sử dụng smart pointer thay vì con trỏ thủ công trong các trường hợp có thể.
*/