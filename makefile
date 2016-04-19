#MakeFile for first Task paper

buildAll: src/DLL.c src/DLLTest.c
	gcc -Wall -o bin/DLLTest src/DLLTest.c src/DLL.c

clean:
	rm bin/*
