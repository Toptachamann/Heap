#pragma once
#include "HeapTester.h"




void HeapTester::test(int numOfOperations)
{
	Heap<int> heap([](const int& one, const int& two) {
		return one > two;
	});
	int insertCounter = 0, extractCounter = 0;
	clock_t beg = clock();
	fi(initSize) {
		heap.insert(rand());
	}
	clock_t en = clock();
	clock_t begin = clock();
	fi(numOfOperations) {
		if (rand() % 2 == 0) {
			heap.extractMax();
			++extractCounter;
		}
		else {
			heap.insert(rand());
			++insertCounter;
		}
	}
	clock_t end = clock();
	double delta = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << "Number of operations is " << numOfOperations  << ": " << insertCounter << " insertions and " << extractCounter << " extractions\n";
	cout << "Time for filling is " << (double)(en - beg) / CLOCKS_PER_SEC << " seconds\n";
	cout << "Time for operations is " << delta << " seconds\n";
}

void HeapTester::testSTL(int numOfOperations)
{
	priority_queue<int> q;
	fi(initSize) {
		q.push(rand());
	}
	int counter = 0;
	fi(numOfOperations) {
		if (rand() % 2 == 0) {
			q.pop();
		}
		else {
			q.push(rand());
		}
		++counter;
	}
}

HeapTester::HeapTester(int initSize): fail(0), success(0)
{
	this->initSize = max(initSize, 100);
	srand(time(nullptr));
}


HeapTester::~HeapTester()
{
}

void HeapTester::test(int numOfTestCases, int sleepTime, int numOfOperations)
{
	clock_t b = clock();
	fi(numOfTestCases) {
		cout << "Test #" << i + 1 << '\n';
		clock_t begin = clock();
		test(numOfOperations);
		clock_t end = clock();
		double deltaTime = (double)(end - begin) / CLOCKS_PER_SEC;
		cout << "Testcase time is: " << deltaTime << " seconds\n\n";
		chrono::seconds sleep(sleepTime);
		this_thread::sleep_for(sleep);
	}
	fi(numOfTestCases) {
		cout << "STL heap\n";
		clock_t b = clock();
		testSTL(numOfOperations);
		clock_t e = clock();
		cout << "STL time is " << (double)(e - b) / CLOCKS_PER_SEC << " seconds\n\n";
	}
	clock_t e = clock();
	cout << "\nOverall time is " << (double)(e - b) / CLOCKS_PER_SEC << " seconds\n";
}
