#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// + - * / double : stack使わない解法

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
vector<pair<char, double>> parseTerm(string& s) {
  vector<pair<char, double>> ans;
  vector<string> parsed = parse(s);
  // ()なし・単項なし前提 // inputエラーありうる
  ans.push_back({'^', stod(parsed[0])});
  for (int i = 1; i < parsed.size(); i += 2) {
    if (!isdigit(parsed[i+1][0])) throw "parseTerm error";
    ans.push_back({parsed[i][0], stod(parsed[i+1])});
  }
  return ans;
}

double applyOp(double left, char op, double right) {
  switch(op) {
    case '+':
      return left + right;
    case '-':
      return left - right;
    case '*':
      return left * right;
    case '/':
      return left / right;
    default:
      return right;
  }
}

pair<char, double> collapseTerm(pair<char, double>& a, pair<char, double>& b) {
  if (!a.first) return b;
  if (!b.first) return a;
  double val = applyOp(a.second, b.first, b.second);
  a.second = val;
  return a;
}

double calc(string s) {
  vector<pair<char, double>> input = parseTerm(s);
  input.push_back({'$', 0});
  double result = 0;
  pair<char, double> processing;

  for (int i = 0; i < input.size() - 1; i++) {
    auto current = input[i];
    auto next = input[i+1];
    processing = collapseTerm(processing, current);
    if (next.first == '$' || next.first == '+' || next.first == '-') {
      result = applyOp(result, processing.first, processing.second);
      processing = {}; // 初期化
    }
  }
  return result;
}

int main() {
  vector<string> inputs = {"1+3-2+4", "3-1*2", "1*2-3/1-2", "2*3+5/6*3+15"};
  for (string& in : inputs) {
    cout << calc(in) << endl;
  }
}