#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int findsum(long long n){
      long long sum=(1LL*n*(1+n)/2);
      return sum;
    }
};


int main(){
    long long a;
    cout<<"enter the steps count 'n' \n";
    cin>>a;
    solution s;
    cout<<s.findsum(a)<<'\n';

    return 0;
}
