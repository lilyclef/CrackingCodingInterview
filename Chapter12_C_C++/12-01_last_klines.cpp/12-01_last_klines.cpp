#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
// https://www.cplusplus.com/doc/tutorial/files/
int main () {
  ifstream file ("text");
  string line;
  int k = 7;
  std::vector<string> arr(k);
  int i = 0;
  if (file.is_open()) {
    while (std::getline(file, line)) {
      arr[i % k] = line;
      i++;
    }
    file.close();
  }
  // 順番が狂っているのを戻さないといけない。<- 忘れていたので
  int start = (i+1) % k;
  for (int j = start; j < start + arr.size(); ++j) {
    std::cout << arr[(start + j) % k] << std::endl;
  }
  return 0;
}