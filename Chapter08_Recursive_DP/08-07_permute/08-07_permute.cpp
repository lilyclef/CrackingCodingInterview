// https://leetcode.com/problems/permutations/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> permute(string input) {
    int n = input.size();
    if (n == 0) return {""};
    vector<string> ans;
    for (int i = 0; i < n; i++) {
        string before = input.substr(0, i); // 0 - i-1
        string after = input.substr(i+1);  // i+1 -
        vector<string> tmp = permute(before + after);
        for (string& t : tmp) {
            ans.push_back(input[i] + t);
        }
    }
    return ans;
}

int main() {
    string input = "abc";
    auto ans = permute(input);
    for (string& a : ans) {
        cout << a << endl;
    }
    // 計算量O(n^2*n!)
}