namespace s21 {

template <typename T>
vector<T>::vector() : _size(0), _capacity(0), _data(nullptr) {}

template <typename T>
vector<T>::vector(size_type n) : _size(n), _capacity(n), _data(new T[n]) {}

template <typename T>
vector<T>::vector(std::initializer_list<T> const &items)
    : _size(items.size()), _capacity(items.size()), _data(new T[_capacity]) {
  std::copy(items.begin(), items.end(), _data);
}

template <typename T>
vector<T>::vector(const vector &v)
    : _size(v._size), _capacity(v._capacity), _data(new T[v._capacity]) {
  for (size_t i = 0; i < v._size; ++i) {
    _data[i] = v._data[i];
  }
}

template <typename T>
vector<T>::vector(vector &&v)
    : _size(v._size), _capacity(v._capacity), _data(v._data) {
  v._size = 0;
  v._capacity = 0;
  v._data = nullptr;
}

template <typename T>
vector<T>::~vector() {
  delete[] _data;
}

template <typename T>
vector<T> &vector<T>::operator=(vector &&v) {
  if (this != &v) {
    delete[] _data;

    _size = v._size;
    _capacity = v._capacity;
    _data = v._data;

    v._size = 0;
    v._capacity = 0;
    v._data = nullptr;
  }
  return *this;
}

template <typename T>
typename vector<T>::reference vector<T>::at(size_type pos) {
  if (pos >= _capacity) {
    throw std::out_of_range("Out of range");
  } else {
    return _data[pos];
  }
}

template <typename T>
typename vector<T>::reference vector<T>::operator[](size_type pos) {
  return _data[pos];
}

template <typename T>
typename vector<T>::const_reference vector<T>::front() {
  return _data[0];
}

template <typename T>
typename vector<T>::const_reference vector<T>::back() {
  return _data[_size - 1];
}

template <typename T>
T *vector<T>::data() {
  return _data;
}

template <typename T>
typename vector<T>::iterator vector<T>::begin() {
  return _data;
}

template <typename T>
typename vector<T>::iterator vector<T>::end() {
  return _data + _size;
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cbegin() const {
  return const_iterator(_data);
}

template <typename T>
typename vector<T>::const_iterator vector<T>::cend() const {
  return const_iterator(_data + _size);
}

template <typename T>
bool vector<T>::empty() {
  if (_size == 0) {
    return 1;
  } else {
    return 0;
  }
}

template <typename T>
typename vector<T>::size_type vector<T>::size() {
  return _size;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() {
  return std::numeric_limits<size_type>::max() / (2 * sizeof(T));
}

template <typename T>
void vector<T>::reserve(size_type size) {
  if (size > _capacity) {
    T *new_data = new T[size];

    for (size_type i = 0; i < _size; ++i) {
      new_data[i] = std::move(_data[i]);
    }

    delete[] _data;

    _data = new_data;
    _capacity = size;
  }
}

template <typename T>
typename vector<T>::size_type vector<T>::capacity() {
  return _capacity;
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (_size < _capacity) {
    vector temp;
    temp.reserve(_size);
    for (size_type i = 0; i < _size; ++i) {
      temp.push_back(_data[i]);
    }
    swap(temp);
  }
}

template <typename T>
void vector<T>::clear() {
  _size = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  size_type index = pos - begin();

  if (_size == _capacity) {
    reserve(_capacity > 0 ? _capacity * 2 : 1);
  }

  for (size_type i = _size; i > index; --i) {
    _data[i] = std::move(_data[i - 1]);
  }

  _data[index] = value;
  _size++;

  return begin() + index;
}

template <typename T>
void vector<T>::erase(iterator pos) {
  size_type num_pos = pos - begin();

  for (size_type i = num_pos; i < _size - 1; ++i) {
    _data[i] = _data[i + 1];
  }

  _size--;
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  this->insert(this->end(), value);
}

template <typename T>
void vector<T>::pop_back() {
  this->erase(this->end() - 1);
}

template <typename T>
void vector<T>::swap(vector &other) {
  value_type *temp = other.data();
  int size = other.size();
  int capacity = other.capacity();

  other._data = this->data();
  other._size = this->size();
  other._capacity = this->capacity();

  this->_data = temp;
  this->_size = size;
  this->_capacity = capacity;
}

template <typename T>
template <class... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  std::vector<T> temp = {std::forward<Args>(args)...};

  size_type num_new_elements = temp.size();
  size_type index = pos - begin();

  if (_size + num_new_elements > _capacity) {
    reserve((_size + num_new_elements) * 2);
  }

  for (size_type i = _size; i > index; --i) {
    _data[i + num_new_elements - 1] = std::move(_data[i - 1]);
  }

  for (size_type i = 0; i < num_new_elements; ++i) {
    _data[index + i] = std::move(temp[i]);
  }

  _size += num_new_elements;

  return begin() + index;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  (push_back(std::forward<Args>(args)), ...);
}

}  // namespace s21