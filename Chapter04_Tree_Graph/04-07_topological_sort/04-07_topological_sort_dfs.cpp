#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int topological_dfs(unordered_map<int, vector<int>>& mp, vector<int>& ans, int index, vector<int>& reached, vector<int>& executing) {
  if (reached[index]) return 0;
  if (executing[index]) return -1;
  executing[index] = 1;
  for(int child : mp[index]) {
    int child_res = topological_dfs(mp, ans, child, reached, executing);
    if (child_res == -1) return -1;
  }
  ans.push_back(index);
  executing[index] = 0;
  reached[index] = 1;
  return 0;
}

int main () {
  int n = 9;
  vector<vector<int>> input = {{7, 1}, {7, 8}, {5, 6}, {3, 8}, {3, 0}, {1, 2}, {4, 5}};
  vector<vector<int>> input_col = {{7, 1}, {7, 8}, {5, 6}, {3, 8}, {3, 0}, {1, 2}, {4, 5}, {2, 1}};
  unordered_map<int, vector<int>> mp;
  for (int i = 0; i < input.size(); i++) {
    mp[input[i][0]].push_back(input[i][1]);
  }
  vector<int> ans;
  vector<int> reached(n, 0);
  vector<int> executing(n, 0);
  for (int i = 0; i < n; i++) {
    int tmp_ans = topological_dfs(mp, ans, i, reached, executing);
    if (tmp_ans == -1) cout << "collision" << endl;
  }
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << " ";
  }
  cout << endl;

  unordered_map<int, vector<int>> mp_col;
  for (int i = 0; i < input_col.size(); i++) {
    mp_col[input_col[i][0]].push_back(input_col[i][1]);
  }

  ans.clear();
  reached = vector<int>(n, 0);
  executing = vector<int> (n, 0);
  for (int i = 0; i < n; i++) {
    int tmp_ans = topological_dfs(mp_col, ans, i, reached, executing);
    if (tmp_ans == -1) cout << "collision! I can't order them" << endl;
  }

  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << " ";
  }
}