// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/ => 今回は回転なしだが、リンクは回転ありなのでソートする
#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
    // 今回の問題の条件は幅高さ奥行き全てが大きい箱の上に積む
     bool canBeAbove(tuple<int, int, int>& target, tuple<int, int, int>& below) {
        auto [th, tw, td] = target;
        auto [bh, bw, bd] = below;
        return tw < bw && td < bd && th < bh;
    }

    int __createStack(vector<tuple<int, int, int>>& boxes, int index, vector<int>& stackMap) {
        if (index < boxes.size() && stackMap[index] != -1) return stackMap[index];
        tuple<int, int, int> bottom = boxes[index];
        int max_height = 0;
        for (int i = index + 1; i < boxes.size(); i++) {
            if (canBeAbove(boxes[i], bottom)) {
                int height = __createStack(boxes, i, stackMap);
                max_height = max(max_height, height);
            }
        }
        max_height += get<0>(bottom);
        stackMap[index] = max_height;
        return max_height;
    }

    int createStack(vector<tuple<int, int, int>>& boxes) {
        // 高さで降順ソート
        sort(boxes.begin(), boxes.end(), greater<tuple<int, int, int>>());
        // xxを一番下にして最大の高さ
        int max_height = 0;
        vector<int> stackMap(boxes.size(), -1);
        for (int i = 0; i < boxes.size(); i++) {
            int height = __createStack(boxes, i, stackMap);
            max_height = max(max_height, height);
        }
        return max_height;
    }

int main () {
    vector<tuple<int, int, int>> boxes = {{50,45,20}, {95,37,53}, {45,23,12}};
    // 解法1. 一番下にbox iを置く
    cout << createStack(boxes) << endl;
}