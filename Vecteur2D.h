#ifndef PRJ_VECTEUR_H
#define PRJ_VECTEUR_H

#include <iostream>
#include <cmath>

#EPSILON 0.1

using namespace std;

class Vecteur2D // Objet immutable
{

private:
	double x;
	double y;

public: 
	Vecteur2D();
	Vecteur2D(double , double );
	Vecteur2D(Vecteur2D const&);
	double getX() const;
	double getY() const;

	//Méthodes normales	

	bool compare(Vecteur2D const&) const;
	void affiche() const;
	void affiche(ostream&) const;
	Vecteur2D addition(Vecteur2D const&) const;
	Vecteur2D& incremente(Vecteur2D const&);
	Vecteur2D& decremente(Vecteur2D const&);
	Vecteur2D soustraction(Vecteur2D const&) const;
	Vecteur2D oppose() const;
	Vecteur2D multiplication(double) const;
	Vecteur2D& multiplicationEqual(double);
	Vecteur2D& divisionEqual(double);
	Vecteur2D division(double) const; 	
	double prod_scal(Vecteur2D const&) const;
	double length() const;
	double lengthSquared() const;

	//surccharge des opérateurs


	bool operator==(Vecteur2D const&) const;
	bool operator!=(Vecteur2D const&) const;
	Vecteur2D operator+(Vecteur2D const&) const;
	Vecteur2D operator-(Vecteur2D const&) const;
	Vecteur2D operator-() const;
	Vecteur2D operator*(double) const;
	double operator*(const Vecteur2D&) const;
	Vecteur2D operator/(double ) const;
	Vecteur2D& operator+=(Vecteur2D const&);
	Vecteur2D& operator-=(Vecteur2D const&);
	Vecteur2D& operator*=(double);
	Vecteur2D& operator/=(double);
	double operator[](int const&) const;	
};

std::ostream &operator << (std::ostream &f, const Vecteur2D &toDisplay);
Vecteur2D operator*(double coef , Vecteur2D const &vect);
Vecteur2D operator/(double coef , Vecteur2D const &vect);

#endif
