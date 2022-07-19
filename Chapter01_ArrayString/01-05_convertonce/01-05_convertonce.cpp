
#include <iostream>
using namespace std;
bool convert(string s1, string s2) {
int s1_len = s1.size();
int s2_len = s2.size();
	if (abs(s1_len - s2_len) > 1) return false;
	int i = 0, j = 0;
int one_flag = false;
	while (i < s1_len || j < s2_len) {
		if (s1[i] == s2[j]) {
			i++; j++;
			continue;
		}
		if (one_flag) return false;
		one_flag = true;
		if (s1_len > s2_len) {
			i++;
		} else if (s1_len < s2_len) {
			j++;
		} else {
			i++; j++;
		}
	}
	return true;
}
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << (convert(s1, s2) ? "True" : "False") << endl;
}
