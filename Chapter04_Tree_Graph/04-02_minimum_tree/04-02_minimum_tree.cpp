#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v) {};
};

void print(Node* node) {
    if (!node) return;
    print(node->left);
    cout << node->val << " ";
    print(node->right);
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
    print(head);
}