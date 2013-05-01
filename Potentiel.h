#include <memory>
#include "Vecteur2D.h"

using namespace std;

class Potentiel
{
private:
	unique_ptr<Vecteur2D> value:
	unique_ptr<Vecteur2D> laplacien;

public:
	Potentiel();

	void setLaplacien(const Vecteur2D&);
	void setLaplacien(const Vecteur2D*&);
	void setLaplacien(unique_ptr<Vecteur2D>&&);
	void setLaplacien(const unique_ptr<Vecteur2D>&);

	void setValue(const Vecteur2D&);
	void setValue(const Vecteur2D*&);
	void setValue(unique_ptr<Vecteur2D>&&);
	void setValue(const unique_ptr<Vecteur2D>&);
	/* data */
};