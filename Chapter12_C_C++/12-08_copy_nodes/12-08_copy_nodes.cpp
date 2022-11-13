#include<iostream>
#include<map>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) {
        val = v;
    }
    Node(int v, Node* l, Node* r) {
        val = v;
        left = l;
        right = r;
    }
};

map<Node*, Node*> memo;

Node* copyNode(Node* org) {
    if (!org) return nullptr;
    // コピー済みをチェック ノードを変えるのはちょっとやだ。
    // 既に渡されたノードの新しいノードが生成されている時
    if (memo.find(org) != memo.end()) return memo[org];
    Node* newLeft = copyNode(org->left);
    Node* newRight = copyNode(org->right);
    Node* newNode = new Node(org->val, newLeft, newRight);
    memo[org] = newNode;
    return newNode;
}

int main () {
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3, first, second);
    Node* ans = copyNode(third);
}