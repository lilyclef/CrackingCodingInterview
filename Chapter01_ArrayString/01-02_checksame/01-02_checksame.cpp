#include<iostream>
#include<algorithm>

using namespace std;
bool compare(string& s1, string& s2) {
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
    return s1 == s2;
}

int main () {
  string s1, s2;
  std::cin >> s1 >> s2;
    cout << (compare(s1, s2) ? "true" : "else") << endl;
}