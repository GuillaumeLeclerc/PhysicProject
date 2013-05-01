
ChampPotentiel::ChamChampPotentiel(int i_nombreX , int i_nombreY , int i_nombreZ , double i_tauxEchantillonage){
	nombreX = i_nombreX;
	nombreY = i_nombreY:
	nombreZ = i_nombreZ;

	montagne = nullptr;

	potentiels.resize(nombreX);

	for(int i = 0 ; i < nombreX ; i++){
		potentiels[i].resize(nombreY);
		for(int j =0 ; j < nombreY ; j++){
			potentiels[i][j].resize(nombreZ);
		}
	}
	forEachCoords([](int x, int z , int z , unique_ptr<Potentiel> potentiel){
		potentiel = new Potentiel();
	});
	tauxEchantillonage = i_tauxEchantillonage;
	
}

void ChampPotentiel::forEachCoords(void (*action)(int , int , int , const unique_ptr<Vecteur2D>&)) const{
	for(int i = 0 ; i < nombreX ; i++){
		for(int j = 0 ; j < nombreY ; j++){
			for(int k = 0 ; k < nombreZ ; k++){
				action(x,y,z,potentiels[x][y][z]);
			}
		}
	}
}

double ChampPotentiel::getLengthX() const{
	return NombreX * tauxEchantillonage;
}

double ChampPotentiel::getLengthY() const{
	return nombreY * tauxEchantillonage;
}

double ChampPotentiel::getLengthZ() const{
	return nombreZ * tauxEchantillonage;
}

void ChampPotentiel::initialise(double i_ventAuLoin , unique_ptr<Montagne>&& i_montagne){

	montagne= i_montagne;
	ventAuLoin = i_ventAuLoin;

	forEachCoords([](int x , int y , int z , const unique_ptr<Vecteur2D>& potentiel){
		potentiels->setLaplacien(new Vecteur2D());
		if(montagne.altitude(x,y,z) != 0){
			
			potentiels->setValue(formuleConditionAuBord(y , z));
		}
		else{
			potentiels->setValue(new Vecteur2D());
		}
	});
}
void ChampPotentiel::calculeLaplacien(){

	forEachCoords([](int x , int y , int z , const unique_ptr<Vecteur2D>& potentiel){
		if( x> 0  and x < nombreX - 1 and x > 0  and y < nombreY - 1 and z > 0  and z < nombreZ - 1){
			potentiel->setLaplacien(formuleDifferenceFinies(x , y, z));
		}
	});
}


Vecteur2D* ChampPotentiel::formuleConditionAuBord(int y , int z){
	double a = ventAuLoin/2;
	return new Vecteur2D(-a*z , a*y);
}

Vecteur2D* ChampPotentiel::formuleDifferenceFinies(int x , int y , int z){
	Vecteur2D* result= new Vecteur2D();
	result += *potentiel[x-1][j][k];
	result += *potentiel[x][y-1][z];
	result += *potentiel[x][y][z-1];
	result -= *potentiel[x][y][z] * 6;
	result += *potentiel[x+1][y][z];
	result += *potentiel[x][y+1][z];
	result += *potentiel[x][y][z+1];
	return result;
}