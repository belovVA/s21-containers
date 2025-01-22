#ifndef S21_ARRAY_H
#define S21_ARRAY_H

#include <initializer_list>

namespace s21 {

template <typename T, size_t N>
class array {
 public:
  /* Member type */

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  /* Functions */

  array() noexcept;
  array(std::initializer_list<value_type> const &items);
  array(const array &a);
  array(array &&a) noexcept;
  ~array();
  array &operator=(const array &a);
  array &operator=(array &&a) noexcept;

  /* Element access */

  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  const_reference front() const noexcept;
  const_reference back() const noexcept;
  iterator data() noexcept;
  const_iterator data() const noexcept;

  /* Iterators */

  iterator begin() noexcept;
  iterator end() noexcept;

  /* Capacity */

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  /* Modifiers */

  void swap(array &other) noexcept;
  void fill(const_reference value) noexcept;

 private:
  value_type arr[N];
};

}  // namespace s21

#include "s21_array.tpp"

#endif