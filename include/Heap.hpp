#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

namespace data_structures {
  template<class T>
  class Heap {
  private:
    unsigned long long _size, _capacity;
    std::vector<T> _heap;

    bool (*comparator)(const T &, const T &);

    void maxHeapify(unsigned long long index);

    constexpr unsigned long long parent(unsigned long long i) const;

    constexpr unsigned long long left(unsigned long long i) const;

    constexpr unsigned long long right(unsigned long long i) const;

  public:
    explicit Heap(bool(*comparator)(const T &, const T &) = nullptr);

    explicit Heap(unsigned long long capacity, bool(*comparator)(const T &, const T &) = nullptr);

    explicit Heap(const std::vector<T> &arr, bool(*comparator)(const T &, const T &) = nullptr);

    T getMax();

    void extractMax();

    void insert(const T &value);

    bool empty();

    unsigned long long size();

    unsigned long long capacity();
  };

  template<class T>
  void Heap<T>::maxHeapify(unsigned long long index) {

    unsigned long long largest;
    unsigned long long l = left(index);
    unsigned long long r = right(index);
    if (comparator) {
      if (l < _size && comparator(_heap[index], _heap[l])) {
        largest = l;
      } else {
        largest = index;
      }

      if (r < _size && comparator(_heap[largest], _heap[r])) {
        largest = r;
      }
      if (largest != index) {
        std::swap(_heap[index], _heap[largest]);
        maxHeapify(largest);
      }
    } else {
      if (l < _size && _heap[index] < _heap[l]) {
        largest = l;
      } else {
        largest = index;
      }

      if (r < _size && _heap[r] > _heap[largest]) {
        largest = r;
      }
      if (largest != index) {
        std::swap(_heap[index], _heap[largest]);
        maxHeapify(largest);
      }
    }
  }

  template<class T>
  constexpr inline unsigned long long Heap<T>::parent(const unsigned long long i) const {
    return (i == 0) ? 0 : (i - 1) >> 1;
  }

  template<class T>
  constexpr inline unsigned long long Heap<T>::left(const unsigned long long i) const {
    return (i << 1) + 1;
  }

  template<class T>
  constexpr inline unsigned long long Heap<T>::right(const unsigned long long i) const {
    return (i + 1) << 1;
  }

  template<class T>
  Heap<T>::Heap(bool(*comparator)(const T &, const T &)) {
    _size = _capacity = 0;
    this->comparator = comparator;
  }

  template<class T>
  Heap<T>::Heap(unsigned long long capacity, bool(*comparator)(const T &, const T &)) {
    _size = 0;
    this->_capacity = capacity;
    this->comparator = comparator;
  }

  template<class T>
  Heap<T>::Heap(const std::vector<T> &arr, bool(*comparator)(const T &, const T &)) : _heap(arr) {
    _size = _capacity = arr.size();
    this->comparator = comparator;
    for (unsigned long long i = _size / 2 - 1; i >= 0; --i) {
      maxHeapify(i);
    }
  }

  template<class T>
  T Heap<T>::getMax() {
    if (_size == 0) {
      std::cerr << "Heap underflow\n";
      return T();
    } else {
      return _heap[0];
    }
  }

  template<class T>
  void Heap<T>::extractMax() {
    if (_size == 0) {
      std::cerr << "Heap underflow\n";
    } else {
      std::swap(_heap[0], _heap[_size - 1]);
      --_size;
      maxHeapify(0);
      if (_size < _capacity >> 2) {
        _heap.resize(_capacity >> 1);
        _capacity >>= 1;
      }
    }
  }

  template<class T>
  void Heap<T>::insert(const T &value) {
    if (_size == _capacity) {
      _heap.resize((_size << 1) + 1);
      _capacity = (_capacity << 1) + 1;
    }
    unsigned long long index = _size;
    unsigned long long par = parent(index);
    _heap[_size++] = value;
    if (comparator) {
      while (index != 0 && comparator(_heap[par], _heap[index])) {
        std::swap(_heap[index], _heap[par]);
        index = parent(index);
        par = parent(index);
      }
    } else {
      while (index != 0 && _heap[index] > _heap[par]) {
        std::swap(_heap[index], _heap[par]);
        index = parent(index);
        par = parent(index);
      }
    }
  }

  template<class T>
  inline bool Heap<T>::empty() {
    return _size == 0;
  }

  template<class T>
  inline unsigned long long Heap<T>::size() {
    return _size;
  }

  template<class T>
  inline unsigned long long Heap<T>::capacity() {
    return _capacity;
  }

}

