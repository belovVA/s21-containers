#include "s21_set.h"

namespace s21 {
template <typename Key>
set<Key>::set() : BinaryTree<Key>() {}

template <typename Key>
set<Key>::set(std::initializer_list<value_type> const &items)
    : BinaryTree<Key>(items) {}

template <typename Key>
set<Key>::set(const set &s) : BinaryTree<Key>(s) {}

template <typename Key>
set<Key>::set(set &&s) : BinaryTree<Key>(std::move(s)) {}

template <typename Key>
set<Key>::~set() {}

template <typename Key>
set<Key> &set<Key>::operator=(set<Key> &&other) {
  BinaryTree<Key>::operator=(std::move(other));
  return *this;
}

template <typename Key>
void set<Key>::insert_many(const std::vector<value_type> &items) {
  for (const auto &item : items) {
    this->insert(item);
  }
}
}  // namespace s21