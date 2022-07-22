// https://leetcode.com/problems/binary-tree-level-order-traversal/
#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v) {};
};

// 再帰で解くとき、どの情報を引数におくべきか、返り値はvoidか答えなのか、考えてから書き始める。
// グローバル変数として扱いたいときは参照渡しになると思う。
// levelは上から伝播させるものなので、引数に必要。
void createLevelLList(Node* node, vector<list<Node*>>& ans, int level) {
    if (!node) return;
    if (level == ans.size()) {
        ans.push_back({});
    }
    ans[level].push_back(node);
    createLevelLList(node->left, ans, level + 1);
    createLevelLList(node->right, ans, level + 1);
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
    vector<list<Node*>> ans;
    vector<int> input = {1, 4, 7, 9, 10, 11, 12, 20, 50, 100};
    Node* head = createTree(input, 0, input.size() - 1);
    createLevelLList(head, ans, 0);
    for (auto& anslst : ans) {
        for (auto& ansnode : anslst) { // listはforが使える
            cout << ansnode->val << " ";
        }
        cout << endl;
    }
}