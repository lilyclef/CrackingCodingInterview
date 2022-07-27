#include<iostream>
#include<random>

using namespace std;
int rand5() {
  random_device seed_gen;
  mt19937 engine(seed_gen());
  return engine() % 5;
}

int rand7() {
  while(true) {
    int num = 5 * rand5() * rand5();
    if (num < 21) {
      return num % 7;
    }
  }
}

int main() {
  // 解答見た
  cout << rand7();

}