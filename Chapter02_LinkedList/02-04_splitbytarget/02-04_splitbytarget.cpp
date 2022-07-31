#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) : val(v) {}
    Node(int v, Node* n) : val(v), next(n) {}
};


Node* split_by_target(Node* node, int target) {
  Node* smallers = new Node(-1); // ダミー
  Node* smallers_head = smallers;
  Node* node_head = node;
  while(node) {
    if (node->val < target) {
      // 小さいものを登録する
      Node* new_small_node = new Node(node->val);
      smallers->next = new_small_node;
      smallers = smallers->next;
      // 小さいものを弾く
      if (!node->next) { // 一番最後のものがtargetより小さかった
        node = nullptr;
        break;
      }
      node->val = node->next->val;
      node->next = node->next->next;
      continue;
    }
    node = node->next;
  }
  smallers->next = node_head;
  return smallers_head->next;
}

int main () {
    // [1]->[2]->[2]->[3]->[1]->[4]
    Node* node6 = new Node(4);
    Node* node5 = new Node(1, node6);
    Node* node4 = new Node(3, node5);
    Node* node3 = new Node(2, node4);
    Node* node2 = new Node(2, node3);
    Node* node1 = new Node(1, node2);
    Node* curr = split_by_target(node1, 2);
    while(curr) {
      cout << curr->val << endl;
      curr = curr->next;
    }
}