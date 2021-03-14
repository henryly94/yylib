#include <iostream>
#include <string>

#include "vector.h"

int main() {
  yylib::vector<int> v(5), q;

  v.assign(3, 1);

  v.reserve(128);
  std::cout << "After reserve\n";

  yylib::vector<std::string> s;
  s.assign(3, "abdc");

  for (int i = 0; i < 1000; i++) {
    v.push_back(i);
  }

  v.emplace_back(1);
  s.emplace_back("asdsd");
  std::cout << v.size() << std::endl;
  for (const auto& str : s) {
    std::cout << str << std::endl;
  }
  for (int i = 0; i < s.size(); i++) {
    std::cout << s[i] << std::endl;
  }
  return 0;
}
