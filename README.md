# Heap
Template heap class with tester
Classical data structure implementation. Every constructor has one optional argument - pointer to comparator, according to which elements
will be ordered in the heap. Personally I found it very usefull.
HeapTester is a very primite class for comparing performance of this heap class and one from STL. When testing at a small number of 
elements, both perfom relatively equally. When testing with inilial 100'000 elements and 100'000 operations, STL's heap is two times slower.
So, if you need performance rather then STL's features, use this one.
If you've found some bug or you have suggestions how to improve the code, you're welcome to do write about it or directly make changes to 
code.
