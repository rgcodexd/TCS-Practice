#include<bits/stdc++.h>
using namespace std;

vector<int> sbf(vector<int> &arr){
    int n=arr.size();

    sort(arr.begin(),arr.end());

    vector<vector<int>> freq;

    auto comp = [&](vector<int>&a , vector<int> &b){
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]>b[0];
        
    };

    for(int i=0;i<n;i++){
        int cnt=1;
        while(i<n-1 && arr [i]==arr[i+1]){
            cnt++;
            i++;
        }

        freq.push_back({cnt,arr[i]});

    }

    sort(freq.begin(),freq.end(),comp);

    vector<int> ans;

    for(int i=0;i<freq.size();i++){
        for(int j=0;j<freq[i][0];j++){
            ans.push_back(freq[i][1]);
        }
    }

    return ans;


}

int main(){
    vector<int> arr={1,1,3,3,2,2,2};

    vector<int> ans=sbf(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;

}