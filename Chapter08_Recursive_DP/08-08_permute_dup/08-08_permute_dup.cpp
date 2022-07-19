// https://leetcode.com/problems/permutations-ii/
#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

void __permute_dup(map<char,int>& mp, string prefix, int index, vector<int> ans) {
    if (index == 0) {
        ans.push_back(prefix);
        return;
    }

    for (auto [target_c, count] : mp) {
        if (count == 0) continue;
        mp[target_c]--;
        __permute_dup(mp, prefix + c, index - 1, ans);
        mp[target_c]++;
    }

}

vector<string> permute_dup(string input) {
    map<char, int> mp;
    for (char c : input) {
        mp[c]++;
    }

    vector<string> ans;
    __permute_dup(mp, "", input.size(), ans);
    return ans;
}

int main() {
    string input = "abbc";
    auto ans = permute_dup(input);
    for (string& a : ans) {
        cout << a << endl;
    }
}