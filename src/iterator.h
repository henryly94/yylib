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

  reference operator*() { return *ptr_; }

  pointer operator->() const { return ptr_; }

  basic_iterator& operator++() {
    ptr_++;
    return *this;
  }

  basic_iterator operator++(int) {
    pointer tmp_ptr = ptr_;
    ++(*this);
    return basic_iterator(tmp_ptr);
  }

  basic_iterator& operator--() {
    ptr_--;
    return *this;
  }

  basic_iterator operator--(int) {
    pointer tmp_ptr = ptr_;
    --(*this);
    return basic_iterator(tmp_ptr);
  }

  bool operator==(const basic_iterator& other) const {
    return ptr_ == other.ptr_;
  }

  bool operator!=(const basic_iterator& other) const {
    return ptr_ != other.ptr_;
  }

 private:
  pointer ptr_;
};

}  // namespace yylib

#endif  // ITERATOR_H
