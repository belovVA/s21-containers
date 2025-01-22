#include "s21_map.h"

namespace s21 {
template <typename Key, typename T>
map<Key, T>::map() : BinaryTree<value_type>() {}

template <typename Key, typename T>
map<Key, T>::map(std::initializer_list<value_type> const &items)
    : BinaryTree<value_type>(items) {}

template <typename Key, typename T>
map<Key, T>::map(const map &s) : BinaryTree<value_type>(s) {}

template <typename Key, typename T>
map<Key, T>::map(map &&m) noexcept : BinaryTree<value_type>(std::move(m)) {}

template <typename Key, typename T>
map<Key, T>::~map() {}

template <typename Key, typename T>
T &map<Key, T>::at(const Key &key) {
  iterator it = find(key);

  if (it == this->end()) {
    throw "the key doesn't exist";
  }

  return (*it).second;
}

template <typename Key, typename T>
T &map<Key, T>::operator[](const Key &key) {
  iterator it = find(key);
  if (it == this->end_node_) {
    it = (insert(key, T())).first;
  }
  return (*it).second;
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type &value) {
  std::pair<typename map<Key, T>::iterator, bool> result;
  auto it_find = find(value.first);
  if (it_find != this->end()) {
    result.first = it_find;
    result.second = false;
  } else {
    result = BinaryTree<value_type>::insert(value);
  }
  return result;
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key &key, const T &obj) {
  return insert(value_type(key, obj));
}

template <class Key, class T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key &key, const T &obj) {
  this->operator[](key) = obj;
  return std::pair<iterator, bool>(find(key), true);
}

template <typename Key, typename T>
typename map<Key, T>::iterator map<Key, T>::find(const Key &key) {
  iterator result(this->end_node_);
  if ((this->root_->key).first == key)
    result = iterator(this->root_);
  else {
    auto *check =
        (this->root_->key.first > key) ? this->root_->left : this->root_->right;
    while (check != nullptr && result == this->end()) {
      if (check->key.first == key) {
        result = iterator(check);
      } else if (check->key.first > key) {
        check = check->left;
      } else {
        check = check->right;
      }
    }
  }

  return result;
}

template <typename Key, typename T>
void map<Key, T>::insert_many(const std::vector<value_type> &items) {
  for (const auto &item : items) {
    insert(item);  // Вставляем каждый элемент
  }
}

}  // namespace s21
