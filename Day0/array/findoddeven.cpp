#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
        int findoddeven(int n){
          return n % 2==0 ? 1 :0;
        }
};

int main(){
    int a;
    cout<<"enter a num\n";
    cin>>a;
    solution s;
    cout<<s.findoddeven(a);
    return 0;
}