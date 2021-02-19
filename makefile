all : test_evaluator unit_test

test_evaluator : main.cpp evaluator.o
	g++ -Wall -O2 -o test_evaluator main.cpp evaluator.o

unit_test: tests.cpp evaluator.o catch_amalgamated.o
	g++ -Wall -O2 -o unit_test tests.cpp catch_amalgamated.o evaluator.o

evaluator.o: evaluator.cpp evaluator.hpp
	g++ -Wall -O2 -c evaluator.cpp

catch_amalgamated.o: catch_amalgamated.cpp catch_amalgamated.hpp
	@echo "Sorry, tarda un poco compilando las pruebas unitarias"
	g++ -Wall -O2 -c catch_amalgamated.cpp

clean:
	rm *.o test_evaluator unit_test