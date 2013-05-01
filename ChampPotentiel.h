#include <vector>
#include <memory>
#include <iostream>
#include "Vecteur2D.h"
#include "Montagne.h"
#include "Potentiel.h"

using namespace std;

class ChampPotentiel
{
private:

	int nombreX;
	int nombreY;
	int nombreZ;

	double ventAuLoin; 
	unique_ptr<Montagne> montagne;

	vector<vector<vector<unique_ptr<Potentiel>>>> potentiels;

	double tauxEchantillonage; 

	void forEachCoords(void (*action)(int , int , int , ChampPotentiel* ));

	unique_ptr<Vecteur2D> formuleConditionAuBord(int y , int z);
	unique_ptr<Vecteur2D> formuleDifferenceFinies(int x , int y , int z);

	double getXTransformed(int)const;
	double getYTransformed(int)const;
	double getZTransformed(int)const;

public:
	ChampPotentiel(int i_nombreX , int i_nombreY , int i_nombreZ , double i_tauxEchantillonage);

	void initialise(double , unique_ptr<Montagne>&&);
	void calculeLaplacien();

	double getLengthX() const;
	double getLengthY() const;
	double getLengthZ() const;

	void affichePotentiels() const;
	void affichePotentiels(ostream&) const;
	void afficheLaplaciens() const;
	void afficheLaplaciens(ostream&) const;

};

