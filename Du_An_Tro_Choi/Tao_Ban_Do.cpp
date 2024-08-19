#include <iostream>
#include <iomanip>
using namespace std;

void deleteTable(int **table, int rows, int cols){
    for(int row = 0; row < rows; ++row){
        delete[] table[row];
    }

    delete[] table;
}

int main()
{
    unsigned short int rows, cols;
    cout << "Nhap so hang: ";
    cin >> rows;
    cin.ignore(256, '\n');
    cout << "Nhap so cot: ";
    cin >> cols;
    int **table = new int* [rows];
    for(int row = 0; row < rows; ++row){
        table[row] = new int[cols];
        for(int col = 0; col < cols; ++col){
            table[row][col] = col;
        }
    }

    for(int row = 0; row < rows; ++row){
        for(int col = 0; col < cols; ++col){
            cout << setw(4) << left << table[row][col] + row << " ";
        }

        cout << "\n\n";
    }

    deleteTable(table, rows, cols);
    return 0;
}