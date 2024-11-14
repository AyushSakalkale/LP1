#include <bits/stdc++.h>
using namespace std;

int partition(vector<pair<int, float>> &arr, int low, int high)
{
    float pivot = arr[low].second;
    int i = low + 1;
    int j = high;
    while (i <= j)
    {
        while (i <= high && arr[i].second <= pivot)
        {
            i++;
        }
        while (j >= low && arr[j].second > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        
    }swap(arr[low], arr[j]);
        return j;
}

void quicksort(vector<pair<int, float>> &arr, int low, int high)
{
    if (low < high)
    {
        int index = partition(arr, low, high);
        quicksort(arr, low, index - 1);
        quicksort(arr, index + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter the number of Items:";
    cin >> n;
    vector<int> p(n);
    vector<int> w(n);
    int W;
    cin >> W;
    cout << "Enter profits:";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << "Enter weights:";
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    vector<pair<int, float>> r;
    for (int i = 0; i < n; i++)
    {
        r.push_back({i, (float)p[i] / w[i]});
    }
    quicksort(r, 0, n - 1);
    reverse(r.begin(), r.end());

    int ind = 0;
    int ans = 0;

    cout << "Items selected:";
    while (W != 0 && ind < n)
    {
        int item_index = r[ind].first;
        int ratio = r[ind].second;

        if (w[item_index] <= W)
        {
            ans += p[item_index];
            W -= w[item_index];
            cout << "item " << item_index + 1 << "Profit " << p[item_index] << "weight " << w[item_index] << "Selected completely " << endl;
        }
        else
        {
            ans += (float)W / w[item_index] * p[item_index];
            W = 0;
            cout << "item " << item_index + 1 << "Profit " << p[item_index] << "weight " << w[item_index] << "Selected partially "<< endl;
        }
        ind++;
    }
    cout << "Profit to Weight Ratio :" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Item" << r[i].first + 1 << "Ratio" << r[i].second << endl;
        cout << "Max profit" << ans << endl;
    }
}