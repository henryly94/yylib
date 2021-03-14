#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <utility>

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
  using const_iterator_type = basic_iterator<const T>;

  // Ctors.
  vector() : data_(nullptr), allocator_(), size_(0), capacity_(0) {}
  vector(size_type n) : size_(0), capacity_(n) {
    data_ = allocator_.allocate(n);
  }

  void assign(size_type count, const_reference value) {
    if (data_ != nullptr) {
      allocator_.deallocate(data_, capacity_);
    }
    data_ = allocator_.allocate(count);
    for (size_type i = 0; i < count; i++) {
      data_[i] = value;
    }
    size_ = capacity_ = count;
  }

  allocator_type get_allocator() const { return allocator_; }

  // Element Access.
  reference at(size_type i) { return data_[i]; }
  const_reference at(size_type i) const { return data_[i]; }

  reference operator[](size_type i) { return data_[i]; }
  const_reference operator[](size_type i) const { return data_[i]; }

  reference front() { return data_[0]; }
  const_reference front() const { return data_[0]; }

  reference back() { return data_[size_ - 1]; }
  const_reference back() const { return data_[size_ - 1]; }

  // Iterators.
  iterator_type begin() { return iterator_type(data_); }
  const_iterator_type cbegin() { return const_iterator_type(data_); }

  iterator_type end() { return iterator_type(data_ + size_); }
  const_iterator_type cend() { return const_iterator_type(data_ + size_); }

  // Modifiers.
  void push_back(const value_type& value) {
    if (size_ == capacity_) expansion();
    data_[size_++] = value;
  }
  void push_back(value_type&& value) {
    if (size_ == capacity_) expansion();
    data_[size_++] = value;
  }

  template <typename... Args>
  void emplace_back(Args&&... args) {
    this->push_back(value_type(std::forward<Args>(args)...));
  }

  // Capacity.
  void reserve(size_type n) {
    while (capacity_ < n) expansion();
  }

  bool empty() const { return size_ == 0; }
  size_type size() const { return size_; }
  size_type capacity() const { return capacity_; }

 private:
  void expansion() {
    size_type new_capacity = 2 * capacity_;
    new_capacity = new_capacity < 10 ? 10 : new_capacity;
    std::cout << "Expansion: " << capacity_ << ", " << new_capacity
              << std::endl;
    pointer new_data = allocator_.allocate(new_capacity);
    for (size_type i = 0; i < size_; i++) {
      new_data[i] = data_[i];
    }
    allocator_.deallocate(data_, capacity_);
    data_ = new_data;
    capacity_ = new_capacity;
  }

  allocator_type allocator_;
  pointer data_;
  size_type size_;
  size_type capacity_;
};

}  // namespace yylib

#endif  // VECTOR_H
