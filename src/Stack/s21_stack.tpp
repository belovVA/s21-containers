#include "s21_stack.h"

namespace s21 {

template <typename T>
stack<T>::stack() {}

template <typename T>
stack<T>::stack(std::initializer_list<value_type> const &items) {
  for (const auto &item : items) {
    push(item);
  }
}

template <typename T>
stack<T>::stack(const stack &s) {
  for (Node *current = s.top_; current != nullptr; current = current->next) {
    push(current->data);
  }
}

template <typename T>
stack<T>::stack(stack &&s) noexcept : top_(s.top_), size_(s.size_) {
  s.top_ = nullptr;
  s.size_ = 0;
}

template <typename T>
stack<T>::~stack() {
  while (!empty()) {
    pop();
  }
}

template <typename T>
stack<T> &stack<T>::operator=(const stack &s) {
  if (this != &s) {
    stack<T> tmp;

    for (Node *current = s.top_; current != nullptr; current = current->next) {
      tmp.push(current->data);
    }

    for (Node *current = tmp.top_; current != nullptr;
         current = current->next) {
      push(current->data);
    }
  }
  return *this;
}

template <typename T>
stack<T> &stack<T>::operator=(stack &&s) noexcept {
  if (this != &s) {
    swap(s);
  }
  return *this;
}

/* Element access */

template <typename T>
typename stack<T>::const_reference stack<T>::top() const noexcept {
  return top_->data;
}

/* Capacity */

template <typename T>
bool stack<T>::empty() const noexcept {
  return size_ == 0;
}
template <typename T>
typename stack<T>::size_type stack<T>::size() const noexcept {
  return size_;
}

/* Modifiers */
template <typename T>
void stack<T>::swap(stack &other) noexcept {
  std::swap(top_, other.top_);
  std::swap(size_, other.size_);
}

template <typename T>
void stack<T>::push(const_reference value) {
  Node *newVal = new Node(value);
  newVal->next = top_;
  top_ = newVal;
  size_++;
}

template <typename T>
void stack<T>::pop() {
  if (empty()) {
    throw std::out_of_range("Stack is empty");
  }
  Node *tmp = top_;
  top_ = tmp->next;
  delete tmp;
  size_--;
}

template <typename T>
template <typename... Args>
void stack<T>::insert_many_back(Args &&...args) {
  (push(std::forward<Args>(args)), ...);
}

}  // namespace s21