#include <iostream>
using namespace std;

const int MAX = 20;
char board[MAX][MAX];

bool isSafe(int row, int col, int N)
{
    for (int i = 0; i < row; i++){
        if (board[i][col] == 'Q'){
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
        if (board[i][j] == 'Q'){
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++){
        if (board[i][j] == 'Q'){
            return false;
        }
    }
    return true;
}

void printBoard(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j];
        cout << "\n";
    }
}

void NQueens(int row, int N, int &count, bool &f){
    if(row==N){
        count++;
        if(!f){
            cout<< "\nOne valid board configuration:\n";
            printBoard(N);
            f=true;
        }
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col, N)) {
            board[row][col] = 'Q';
            NQueens(row + 1, N, count, f);
            board[row][col] = '.';
        }
    }
}

int main()
{
    int N;
    cout << "Enter value of N: ";
    cin >> N;
    if (N > MAX || N <= 0) {
        cout << "Please choose N between 1 and " << MAX << ".\n";
        return 0;
    }
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            board[i][j] = '.';
        }
    }
    int count = 0;
    bool f = false;
    NQueens(0, N, count, f);

    cout << "\nTotal number of distinct solutions "<<" : " << count << "\n";
    return 0;
}