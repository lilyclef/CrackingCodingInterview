#include <iostream>
#include <vector>
#include <map>

using namespace std;

//algorithm -> aighlmort
//aoringo -> aignoor : O(NlogN) >  O(N) : O(1)

bool check (string s) {
    vector<int> map(26, 0); // 4byte 32bit * 26
    for (int i = 0; i < s.length(); i++) {
        if (map[s[i]] == 1) return true;
        map[s[i]] = 1;
    }
    return false;

}

int main() {
    string s;
    cin >> s;
    if (check(s)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
}