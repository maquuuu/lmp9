all:
	gcc -W --pedantic src/*.c -o bin/gauss


debug:
	gcc -g -W --pedantic src/*.c -o bin/gauss

release:
	gcc -O2 -W --pedantic src/*.c -o bin/gauss





test: all
	bin/gauss dane/A dane/b
