#include<bits/stdc++.h>
using namespace std;

bool flag = 0;
void printsubset(int i,int n,int set[],int target,vector<int> &subset){
    if(target==0){
        flag = 1;
        cout << "[";
        for (int i = 0; i < subset.size();i++){
            cout << subset[i]<<" ";
        }
        cout << "]";
        return;
    }
    if(i==n){
        return;
    }
    printsubset(i + 1, n, set, target, subset);
    if(set[i]<=target){
        subset.push_back(set[i]);
        printsubset(i + 1, n, set, target-set[i], subset);
        subset.pop_back();
    }
}

int main(){
    int set[] = {2, 4, 6};
    int target = 10;
    int n = sizeof(set) / sizeof(set[0]);
    vector<int> subset;
    printsubset(0, n, set, target, subset);
    
}