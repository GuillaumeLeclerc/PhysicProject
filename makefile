CXX = g++ 
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11


#Executables

final: Vecteur2D.o main.o Montagne.o 
	g++ -o final.exe Vecteur2D.o main.o

testVect2D: TestVect2D.o Vecteur2D.o
	g++ -o testVect2D.exe Vecteur2D.o TestVect2D.o 

testMontagne: Vecteur2D.o Montagne.o TestMontagne.o
	g++ -o testMontagne.exe Vecteur2D.o Montagne.o TestMontagne.o

#Fichiers objects

main.o: Main.cpp

Vecteur2D.o: Vecteur2D.cpp Vecteur2D.h

Montagne.o: Montagne.cpp Montagne.h

TestVect2D.o: TestVect2D.cpp

Montagne.o: Montagne.cpp

TestMontagne.o: TestMontagne.cpp

