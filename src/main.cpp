#include "HeapPerformanceTester.h"
#include <Heap.hpp>

using namespace data_structures;

int main() {
  HeapPerformanceTester tester(100000);
  tester.test(10, 100000, 10, 20);
}