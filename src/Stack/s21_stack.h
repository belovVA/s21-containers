#ifndef S21_STACK_H
#define S21_STACK_H

#include <initializer_list>

namespace s21 {

template <typename T>
class stack {
  /* Member type */
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  /* Functions */
  stack();
  stack(std::initializer_list<value_type> const &items);
  stack(const stack &s);
  stack(stack &&s) noexcept;
  ~stack();

  stack &operator=(const stack &s);
  stack &operator=(stack &&s) noexcept;

  /* Element access */
  const_reference top() const noexcept;

  /* Capacity */
  bool empty() const noexcept;
  size_type size() const noexcept;

  /* Modifiers */
  void swap(stack &other) noexcept;
  void push(const_reference value);
  void pop();

  template <typename... Args>
  void insert_many_back(Args &&...args);

 private:
  struct Node {
    value_type data;
    Node *next{nullptr};

    explicit Node(const_reference value) : data(value) {}
  };

  Node *top_{nullptr};
  size_type size_{0};
};
}  // namespace s21

#include "s21_stack.tpp"

#endif  // S21_STACK_H