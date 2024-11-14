#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int partition(int low,int high,vector<double>& value,vector<double>& weight,vector<double>& common){
        double pivot=common[high];
        int i=low-1;
        for(int j=low; j<high; j++){
            if(common[j]<pivot){
                i++;
                swap(common[i],common[j]);
                swap(value[i],value[j]);
                swap(weight[i],weight[j]);
            }
        }
        swap(common[i+1],common[high]);
        swap(value[i+1],value[high]);
        swap(weight[i+1],weight[high]);
        return i+1;
    }
    void quickSort(int low,int high,vector<double>& value,vector<double>& weight,vector<double>& common){
        if(low>=high) return;
        int p=partition(low,high,value,weight,common);
        quickSort(low,p-1,value,weight,common);
        quickSort(p+1,high,value,weight,common);
    }

    void find(int n,double& cap,vector<double>& value,vector<double>& weight){
        vector<double>common(n);
        for(int i=0; i<n; i++){
            common[i]=value[i]/weight[i];
        }
        quickSort(0,n-1,common,value,weight);

        cout<<"ratios (value/weight): ";
        for(double ele : common) cout<<ele<<" ";
        cout << "\nvalues: ";
        for(double v : value)cout<<v<<" ";
        cout << "\nweights: ";
        for (double w : weight) cout<<w<<" ";
        cout << endl;
        double maxProfit=0;
        for(int i=n-1; i>=0 && cap>0; i--){
            if(cap>=weight[i]){
                maxProfit+=value[i];
                cap-=weight[i];
            }
            else{
                maxProfit+=(cap/weight[i])*value[i];
                cap=0;
            }
        }
        cout<<endl;
        cout<<"Max Profit is : "<<maxProfit;
    }
};

int main(){
    Solution ans;
    int n;
    cout<<"Enter size of arr : ";
    cin>>n;
    vector<double>value(n),weight(n);
    for(int i=0; i<n; i++){
        cout<<"Enter value and weight : ";
        cin>>value[i]>>weight[i];
    }
    double cap;
    cout<<"Enter weight capacity: ";
    cin>>cap;
    ans.find(n,cap,value,weight);
}