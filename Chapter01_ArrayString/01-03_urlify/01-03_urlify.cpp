#include <iostream>
#include <string>
using namespace std;
string urlify (string s, int n) {
  auto pos = s.find(" ");
  string ans = "";
  int pos_begin = 0;
  while (pos != std::string::npos) {
    ans += s.substr(pos_begin, pos - pos_begin);
    ans += "%20";
    pos_begin = pos + 1;
    pos = s.find(" ", pos + 1);
  }
  return ans;
}

int main() {
  string s = "Mr John Smith";
  int n = 13;
  cout << urlify(s, n) << endl;
}