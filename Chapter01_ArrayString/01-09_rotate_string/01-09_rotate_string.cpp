#include <iostream>
using namespace std;
template<class T> bool contain(const std::string& s, const T& v) {
   return s.find(v) != std::string::npos;
}
bool isSubstring(string s, string t) {
  return contain(s, t);
}

bool isRotatePair(string s1, string s2) {
  return isSubstring(s2+s2, s1);
}

int main () {
  string s = "yuririn";
  string t = "rinrinyu";
  
  if (isRotatePair(s, t)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
}