all : lab1

main.o : main.cpp functions.h
	g++ -c -g main.cpp

functions.o : functions.cpp functions.h
	g++ -c -g functions.cpp

lab1 : main.o functions.o
	g++ main.o functions.o -o lab1

check : all
	./lab1

clean :
	rm -f *.o lab1


