#include <iostream>
using namespace std;
int main()
{
  string input;
  cin >> input;
  string ans;
  char before_char;
  int before_char_count = 1;

  for (int i = 0; i < input.size(); ++i)
  {
    if (input[i] == before_char)
    {
      before_char_count++;
      continue;
    }
    ans += before_char;
    if (before_char_count > 1)
    {
      ans += to_string(before_char_count);
    }
    before_char_count = 1;
    before_char = input[i];
  }
  ans += before_char;
  if (before_char_count > 1)
  {
    ans += to_string(before_char_count);
  }
  ans.erase(0, 1);
  cout << ans << endl;
}
