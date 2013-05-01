#include <iostream>
#include <memory>

#include "Vecteur2D.h"
#include "Montagne.h"
#include "ChampPotentiel.h"

using namespace std;

int main(int argc, char const *argv[])
{
	ChampPotentiel champ(30,30,30,20.0/29.0);
	unique_ptr<Montagne> p(new Montagne(Vecteur2D(15 , 15) , 15 ,  5 , 5));
	champ.initialise(15 , move(p));
	champ.affichePotentiels();
	return 0;
}