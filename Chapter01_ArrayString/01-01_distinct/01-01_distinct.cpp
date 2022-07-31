#include<iostream>

int main () {
    std::string s;
    std::cin >> s;
    for(int i = 0;  i < s.length() - 1; i++){
    for(int j = i+1; j < s.length(); j++){
      if (s[i] == s[j]) {
                std::cout << "T" << std::endl;
        return true;
      }
        }
    }
    std::cout << "F" << std::endl;
    return false;
}

// CPUの速さ 1GB Hz 1秒に 10^9 * 8 bit 処理できる
// N^2 (10^5) ^2 ぐらいで10^9を超える
// 1日 10^4秒ぐらい 10^13で10^8