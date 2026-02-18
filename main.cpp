#include <iostream>
int djb2(std::string &str) {
  int hash = 5381;
  for (char c : str) {
    hash = (hash << 5) + hash + c;
  }
  return hash;
}
int main() {
  std::string str;
  std::cin >> str;
  int hash = djb2(str);
  std::cout << hash << '\n';
}
