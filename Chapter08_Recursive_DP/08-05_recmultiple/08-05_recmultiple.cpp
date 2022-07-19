#include<iostream>
using namespace std;

int __multi_rec(int smaller, int bigger) {
    if (smaller == 0) return 0;
    if (smaller == 1) return bigger;
    int half_smaller = smaller >> 1;
    int ans = __multi_rec(half_smaller, bigger);
    ans = ans << 1;
    if (smaller & 1) {
        ans += bigger;
    }
    return ans;
}

int multi_rec(int m, int n) {
    if (m < n) {
        return __multi_rec(m, n);
    } else {
        return __multi_rec(n, m);
    }
}

int main () {
    int m, n;
    cin >> m >> n;
    cout << multi_rec(m, n) << endl;
}