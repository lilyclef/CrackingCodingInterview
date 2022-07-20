#include<iostream>
#include<vector>
#include<string>

using namespace std;

int __search(vector<string>& input, string& target, int start, int end) {
    if (start > end) return -1;
    int mid = (start + end) / 2;
    // 空を飛ばす
    if (input[mid] == "") {
        int left = mid - 1;
        int right = mid + 1;
        while (true) {
            if (left < start && right > end) {
                return -1;
            } else if (right <= end && input[right] != "") {
                mid = right;
                break;
            } else if (left >= start && input[left] != "") {
                mid = left;
                break;
            }
            left--;
            right++;
        }
    }

    if (input[mid] == target) return mid;
    if (input[mid] < target) {
        int right = __search(input, target, mid+1, end);
        if (right != -1) return right;
    }
    int left = __search(input, target, start, mid-1);
    return left;
}

int search(vector<string>& input, string& target) {
    if (input.size() == 0 || target.size() == 0) return -1; // 下を書くときに気にしておく
    return __search(input, target, 0, input.size() - 1);
}

int main () {
    vector<string> input = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    string target = "ball";
    cout << search(input, target) << endl;
}