#include "s21_multiset.h"

namespace s21 {

template <typename Key>
multiset<Key>::multiset() : BinaryTree<Key>() {
  this->SetMultiset(true);
}

template <typename Key>
multiset<Key>::multiset(std::initializer_list<value_type> const &items)
    : multiset() {
  this->SetMultiset(true);
  for (const auto &item : items) {
    insert(item);
  }
}

template <typename Key>
multiset<Key>::multiset(const multiset &s) : BinaryTree<Key>(s) {}

template <typename Key>
multiset<Key>::multiset(multiset &&s) : BinaryTree<Key>(std::move(s)) {}

template <typename Key>
multiset<Key>::~multiset() {}

template <typename Key>
multiset<Key> &multiset<Key>::operator=(const multiset<Key> &other) {
  if (this != &other) {
    BinaryTree<Key>::operator=(other);
  }
  return *this;
}

template <typename Key>
multiset<Key> &multiset<Key>::operator=(multiset<Key> &&other) {
  if (this != &other) {
    BinaryTree<Key>::operator=(std::move(other));
  }
  return *this;
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::insert(
    const value_type &value) {
  BinaryTree<Key>::insert(value);
  return this->find(value);
}

template <typename Key>
void multiset<Key>::insert_many(const std::vector<value_type> &items) {
  for (const auto &item : items) {
    insert(item);
  }
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::lower_bound(const Key &value) {
  iterator it = this->begin();
  while (it != this->end() && *it < value) {
    ++it;
  }
  return it;
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::upper_bound(const Key &value) {
  iterator it = this->begin();
  while (it != this->end() && *it <= value) {
    ++it;
  }
  return it;
}

template <typename Key>
typename multiset<Key>::size_type multiset<Key>::count(const Key &key) const {
  size_type cnt = 0;
  for (auto it = this->begin(); it != this->end(); ++it) {
    if (*it == key) {
      ++cnt;
    }
  }
  return cnt;
}

template <typename Key>
std::pair<typename multiset<Key>::iterator, typename multiset<Key>::iterator>
multiset<Key>::equal_range(const Key &key) {
  return {lower_bound(key), upper_bound(key)};
}

}  // namespace s21