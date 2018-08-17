#include "HeapPerformanceTester.h"

using namespace data_structures;
using namespace std;

double HeapPerformanceTester::test_heap(int numOfOperations) {
  auto start = chrono::high_resolution_clock::now();
  Heap<int> heap;
  fi(initSize) {
    heap.insert(rand());
  }
  fi(numOfOperations) {
    if (rand() % 2 == 0) {
      heap.extractMax();
    } else {
      heap.insert(rand());
    }
  }
  auto end = chrono::high_resolution_clock::now();
  return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

double HeapPerformanceTester::test_stl(int numOfOperations) {
  auto start = chrono::high_resolution_clock::now();
  priority_queue<int> q;
  fi(initSize) {
    q.push(rand());
  }
  fi(numOfOperations) {
    if (rand() % 2 == 0) {
      q.pop();
    } else {
      q.push(rand());
    }
  }
  auto end = chrono::high_resolution_clock::now();
  return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

HeapPerformanceTester::HeapPerformanceTester(int initSize) : initSize(max(100, initSize)), fail(0), success(0) {
  srand(time(nullptr));
}


HeapPerformanceTester::~HeapPerformanceTester() {
}

string get_time(double x) {
  return (boost::format("%.3f") % (x/1e9)).str();
}

void HeapPerformanceTester::test(int num_of_test_cases, int num_of_operations, int warm_up, int measurement) {
  fi(num_of_test_cases) {
    fj(warm_up) {
      test_heap(num_of_operations);
      test_stl(num_of_operations);
    }
    double heap_total = 0, stl_total = 0;
    fj(measurement) {
      heap_total += test_heap(num_of_operations);
      stl_total += test_stl(num_of_operations);
    }
    cout << boost::format("Test case %d: heap average = %s, stl average = %s\n") % (i + 1) % get_time(heap_total) %
            get_time(stl_total);
  }

}
