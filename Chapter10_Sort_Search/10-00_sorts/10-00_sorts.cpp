#include<iostream>
#include<vector>
#include<map>

using namespace std;

void print_vec(const vector<int>& input) {
    for (int item : input) {
        cout << item << " ";
    }
    cout << endl;
}

// 不安定なソート
// *期待*計算量の漸化式T(n) = 2T(n/2) + O(n) => T(n) = O(nlogn)
// ピボットの選択が悪い時の最悪計算量O(n*2)
void quicksort(vector<int>& input, int l, int r) {
    if (l >= r) return;
    int pivot = input[(l+r)/2];
    // 両方とも含めないパターン
    int i = l - 1;
    int j = r + 1;
    while (true) {
        while (input[++i] < pivot);
        while (input[--j] > pivot);
        if (i >= j) break;
        swap(input[i], input[j]);
    }
    quicksort(input, l, i-1);
    quicksort(input, j+1, r);
}

// 安定ソート
// 計算量の漸化式はT(n) = 2 * T(n/2) + O(n) => 最良時も最悪時もO(nlogn)
// 外部にvectorを持つときO(n)かかる。swap使うと節約できて、インプレースマージと呼ばれる。
// 現実としては速度低下するのであまり使われない。
// STLのstable_sortは安定ソート
void mergesort(vector<int>& input) {
    int n = input.size();
    if (n <= 1) return;
    vector<int> b(input.begin(), input.begin() + n/2);
    vector<int> c(input.begin() + n/2, input.end());
    mergesort(b);
    mergesort(c);
    for (int i = 0, j = 0, k = 0; i < n; ++i) {
        if (k == c.size()) input[i] = b[j++];
        else if (j == b.size()) input[i] = c[k++];
        else if (b[j] < c[k]) input[i] = b[j++];
        else input[i] = c[k++];
    }
}

// 計数ソート O(n+k) kはキーの種類
// 出現アイテムが固定の範囲の時に使える
void countingSort(vector<int>& input, int k) {
    map<int, int> mp;
    for (int item : input) {
        mp[item]++;
    }
    int counter = 0;
    for (auto& iter : mp) {
        for (int j = 0; j < mp[iter.first]; j++) {
            input[counter++] = iter.first;
        }
    }
}


int main() {
    vector<int> input = {3, 1, 6, 4, 5, 7, 10, 8};
    quicksort(input, 0, input.size());
    mergesort(input);
    countingSort(input, 10);
    print_vec(input);
}