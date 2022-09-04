#include<iostream>
#include<stack>

using namespace std;

class Node {
public:
    char val;
    Node* next;
    Node(int v) {
      val = v;
    }
};

bool isKaibun(Node* head, int length) {
    stack<char> st;
    Node* curr = head;

    for (int i = 0; i < length/2; i++)   {
      st.push(curr->val);
      curr = curr->next;
  }

  if (length % 2) curr = curr->next;

  /*for (int i = 0; i < length/2; i++) {
    char top = st.top();
    st.pop();
    if (top != curr->val) return false;
  }*/
  return true;
}

int main () {
    string s = "madam";
    Node* head = new Node('-');
    Node* curr = head;
    for (int i = 0; i < s.size(); i++) {
      Node* tmp = new Node(s[i]);
      curr->next = tmp;
      curr = curr->next;
  }
  if (isKaibun(head->next, s.size())) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
}