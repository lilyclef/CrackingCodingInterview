// https://leetcode.com/problems/find-if-path-exists-in-graph/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
    Node(int v) : val(v) {};
};

bool is_connect(Node* start, Node* end, unordered_map<Node*, int>& seen) {
    if (start == end) return true;
    queue<Node*> que;
    que.push(start);
    while (!que.empty()) {
        Node* curr = que.front();
        que.pop();
        cout << curr->val << endl;
        if (seen.find(curr) != seen.end()) continue;
        seen[curr] = 1;
        if (curr == end) return true;
        for (auto& child : curr->children) {
            que.push(child);
        }
    }
    return false;
}

int main () {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);

    a->children.push_back(b);
    b->children.push_back(a);
    a->children.push_back(c);
    c->children.push_back(a);
    c->children.push_back(d);
    d->children.push_back(c);
    e->children.push_back(f);
    f->children.push_back(e);
    unordered_map<Node*, int> mp;
    if (is_connect(a, d, mp)) {
        cout << "connected" << endl;
    } else {
        cout << "not connected" << endl;
    }
}