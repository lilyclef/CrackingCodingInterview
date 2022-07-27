#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

pair<int, int> twosum_twopointer(vector<int>& input, int target) {
  sort(input.begin(), input.end());
  int i = 0;
  int j = input.size() - 1;
  while (i < j) {
    if (input[i] + input[j] == target) return {i, j};
    if (input[i] + input[j] < target) i++;
    else j++;
  }
  return {-1, -1};
}

pair<int, int> towsum_hashmap(vector<int>& input, int target) {
  unordered_map<int, int> indexes;
  for (int i = 0; i < input.size(); i++) {
    indexes[target - input[i]] = i;
  }
  for (int i = 0; i < input.size(); i++) {
    if (indexes.find(input[i]) != indexes.end()) return {i, indexes[input[i]]};
  }
  return {-1, -1};
}

int main() {
  vector<int> input = {0, 1, 3, 4, 5, 8};
  int target = 12;
  auto [ai, aj] = twosum_twopointer(input, target);
  cout << ai << " "<< aj << endl;
}