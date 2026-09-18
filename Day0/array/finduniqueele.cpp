#include <bits/stdc++.h>
using namespace std;

class solution{
    public:
        int findunion(vector<int>arr1 , vector<int>arr2){
            unordered_set<int> s;

            for(int i=0;i<arr1.size();i++){
                s.insert(arr1[i]);   

            }

            
            for(int i=0;i<arr2.size();i++){
                s.insert(arr2[i]);   

            }

            return s.size();


        }

};

int main(){
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {2, 3, 4};

    solution s;
    cout << s.findunion(arr1, arr2) << '\n';
}

