// https://leetcode.com/problems/validate-binary-search-tree/
#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v) {};
};


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

 bool __isValidBST(Node* root, long int min_v, long int max_v) {
        if (!root) return true;
        if (root->val <= min_v || root->val >= max_v) return false;
        return __isValidBST(root->left, min_v, root->val) && __isValidBST(root->right, root->val, max_v);
    }
    bool isValidBST(Node* root) {
        return __isValidBST(root, LONG_MIN, LONG_MAX);
    }

int main () {
    vector<int> input = {1, 4, 7, 9, 10, 11, 12, 20, 50, 100};
    Node* head = createTree(input, 0, input.size() - 1);
    if (isValidBST(head)) cout << "true" << endl;
}