#include "s21_tree.h"

namespace s21 {
template <typename T>
BinaryTree<T>::iterator::iterator() : current(nullptr) {}

template <typename T>
BinaryTree<T>::iterator::iterator(const iterator& other) {
  this->current = other.current;
}

template <typename T>
BinaryTree<T>::iterator::iterator(Node* node) : current(node) {}

template <typename T>
T& BinaryTree<T>::iterator::operator*() {
  return current->key;
}

template <typename T>
typename BinaryTree<T>::iterator& BinaryTree<T>::iterator::operator=(
    const iterator& other) {
  if (this != &other) {
    current = other.current;
  }
  return *this;
}

template <typename T>
typename BinaryTree<T>::iterator& BinaryTree<T>::iterator::operator++() {
  if (current->right) {
    current = current->right;
    while (current->left) {
      current = current->left;
    }
  } else {
    Node* parrent = current->parent;
    while (parrent && current == parrent->right) {
      current = parrent;
      parrent = parrent->parent;
    }
    current = parrent;
  }
  return *this;
}

template <typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::iterator::operator++(int) {
  iterator temp = *this;
  ++(*this);
  return temp;
}

template <typename T>
typename BinaryTree<T>::iterator& BinaryTree<T>::iterator::operator--() {
  if (current->left) {
    current = current->left;
    while (current->right) {
      current = current->right;
    }
  } else {
    Node* parent = current->parent;
    while (parent && current == parent->left) {
      current = parent;
      parent = parent->parent;
    }
    current = parent;
  }
  return *this;
}

template <typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::iterator::operator--(int) {
  iterator temp = *this;
  --(*this);
  return temp;
}

template <typename T>
bool BinaryTree<T>::iterator::operator==(const iterator& other) const {
  return current == other.current;
}

template <typename T>
bool BinaryTree<T>::iterator::operator!=(const iterator& other) const {
  return current != other.current;
}

template <typename T>
BinaryTree<T>::BinaryTree() {
  end_node_ = new Node;
  root_ = end_node_;
}

template <typename T>
BinaryTree<T>::BinaryTree(std::initializer_list<T> const& items) {
  end_node_ = new Node;
  root_ = end_node_;
  for (auto it = items.begin(); it != items.end(); ++it) {
    insert(*it);
  }
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& other) {
  end_node_ = new Node;
  root_ = end_node_;
  insert_tree(other.root_, other.end_node_);
}

template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree<T>&& other) {
  end_node_ = new Node;
  root_ = end_node_;
  this->swap(other);
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
  clear();
  delete end_node_;
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(BinaryTree<T> other) {
  std::swap(root_, other.root_);
  std::swap(end_node_, other.end_node_);
  std::swap(size_tree_, other.size_tree_);

  return *this;
}

template <typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::begin() const noexcept {
  Node* current = root_;
  while (current && current->left) {
    current = current->left;
  }
  return iterator(current);
}

template <typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::end() const noexcept {
  return iterator(end_node_);
}

template <typename T>
void BinaryTree<T>::clear(Node* node) {
  if (node && node != end_node_) {
    clear(node->left);
    clear(node->right);
    delete node;
  }
}

template <typename T>
void BinaryTree<T>::insert_tree(Node* node, Node* endNode) {
  if (node && node != endNode) {
    insert(node->key);
    insert_tree(node->left, endNode);
    insert_tree(node->right, endNode);
  }
}

template <typename T>
std::pair<typename BinaryTree<T>::iterator, bool> BinaryTree<T>::insert(
    const T& key, Node* check, Node* parent) {
  std::pair<iterator, bool> result(end(), false);
  if (!check || check == end_node_) {
    Node* insert_node = new Node;
    insert_node->key = key;
    insert_node->parent = parent;
    if (!parent) {
      insert_node->right = end_node_;
      end_node_->parent = insert_node;
      root_ = insert_node;
    } else if (check == end_node_) {
      parent->right = insert_node;
      insert_node->right = end_node_;
      end_node_->parent = insert_node;
    } else {
      if (key < parent->key) {
        parent->left = insert_node;
      } else {
        parent->right = insert_node;
      }
    }
    result.first = iterator(insert_node);
    result.second = true;
  } else if (key < check->key) {
    result = insert(key, check->left, check);
  } else if (key > check->key) {
    result = insert(key, check->right, check);
  } else {
    if (is_multiset_) {
      result = insert(key, check->right, check);
    } else {
      result.first = iterator(check);
    }
  }
  return result;
}

template <typename T>
bool BinaryTree<T>::empty() const noexcept {
  return size_tree_ == 0;
}

template <typename T>
size_t BinaryTree<T>::size() const noexcept {
  return size_tree_;
}

template <typename T>
size_t BinaryTree<T>::max_size() const noexcept {
  return std::numeric_limits<size_t>::max();
}

template <typename T>
void BinaryTree<T>::clear() noexcept {
  clear(root_);
  size_tree_ = 0;
  root_ = end_node_;
  end_node_->parent = nullptr;
}

template <typename T>
std::pair<typename BinaryTree<T>::iterator, bool> BinaryTree<T>::insert(
    const T& key) {
  if (this->is_multiset_)
    size_tree_++;
  else if (!contains(key))
    size_tree_ += 1;

  return insert(key, root_, nullptr);
}

template <typename T>
typename BinaryTree<T>::iterator BinaryTree<T>::find(const T& key) {
  iterator result(end_node_);

  if (root_->key == key)
    result.current = root_;
  else {
    Node* check = (root_->key < key) ? root_->right : root_->left;
    while (check != nullptr && result.current == end_node_) {
      if (check->key == key) {
        result.current = check;
      } else if (check->key < key) {
        check = check->right;
      } else {
        check = check->left;
      }
    }
  }

  return result;
}

template <typename T>
bool BinaryTree<T>::contains(const T& key) {
  return find(key).current != end_node_;
}

template <typename T>
void BinaryTree<T>::erase(BinaryTree<T>::iterator pos) {
  if (pos.current != end_node_) {
    Node* erasing_node = pos.current;
    Node* parent = erasing_node->parent;

    if (root_ == erasing_node && !root_->right) {
      if (root_->left) {
        root_ = root_->left;
      } else {
        root_ = end_node_;
      }
    }

    if (pos.current->right) {
      Node* left = erasing_node->left;
      Node* right = erasing_node->right;
      Node* replacement_node = (++pos).current;

      if (root_ == erasing_node) root_ = replacement_node;

      if (replacement_node->parent->left == replacement_node) {
        replacement_node->parent->left = replacement_node->right;
        if (replacement_node->right)
          replacement_node->right->parent = replacement_node->parent;
        replacement_node->right = right;
        right->parent = replacement_node;
      }
      if (parent)
        parent->left == erasing_node ? parent->left = replacement_node
                                     : parent->right = replacement_node;

      replacement_node->parent = parent;
      if (left) {
        replacement_node->left = left;
        left->parent = replacement_node;
      }
    } else {
      if (parent)
        parent->left == erasing_node ? parent->left = erasing_node->left
                                     : parent->right = erasing_node->left;
      if (erasing_node->left) {
        erasing_node->left->parent = parent;
      }
    }

    size_tree_ -= 1;
    delete erasing_node;
  }
}

template <typename T>
void BinaryTree<T>::swap(BinaryTree<T>& other) {
  std::swap(root_, other.root_);
  std::swap(end_node_, other.end_node_);
  std::swap(size_tree_, other.size_tree_);
}

template <typename T>
void BinaryTree<T>::merge(BinaryTree<T>& other) {
  insert_tree(other.root_, other.end_node_);
  other.clear();
}
}  // namespace s21