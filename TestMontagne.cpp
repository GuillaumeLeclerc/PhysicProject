#include <iostream>

#include "Vecteur2D.h"
#include "Montagne.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Montagne montagneTest(Vecteur2D(15,15) , 18 , 5 ,10);

	for(int x = 0 ; x < 30 ; x++){
		for(int y = 0 ; y < 30 ; y++){
			cout << x << " " << y << " " << montagneTest.altitude(x , y) << endl;
		}
		cout << endl;
	}

}