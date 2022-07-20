// No Duplicated Numbers
// https://leetcode.com/problems/search-in-rotated-sorted-array/
// 1 3 4 5 7 10 14 15 16 19 20 25 

// 15 16 19 20 25 1 3 4 5 7 10 14
// target = 5

// begin : [0] -> 15
// mid : [5] -> 1
// end : [11] -> 14

// begin : [5] -> 1
// mid : [8] -> 5
// end : [11] -> 14

#include<iostream>
#include<vector>
using namespace std;

// binary search - open close close close
int findTargetFromRotate(vector<int>& nums, int target) {
    int begin = 0;
    int end = nums.size() - 1;
    int mid = (begin + end) / 2;

    // [3, 1] target = 1
    while (begin <= end) {
        mid = (begin + end) / 2;
        // found
        if (nums[mid] == target) return mid;

        /*if (end - begin == 1) {
            if (nums[end] == target) return end;
        }
        */
        // beginよりもmidが大きい時
        if (nums[begin] <= nums[mid])  {
            if (nums[begin] <= target && target < nums[mid]) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[end]) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;

}

int main() {
    int n;
    cin >> n;
    vector<int> nums = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    cout << findTargetFromRotate(nums, n) << endl;
}

