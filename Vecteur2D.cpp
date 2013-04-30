#include "Vecteur2D.h"

Vecteur2D::Vecteur2D(){
	x = 0;
	y = 0;
}
Vecteur2D::Vecteur2D(double i_x , double i_y){
	x = i_x;
	y = i_y;
}

Vecteur2D::Vecteur2D(Vecteur2D const &other){
	x = other.x;
	y = other.y;
}

double Vecteur2D::getX()const {
	return x;
}

double Vecteur2D::getY()const{
	return y;
}

bool Vecteur2D::compare(Vecteur2D const &other)const{
	return other.x == x and other.y == y;
}

void Vecteur2D::affiche()const {
	affiche(cout);
}

void Vecteur2D::affiche(ostream& stream) const{
	stream << x << " " << y;
}
Vecteur2D Vecteur2D::addition(Vecteur2D const &other)const{
	return Vecteur2D(x + other.x , y + other.y);
}
Vecteur2D Vecteur2D::soustraction(Vecteur2D const &other) const {
	return addition(other.oppose());
}

Vecteur2D Vecteur2D::oppose()const{
	return Vecteur2D(-x , -y);
}

Vecteur2D Vecteur2D::multiplication(double coef)const{
	return Vecteur2D(coef * x , coef * y);
}

Vecteur2D Vecteur2D::division(double coef)const {
	if(coef == 0 ){
		return *this;
	}
	else{
		return multiplication(1/coef);
	}
}

double Vecteur2D::prod_scal(Vecteur2D const &other)const{
	return x*other.x + y*other.y;
}

double Vecteur2D::length()const{
	return sqrt(x*x + y*y);
}

double Vecteur2D::lengthSquared() const{
	return x*x + y*y;
}


//Opérateurs internes

Vecteur2D Vecteur2D::operator+(Vecteur2D const &other) const{
	return addition(other);
}

Vecteur2D Vecteur2D::operator-(Vecteur2D const &other) const{ 	
	return soustraction(other);
}

Vecteur2D Vecteur2D::operator-() const{
	return oppose();
}

Vecteur2D Vecteur2D::operator*(double coef) const{
	return multiplication(coef);
}

Vecteur2D Vecteur2D::operator/(double coef) const{
	return division(coef);
}

double Vecteur2D::operator*(const Vecteur2D& other) const{
	return prod_scal(other);
}

double Vecteur2D::operator[](int const &index) const{
	switch(index){
		case 1:
			return x;
			break;
		case 2:
			return y;
			break;
		default:
			return 0;
			break;
	}
}

bool Vecteur2D::operator==(Vecteur2D const &other) const{
	return compare(other);
}

bool Vecteur2D::operator!=(Vecteur2D const &other) const{
	return !compare(other);
}

Vecteur2D& Vecteur2D::incremente(Vecteur2D const &other){
	x += other.x;
	y += other.y;
	return *this;
}

Vecteur2D& Vecteur2D::decremente(Vecteur2D const &other){
	x -= other.x;
	y -= other.y;
	return *this;
}

Vecteur2D& Vecteur2D::operator+=(Vecteur2D const &other){
	return incremente(other);
}

Vecteur2D& Vecteur2D::operator-=(Vecteur2D const &other){
	return decremente(other);
}

Vecteur2D& Vecteur2D::multiplicationEqual(double coef){
	x *= coef;
	y *= coef;
	return *this;
}

Vecteur2D& Vecteur2D::operator*=(double other){
	return multiplicationEqual(other);
}

Vecteur2D& Vecteur2D::divisionEqual(double coef){
	if(coef != 0)
	{
		x /= coef;
		y /= coef;
	}
	return *this;
}

Vecteur2D& Vecteur2D::operator/=(double coef){
	return divisionEqual(coef);
}



//Opérateurs externes

std::ostream &operator << (std::ostream &f, const Vecteur2D &toDisplay){
	toDisplay.affiche(f);
	return f; 
}

Vecteur2D operator*(double coef , Vecteur2D const &vect){
	return vect.multiplication(coef);
}

Vecteur2D operator/(double coef , Vecteur2D const &vect){
	return vect.division(coef);
}



