# git archive --format=zip --output <Đường dẫn tới> <Tên branch>
import subprocess


def run_cmd(command):
    """Hàm thực thi một lệnh CMD"""
    result = subprocess.run(command, shell=True, capture_output=True, text=True)
    if result.returncode == 0:
        print(result.stdout)
        print("Done rồi đấy cưng à~")
    else:
        print(result.stderr)
        print("Có vấn đề rồi cưng à, thử lại đi nào!")


p = input(
    "Copy đường dẫn mong muốn và quăng vào đây lẹ hoặc cưng cứ nhấn enter và dùng set mặc định: "
)
b = input("Nhập tên branch mà mi muốn sao lưu hoặc như nãy: ")

Path = "../Sao_Luu_Du_An_HAOKE.zip" if (p.strip() == "") else p
Branch = "haoke" if (b.strip() == "") else b

run_cmd(f"git archive --format=zip --output {Path} {Branch}")
