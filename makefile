all : test_evaluator

test_evaluator : main.cpp evaluator.o
	g++ -Wall -O2 -o test_evaluator main.cpp evaluator.o

evaluator.o: evaluator.cpp evaluator.hpp
	g++ -Wall -O2 -c evaluator.cpp

clean:
	rm *.o test_evaluator