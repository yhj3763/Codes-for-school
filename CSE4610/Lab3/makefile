myprog: sdisk.o filesys.o main.o
	c++ -o myprog sdisk.o filesys.o main.o

sdisk.o: sdisk.cpp
	c++ -c sdisk.cpp

filesys.o: filesys.cpp
	c++ -c filesys.cpp

main.o: main.cpp
	c++ -c main.cpp

clean:
	rm *.o
