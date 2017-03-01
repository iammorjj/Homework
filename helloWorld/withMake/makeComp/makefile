objs = main.o func.o
helloWorld : $(objs)
	g++ -o helloWorld $(objs)
main.o : main.cpp func.h
	g++ -c main.cpp
func.o : func.cpp func.h
	g++ -c func.cpp
