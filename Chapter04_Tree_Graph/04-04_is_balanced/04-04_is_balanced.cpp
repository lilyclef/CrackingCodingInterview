// https://leetcode.com/problems/balanced-binary-tree/
#include<iostream>
#include<vector>
#include <climits>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v) {};
};

bool checkHeight(Node* root) {
    if (!root) return -1; // 両腕がnullのものを0にする
    int left_height = checkHeight(root->left);
    if (left_height == INT_MIN) return INT_MIN;
    int right_height = checkHeight(root->right);
    if (right_height == INT_MIN) return INT_MIN;
    int height_diff = abs(left_height - right_height);
    if (height_diff > 1) {
        return INT_MIN;
    }
    return max(left_height, right_height) + 1;
}

bool is_balanced(Node* root) {
    return checkHeight(root) != INT_MIN;
}


Node* createTree(vector<int>& input, int begin, int end) {
    if (begin > end) return nullptr;
    int mid = (begin + end) / 2;
    Node* node = new Node(input[mid]);
    Node* left = createTree(input, begin, mid - 1);
    Node* right = createTree(input, mid + 1, end);
    node->left = left;
    node->right = right;
    return node;
}

int main () {
    vector<int> input = {1, 4, 7, 9, 10, 11, 12, 20, 50, 100};
    Node* head = createTree(input, 0, input.size() - 1);
}