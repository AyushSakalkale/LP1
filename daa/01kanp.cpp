#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, W;

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter W: ";
    cin >> W;

    // Declare arrays after knowing the size n
    int w[n], p[n];

    cout << "Enter the profits: ";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    // DP table to store maximum profit values
    int matrix[n + 1][W + 1];

    // Initialize the DP table
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            matrix[i][j] = 0;
        }
    }

    // Fill the DP table using the 0/1 knapsack logic
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (w[i - 1] <= j)
            {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i - 1][j - w[i - 1]] + p[i - 1]);
            }
            else
            {
                matrix[i][j] = matrix[i - 1][j];
            }
        }
    }

    // Output the DP table for debugging
    cout << "DP Table:\n";
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Calculate the items included in the knapsack
    int maxValue = matrix[n][W];
    int remainingWeight = W;
    cout << "\nItems included in the knapsack:\n";
    for (int i = n; i > 0 && maxValue > 0; i--)
    {
        if (maxValue != matrix[i - 1][remainingWeight])
        {
            cout << "Item " << i << " (Weight: " << w[i - 1] << ", Profit: " << p[i - 1] << ")\n";
            maxValue -= p[i - 1];
            remainingWeight -= w[i - 1];
        }
    }

    cout << "\nMax profit is " << matrix[n][W] << endl;
    return 0;
}
