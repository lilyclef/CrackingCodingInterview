#include <iostream>
#include <vector>
using namespace std;

bool checkValid(vector<int> &columns, int row1, int column1)
{
    for (int row2 = 0; row2 < row1; row2++)
    {
        int column2 = columns[row2];
        if (column1 == column2)
            return false;
        int columnDistance = abs(column2 - column1);
        int rowDistance = row1 - row2;
        if (columnDistance == rowDistance)
            return false;
    }
    return true;
}

void placeQueens(int n, int row, vector<int> &columns, vector<vector<int>> &results)
{
    if (row == n)
    {
        results.push_back(columns);
        return;
    }
    for (int col = 0; col < n; col++)
    {
        if (checkValid(columns, row, col))
        {
            columns[row] = col;
            placeQueens(n, row + 1, columns, results);
        }
    }
}

int main()
{
    int n = 8;
    vector<vector<int>> results;
    vector<int> cols(n, 0);
    placeQueens(n, 0, cols, results);
    for (auto& res : results) {
        for (auto& r : res) {
            for (int i = 0; i < n; i++) {
                if (i == r) cout << "* ";
                else cout << "- ";
            }
            cout << endl;
        }
        cout << "(=ﾟωﾟ)ﾉ" << endl;
    }
    cout << results.size() << endl;
}
