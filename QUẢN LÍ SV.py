import os
os.system("cls")

def dataset():
    global data
    with open(r"sinhvien.txt", "r", encoding = 'utf-8') as file:
        data = list(map(lambda x: list(map(lambda y: y.strip(' '), x.split(";"))), file.readlines()))

def spacesset(Data):
    maxspace = max(list(map(lambda x: len(x[0]), Data)))
    if (maxspace >= 3):
        return maxspace
    
    else:
        return 3

def lietke(Data):
    Namespaces = spacesset(Data)
    len_data = len(str(len(Data)))
    line = f"+-{'-' * len_data}-+-{'-' * Namespaces}-+{'-' * 6}+{'-' * 6}+{'-' * 6}+{'-' * 6}+"
    header = f"|{'ID':^{len_data + 2}}|{'TÊN':^{Namespaces + 2}}|{'Tuổi':^6}|{'Toán':^6}|{'Lý':^6}|{'Hóa':^6}|"
    print(line)
    print(header)
    print(line)
    for sv in Data:
        print(f"|{data.index(sv):^{len_data + 2}}| {sv[0]:<{Namespaces + 1}}|{sv[1]:^6}|{sv[2]:^6}|{sv[3]:^6}|{sv[4].strip('\n'):^6}|")
        print(line)

def them():
    print("THÊM SINH VIÊN:")
    name = input("-Tên sinh viên (ENTER để hủy): ")
    if name:
        age = input("-Tuổi: ")
        T = round(float(input("-Điểm toán: ")), 1)
        L = round(float(input("-Điểm lý: ")), 1)
        H = round(float(input("-Điểm hóa: ")),1)
        with open(r"sinhvien.txt", "a", encoding = 'utf-8') as file:
            file.write(f"{name}; {age}; {T}; {L}; {H}\n")
        dataset()
        print(f"Đã thêm sinh viên '{name}' thành công!")
    
    else:
        print("Đã hủy thêm sinh viên...")

def xoa():
    print("XÓA SINH VIÊN:")
    name = input("Nhập tên sinh viên cần xóa (ENTER để hủy): ")
    if name:
        find = tim(name)
        if find:
            id = input("Nhập ID sinh viên cần xóa (ENTER để hủy): ")
            if id:
                id = int(id)
                svname = data[id][0]
                del data[id]
                with open(r"sinhvien.txt", "w", encoding = 'utf-8') as file:
                    for sv in data:
                        file.write(f"{sv[0]}; {sv[1]}; {sv[2]}; {sv[3]}; {sv[4].strip('\n')}\n")
                dataset()
                print(F"Đã xóa sinh viên 'TÊN: {svname}; ID: {id}' thành công...")
            else:
                print("Đã hủy xóa sinh viên...")
    
    else:
        print("Đã hủy xóa sinh viên...")

def tim(key = None):
    print("LIỆT KÊ SINH VIÊN:")
    if key != None:
        text = key 
    else:
        text = input("Nhập tên của sinh viên: ")

    result = []
    for sv in data:
        if sv[0].lower().strip(" ") == text.lower().strip(" "):
            result.insert(0, sv)
        elif text.lower().strip(" ") in sv[0].lower().strip(" ").split(" "):
            result.append(sv)
        else:
            for part in sv[0].lower().strip(" ").split(" "):
                if text.lower().strip(" ") in part:
                    result.append(sv)
                    break
                
    if result:
        lietke(result)
        return True
    else:
        print(f"Không tìm thấy sinh viên trong tên có '{text}'...")
        return False

data = ''
dataset()

def main():
    while True:
        print("QUẢN LÝ SINH VIÊN\nHÃY CHỌN CÁC LỰA CHỌN BẠN MUỐN:")
        print("1/ Liệt kê sinh viên\n2/ Thêm sinh viên\n3/ Xóa sinh viên\n4/ Tìm sinh viên\n5/ EXIT")
        print("-" * len(f"+-{'-' * spacesset(data)}-+{'-' * 6}+{'-' * 6}+{'-' * 6}+{'-' * 6}+"))
        choice = input("Lựa chọn của bạn: ")
        if choice == "1":
            lietke(data)
        
        elif choice == "2":
            them()
        
        elif choice == "3":
            xoa()
        
        elif choice == "4":
            tim()
        
        elif choice == "5":
            break

        input("Nhấn ENTER để tiếp tục...")
        os.system("cls")

if __name__ == "__main__":
    main()