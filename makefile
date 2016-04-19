#MakeFile for first Task paper

default: bin/DLLTest

bin/DLLTest: src/DLL.c src/DLLTest.c
	gcc -Wall -o bin/DLLTest src/DLLTest.c src/DLL.c

test: bin/DLLTest
	bin/DLLTest 12 4 0 9

clean:
	rm bin/*
