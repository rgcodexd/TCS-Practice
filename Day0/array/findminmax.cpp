#include <bits/stdc++.h>
using namespace std;

pair<int, int> findminmax(const vector<int>&  num){
    int minimum = num[0];
    int maximum = num[0];

    for (int value : num) {
        minimum = min(minimum, value);
        maximum = max(maximum, value);
    }

    return {minimum, maximum};
}

int main(){
    vector<int> arr = {3, 2, 1, 56, 10000, 167};
    pair<int, int> result = findminmax(arr);
    cout << result.first << " " << result.second << "\n";

    return0;
    
}



/*pair<int, int> bruteForceTwoLoops(vector<int> num) {
    int minimum = num[0];
    int maximum = num[0];

    // Loop 1: Find only the minimum
    for (int value : num) {
        if (value < minimum) {
            minimum = value;
        }
    }

    // Loop 2: Find only the maximum
    for (int value : num) {
        if (value > maximum) {
            maximum = value;
        }
    }

    return {minimum, maximum};
}*/