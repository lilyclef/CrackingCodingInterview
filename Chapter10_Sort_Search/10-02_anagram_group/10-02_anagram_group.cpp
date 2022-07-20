// https://leetcode.com/problems/group-anagrams/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

vector<string> sort_anagram(vector<string>& wordlist) {
    map<string, vector<string>> mp;
    for (string& w : wordlist) {
        string tmp = w;
        sort(tmp.begin(), tmp.end()); // O(SlogS * N)
        mp[tmp].push_back(w);         // O(NlogN) ?
    }
    vector<string> ans;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        for (auto str : iter->second) {
            ans.push_back(str);
        }
    }
    return ans;
}

int main () {
    vector<string> word_list = { "amazon",  "yamamotoyuri", "cake", "zonama", "yuriyamamoto", "cookie", "cakepie"};
    vector<string> ans = sort_anagram(word_list);
    for (string& word : ans) {
        cout << word << " ";
    }
    cout << endl;
}