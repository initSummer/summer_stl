// 
// Author        : summer
// Description   : Make a short description for your file
// 
// Revision      :
// Rev.    Date        Designer    Description
// 1.0     2024-03-16  summer      Initial version
// 

#pragma once

#define SUMMER_DEBUG

#ifdef SUMMER_DEBUG
#include <iostream>
#endif
#include <stdexcept>

namespace Summer {
template<typename T>
class vector {
// todo: function discription
 public:
  vector();
  ~vector();

 public:
  [[nodiscard]] bool empty() const;
  [[nodiscard]] int size() const;
  [[nodiscard]] int capacity() const;

 public:
  const T &front() const;
  const T &back() const;
  const T &at(int index) const;
  T &operator[](int index);
  T *data();

 public:
  vector<T> &operator=(const vector<T> &other);
  void push_back(const T &value);
  void pop_back();
  void reserve(int capacity);
  void resize(int size);
  void clear();
  void swap(vector<T> &other);

#ifdef SUMMER_DEBUG
 public:
  void print() const;
#endif

 private:
  // todo:
  void _resize(int size);

 private:
  T *data_;
  int size_;
  int capacity_;
};

template<typename T>
vector<T>::vector(): data_(nullptr), size_(0), capacity_(0) {

}
template<typename T>
vector<T>::~vector() {
  delete[] data_;
}

template<typename T>
bool vector<T>::empty() const {
  return size_ == 0;
}

template<typename T>
int vector<T>::size() const {
  return size_;
}

template<typename T>
int vector<T>::capacity() const {
  return capacity_;
}

template<typename T>
const T &vector<T>::at(int index) const {
  if (index < 0 || index >= size_) {
    throw std::logic_error("at() index out of range");
  }
  return data_[index];
}

template<typename T>
const T &vector<T>::front() const {
  if (size_ != 0) {
    return data_[0];
  } else {
    throw std::logic_error("try to get front from a empty vector");
  }
}

template<typename T>
T *vector<T>::data() {
  return data_;
}

template<typename T>
const T &vector<T>::back() const {
  if (size_ != 0) {
    return data_[size_ - 1];
  } else {
    throw std::logic_error("try to get back from a empty vector");
  }
}

template<typename T>
T &vector<T>::operator[](int index) {
  if (index < 0 || index >= size_) {
    throw std::logic_error("[index] index out of range");
  }
  return data_[index];
}

template<typename T>
vector<T> &vector<T>::operator=(const vector<T> &other) {
  if (capacity_ < other.size_) {
    _resize(other.size_);
  }
  for (int i = 0; i < other.size_; ++i) {
    data_[i] = other.data_[i];
  }
  size_ = other.size_;
  capacity_ = other.capacity_;
}

template<typename T>
void vector<T>::push_back(const T &value) {
  if (size_ < capacity_) {
    data_[size_] = value;
  } else if (capacity_ == 0) {
    capacity_ = 1;
  } else {
    capacity_ *= 2;
  }
  T *data = new T[capacity_];
  for (int i = 0; i < size_; ++i) {
    data[i] = data_[i];
  }
  delete[] data_;
  data_ = data;
  data_[size_] = value;
  size_ += 1;
}

template<typename T>
void vector<T>::pop_back() {
  if (size_ != 0) {
    size_ -= 1;
  }
}

template<typename T>
void vector<T>::reserve(int capacity) {
  if (capacity == capacity_) {
    return;
  } else if (capacity >= size_) {
    T *data = new T[capacity];
    for (int i = 0; i < size_; ++i) {
      data[i] = data_[i];
    }
    delete[] data_;
    data_ = data;
    capacity_ = capacity;
  }
}

template<typename T>
void vector<T>::resize(int size) {
  if (size_ == size) {
    return;
  } else if (size_ < size) {
    if (size > capacity_) {
      _resize(size);
    }
    for (int i = size_; i < size; ++i) {
      data_[i] = T();
    }
  }
  size_ = size;
}

template<typename T>
void vector<T>::clear() {
  size_ = 0;
}

template<typename T>
void vector<T>::swap(vector<T> &other) {
  T *data = other.data_;
  int size = other.size_;
  int capacity = other.capacity_;

  other.data_ = data_;
  other.size_ = size_;
  other.capacity_ = capacity_;

  data_ = data;
  size_ = size;
  capacity_ = capacity;
}

#ifdef SUMMER_DEBUG
template<typename T>
void vector<T>::print() const {
  std::cout << "type: " << typeid(T).name() << std::endl;
  std::cout << "size: " << size_ << std::endl;
  std::cout << "capacity: " << capacity_ << std::endl;
  for (int i = 0; i < size_; ++i) {
    std::cout << data_[i] << std::endl;
  }
}
#endif

template<typename T>
void vector<T>::_resize(int size) {
  // todo: debug: what if size < size_
  capacity_ = 0;
  while (capacity_ < size) {
    if (capacity_ == 0) {
      capacity_ = 1;
    } else {
      capacity_ *= 2;
    }
  }
  T *data = new T(capacity_);
  for (int i = 0; i < size_; ++i) {
    data[i] = data_[i];
  }
  delete[] data_;
  data_ = data;
}
}
