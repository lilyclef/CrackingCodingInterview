#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    string s;
    // cin >> s;
    getline(cin, s);
    unordered_map<char, int> mp;
    for (char c : s)
    {
        if (c == ' ') continue;
        mp[tolower(c)]++;
    }
    int odd_count = 0;
    for (auto iter = mp.begin(); iter != mp.end(); ++iter)
    {
        cout << iter->first << " " << iter->second << endl;
        if (iter->second % 2)
            odd_count++;
    }
    if (odd_count <= 1)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}
