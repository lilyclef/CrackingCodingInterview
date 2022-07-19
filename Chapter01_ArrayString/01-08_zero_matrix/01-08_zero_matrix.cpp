#include <iostream>
#include <vector>
using namespace std;

void convertZero(vector<vector<int>> &matrix){
  for (int i = 0; i < matrix.size(); i++){
    for (int j = 0; j < matrix[0].size(); j++){
      if (!matrix[i][j]) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }
  for (int i = 0; i < matrix.size(); i++){
    if (!matrix[i][0]) {
      for (int j = 1; j < matrix[0].size(); j++){
        matrix[i][j] = 0;
      }
    }
  }
  for (int j = 0; j < matrix[0].size(); j++){
    if (!matrix[0][j]) {
      for (int i = 1; i < matrix.size(); i++){
        matrix[i][j] = 0;
      }
    }
  }
}

int main() {
  vector<vector<int>> test = {{1, 2, 3, 4, 5}, {4, 0, 2, 1, 9}, {3, 9, 0, 7, 10}, {11, 2, 3, 4, 5}, {9, 1, 1, 2, 3}};
  convertZero(test);
  for (auto& ti : test) {
    for (int i : ti) {
      cout << i << " ";
    }
    cout << endl;
  }
}
