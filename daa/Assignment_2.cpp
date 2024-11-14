#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int find(int n, int cap, vector<int> &value, vector<int> &weight, vector<vector<int>> &dp)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= cap; j++)
            {
                if (weight[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
                }
            }
        }
        return dp[n][cap];
    }
};
int main()
{
    Solution ans;
    int n;
    cout << "Enter size of arr : ";
    cin >> n;
    vector<int> value(n), weight(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value and weight : ";
        cin >> value[i] >> weight[i];
    }
    double cap;
    cout << "Enter capacity: ";
    cin >> cap;
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));
    cout << "Max Profit : " << ans.find(n, cap, value, weight, dp);
}