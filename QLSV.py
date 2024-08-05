import os 
os.system("cls")

def craw_data():
    with open("sv.txt", "r", encoding = 'utf-8') as file:
        data = list(map(lambda x: x.strip("\n"), file.readlines()))
    
    filled_data = list(map(lambda x: x.split(";"), data))
    maxnamelength = max(list(map(lambda x: len(x[0].strip(" ")), filled_data)))
    maxdatelength = max(list(map(lambda x: len(x[1].strip(" ")), filled_data)))
    maxschoollength = max(list(map(lambda x: len(x[2].strip(" ")), filled_data)))
    maxclasslength = max(list(map(lambda x: len(x[3].strip(" ")), filled_data)))
    maxidlength = max(list(map(lambda x: len(x[4].strip(" ")), filled_data)))
    value_length = [maxnamelength, maxdatelength, maxschoollength, maxclasslength, maxidlength]
    return (filled_data, value_length)

def lietke(key = None, index = None):
    print("Liệt kê sinh viên: ")
    a = craw_data()
    data = a[0]; listtypespace = a[1]
    namespace = listtypespace[0]
    datespace = listtypespace[1]
    schoolspace = listtypespace[2]
    classspace = listtypespace[3]
    idspace = listtypespace[4]

    line = f"*{'-'*(idspace + 2)}*{'-'*(namespace + 2)}*{'-'*(datespace + 2)}*{'-'*(schoolspace + 2)}*{'-'*(classspace + 2)}*"
    info = lambda ten, ns, truong, lop, id: f"|{id:^{idspace + 2}}| {ten:<{namespace + 1}}| {ns:<{datespace + 1}}| {truong:<{schoolspace + 1}}| {lop:<{classspace + 1}}|"
    outdata = data

    if key != None:
        outdata = []
        for i in data:
            if key != None:
                if key in i[index].upper():
                    if key == i[index].upper():
                        outdata.insert(0, i)
                    
                    else:
                        outdata.append(i)
    print(line)
    for i in outdata:
        i = list(map(lambda x: x.strip(" "), i))
        print(info(i[0], i[1], i[2], i[3], i[4]))
        print(line)

    print("<<<ENTER>>>")

def them():
    os.system("cls")
    print("Thêm sinh viên: ")
    ten = input("Tên sinh viên: ").strip(" ")
    print("Ngày/ tháng/ năm sinh: ")
    day = input("-Ngày: ").strip(" "); month = input("-Tháng: ").strip(" "); year = input("-Năm: ").strip(" ")
    truong = input("Trường: ").strip(" ")
    lop = input("Lớp: ").strip(" ")
    formatted_data = f"{ten}; {day}/{month}/{year}; {truong}; {lop}"

    with open("sv.txt", "a", encoding = 'utf-8') as file:
        file.write(f"{formatted_data}; {len(craw_data()[0])}\n")
    
    input("Đã thêm sinh viên... <<<ENTER>>>")

def xoa():
    tim()
    id = input('Nhập id của sinh viên cần xóa: ').strip(" ")
    while not id.isdigit():
        if len(id.strip(" ")) == 0:
            print("Đã hủy xóa sinh viên.")
            return None
        
        id = input('Nhập lại id của sinh viên cần xóa (kiểu số nguyên): ').strip(" ")
    
    data = craw_data()[0]
    for i in data:
        a = list(map(lambda x: x.strip(" "), i))
        if id in a[4]:
            data.remove(i)
            break

    data = list(map(lambda x: ";".join(x) + "\n", data))
    with open("sv.txt", "w", encoding = 'utf-8') as file:
        file.writelines(data)
    
    print("Đã xóa sinh viên... <<ENTER>>")

def tim():
    os.system("cls")
    print("Tìm sinh viên: ")
    choice = input("-1.Tìm theo tên\n-2.Tìm theo ngày sinh\n-3.Tìm theo Trường\nNhập lựa chọn của bạn: ").strip(" ")
    if choice in ("1", "3"):
        if choice == "1":
            text = input("\nNhập tên sinh viên hoặc một phần của tên: ").strip(" ").upper()
            lietke(text, 0)
        
        else:
            text = input("\nNhập tên trường hoặc một phần của tên: ").strip(" ").upper()
            lietke(text, 2)
    
    elif choice == "2":
        date = input("Quy tắc tìm: day, month, year\nNhập ngày sinh: ").strip(" ").split(",")
        date = list(map(lambda x: x.strip(" ").lstrip("0"), date))
        lietke("/".join(date), 1)

def main():
    while True:
        print("QUẢN LÝ SINH VIÊN\nHÃY CHỌN CÁC LỰA CHỌN BẠN MUỐN:")
        print("1/ Liệt kê sinh viên\n2/ Thêm sinh viên\n3/ Xóa sinh viên\n4/ Tìm sinh viên\n5/ EXIT")
        choice = input("Lựa chọn của bạn: ")
        if choice == "1":
            lietke()
        
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