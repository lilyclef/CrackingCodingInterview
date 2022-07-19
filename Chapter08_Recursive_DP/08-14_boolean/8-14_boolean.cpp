#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, pair<int, int>> memo;

pair<int, int> __countParan(const string &s)
{
    // stop
    if (s.length() == 1 && s[0] == '1')
        return {1, 0};
    if (s.length() == 1 && s[0] == '0')
        return {0, 1};

    // edge
    if (s.length() == 0)
        return {0, 0};

    if (memo.find(s) != memo.end()) return memo[s];

    // 区切りをどこで入れるか？
    int ans_true = 0;
    int ans_false = 0;
    for (int i = 1; i < s.length(); i += 2)
    {
        auto [lt, lf] = __countParan(s.substr(0, i));
        auto [rt, rf] = __countParan(s.substr(i + 1));

        if (s[i] == '^')
        {
            ans_true += lt * rf + lf * rt;
            ans_false += lt * rt + lf * rf;
        }
        else if (s[i] == '|')
        {
            ans_true += lt * rf + lf * rt + lt * rt;
            ans_false += rf * lf;
        }
        else if (s[i] == '&')
        {
            ans_true += lt * rt;
            ans_false += lt * rf + lf * rt + lf * rf;
        }
    }
    memo[s] = {ans_true, ans_false};
    return {ans_true, ans_false};
}
int countParan(const string &s, const bool target)
{
    auto [true_res, false_res] = __countParan(s);
    return target ? true_res : false_res;
}

int main()
{
    string s;
    cin >> s;
    string bs;
    bool target;
    cin >> bs;
    target = bs == "T" ? true : false;
    cout << countParan(s, target) << endl;
}