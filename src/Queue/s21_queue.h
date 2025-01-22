#ifndef S21_QUEUE_H
#define S21_QUEUE_H

#include <initializer_list>

namespace s21 {

template <typename T>
class queue {
 public:
  /* Member type */

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  /* Functions */

  queue();
  queue(std::initializer_list<value_type> const &items);
  queue(const queue &q);
  queue(queue &&q) noexcept;
  ~queue();

  queue &operator=(const queue &q);
  queue &operator=(queue &&q) noexcept;

  /* Element access */

  const_reference front() const noexcept;
  const_reference back() const noexcept;

  /* Capacity */

  bool empty() const noexcept;
  size_type size() const noexcept;

  /* Modifiers */

  void swap(queue &other) noexcept;
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

  Node *front_{nullptr};
  Node *back_{nullptr};
  size_type size_{0};
};

}  // namespace s21

#include "s21_queue.tpp"

#endif  // S21_QUEUE_H