#ifndef SRC_S21_MULTISET_H_
#define SRC_S21_MULTISET_H_

#include "../Tree/s21_tree.h"

namespace s21 {
template <typename Key>
class multiset : public BinaryTree<Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename BinaryTree<Key>::iterator;
  using const_iterator = const typename BinaryTree<Key>::const_iterator;
  using size_type = size_t;

  multiset();
  multiset(std::initializer_list<value_type> const &items);
  multiset(const multiset &s);
  multiset(multiset &&s);
  ~multiset();
  multiset<Key> &operator=(const multiset<Key> &other);
  multiset<Key> &operator=(multiset<Key> &&other);

  iterator insert(const value_type &value);
  void insert_many(const std::vector<value_type> &items);

  iterator lower_bound(const Key &value);
  iterator upper_bound(const Key &value);
  size_type count(const Key &key) const;
  std::pair<iterator, iterator> equal_range(const Key &key);
};

}  // namespace s21

#include "s21_multiset.tpp"

#endif  // SRC_S21_MULTISET_H_
