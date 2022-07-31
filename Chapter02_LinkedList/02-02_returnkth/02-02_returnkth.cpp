#include <iostream>

using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node(int v) : val(v) {}
    Node(int v, Node* n) : val(v), next(n) {}
};

Node* ans;
// headはnullptrは入ってこない
int returnKth(Node* head, int k) {
  if (!head->next) {
    if (k == 0) ans = head;
    return 0;
  }
  int num = returnKth(head->next, k);
  if (num + 1 == k) ans = head;
  return num + 1;
}

int returnKth2(Node* head, int k) {
    Node* rabbit = head;
    Node* turtle = head;
    for (int i = 0; i < k; i++) {
        rabbit = rabbit->next;
    }
    while (rabbit->next) {
        rabbit = rabbit->next;
        turtle = turtle->next;
    }
    return turtle->val;
}

int main () {
    // [1]->[2]->[2]->[3]->[1]->[4]
    Node* node6 = new Node(4);
    Node* node5 = new Node(1, node6);
    Node* node4 = new Node(3, node5);
    Node* node3 = new Node(2, node4);
    Node* node2 = new Node(2, node3);
    Node* node1 = new Node(1, node2);
    returnKth(node1, 3);
    cout << ans->val << endl;
    //cout << returnKth2(node1, 3) << endl;
}