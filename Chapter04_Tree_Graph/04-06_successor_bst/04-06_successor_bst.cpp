#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
    Node(int v) : val(v) {};
};

Node* createTree(vector<int>& input, int begin, int end, Node* parent) {
    if (begin > end) return nullptr;
    int mid = (begin + end) / 2;
    Node* node = new Node(input[mid]);
    Node* left = createTree(input, begin, mid - 1, node);
    Node* right = createTree(input, mid + 1, end, node);
    node->left = left;
    node->right = right;
    node->parent = parent;
    return node;
}



Node* rec_succ(Node* root, int target, bool& flag) {
    if (!root) return nullptr;
    Node* ans_left = rec_succ(root->left, target, flag);
    if (ans_left) return ans_left;
    if (flag) return root;
    if (target == root->val) flag = true;
    return rec_succ(root->right, target, flag);
}

Node* succ_loop(Node* root, int target) {
    if (!root) return nullptr;
    stack<pair<Node*, int>> st;
    bool flag = false;
    st.push({root, 0});
    while(!st.empty()) {
        auto [curr, process] = st.top();
        st.pop();
        if (process == 0) {
            if (curr->val <= target && curr->right) st.push({curr->right, 0});
            st.push({curr, 1}); // 中処理
            if (curr->val >= target && curr->left) st.push({curr->left, 0});        
        } else {
            if (flag) return curr;
            if (curr->val == target) flag = true;
        }
    }
    return nullptr;
}

Node* lastMostChild(Node* root) {
    if (!root) return nullptr;
    while (root->left) {
        root = root->left;
    }
    return root;
}

Node* get_succ(Node* root, int target) {
    if (!root) return nullptr;
    Node* parent = nullptr;
    Node* current = root;
    while(1) {
        if (!current) return nullptr;
        if (target == current->val) {
            if (current->right) return lastMostChild(current->right);
            return parent;
        }
        if (target > current->val) {
            current = current->right;
        } else {
            parent = current;
            current = current->left;
        }
    }
    return nullptr;
}

int main () {
    vector<int> input = {1, 4, 7, 9, 10, 11, 12, 20, 50, 100};
    Node* head = createTree(input, 0, input.size() - 1, nullptr);

    bool flag = false;
    Node* ans = rec_succ(head, 9, flag);
    cout << ans->val << endl;

    ans = succ_loop(head, 9);
    cout << ans->val << endl;

    ans = get_succ(head, 9);
    if (!ans) cout << "null ptr" << endl;
    cout << ans->val << endl;
}