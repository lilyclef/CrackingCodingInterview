// https://www.fe-siken.com/kakomon/27_haru/pm08.html
#include<iostream>
#include<vector>

using namespace std;

// k番目の要素選択をクイックソートっぽく(分割統治法で)解く
// 集合の要素数からk番目の要素が見ているどちらのグループに入るのかを判定していく
// 計算量 T(n) = T(n/2) + O(n) T(n) = O(n)
int quick_select(vector<int>& input, int k) {
    int left = 0;
    int right = input.size() - 1;
    while (left <= right) {
        int mid_val = input[(left + right) / 2];
        int i = left - 1;
        int j = right + 1;
        while (true) {
            while (input[++i] < mid_val);
            while (input[--j] > mid_val);
            if (i >= j) break;
            swap(input[i], input[j]);
        }
        if (k == i - left) {
            return input[i];
        } else if (k < i - left) {
            right = i - 1;
        } else if (k > i - left) {
            k -= (i - left + 1);
            left = j + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> input = { 3, 5, 9, 2, 7, 1};
    cout << quick_select(input, 3) << endl;
}