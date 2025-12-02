#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

bool isSafe(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

bool searchWord(char grid[ROWS][COLS], char word[], int x, int y, int index, bool visited[ROWS][COLS]) {
    if(word[index] == '\0') return true; // whole word found
    if(!isSafe(x, y)) return false;
    if(visited[x][y] || grid[x][y] != word[index]) return false;

    visited[x][y] = true;

    int dx[] = {-1,-1,-1,0,0,1,1,1}; // 8 directions
    int dy[] = {-1,0,1,-1,1,-1,0,1};

    for(int dir = 0; dir < 8; dir++) {
        if(searchWord(grid, word, x + dx[dir], y + dy[dir], index + 1, visited))
            return true;
    }

    visited[x][y] = false; // backtrack
    return false;
}

bool exist(char grid[ROWS][COLS], char word[]) {
    bool visited[ROWS][COLS] = {false};

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(searchWord(grid, word, i, j, 0, visited))
                return true;
        }
    }
    return false;
}

int main() {
    char grid[ROWS][COLS] = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    char word[] = "ABCCED";

    if(exist(grid, word)) cout << "Word found!" << endl;
    else cout << "Word not found." << endl;
}
