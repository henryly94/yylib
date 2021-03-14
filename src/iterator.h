#ifndef ITERATOR_H
#define ITERATOR_H

namespace yylib {

template <typename T>
class basic_iterator {
 public:
  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  basic_iterator() = default;
  basic_iterator(pointer ptr) : ptr_(ptr) {}

  pointer operator->() { return ptr_; }

 private:
  pointer ptr_;
};

}  // namespace yylib

#endif  // ITERATOR_H
