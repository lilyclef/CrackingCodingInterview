#include <iostream>
#include <set>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) : val(v) {}
    Node(int v, Node* n) : val(v), next(n) {}
};
Node* removeNodes(Node* node) {
	set<int> table;
	Node* curr = new Node(0);
    // [0]->[1]->[2]->[3]->[4]
    //  ^ans                ^ curr
    // [1]->[2]->[2]->[3]->[1]->[4]
    Node* ans = curr;
	while (node) {
		if (table.find(node->val) != table.end()) { // 既にある時
		    node = node->next;
			continue;
		}
        // 初めてその値が登場した時
		table.insert(node->val);
		curr->next = new Node(node->val);
        curr = curr->next;
		node = node->next;
    }
    return ans->next;
}

int main() {
    // [1]->[2]->[2]->[3]->[1]->[4]
    Node* node6 = new Node(4);
    Node* node5 = new Node(1, node6);
    Node* node4 = new Node(3, node5);
    Node* node3 = new Node(2, node4);
    Node* node2 = new Node(2, node3);
    Node* node1 = new Node(1, node2);
    Node* head = removeNodes(node1);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}
