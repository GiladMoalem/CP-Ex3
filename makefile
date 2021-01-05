all: isort txtfind
	

isort: isort.c isort.o
	gcc -Wall isort.c -o isort

txtfind: txtfind.c txtfind.o
	gcc -Wall txtfind.c -o txtfind

clean:
	rm *.o isort txtfind
