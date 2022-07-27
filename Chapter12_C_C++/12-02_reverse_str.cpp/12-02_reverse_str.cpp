#include <iostream>

void reverse(char* str) {
  int count = 0;
  // null 終端間違えた。
  while(str[count] != '\0') {
    count++;
  }
  for (int i = 0; i < count / 2; ++i) {
    char tmp = str[i];
    str[i] = str[count - i - 1];
    str[count -i - 1] = tmp;
  }
}

int main () {
  // char [] : ISO C++ forbids converting a string constant to 'char*'
  char input[] = "abcdefg";
  reverse(input);
  std::cout << input << std::endl;
  return 0;
}