#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

#include "allocator.h"
#include "iterator.h"

namespace yylib {

template <typename T, typename Allocator = allocator<T>>
class vector {
 public:
  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;
  using allocator_type = Allocator;
  using iterator_type = basic_iterator<T>;

  vector() : data_(nullptr), allocator_() {}
  vector(size_type n) { data_ = allocator_.allocate(n); }

  reference at(size_type i) { return data_[i]; }
  const_reference at(size_type i) const { return data_[i]; }

  void assign(size_type count, const_reference value) {
    if (data_ != nullptr) {
      allocator_.deallocate(data_, size_);
    }
    data_ = allocator_.allocate(count);
    for (size_type i = 0; i < count; i++) {
      data_[i] = value;
    }
  }

  iterator_type begin() { return iterator_type(data_); }

 private:
  allocator_type allocator_;
  pointer data_;
  size_type size_;
};

}  // namespace yylib

#endif  // VECTOR_H
