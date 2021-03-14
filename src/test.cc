#include <iostream>
#include <string>

#include "vector.h"

int main() {
  yylib::vector<int> v(5), q;

  std::cout << v.at(0) << v.at(1) << v.at(2) << std::endl;
  v.assign(3, 1);

  std::cout << v.at(0) << v.at(1) << v.at(2) << std::endl;

  yylib::vector<std::string> s;
  s.assign(3, "abdc");
  std::cout << s.begin()->size() << std::endl;
  return 0;
}
