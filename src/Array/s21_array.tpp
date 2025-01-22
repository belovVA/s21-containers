#include "s21_array.h"

namespace s21 {

template <typename T, size_t N>
array<T, N>::array() noexcept {}

template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
  size_type i = 0;
  for (const auto &item : items) {
    arr[i++] = item;
  }
}

template <typename T, size_t N>
array<T, N>::array(const array &a) {
  std::copy(a.arr, a.arr + N, arr);
}

template <typename T, size_t N>
array<T, N>::array(array &&a) noexcept {
  swap(a);
}

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(array &&a) noexcept {
  if (this != &a) {
    swap(a);
  }
  return *this;
}

template <typename T, size_t N>
array<T, N> &array<T, N>::operator=(const array &a) {
  if (this != &a) {
    std::copy(a.arr, a.arr + N, arr);
  }
  return *this;
}

template <typename T, size_t N>
array<T, N>::~array() {}

// Element access
template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
  if (pos >= N) throw std::out_of_range("Index out of range");

  return arr[pos];
}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
  return arr[pos];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::front() const noexcept {
  return arr[0];
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::back() const noexcept {
  return arr[N - 1];
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::data() noexcept {
  return (N == 0) ? nullptr : arr;
}

// Iterators
template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::begin() noexcept {
  return arr;
}

template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::end() noexcept {
  return arr + N;
}

// Capacity
template <typename T, size_t N>
bool array<T, N>::empty() const noexcept {
  return size() == 0;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::size() const noexcept {
  return N;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::max_size() const noexcept {
  return N;
}

// Modifiers
template <typename T, size_t N>
void array<T, N>::swap(array &other) noexcept {
  std::swap_ranges(arr, arr + N, other.arr);
}

template <typename T, size_t N>
void array<T, N>::fill(const_reference value) noexcept {
  std::fill(arr, arr + N, value);
}

}  // namespace s21