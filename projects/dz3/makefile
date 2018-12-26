main: main.o min.lib
	g++ main.o min.lib -o main
main.o: main.cpp
	g++ -c main.cpp
min.lib: first_min.o second_min.o
	ar rs min.lib first_min.o second_min.o
first_min.o: first_min.cpp
	g++ -c first_min.cpp
second_min.o: second_min.cpp
	g++ -c second_min.cpp
