#include <iostream>
#include <vector>
using namespace std;

void sumOfSubsets(vector<int> &arr, int target_sum, vector<int> &subset, int current_sum, int index)
{
    if (current_sum == target_sum)
    {
        cout << "{ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
        return;
    }

    if (current_sum > target_sum || index >= arr.size())
    {
        return;
    }

    subset.push_back(arr[index]);
    sumOfSubsets(arr, target_sum, subset, current_sum + arr[index], index + 1);

    subset.pop_back();
    sumOfSubsets(arr, target_sum, subset, current_sum, index + 1);
}

int main()
{
    int n, target_sum;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> target_sum;

    vector<int> subset;
    cout << "Subsets with sum " << target_sum << ":" << endl;
    sumOfSubsets(arr, target_sum, subset, 0, 0);

    return 0;
}
