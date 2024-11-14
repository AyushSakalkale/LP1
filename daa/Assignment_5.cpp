#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    void find(int idx,int n,int sum,int target,vector<int>& nums,vector<int>temp,vector<vector<int>>& subsets){
        if(sum==target){
            subsets.push_back(temp);
            return;
        }
        if(idx>=n || sum>target) return;
        for(int i=idx; i<n; i++){
            temp.push_back(nums[i]);
            sum+=nums[i];
            find(i+1,n,sum,target,nums,temp,subsets);
            temp.pop_back();
            sum-=nums[i];
        }
    }
    void output(vector<vector<int>>& subsets){
        for(int i=0; i<subsets.size(); i++){
            cout<<"[ ";
            for(int j=0; j<subsets[i].size(); j++){
                cout<<subsets[i][j]<<" ";
            }
            cout<<"]";
            cout<<endl;
        }
    }
};

int main(){
    Solution ans;
    int n;
    cout<<"Enter length : ";
    cin>>n;
    vector<int>nums(n),temp;
    vector<vector<int>>subsets;
    cout<<"Enter element : ";
    for(int i=0; i<n; i++) cin>>nums[i];
    int target;
    cout<<"Enter target : ";
    cin>>target;
    ans.find(0,n,0,target,nums,temp,subsets);
    ans.output(subsets);
}