//with backtracking
#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

// Check if (x, y) is inside the grid
bool isSafe(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

// Recursive function to find the word
bool searchWord(char grid[ROWS][COLS], char word[], int x, int y, int index, bool visited[ROWS][COLS]) {
    if(word[index] == '\0') return true; // Word fully matched
    if(!isSafe(x, y)) return false;
    if(visited[x][y] || grid[x][y] != word[index]) return false;

    visited[x][y] = true; // Mark cell as used

    // Explore all 4 directions (up, down, left, right)
    if(searchWord(grid, word, x-1, y, index+1, visited) ||
       searchWord(grid, word, x+1, y, index+1, visited) ||
       searchWord(grid, word, x, y-1, index+1, visited) ||
       searchWord(grid, word, x, y+1, index+1, visited)) 
    {
        return true;
    }

    visited[x][y] = false; // Backtrack
    return false;
}

// Check every cell as starting point
bool exist(char grid[ROWS][COLS], char word[]) {
    bool visited[ROWS][COLS] = {false};

    for(int i = 0; i < ROWS; i++)
        for(int j = 0; j < COLS; j++)
            if(searchWord(grid, word, i, j, 0, visited))
                return true;

    return false;
}

int main() {
    char grid[ROWS][COLS] = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    char word[] = "ABCCED";

    if(exist(grid, word))
        cout << "Word found!" << endl;
    else
        cout << "Word not found." << endl;
}
