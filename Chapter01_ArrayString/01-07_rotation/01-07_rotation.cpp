#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> convert(vector<vector<int>>& target) {
  int n = target.size();
  int m = target[0].size();
  vector<vector<int>> ans(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans[j][n-i-1] = target[i][j];
}
  }
  return ans;
}

int main() {

vector <vector<int>> target = { {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};
    auto ans = convert(target);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}