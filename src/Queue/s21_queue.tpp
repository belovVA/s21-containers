#include "s21_queue.h"

namespace s21 {
template <typename T>
queue<T>::queue() {}

template <typename T>
queue<T>::queue(std::initializer_list<value_type> const &items) {
  for (const auto &item : items) {
    push(item);
  }
}

template <typename T>
queue<T>::queue(const queue &q) {
  for (Node *current = q.front_; current != nullptr; current = current->next) {
    push(current->data);
  }
}

template <typename T>
queue<T>::queue(queue &&q) noexcept
    : front_(q.front_), back_(q.back_), size_(q.size_) {
  q.front_ = nullptr;
  q.back_ = nullptr;
  q.size_ = 0;
}

template <typename T>
queue<T>::~queue() {
  while (!empty()) {
    pop();
  }
}

template <typename T>
queue<T> &queue<T>::operator=(const queue &q) {
  if (this != &q) {
    for (Node *current = q.front_; current != nullptr;
         current = current->next) {
      push(current->data);
    }
  }
  return *this;
}

template <typename T>
queue<T> &queue<T>::operator=(queue &&q) noexcept {
  if (this != &q) {
    swap(q);
  }
  return *this;
}
/* Element access */
template <typename T>
typename queue<T>::const_reference queue<T>::front() const noexcept {
  return front_->data;
}

template <typename T>
typename queue<T>::const_reference queue<T>::back() const noexcept {
  return back_->data;
}

/* Capacity */

template <typename T>
bool queue<T>::empty() const noexcept {
  return size_ == 0;
}
template <typename T>
typename queue<T>::size_type queue<T>::size() const noexcept {
  return size_;
}

/* Modifiers */

template <typename T>
void queue<T>::swap(queue &other) noexcept {
  std::swap(front_, other.front_);
  std::swap(back_, other.back_);
  std::swap(size_, other.size_);
}

template <typename T>
void queue<T>::push(const_reference value) {
  Node *current = new Node(value);
  if (empty()) {
    front_ = current;
  } else {
    back_->next = current;
  }
  back_ = current;
  size_++;
}

template <typename T>
void queue<T>::pop() {
  if (empty()) {
    throw std::out_of_range("Queue is empty");
  }
  Node *tmp = front_;
  front_ = front_->next;
  delete tmp;
  size_--;

  if (front_ == nullptr) back_ = nullptr;
}
template <typename T>
template <typename... Args>
void queue<T>::insert_many_back(Args &&...args) {
  (push(std::forward<Args>(args)), ...);
}
}  // namespace s21