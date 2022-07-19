// https://leetcode.com/problems/subsets/
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> make_subsets(vector<int>& input, int index) {
    // indexが入力配列のサイズを超えた時、{{}}を返す
    if (index == input.size()) return {{}};
    // 再帰でindexより右の要素で作った集合をもらってくる
    auto next_sets = make_subsets(input, index + 1);
    // 今回、全ての長さの部分集合が欲しいので、答え用にコピーする
    auto ans = next_sets; // copy
    // indexの位置にある数字をくっつける
    for (int i = 0; i < next_sets.size(); i++) {
        next_sets[i].push_back(input[index]);
    }
    // くっつけたものをansに追加する
    ans.insert(ans.end(), next_sets.begin(), next_sets.end());
    // 完成
    return ans;
}

int main () {
    vector<int> input = {1, 2, 3};
    vector<vector<int>> ans = make_subsets(input, 0);
    for (vector<int> ans_item : ans) {
        for (int i : ans_item) {
            cout << i << " ";
        }
        cout << endl;
    }
}