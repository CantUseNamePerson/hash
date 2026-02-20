#include <iostream>

// djb2 hash, popular for strings
unsigned long long djb2(std::string &str) {
  unsigned long long hash = 5381; // magic number
  // for every char in str
  for (char c : str) {
    hash = (hash << 5) + hash + c; // hash * 33 + c (the char)
  }
  return hash;
}

// fnv-1a hash, fast and general
unsigned long long fnv1a(std::string &str) {
  unsigned long long hash = 14695981039346656037ULL; // magic number
  // for every char in str
  for (char c : str) {
    hash ^= static_cast<unsigned long long>(
        c); // add current bits from c (the char) and change the type to
            // unsigned long long
    hash *= 1099511628211ULL; // multiply by FNV_prime
  }
  return hash;
}

int main() {
  std::string str;
  std::cin >> str;
  int hash = fnv1a(str);
  std::cout << hash << '\n';
}
