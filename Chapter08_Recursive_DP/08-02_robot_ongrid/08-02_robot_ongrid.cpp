#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

void fill(vector<vector<int>>& field, int i, int j, vector<vector<int>>& checked, vector<vector<pair<int, int>>>& frompath, pair<int, int> prev) {
    int r = field.size();
    int c = field[0].size();
    if (i < 0 || j < 0 || i >= r || j >= c) return;
    if (checked[i][j]) return;
    checked[i][j] = 1;
    if (field[i][j]) return;

    frompath[i][j] = prev;
    if (i == r - 1 && j == c - 1) return;
    fill(field, i+1, j, checked, frompath, {i, j});
    fill(field, i, j+1, checked, frompath, {i, j});
}

int main() {
    // start: (0, 0) end: (m-1, n-1) obstacle:1, road:0
    // find ways by dp
    vector<vector<int>> field = {{0, 0, 0, 0, 0}, 
                                 {0, 0, 1, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 1, 0, 0},
                                 {1, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0}};
    int r = 6, c = 5;
    // if we can reach set 1, otherwise set 0
    vector<vector<int>> checked(r, vector<int>(c, 0));
    vector<vector<pair<int, int>>> frompath(r, vector<pair<int, int>>(c, {-1, -1}));

    fill(field, 0, 0, checked, frompath, {0, 0});

    int i = r-1;
    int j = c-1;
    cout << i << " " << j << endl;
    while (!(i == 0 && j == 0)) {
        auto [ci, cj] = frompath[i][j];
        cout << ci << " " << cj << endl;
        tie(i, j) = frompath[i][j];
    }
}