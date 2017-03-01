objs = main.o inout.o sort.o
sortStr : $(objs)
	g++ -o sortStr $(objs)
main.o : main.cpp inout.h sort.h 
	g++ -c main.cpp
inout.o : inout.cpp inout.h
	g++ -c inout.cpp
sort.o : sort.cpp sort.h
	g++ -c sort.cpp
