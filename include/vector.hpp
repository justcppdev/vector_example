#include <iostream>

template <typename T>
class vector_t {
 private:
  T* elements_;
  std::size_t size_;
  std::size_t capacity_;

 public:
  vector_t();
  vector_t(vector_t const& other);
  vector_t& operator=(vector_t const& other);
  ~vector_t();

  std::size_t size() const;
  std::size_t capacity() const;

  void push_back(int value);
  void pop_back();

  T& operator[](std::size_t index);
  T operator[](std::size_t index) const;
  T& as(std::size_t index);
  bool operator==(vector_t const& other) const;
};

template <typename T>
vector_t<T>::vector_t() {
  size_ = 0;
  capacity_ = 0;
  elements_ = nullptr;
}
template <typename T>
vector_t<T>::vector_t(vector_t const& other) {
  this->size_ = other.size_;
  this->capacity_ = other.capacity_;
  this->elements_ = new T[capacity_];
  for (std::size_t i = 0; i < size_; i++) {
    elements_[i] = other.elements_[i];
  }
}
template <typename T>
vector_t<T>& vector_t<T>::operator=(vector_t const& other) {
  if (this != &other) {
    delete[] elements_;
    this->size_ = other.size_;
    this->capacity_ = other.capacity_;
    this->elements_ = new T[capacity_];
    for (std::size_t i = 0; i < size_; i++) {
      elements_[i] = other.elements_[i];
    }
  }
  return *this;
}
template <typename T>
bool vector_t<T>::operator==(vector_t const& other) const {
  if (this->size_ == other.size_) {
    for (std::size_t i = 0; i < size_; i++) {
      if (this->elements_[i] != other.elements_[i]) {
        return false;
        break;
      }
    }
    return true;
  }

  else
    return false;
}
template <typename T>
vector_t<T>::~vector_t() {
  delete[] elements_;
  size_ = 0;
  capacity_ = 0;
}
template <typename T>
std::size_t vector_t<T>::size() const {
  return size_;
}

template <typename T>
std::size_t vector_t<T>::capacity() const {
  return capacity_;
}

template <typename T>
void vector_t<T>::push_back(int value) {
  if (size_ == 0) {
    size_ = 1;
    capacity_ = 1;
    elements_ = new T[capacity_];
    elements_[0] = value;
  } else if (size_ == capacity_) {
    capacity_ = capacity_ * 2;
    int* mas = new T[capacity_];
    for (std::size_t i = 0; i < size_; i++) {
      mas[i] = elements_[i];
    }
    delete[] elements_;
    elements_ = mas;
    elements_[size_] = value;
    size_++;
  } else {
    elements_[size_] = value;
    size_++;
  }
}
template <typename T>
void vector_t<T>::pop_back() {
  size_--;
  if (size_ == 0 || size_ * 4 == capacity_) {
    int* mas;
    mas = new T[size_];
    for (std::size_t i = 0; i < size_; i++) {
      mas[i] = elements_[i];
    }
    delete[] elements_;
    capacity_ = capacity_ / 2;
    elements_ = new T[capacity_];
    for (std::size_t i = 0; i < size_; i++) {
      elements_[i] = mas[i];
    }
    delete[] mas;
  }
}

template <typename T>
T& vector_t<T>::operator[](std::size_t index) {
  return elements_[index];
}

template <typename T>
T vector_t<T>::operator[](std::size_t index) const {
  return elements_[index];
}

template <typename T>
bool operator!=(vector_t<T> const& lhs, vector_t<T> const& rhs) {
  if (lhs == rhs) {
    return false;
  }
  return true;
}
template <typename T>

T& vector_t<T>::as(std::size_t index) {
  if (index >= size_ ) {
    throw std::out_of_range("Out of range");
  }
  else return elements_[index];
}
