#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

#include "../Vector/s21_vector.h"

namespace s21 {
template <typename T>
class list {
 private:
  struct Node {
    T _data;
    Node *_next;
    Node *_prev;

    Node() : _data(), _next(nullptr), _prev(nullptr) {}
    Node(const T &value) : _data(value), _next(nullptr), _prev(nullptr) {}
  };

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;

  list();
  list(size_type n);
  list(std::initializer_list<T> const &items);
  list(const list &l);
  list(list &&l);
  ~list();

  list &operator=(list &&l);
  list &operator=(const list &l);

  const_reference front();
  const_reference back();

  bool empty();
  size_type size();
  size_type max_size();

  void clear();
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void reverse();
  void unique();
  void sort();
  void quic_sort(Node *low, Node *high);
  // В класс list добавьте метод:

  void print() const {
    std::cout << "List (size " << _size << "): ";
    if (nullptr) {
      std::cout << "empty";
    } else {
      Node *current = _head;
      while (current != nullptr) {
        std::cout << current->_data;
        if (current->_next != nullptr) {
          std::cout << " -> ";
        }
        current = current->_next;
      }
    }
    std::cout << std::endl;
  }
  template <typename value_type>
  class ListIterator {
   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;

    ListIterator() : _node(nullptr) {}
    ListIterator(Node *node) : _node(node) {}
    ListIterator(Node *node, list *parent_list)
        : _node(node), _list(parent_list) {}

    reference operator*() const { return _node->_data; }

    T operator->() { return &_node->_data; }

    ListIterator &operator++() {
      if (_node) {
        _node = _node->_next;
      }
      return *this;
    }

    ListIterator &operator--() {
      if (_node == nullptr) {
        _node = _list->_tail;
      } else if (_node->_prev != nullptr) {
        _node = _node->_prev;
      }
      return *this;
    }

    ListIterator operator++(int) {
      ListIterator temp = *this;
      _node = _node->_next;
      return temp;
    }

    ListIterator operator--(int) {
      ListIterator temp = *this;
      if (_node == nullptr) {
        _node = _list->_tail;
      } else {
        _node = _node->_prev;
      }
      return temp;
    }

    bool operator==(const ListIterator &other) const {
      return _node == other._node;
    }
    bool operator!=(const ListIterator &other) const {
      return _node != other._node;
    }
    bool operator<(const ListIterator &other) const {
      return _node < other._node;
    }
    bool operator>(const ListIterator &other) const {
      return _node > other._node;
    }
    bool operator<=(const ListIterator &other) const {
      return _node <= other._node;
    }
    bool operator>=(const ListIterator &other) const {
      return _node >= other._node;
    }

   private:
    Node *_node;
    list *_list;
    friend class list<T>;
  };

  template <typename value_type>
  class ListConstIterator {
   public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;

    ListConstIterator() : _node(nullptr) {}
    ListConstIterator(const ListIterator<T> &node) : _node(node._node) {}

    const_reference operator*() const { return _node->_data; }

    const T *operator->() const { return &_node->_data; }

    ListConstIterator &operator++() {
      _node = _node->_next;
      return *this;
    }

    ListConstIterator &operator--() {
      if (_node == nullptr) {
        _node = _tail;
      } else {
        _node = _node->_prev;
      }
      return *this;
    }

    ListConstIterator operator++(int) {
      ListConstIterator temp = *this;
      _node = _node->_next;
      return temp;
    }

    ListConstIterator operator--(int) {
      ListConstIterator temp = *this;
      _node = _node->_prev;
      return temp;
    }

    bool operator==(const ListConstIterator &other) const {
      return _node == other._node;
    }
    bool operator!=(const ListConstIterator &other) const {
      return _node != other._node;
    }

   private:
    const Node *_node;
    friend class list;
  };

  using iterator = ListIterator<T>;
  using const_iterator = ListConstIterator<T>;

  iterator begin();
  iterator end();

  const_iterator begin() const;
  const_iterator end() const;

  const_iterator cbegin() const;
  const_iterator cend() const;

  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void splice(const_iterator pos, list &other);
  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <class... Args>
  void insert_many_back(Args &&...args);
  template <class... Args>
  void insert_many_front(Args &&...args);

 private:
  Node *_head;
  Node *_tail;
  size_type _size;
};
}  // namespace s21

#include "s21_list.tpp"

#endif  // LIST_H