#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int subarray_sum(vector<int>& input) {
    int n = input.size();
    vector<int> sums(n);
    vector<int> min_sums(n+1);
    int sum = 0, min_sum = 0;
    for (int i = 0; i < n; i++) {
        sum += input[i];
        min_sum = min(min_sum, sum);
        sums[i] = sum;
        min_sums[i+1] = min_sum;
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        ans = max(ans, sums[i] - min_sums[i]);
    }
    return ans;
}

int main () {
    vector<int> input = {2, -8, 3, -2, 4, -10};
    cout << subarray_sum(input) << endl;
}