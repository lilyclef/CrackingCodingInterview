#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) : val(v) {}
    Node(int v, Node* n) : val(v), next(n) {}
};


void remove_target(Node* node, Node* target) {
  if (node == target) {
    node = target->next;
    return;
  }
  while (node->next) {
    if (node->next == target) {
      node->next = target->next;
    }
    node = node->next;
  }
}


void remove_target_original(Node* target) {
  if (!target) return;
  if (!target->next) {
    target = nullptr;
    return;
  }
  target->val = target->next->val;
  target->next = target->next->next;
}


int main () {
    // [1]->[2]->[2]->[3]->[1]->[4]
    Node* node6 = new Node(4);
    Node* node5 = new Node(1, node6);
    Node* node4 = new Node(3, node5);
    Node* node3 = new Node(2, node4);
    Node* node2 = new Node(2, node3);
    Node* node1 = new Node(1, node2);
    remove_target(node1, node3);
    Node* curr = node1;
    while(curr) {
      cout << curr->val << endl;
      curr = curr->next;
    }
}