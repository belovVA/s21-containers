#include "s21_list.h"

namespace s21 {
template <typename T>
list<T>::list() : _head(nullptr), _tail(nullptr), _size(0){};

template <typename T>
list<T>::list(size_type n) : _head(nullptr), _tail(nullptr), _size(0) {
  for (size_type i = 0; i < n; ++i) {
    push_back(T());
  }
};

template <typename T>
list<T>::list(std::initializer_list<T> const &items)
    : _head(nullptr), _tail(nullptr), _size(0) {
  for (const T &item : items) {
    push_back(item);
  }
}

template <typename T>
list<T>::list(const list &l) : _head(nullptr), _tail(nullptr), _size(0) {
  for (const auto &element : l) {
    push_back(element);
  }
}

template <typename T>
list<T>::list(list &&l) : _head(l._head), _tail(l._tail), _size(l._size) {
  l._head = nullptr;
  l._tail = nullptr;
  l._size = 0;
}

template <typename T>
list<T>::~list() {
  while (_head != nullptr) {
    Node *temp = _head;
    _head = _head->_next;
    delete temp;
  }
  _tail = nullptr;
  _size = 0;
}

template <typename T>
list<T> &list<T>::operator=(list &&l) {
  if (this != &l) {
    clear();
    swap(l);
  }
  return *this;
}

template <typename T>
typename list<T>::const_reference list<T>::front() {
  return this->_head->_data;
}

template <typename T>
typename list<T>::const_reference list<T>::back() {
  return this->_tail->_data;
}

template <typename T>
typename list<T>::iterator list<T>::begin() {
  return iterator(_head);
}

template <typename T>
typename list<T>::iterator list<T>::end() {
  return iterator(nullptr, this);
}

template <typename T>
typename list<T>::const_iterator list<T>::begin() const {
  return const_iterator(_head);
}

template <typename T>
typename list<T>::const_iterator list<T>::end() const {
  return const_iterator(nullptr);
}

template <typename T>
typename list<T>::const_iterator list<T>::cbegin() const {
  return const_iterator(_head);
}

template <typename T>
typename list<T>::const_iterator list<T>::cend() const {
  return const_iterator(nullptr);
}

template <typename T>
bool list<T>::empty() {
  return this->_size == 0;
}

template <typename T>
typename list<T>::size_type list<T>::size() {
  return _size;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() {
  return std::numeric_limits<size_type>::max() / (sizeof(Node) * 2);
}

template <typename T>
void list<T>::clear() {
  while (!empty()) pop_front();
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  if (pos == begin()) {
    push_front(value);
    pos = this->_head;
  } else if (pos == this->end()) {
    push_back(value);
    pos = this->_tail;
  } else {
    Node *current = pos._node;
    Node *prev = current->_prev;
    Node *newNode = new Node(value);

    newNode->_next = current;
    newNode->_prev = prev;

    prev->_next = newNode;
    current->_prev = newNode;

    this->_size++;
    return iterator(newNode);
  }
  return pos;
}

template <typename T>
void list<T>::erase(iterator pos) {
  Node *current = pos._node;
  Node *next = current->_next;
  Node *prev = current->_prev;

  if (prev) {
    prev->_next = next;
  } else {
    _head = next;
  }

  if (next) {
    next->_prev = prev;
  } else {
    _tail = prev;
  }

  delete current;
  _size--;
}

template <typename T>
void list<T>::push_back(const_reference value) {
  Node *newNode = new Node(value);
  if (_tail == nullptr) {
    _head = newNode;
    _tail = newNode;
  } else {
    _tail->_next = newNode;
    newNode->_prev = _tail;
    _tail = newNode;
  }
  _size++;
}

template <typename T>
void list<T>::pop_back() {
  Node *last_node = _tail;
  if (_size == 1) {
    _head = nullptr;
    _tail = nullptr;
  } else {
    _tail = last_node->_prev;
    _tail->_next = nullptr;
  }
  delete last_node;
  _size--;
}

template <typename T>
void list<T>::push_front(const_reference value) {
  Node *newNode = new Node(value);
  if (_head == nullptr) {
    _head = newNode;
    _tail = newNode;
  } else {
    newNode->_next = _head;
    _head->_prev = newNode;
    _head = newNode;
  }
  _size++;
}

template <typename T>
void list<T>::pop_front() {
  Node *temp = _head;
  _head = _head->_next;
  delete temp;

  if (_head == nullptr) {
    _tail = nullptr;
  } else {
    _head->_prev = nullptr;
  }

  _size--;
}

template <typename T>
void list<T>::swap(list &other) {
  if (this != &other) {
    std::swap(_head, other._head);
    std::swap(_tail, other._tail);
    std::swap(_size, other._size);
  }
}

template <typename T>
void list<T>::merge(list &other) {
  if (empty()) {
    swap(other);
    return;
  }
  if (other.empty()) return;

  Node *it1 = _head;
  Node *it2 = other._head;

  while (it1 != nullptr && it2 != nullptr) {
    if (it2->_data < it1->_data) {
      Node *next = it2->_next;
      if (it1->_prev != nullptr) {
        it1->_prev->_next = it2;
        it2->_prev = it1->_prev;
      } else {
        _head = it2;
        _head->_prev = nullptr;
      }
      it2->_next = it1;
      it1->_prev = it2;
      it2 = next;
    } else {
      it1 = it1->_next;
    }
  }

  if (it2 != nullptr) {
    _tail->_next = it2;
    it2->_prev = _tail;

    _tail = other._tail;
  }
  _size += other._size;
  other._head = nullptr;
  other._tail = nullptr;
  other._size = 0;
}

template <typename T>
void list<T>::splice(const_iterator pos, list &other) {
  if (!other.empty() && this != &other) {
    Node *insert_point = const_cast<Node *>(pos._node);

    if (insert_point == nullptr) {
      if (_tail != nullptr) {
        _tail->_next = other._head;
        other._head->_prev = _tail;
        _tail = other._tail;
      } else {
        _head = other._head;
        _tail = other._tail;
      }
    } else {
      Node *prev = insert_point->_prev;

      if (prev != nullptr) {
        prev->_next = other._head;
        other._head->_prev = prev;
      } else {
        _head = other._head;
      }

      other._tail->_next = insert_point;
      insert_point->_prev = other._tail;
    }

    _size += other._size;
    other._head = nullptr;
    other._tail = nullptr;
    other._size = 0;
  }
}

template <typename T>
void list<T>::reverse() {
  if (_head == _tail) {
    return;
  }

  Node *current = _head;
  Node *tail = _tail;
  Node *temp = nullptr;

  while (current != nullptr) {
    temp = current->_prev;
    current->_prev = current->_next;
    current->_next = temp;
    current = current->_prev;
  }

  _head = tail;
}

template <typename T>
void list<T>::unique() {
  if (!_head || !_head->_next) {
    return;
  }

  Node *current = _head;

  while (current && current->_next) {
    if (current->_data == current->_next->_data) {
      Node *duplicate = current->_next;
      current->_next = duplicate->_next;

      if (duplicate->_next) {
        duplicate->_next->_prev = current;
      } else {
        _tail = current;
      }
      delete duplicate;
      _size--;
    } else {
      current = current->_next;
    }
  }
}

template <typename T>
void list<T>::sort() {
  if (_head != nullptr) {
    Node *last = _tail;
    quic_sort(_head, last);
  }
}

template <typename T>
void list<T>::quic_sort(Node *low, Node *high) {
  if (low != nullptr && high != nullptr && low != high && low != high->_next) {
    Node *pivot = low;
    T pivotValue = high->_data;

    for (Node *current = low; current != high; current = current->_next) {
      if (current->_data < pivotValue) {
        std::swap(pivot->_data, current->_data);
        pivot = pivot->_next;
      }
    }
    std::swap(pivot->_data, high->_data);

    quic_sort(low, pivot->_prev);
    quic_sort(pivot->_next, high);
  }
}

template <typename T>
template <class... Args>
typename list<T>::iterator list<T>::insert_many(const_iterator pos,
                                                Args &&...args) {
  iterator last(const_cast<Node *>(pos._node));
  iterator first = last;

  (void)std::initializer_list<int>{
      (first = insert(last, std::forward<Args>(args)), 0)...};

  return first;
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_back(Args &&...args) {
  (push_back(std::forward<Args>(args)), ...);
}

template <typename T>
template <typename... Args>
void list<T>::insert_many_front(Args &&...args) {
  s21::vector<T> elements = {std::forward<Args>(args)...};

  for (size_t i = elements.size(); i > 0; --i) {
    push_front(elements[i - 1]);
  }
}

}  // namespace s21