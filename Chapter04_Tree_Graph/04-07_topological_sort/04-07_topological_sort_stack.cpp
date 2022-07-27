#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <tuple>

using namespace std;

int topological_stack(vector<vector<int>>& input, vector<int>& ans, int n, vector<int>& reached, vector<int>& executing) {
  unordered_map<int, vector<int>> mp;
  for (int i = 0; i < input.size(); i++) {
    mp[input[i][0]].push_back(input[i][1]);
  }

  stack<pair<int, int>> tasks;
  for (int i = 0; i < n; i++) {
    tasks.push({i, 0});
  }
  while (!tasks.empty()) {
    auto [cnode, kind] = tasks.top();
    tasks.pop();
    if (reached[cnode]) continue;
    if (kind == 0) {
      if (executing[cnode]) {
        cout << "collision" << endl;
        continue;
      }
      executing[cnode] = 1;
      tasks.push({cnode, 1});
      for (int child : mp[cnode]) {
        tasks.push({child, 0});
      }
    } else {
      ans.push_back(cnode);
      executing[cnode] = 0;
      reached[cnode] = 1;
    }
  }

  return 0;
}

int main () {
  int n = 9;
  vector<vector<int>> input = {{7, 1}, {7, 8}, {5, 6}, {3, 8}, {3, 0}, {1, 2}, {4, 5}};
  vector<vector<int>> input_col = {{7, 1}, {7, 8}, {5, 6}, {3, 8}, {3, 0}, {1, 2}, {4, 5}, {2, 1}};
  vector<int> ans;
  vector<int> reached(n, 0);
  vector<int> executing(n, 0);
  topological_stack(input, ans, n, reached, executing);
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << " ";
  }
}