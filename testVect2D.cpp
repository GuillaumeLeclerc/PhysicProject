#include <iostream>
#include "Vecteur2D.h"

using namespace std;

int main(){

		// un vecteur en 2D :
	Vecteur2D vect1(1.0, 2.0);

	// un autre vecteur en 2D
	Vecteur2D  vect2(2.6, 3.5);
	Vecteur2D  vect3(vect1);  // copie de V1
	Vecteur2D  vect4;         // le vecteur nul

	cout << "Vecteur 1 : " << vect1 << endl;
	cout << "Vecteur 2 : " << vect2 << endl;  
	cout << "Vecteur 4 : " << vect4 << endl;

	cout << "Le vecteur 1 est ";
	if (vect1 == vect2) {
	    cout << "egal au";
	} else {
	    cout << "different du";
	}
	cout << " vecteur 2," << endl << "et est ";

	if (vect1 != vect3) {
	    cout << "différent du";
	} else {
	    cout << "egal au";
	}
	cout << " vecteur 3." << endl;

	cout << endl << " Partie 2 : " << endl;

	cout << "vect1 + vect2 = " << vect1 + vect2 << endl;
	cout << "vect2 + vect1 = " << vect2 + vect1 << endl;
	cout << "vect1 + (0 , 0) = " << vect1 + Vecteur2D() << endl;
	cout << "(0 ,0) + vect1 = " << Vecteur2D() + vect1 << endl;
	cout << "vect1 - vect2 = " << vect1 - vect2 << endl;
	cout << "vect1 - vect1 = " << vect1 - vect1 << endl;
	cout << "-vect1 = " << -vect1 << endl;
	cout << "-vect2 + vect1 = " << -vect2 + vect1 << endl;
	cout << "3*vect1 = " << 3*vect1 << endl;
	cout << "vect1 * vect2 = " << vect1 * vect2 << endl;
	cout << "vect2 * vect1 = " << vect2 * vect1 << endl;
	Vecteur2D vectN(12 , -0.1);
	cout << "||vectN||^2 = " << vectN.lengthSquared() << endl;
	cout << "||vectN|| = " << vectN.length() << endl;
	cout << "||vect2||^2 = " << vect2.lengthSquared() << endl;
	cout << "||vect2|| = " << vect2 .length() << endl;

	cout << endl << endl << "test pointeurs" << endl << endl;

	Vecteur2D* pt = &vect1;
	Vecteur2D* pt2 = &vect2;
	cout << pt + pt2 << endl;
}

