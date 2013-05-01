#ifndef PRJ_MONTAGNE_H
#define PRJ_MONTAGNE_H

#include <cmath>
#include "Vecteur2D.h"


class Montagne{ 
private:
	Vecteur2D position;
	double hauteur;
	double etalementX;
	double etalementY;

public:
	Montagne(const Vecteur2D& i_position , double hauteur , double i_etalementX , double i_etalementY);
	double altitude(double positionX , double positionY) const;
	void affiche(int , int);
};

#endif // #define PRJ_MONTAGNE_H