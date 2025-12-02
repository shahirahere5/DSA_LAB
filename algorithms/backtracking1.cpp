#include <iostream>
using namespace std;

const int N = 5;

bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMaze(int maze[N][N], int solution[N][N], int x, int y, int endX, int endY) {
    if (x == endX && y == endY) {
        solution[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y) && solution[x][y] == 0) {
        solution[x][y] = 1;

        // Move right
        if (solveMaze(maze, solution, x, y + 1, endX, endY)) return true;
        // Move down
        if (solveMaze(maze, solution, x + 1, y, endX, endY)) return true;
        // Move left
        if (solveMaze(maze, solution, x - 1, y, endX, endY)) return true;
        // Move up
        if (solveMaze(maze, solution, x, y - 1, endX, endY)) return true;

        solution[x][y] = 0; // Backtrack
    }
    return false;
}

void printSolution(int solution[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int maze[N][N] = {
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };

    int rabbitSolution[N][N] = {0};
    int catSolution[N][N] = {0};

    // Rabbit path from (0,0) to (2,2)
    if (solveMaze(maze, rabbitSolution, 0, 0, 2, 2)) {
        cout << "Rabbit path:" << endl;
        printSolution(rabbitSolution);
    } else {
        cout << "No path for rabbit found." << endl;
    }

    cout << "-------------" << endl;

    // Cat path from (4,4) to (2,2)
    if (solveMaze(maze, catSolution, 4, 4, 2, 2)) {
        cout << "Cat path:" << endl;
        printSolution(catSolution);
    } else {
        cout << "No path for cat found." << endl;
    }

    return 0;
}
