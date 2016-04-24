#MakeFile for first Task paper

bin/DLLTest: src/DLL.c src/DLLTest.c src/Mergesort.c
	gcc -Wall -g -o bin/DLLTest src/DLLTest.c src/DLL.c src/Mergesort.c

test: bin/DLLTest
	bin/DLLTest 12 4 0 9 8 2

valgrind: bin/DLLTest
	valgrind bin/DLLTest 12 4 0 9 8 2

clean:
	rm bin/*
