earnings: MaxHeap.o Utility.o HashTable.o BinarySearchTree.o main.o
	g++ MaxHeap.o Utility.o HashTable.o BinarySearchTree.o main.o -o earnings

MaxHeap.o: MaxHeap.cpp MaxHeap.h defns.h
	g++ -c MaxHeap.cpp MaxHeap.h defns.h

HashTable.o: Utility.cpp Utility.h HashTable.cpp HashTable.h defns.h
	g++ -c Utility.cpp Utility.h HashTable.cpp HashTable.h defns.h 

BinarySearchTree.o: Utility.cpp Utility.h BinarySearchTree.cpp BinarySearchTree.h defns.h
	g++ -c Utility.cpp Utility.h BinarySearchTree.cpp BinarySearchTree.h defns.h

Utility.o: Utility.cpp Utility.h defns.h HashTable.cpp HashTable.h
	g++ -c Utility.cpp Utility.h defns.h HashTable.cpp HashTable.h

main.o: main.cpp defns.h Utility.cpp Utility.h MaxHeap.cpp MaxHeap.h BinarySearchTree.cpp BinarySearchTree.h HashTable.cpp HashTable.h
	g++ -c main.cpp defns.h Utility.cpp Utility.h MaxHeap.cpp MaxHeap.h BinarySearchTree.cpp BinarySearchTree.h HashTable.cpp HashTable.h
