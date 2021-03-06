sub	#include "ChampPotentiel.h"


ChampPotentiel::ChampPotentiel(int i_nombreX , int i_nombreY , int i_nombreZ , double i_tauxEchantillonage){
	nombreX = i_nombreX;
	nombreY = i_nombreY;
	nombreZ = i_nombreZ;
	montagne = nullptr;
	potentiels.resize(nombreX);

	for(int i = 0 ; i < nombreX ; i++){
		potentiels[i].resize(nombreY);
		for(int j =0 ; j < nombreY ; j++){
			potentiels[i][j].resize(nombreZ);
		}
	}
	forEachCoords([](int x, int y , int z , ChampPotentiel* that){
		that->potentiels[x][y][z] = unique_ptr<Potentiel>(new Potentiel());
	});
	tauxEchantillonage = i_tauxEchantillonage;
	
}

void ChampPotentiel::forEachCoords(void (*action)(int , int , int , ChampPotentiel* that)){
	for(int i = 0 ; i < nombreX ; i++){
		for(int j = 0 ; j < nombreY ; j++){
			for(int k = 0 ; k < nombreZ ; k++){
				action(i,j,k,this);
			}
		}
	}
}

double ChampPotentiel::getLengthX() const{
	return nombreX * tauxEchantillonage;
}

double ChampPotentiel::getLengthY() const{
	return nombreY * tauxEchantillonage;
}

double ChampPotentiel::getLengthZ() const{
	return nombreZ * tauxEchantillonage;
}

void ChampPotentiel::initialise(double i_ventAuLoin , unique_ptr<Montagne>&& i_montagne){

	montagne= move(i_montagne);
	ventAuLoin = i_ventAuLoin;

	forEachCoords([](int x , int y , int z , ChampPotentiel* that){
		that->potentiels[x][y][z]->setLaplacien(new Vecteur2D());
		if(z >=  that->montagne->altitude(x, y) ) {			
			that->potentiels[x][y][z]->setValue(that->formuleConditionAuBord(y , z));
		}
		else{
			that->potentiels[x][y][z]->setValue(new Vecteur2D());
		}
	});
}
void ChampPotentiel::calculeLaplacien(){

	forEachCoords([](int x , int y , int z , ChampPotentiel* that){
		if( x> 0  and x < that->nombreX - 1 and x > 0  and y < that->nombreY - 1 and z > 0  and z < that->nombreZ - 1){
			that->potentiels[x][y][z]->setLaplacien(that->formuleDifferenceFinies(x , y, z));
		}
	});
}


unique_ptr<Vecteur2D> ChampPotentiel::formuleConditionAuBord(int y , int z)const {
	double a = ventAuLoin/2.0;
	return unique_ptr<Vecteur2D>(new Vecteur2D(-a* getZTransformed(z), a * getYTransformed(y) ));
}

unique_ptr<Vecteur2D> ChampPotentiel::formuleDifferenceFinies(int x , int y , int z )const{
	Vecteur2D* result= new Vecteur2D();
	result->operator+=(potentiels[x-1][y][z]->getValue());
	result->operator+=(potentiels[x][y-1][z]->getValue());
	result->operator+=(potentiels[x][y][z-1]->getValue());
	result->operator+=(potentiels[x][y][z]->getValue() * 6);
	result->operator+=(potentiels[x+1][y][z]->getValue());
	result->operator+=(potentiels[x][y+1][z]->getValue());
	result->operator+=(potentiels[x][y][z+1]->getValue());
	return unique_ptr<Vecteur2D>(result);
}

void ChampPotentiel::affichePotentiels() const{
	affichePotentiels(cout);
}
void ChampPotentiel::affichePotentiels(ostream& out) const{
	for(int i = 0 ; i < nombreX ; i++){
		for(int j = 0 ; j < nombreY ; j++){
			for(int k = 0 ; k < nombreZ ; k++){
				out << i << " " << j << " " << k << " " << potentiels[i][j][k]->getValue() << endl;
			}
		}		
	}
}
void ChampPotentiel::afficheLaplaciens() const{
	afficheLaplaciens(cout);
}
void ChampPotentiel::afficheLaplaciens(ostream& out) const{
	for(int i = 0 ; i < nombreX ; i++){
		for(int j = 0 ; j < nombreY ; j++){
			for(int k = 0 ; k < nombreZ ; k++){
				out << i << " " << j << " " << k << " " << potentiels[i][j][k]->getLaplacien() << endl;
			}
		}		
	}
}

double ChampPotentiel::getYTransformed(int y)const{
	return tauxEchantillonage * (y - (nombreY-1)/2.0);
}

double ChampPotentiel::getXTransformed(int x)const{
	return tauxEchantillonage * x;
}

double ChampPotentiel::getZTransformed(int z)const{
	return tauxEchantillonage * z;
}

double ChampPotentiel::erreur(){
	double result;
	forEachCoords([&result](int x , int y , int z , ChampPotentiel* that){
		resut += that->potentiels[x][y][z]->getLaplacien().length();
	});
	return result;
}

void ChampPotentiel::iteration(){
	forEachCoords([](int x , int y , int z , ChampPotentiel* that){
		if( x> 0  and x < that->nombreX - 1 and x > 0  and y < that->nombreY - 1 and z > 0  and z < that->nombreZ - 1){
	 		that[x][y][z]->getValue()->operator+(EPSILON * that->formuleDifferenceFinies(x,y,z));
		}
		else
		{
			that[x][y][z]->setValue(that->formuleConditionAuBord(y,z));
		}
	});
}

void ChampPotentiel::resolution(double erreurAdmise , int maxIteration , bool verbeuse=false){
	double currentErreur = -1;
	for(int i = 0 ; i <= maxIteration && (currentErreur < 0 || currentErreur > erreurAdmise); i++){
		iteration();
		erreur = erreur(); 
		if(verbeuse){
			affichePotentiels():
			afficheLaplaciens();
		}
	}
}

double[] ChampPotentiel::formuleDifferenceFiniesVitesse(int i , int j , int k) const {
	double result[] = double[3];
	result[0] = potentiels[i][j+1][k]->getValue()->getY() - potentiels[i][j-1][k]->getValue()->getY() - potentiels[i][j][k+1]->getValue()->getX() +potentiels[i][j][k-1]->getValue()->getX();
	result[1] = -potentiels[i-1][j][k]->getValue()->getY() + potentiels[i+1][j][k]->getValue()->getY();
	result[2] = potentiels[i-1][j][k]->getValue()->getX() - potentiels[i+1][j][k]->getValue()->getX();
	return result;
}

double[] ChampPotentiel::vitesse(int x , int y , int z)const {
	if( x> 0  and x < that->nombreX - 1 and x > 0  and y < that->nombreY - 1 and z > 0  and z < that->nombreZ - 1){
		return formuleDifferenceFiniesVitesse(x ,y, z);
	}
	else{
		return ventAuLoin;
	}

}