CXX = g++
CC  = $(CXX)
CCT = $(CXX) -c

CXXFLAGS = -std=c++11  # C++11


#Executables

Final: Vecteur2D.o Main.o Montagne.o 
	$(CC) -o Final.exe Vecteur2D.o Main.o $(CXXFLAGS)

TestVecteur2D: TestVect2D.o Vecteur2D.o
	$(CC) -o testVect2D.exe Vecteur2D.o TestVect2D.o $(CXXFLAGS)

TestMontagne: Vecteur2D.o Montagne.o TestMontagne.o Vecteur2D.o
	$(CC) -o testMontagne.exe Vecteur2D.o Montagne.o TestMontagne.o $(CXXFLAGS)

TestPotentiel: Vecteur2D.o Potentiel.o ChampPotentiel.o TestPotentiel.o Montagne.o
	$(CC) -o TestPotentiel.exe Vecteur2D.o Potentiel.o ChampPotentiel.o Montagne.o TestPotentiel.o  $(CXXFLAGS)


#Fichiers objects

Main.o: Main.cpp
	$(CCT) Main.cpp $(CXXFLAGS)

Vecteur2D.o: Vecteur2D.cpp Vecteur2D.h
	$(CCT) Vecteur2D.cpp $(CXXFLAGS)

Montagne.o: Montagne.cpp Montagne.h Vecteur2D.o
	$(CCT) Montagne.cpp $(CXXFLAGS)

Potentiel.o: Potentiel.h Potentiel.cpp Vecteur2D.o
	$(CCT) Potentiel.cpp $(CXXFLAGS)

ChampPotentiel.o: ChampPotentiel.h ChampPotentiel.cpp Montagne.o Potentiel.o
	$(CCT) ChampPotentiel.cpp $(CXXFLAGS)

#tests

TestPotentiel.o: TestPotentiel.cpp
	$(CCT) TestPotentiel.cpp $(CXXFLAGS)

TestVect2D.o: TestVect2D.cpp
	$(CCT) TestVect2D.cpp $(CXXFLAGS)

TestMontagne.o: TestMontagne.cpp
	$(CCT) TestMontagne.cpp $(CXXFLAGS)
