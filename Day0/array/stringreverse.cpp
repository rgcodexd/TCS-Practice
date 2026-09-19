#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    string stringReverse(string str) {
        int left = 0;
        int right = str.size() - 1;

        while (left < right) {
            swap(str[left], str[right]);
            left++;
            right--;
        }

        return str;
    }
    
};

int main() {
    string text = "hello";
    Solution solution;
    cout << solution.stringReverse(text) << endl;
    return 0;
}


