#include "Montagne.h"

Montagne::Montagne(const Vecteur2D& i_position , double i_hauteur , double i_etalementX , double i_etalementY){
	position = i_position;
	hauteur = i_hauteur;
	etalementX = i_etalementX;
	etalementY = i_etalementY;
}

double Montagne::altitude(double positionX , double positionY) const{ 
	double result = hauteur * exp(- ((pow(positionX  - position.getX() , 2))/(2*pow(etalementX , 2))) - ((pow(positionY  - position.getY() , 2))/(2*pow(etalementY , 2))));
	if(result < 0.5){
		return 0;
	}
	else{
		return result;
	}

}

void Montagne::affiche(int maxX , int maxY){
	for(int x = 0 ; x < maxX ; x++){
		for(int y = 0 ; y < maxY ; y++){
			cout << x << " " << y << " " << altitude(x , y) << endl;
		}
		cout << endl;
	}
}