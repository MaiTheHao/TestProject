#include <iostream>

using namespace std;

int main()
{
    const int min_char_index = 0, max_char_index = 126;
    string str, result;
    cout << "Nhap chuoi bat ky: ";
    getline(cin, str);

    for(int i = 0; i < str.length(); i++){
        cout << str[i] << endl;
        for(int j = min_char_index; j <= max_char_index; j++){
            system("cls");
            cout << result;
            cout << char(j) << endl;
            if(char(j) == str[i]){
                result += char(j);
                break;
            }
        }
    }
    
    return 0;
}