#include<iostream>
#include<vector>

using namespace std;
int find_magic_index(vector<int>& nums) {
    int begin = 0;
    int end = nums.size() - 1;

    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (mid == nums[mid]) return mid;
        if (mid < nums[mid]) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return -1;
}

int main () {
    vector<int> input = {-100, -10, -6, -3, 1, 4, 6, 10, 12, 20};
    cout << find_magic_index(input) << endl;
}