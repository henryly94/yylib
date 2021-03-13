#include <iostream>

#include "vector.h"

int main() {
  yylib::vector<int> v(5), q;

  std::cout << v.at(0) << v.at(1) << v.at(2) << std::endl;
  v.assign(3, 1);

  std::cout << v.at(0) << v.at(1) << v.at(2) << std::endl;
  return 0;
}
