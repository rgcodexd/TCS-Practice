#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int maximum=arr[0];
        for(int value:arr){
            maximum=max(maximum,value);
        }
        return maximum;
    }
};

int main(){
   vector<int> num={1,3,78,8};

    Solution s;
    cout<<"you result\n"<<s.largest(num);
    return 0;
}

