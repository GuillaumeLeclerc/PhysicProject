CXX = g++ 
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11

CXXFLAGS += -pedantic -Wall

final.exe : Vecteur2D.o main.o
	g++ -o final.exe Vecteur2D.o main.o

main.o : main.cpp

Vecteur2D.o : Vecteur2D.cpp Vecteur2D.h


