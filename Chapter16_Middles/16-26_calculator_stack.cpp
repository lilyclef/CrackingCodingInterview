// https://leetcode.com/problems/basic-calculator-iii/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// + - * / () double : stack解法

// string:12+4 -> vector<string> 12, +, 4
vector<string> parse(string &s) {
  vector<string> ans;
  int i = 0;
  while (i < s.size()) {
    if (isdigit(s[i])) {
      int j = i + 1;
      while (j < s.size() && isdigit(s[j])) {
        j++;
      }
      ans.push_back(s.substr(i, j - i));
      i = j;
      continue;
    }
    ans.push_back(s.substr(i, 1));
    i++;
  }
  return ans;
}
bool is_digit(string &s) {
  return isdigit(s[0]);
}
int get_num_symbol(char a) {
  switch (a) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  case '(':
  case ')':
    return 0;
  case '$':
    return -1;
  default:
    return -2;
  }
}
bool compare_symbols(char a, char b) {
  return get_num_symbol(a) > get_num_symbol(b);
}
double calc_act(double n1, double n2, char o) {
  switch (o) {
  case '+':
    return n1 + n2;
  case '-':
    return n1 - n2;
  case '*':
    return n1 * n2;
  case '/':
    return n1 / n2;
  }
  return 0;
}

double calc(string s) {
  // 12+3 -> 12, +, 3
  vector<string> input = parse(s);
  // 終了時用に弱い演算子を入れておくことで別処理をしなくて住む
  input.push_back("$");
  // stackの代わりにvectorを使うとデバッグでi番目が確認できるので楽
  vector<double> numbers;
  vector<char> symbols;
  // 開始時に最弱の演算子を入れておく symbol stackのサイズが0の時の別処理をやらなくて済む
  symbols.push_back('^');
  int i = 0;
  while (i < input.size()) {
    if (is_digit(input[i])) { // 数字が来たら問答無用でnumber stackへ
      numbers.push_back(stod(input[i]));
      i++;
      continue;
    }
    // シンボル処理 topと比較しつつ行う
    char top = symbols.back();

    // 開けたカッコを閉じるとき、symbolsのtopが(であれば、すでに処理が終了しているのでカッコを取り除く
    if (top == '(' && input[i][0] == ')') {
      symbols.pop_back();
      i++;
      continue;
    }

    // シンボルスタックに積みたい時は、(が来た時と新しく来たシンボルのほうが強いとき
    if (input[i][0] == '(' || compare_symbols(input[i][0], top)) {
      symbols.push_back(input[i][0]);
      i++;
      continue;
    }
    // 新しく来たシンボルが弱い等で、スタックに積まれた値を計算したい時
    double n1 = numbers.back();
    numbers.pop_back();
    double n2 = numbers.back();
    numbers.pop_back();
    double ans_tmp = calc_act(n2, n1, top);
    symbols.pop_back();
    numbers.push_back(ans_tmp);
  }
  return numbers.back();
}

int main()
{
  vector<string> inputs = {"1+3-2+4", "3-1*2", "1*2-3/1-2", "2*3+5/6*3+15"};
  for (string &in : inputs)
  {
    cout << calc(in) << endl;
  }
}