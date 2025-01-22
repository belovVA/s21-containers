#ifndef TREE_H
#define TREE_H

#include <cstddef>
#include <initializer_list>
#include <limits>
#include <utility>

namespace s21 {
template <typename Key>
class BinaryTree {
 public:
  void SetMultiset(bool a) { is_multiset_ = a; }

  using key_type = Key;
  using value_type = key_type;
  using reference = value_type&;
  using const_reference = const value_type&;
  class iterator;
  using const_iterator = const iterator;
  using size_type = size_t;

  BinaryTree();
  BinaryTree(std::initializer_list<value_type> const& items);
  BinaryTree(const BinaryTree<key_type>& other);
  BinaryTree(BinaryTree<key_type>&& other);
  BinaryTree<key_type>& operator=(BinaryTree<key_type> other);

  ~BinaryTree();

  iterator begin() const noexcept;
  iterator end() const noexcept;

  bool empty() const noexcept;
  size_type size() const noexcept;
  size_type max_size() const noexcept;

  void clear() noexcept;
  std::pair<BinaryTree<key_type>::iterator, bool> insert(const value_type& key);
  void erase(iterator pos);
  void swap(BinaryTree<key_type>& other);
  void merge(BinaryTree<key_type>& other);

  bool contains(const Key& key);
  iterator find(const Key& key);

 protected:
  struct Node;
  bool is_multiset_ = false;

  void insert_tree(Node* node, Node* endNode);
  std::pair<BinaryTree<key_type>::iterator, bool> insert(const value_type& key,
                                                         Node* node,
                                                         Node* parent);
  void clear(Node* node);

  Node* root_ = nullptr;
  Node* end_node_ = nullptr;
  size_t size_tree_ = 0;
};

template <typename key_type>
struct BinaryTree<key_type>::Node {
  key_type key;
  Node* parent = nullptr;
  Node* left = nullptr;
  Node* right = nullptr;
};

template <typename key_type>
class BinaryTree<key_type>::iterator {
 public:
  friend class BinaryTree;
  iterator();
  iterator(const iterator& other);
  iterator(Node* node);

  key_type& operator*();
  iterator& operator=(const iterator& other);
  iterator& operator++();
  iterator operator++(int);
  iterator& operator--();
  iterator operator--(int);
  bool operator==(const iterator& other) const;
  bool operator!=(const iterator& other) const;

 private:
  Node* current;
};
}  // namespace s21

#include "s21_tree.tpp"

#endif  //  TREE_H