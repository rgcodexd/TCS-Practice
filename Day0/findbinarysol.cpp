#include<bits/stdc++.h>
using namespace std;

int binarystringoperation(const string& str){
    if(str.empty()) return -1;

    int result = str[0] -'0';

    for(int i=1; i<str.size(); i += 2){
        char op= str[i];
        int value =str[i+1] - '0';

        if(op =='A')
            result &=value;
        else if (op =='B')
            result |=value;
        else if(op=='C')
            result^=value;

    }

    return result;
}

int main(){
    string s;
    cout<<"write the string\n";
    cin >>s;
    cout<<binarystringoperation(s);
    return 0;
}
