#pragma once
#include <iostream>
#include "Heap.h"
#include <ctime>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <queue>
#define fi(n) for (int i = 0;i<(n);i++)
#define fj(n) for (int j = 0;j<(n);j++)
using namespace std;

class HeapTester
{
private:
	int initSize, fail, success;
	void test(int numOfOperations);
	void testSTL(int numOfOperations);
public:
	HeapTester(int initSize);
	~HeapTester();
	void test(int numOfTestCases, int sleepTime, int numOfOperations);
};

