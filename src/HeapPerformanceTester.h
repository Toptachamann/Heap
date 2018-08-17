#pragma once
#include <iostream>
#include "Heap.hpp"
#include <ctime>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <Heap.hpp>
#include <chrono>
#include <ctime>
#include <string>
#include "boost/format.hpp"
#define fi(n) for (int i = 0;i<(n);i++)
#define fj(n) for (int j = 0;j<(n);j++)

class HeapPerformanceTester
{
private:
	int initSize, fail, success;
	double test_heap(int numOfOperations);
	double test_stl(int numOfOperations);
  void test(int numOfOperations, int warmUp, int measurement);
public:
	HeapPerformanceTester(int initSize);
	~HeapPerformanceTester();
	void test(int num_of_test_cases, int num_of_operations, int warm_up, int measurement);
};

