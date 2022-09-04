#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) {
        val = v;
    }
    Node(int v, Node* n) {
        val = v;
        next = n;
    }
};
pair<bool, Node*> getCollision(Node* node1, Node* node2, int n1, int n2) {
    if (!node1 || !node2) return {false, nullptr};
    if (n1 > n2) {
        for (int i = 0; i < n1 - n2; i++) {
            node1 = node1->next;
        }
    } else {
        for (int i = 0; i <  n2 - n1; i++) {
            node2 = node2->next;
        }
    }
    // node1とnode2の長さが一致した状態
    while (node1 && node2) {
        if (node1 == node2) return {true, node1};
            node1 = node1->next;
            node2 = node2->next;
    }
    return {false, nullptr};
}

int main () {
    Node* node6 = new Node(4);
    Node* node5 = new Node(1, node6);
    Node* node4 = new Node(3, node5);
    Node* node3 = new Node(2, node4);
    Node* node2 = new Node(2, node3);
    Node* node1 = new Node(1, node2);
    Node* node2b = new Node(2, node4);
    Node* node1b = new Node(1, node2b);
    auto [flag, ans_node] = getCollision(node1, node1b, 6, 5);
    if (flag) cout << ans_node->val << endl;
}