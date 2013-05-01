#include "Potentiel.h"

Potentiel::Potentiel(){
	value.reset();
	laplacien.reset();
}

void Potentiel::setLaplacien(const Vecteur2D& value){
	Vecteur2D copy = value;
	laplacien = new unique_ptr<Vecteur2D>(&copy);
}
void Potentiel::setLaplacien(const Vecteur2D* &pt){
	laplacien = new unique_ptr<Vecteur2D>(&*pt);
}

void Potentiel::setLaplacien(unique_ptr<Vecteur2D>&& uptr){
	laplacien = uptr;
}

void Potentiel::setLaplacien(const unique_ptr<Vecteur2D>& pt){
	laplacien = new unique_ptr<Vecteur2D>(&*pt);
}

void Potentiel::setValue(const Vecteur2D& value){
	Vecteur2D copy = value;
	value = new unique_ptr<Vecteur2D>(&copy);
}
void Potentiel::setValue(const Vecteur2D* &pt){
	value = new unique_ptr<Vecteur2D>(&*pt);
}

void Potentiel::setValue(unique_ptr<Vecteur2D>&& uptr){
	value = uptr;
}

void Potentiel::setValue(const unique_ptr<Vecteur2D>& pt){
	value = new unique_ptr<Vecteur2D>(&*pt);
}