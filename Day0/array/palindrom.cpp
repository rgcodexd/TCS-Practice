#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
        int palindrom(const string& str){
            int left=0;
            int right=str.size()-1;

            while(left<right){
                if(str[left]!=str[right]) return 0;
                    
                
            left++;
            right--;
                
            }
            return 1;
            
            

        }
};

int main() {
    string text = "sats";
    solution s;
    if(s.palindrom(text)){
        cout<<"yes palindrom";

    }
    else cout<<"not a palindrom";

    return 0;
}
