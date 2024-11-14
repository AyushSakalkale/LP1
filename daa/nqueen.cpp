#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    for (int i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[i][j])
        {
            return false;
        }
    }
    return true;
}

void solveNqueen(vector<vector<int>> &board, int col, int n, int &solutionCount)
{
    if (col >= n)
    {
        solutionCount++;
        cout << "Solutions" << solutionCount << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << (board[i][j] ? "Q" : ".");
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col, n))
        {
            board[i][col] = 1;
            solveNqueen(board, col + 1, n, solutionCount);
            board[i][col] = 0;
        }
    }
}

void findAllSolution(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    int solutionCount = 0;
    solveNqueen(board, 0, n, solutionCount);
    cout << "Total no. of Solutions are:" << solutionCount << endl;
}

int main()
{
    int n;
    cout << "Enter n:";
    cin >> n;
    findAllSolution(n);
    return 0;
}