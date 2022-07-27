#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> direct = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int get_pond_size(vector<vector<int>>& input, int ci, int cj, int m, int n) {
  if (ci < 0 || cj < 0 || ci >= m || cj >= n || input[ci][cj] > 0) return 0;
  int sum = 1;
  input[ci][cj] = 1;
  for (int i = 0; i < direct.size(); i++) {
    sum += get_pond_size(input, ci + direct[i][0], cj + direct[i][1], m, n);
  }
  return sum;
}

int main () {
  vector<vector<int>> input = {{0, 2, 1, 0}, {0, 1, 0, 1}, {1, 1, 0, 1}, {0, 1, 0, 1}};
  int m = input.size();
  int n = input[0].size();
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (!input[i][j]) {
        cout << get_pond_size(input, i, j, m, n) << endl;
      }
    }
  }
}