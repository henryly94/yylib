#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstddef>

namespace yylib {

template <typename T>
class allocator {
 public:
  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  allocator() = default;

  pointer allocate(size_type n) { return new T[n]; }

  void deallocate(pointer p, size_type n) {
    delete[] p, n;
    p = nullptr;
  }
};

}  // namespace yylib

#endif  // ALLOCATOR_H
