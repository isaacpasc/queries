earnings: MaxHeap.o Utility.o main.o
	g++ MaxHeap.o Utility.o main.o -o earnings

MaxHeap.o: MaxHeap.cpp MaxHeap.h
	g++ -c MaxHeap.cpp MaxHeap.h

Utility.o: Utility.cpp Utility.h defns.h
	g++ -c Utility.cpp Utility.h defns.h

main.o: main.cpp defns.h Utility.cpp Utility.h MaxHeap.cpp MaxHeap.h
	g++ -c main.cpp defns.h Utility.cpp Utility.h MaxHeap.cpp MaxHeap.h
