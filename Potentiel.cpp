#include "Potentiel.h"

Potentiel::Potentiel(){
	valeur.reset();
	laplacien.reset();
}

const Vecteur2D& Potentiel::getLaplacien() const {
	return *laplacien;
}

const Vecteur2D& Potentiel::getValue() const {
	return *valeur;
}

void Potentiel::setLaplacien(const Vecteur2D& value){
	laplacien = unique_ptr<Vecteur2D>(new Vecteur2D(value));
}
void Potentiel::setLaplacien( Vecteur2D* pt){
	laplacien = unique_ptr<Vecteur2D>(new Vecteur2D(*pt));
}

void Potentiel::setLaplacien(unique_ptr<Vecteur2D>&& uptr){
	laplacien = move(uptr);
}

void Potentiel::setLaplacien(const unique_ptr<Vecteur2D>& pt){
	laplacien = unique_ptr<Vecteur2D>(new Vecteur2D(*pt));
}

void Potentiel::setValue(const Vecteur2D& value){
	valeur = unique_ptr<Vecteur2D>(new Vecteur2D(value));
}
void Potentiel::setValue(Vecteur2D* pt){
	valeur = unique_ptr<Vecteur2D>(new Vecteur2D(*pt));
}

void Potentiel::setValue(unique_ptr<Vecteur2D>&& uptr){
	valeur = move(uptr);
}

void Potentiel::setValue(const unique_ptr<Vecteur2D>& pt){
	valeur = unique_ptr<Vecteur2D>(new Vecteur2D(*pt));
}
