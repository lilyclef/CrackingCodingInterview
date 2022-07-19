#include<iostream>
#include<vector>

using namespace std;
// Accept duplicate numbers
int __find_magic_index(vector<int>& nums, int begin, int end) {
    if (end < begin) return -1;
    int mid = (begin + end) / 2;
    if (mid == nums[mid]) return mid;

    int left_index = min(mid - 1, nums[mid]);
    int left_ans = __find_magic_index(nums, begin, left_index);
    if (left_ans >= 0) {
        return left_ans;
    }
    int right_index = min(mid + 1, nums[mid]);
    int right_ans = __find_magic_index(nums, right_index, end);
    return right_ans;
}
int find_magic_index(vector<int>& nums) {
    return __find_magic_index(nums, 0, nums.size() - 1);
}

int main () {
    vector<int> input = {-100, -10, -3, -3, 1, 4, 6, 6, 12, 20};
    cout << find_magic_index(input) << endl;
}