#include <vector>

#include "Vecteur2D.h";
#include "Montagne.h"

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

	void forEachCoords(void (*action)(int , int , int , const unique_ptr<Vecteur2D>&)) const;

	unique_ptr<Vecteur2D>&& formuleConditionAuBord();
	unique_ptr<Vecteur2D>&& formuleDifferenceFinies();


public:
	ChampPotentiel(int i_nombreX , int i_nombreY , int i_nombreZ , double i_tauxEchantillonage);

	void initialise(double , const Montagne&);

	double getXLength() const;
	double getYLength() const;
	double getZLength() const;

	/* data */
};