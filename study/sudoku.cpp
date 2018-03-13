#include <iosteam>
using namespace std;

int main(void){
    int sudoku[9][9];
    for (int i = 0; i < 9; i ++){
        for (int j = 0; j < 9; j ++){
            cin >> sudoku[i][j];
        }
    }
    return 0;
}