#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool flag(int row, int col, vector<vector<char>> &queens)
    {
        for (int i = 0; i < row; i++)
        {
            if (queens[i][col] == 'Q')
                return false;
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (queens[i][j] == 'Q')
                return false;
        }
        for (int i = row, j = col; i >= 0 && j < queens.size(); i--, j++)
        {
            if (queens[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void find(int i, int n, vector<vector<char>> &queens)
    {
        if (i == n)
        {
            cout << "Output " << endl;
            output(n, queens);
            cout << endl;
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (flag(i, j, queens))
            {
                queens[i][j] = 'Q';
                find(i + 1, n, queens);
                queens[i][j] = '.';
            }
        }
    }
    void output(int n, vector<vector<char>> &queens)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << queens[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution ans;
    int n;
    cout << "Enter number of Queens : ";
    cin >> n;
    vector<vector<char>> queens(n, vector<char>(n, '.'));
    ans.find(0, n, queens);
}