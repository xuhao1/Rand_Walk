bool:bool.o namibang.o Metropolis.o vector2f.o
	gcc -o bool *.o
namibang.o:namibang.h namibang.cpp
	gcc -c namibang.cpp
Metropolis.o:Metropolis.cpp Metropolis.h
	gcc -c Metropolis.cpp
vector2f.o:vector2f.h vector2f.cpp
	gcc -c vector2f.cpp
