#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

pair<int, int> get_swaps(vector<int>& input_a, vector<int>& input_b) {
  int sum_a = 0, sum_b = 0;
  for (int ia : input_a) {
    sum_a += ia;
  }
  for (int ib : input_b) {
    sum_b += ib;
  }
  // sum_a - a + b = sumb - b + a
  // sum_a - sum_b = 2a - 2b;
  int diff = (sum_a - sum_b) / 2; // diffが奇数のときはnull. 2(a-b)は偶数なので
  // a - diff = b;
  // Two Sum
  unordered_map<int, int> a_plus_diff;
  for (int i = 0; i < input_a.size(); i++) {
    a_plus_diff[input_a[i] - diff] = i;
  }
  for (int i = 0; i < input_b.size(); i++) {
    if (a_plus_diff.find(input_b[i]) != a_plus_diff.end()) return { input_a[a_plus_diff[input_b[i]]], input_b[i]};
  }
  return {-1, -1};
}
int main() {
  vector<int> input_a = {4, 1, 2, 1, 1, 2};
  vector<int> input_b = {3, 6, 3, 3};
  auto [i, j] = get_swaps(input_a, input_b);
  cout << i << " " << j << endl;
}