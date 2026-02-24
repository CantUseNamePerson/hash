#include <iostream>
#include <string>
#include <unordered_map>


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
        c); // add current bits from c (the char) and change the type to unsigned long long
    hash *= 1099511628211ULL; // multiply by FNV_prime
  }
  return hash;
}

// my custom hash
unsigned long long custom(std::string &str) {
  unsigned long long hash = 0; // magic number
  // for every char in str
  for (char c : str) {
    hash ^= static_cast<unsigned long long>(c); // from fnv-1a
    hash *= 0x55fa & 67 | 0x310fff ^ c;         // multiply by random number
  }
  return hash;
}

// test
void test() {
  int collision = 0;
  std::unordered_map<unsigned long long, std::string> seen;
  for (char a = '0'; a <= 'z'; a++) {
    for (char b = '0'; b <= 'z'; b++) {
      for (char c = '0'; c <= 'z'; c++) {
        std::string s = {a, b, c};
        unsigned long long hash = custom(s);
        if (seen.count(hash)) {
          collision++;
          std::cout << "Collision: " << s << " and " << seen[hash] << " both hash to " << hash << "\n";
        } else {
          seen[hash] = s;
          // std::cout << "No collision, for: " << s << ", hash is: " << hash << '\n';
        }
      }
    }
  }
  std::cout << "Total collisions: " << collision << '\n';
  return;
}

// main
int main() {
    test();
}
