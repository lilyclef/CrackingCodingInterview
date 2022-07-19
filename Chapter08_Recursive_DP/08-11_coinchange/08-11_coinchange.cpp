// https://leetcode.com/problems/coin-change/ => 今回は場合の数。リンク先は最小枚数
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int coinChangeRec(vector<int>& coins, int amount, int index, map<pair<int, int>, int>& memo) {
    if (index == coins.size() - 1) return 1;
    if (memo.find({amount, index}) != memo.end()) return memo[{amount, index}];
    int coin_val = coins[index];
    int sum = 0;
    for (int i = 0; i * coin_val <= amount; i++) {
        int tmp = amount - i * coin_val;
        sum += coinChangeRec(coins, tmp, index+1, memo);
    }
    memo[{amount, index}] = sum;
    return sum;
}

int coinChangeDP(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); ++i) {
        for (int j = 0; j <= amount; ++j) {
            if (j + coins[i] > amount) continue;
            dp[j + coins[i]] += dp[j];
        }
    }
    return dp[amount];
}

int main (void) {
    int amount;
    std::cin >> amount;
    std::vector<int> coins = {25, 10, 5, 1};
    cout << coinChangeDP(coins, amount) << endl;
    map<pair<int, int>, int> memo;
    cout << coinChangeRec(coins, amount, 0, memo) << endl;
}