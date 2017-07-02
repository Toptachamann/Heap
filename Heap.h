#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


template <class T>
class Heap {
private:
	int size, capacity;
	vector<T> heap;
	bool(*comparator)(const T&, const T&);
	void maxHeapify(int index);
	int parent(int i);
	int left(int i);
	int right(int i);
public:
	Heap(bool(*comparator)(const T&, const T&) = nullptr);
	Heap(int capacity, bool(*comparator)(const T&, const T&) = nullptr);
	Heap(const vector<T>& arr, bool(*comparator)(const T&, const T&) = nullptr);
	T getMax();
	void extractMax();
	void insert(const T& value);
	bool empty();
	int getSize();
	int getCapacity();
};

template<class T>
inline void Heap<T>::maxHeapify(int i)
{

	int largest;
	int l = left(i);
	int r = right(i);
	if (comparator) {
		if (l < size && comparator(heap[i], heap[l])) {
			largest = l;
		}
		else {
			largest = i;
		}

		if (r < size && comparator(heap[largest], heap[r])) {
			largest = r;
		}
		if (largest != i) {
			swap(heap[i], heap[largest]);
			maxHeapify(largest);
		}
	}
	else {
		if (l < size && heap[l] > heap[i]) {
			largest = l;
		}
		else {
			largest = i;
		}

		if (r < size && heap[r] > heap[largest]) {
			largest = r;
		}
		if (largest != i) {
			swap(heap[i], heap[largest]);
			maxHeapify(largest);
		}
	}
}

template<class T>
inline int Heap<T>::parent(int i)
{
	return (i == 0) ? 0 : (i - 1) >> 1;
}

template<class T>
inline int Heap<T>::left(int i)
{
	return (i << 1) + 1;
}

template<class T>
inline int Heap<T>::right(int i)
{
	return (i + 1) << 1;
}

template<class T>
Heap<T>::Heap(bool(*comparator)(const T&, const T&) = nullptr) {
	size = capacity = 0;
	this->comparator = comparator;
}
template<class T>
Heap<T>::Heap(int capacity = 0, bool(*comparator)(const T&, const T&) = nullptr) {
	size = 0;
	this->capacity = capacity;
	this->comparator = comparator;
}

template<class T>
inline Heap<T>::Heap(const vector<T>& arr, bool(*comparator)(const T&, const T&) = nullptr) : heap(arr)
{
	size = capacity = arr.size();
	this->comparator = comparator;
	for (int i = size / 2 - 1; i >= 0; --i) {
		maxHeapify(i);
	}
}

template<class T>
inline T Heap<T>::getMax()
{
	if (size == 0) {
		cerr << "Heap underflow\n";
		return T();
	}
	else {
		return heap[0];
	}
}

template<class T>
inline void Heap<T>::extractMax()
{
	if (size == 0) {
		cerr << "Heap underflow\n";
	}
	else {
		swap(heap[0], heap[size - 1]);
		--size;
		maxHeapify(0);
		if (size < capacity >> 2) {
			heap.resize(capacity >> 1);
			capacity >>= 1;
		}
	}
}

template<class T>
inline void Heap<T>::insert(const T & value)
{
	if (size == capacity) {
		heap.resize((size << 1) + 1);
		capacity = (capacity << 1) + 1;
	}
	int index = size;
	int par = parent(index);
	heap[size++] = value;
	if (comparator) {
		while (index != 0 && comparator(heap[par], heap[index])) {
			swap(heap[index], heap[par]);
			index = parent(index);
			par = parent(index);
		}
	}
	else {
		while (index != 0 && heap[index] > heap[par]) {
			swap(heap[index], heap[par]);
			index = parent(index);
			par = parent(index);
		}
	}
}

template<class T>
inline bool Heap<T>::empty()
{
	return size == 0;
}

template<class T>
inline int Heap<T>::getSize()
{
	return size;
}

template<class T>
inline int Heap<T>::getCapacity()
{
	return capacity;
}
