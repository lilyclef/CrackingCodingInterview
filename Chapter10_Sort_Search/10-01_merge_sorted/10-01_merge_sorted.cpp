// https://leetcode.com/problems/merge-sorted-array/
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& a, int asize, vector<int>& b, int bsize) {
    int a_index = asize - 1;
    int b_index = bsize - 1;
    for (int i = asize + bsize - 1; i >= 0; i--) {
        if (a_index < 0) {
            a[i] = b[b_index];
            b_index--;
            continue;
        }
        /*if(b_index < 0) {
            a[i] = a[a_index];
            a_index--;
            continue;
        }*/
        if (a[a_index] < b[b_index]) {
            a[i] = b[b_index];
            b_index--;
        } else {
            a[i] = a[a_index];
            a_index--;
        }
    }
}
int main() {
    vector<int> a(20);
    vector<int> b = {2, 3, 4, 6, 7};
    a[0] = 1; a[1] = 5; a[2] = 8; a[3] = 9;
    merge(a, 4, b, 5);
    for (int i = 0; i < 9; i++) {
        cout << a[i];
    }
}