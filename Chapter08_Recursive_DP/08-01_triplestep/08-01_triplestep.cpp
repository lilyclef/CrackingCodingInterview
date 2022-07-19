#include <iostream>
#include <unordered_map>
using namespace std;

// rec:その段に到達する組み合わせ数 fn = f n-1 + f n-2 + f n-3
int rec(int i, unordered_map<int, int>& mp) {
    if (i < 0) return 0;
    if (i == 0) return 1;
    if (mp.find(i) != mp.end()) return mp[i];
    int ans = rec(i-1, mp) + rec(i-2, mp) + rec(i-3, mp);
    mp[i] = ans;
    return ans;
}

int main(void) {
    int n;
    std::cin >> n;
    unordered_map<int, int> mp;
    std::cout << rec(n, mp) << std::endl;
}