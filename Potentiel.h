#include <memory>
#include "Vecteur2D.h"

using namespace std;

class Potentiel
{
private:
	unique_ptr<Vecteur2D> valeur;
	unique_ptr<Vecteur2D> laplacien;
	unique_ptr<Vecteur2D> laplacien2;

public:
	Potentiel();

	const Vecteur2D& getLaplacien()const;
	const Vecteur2D& getValue() const;


	void setLaplacien(const Vecteur2D&);
	void setLaplacien(Vecteur2D*);
	void setLaplacien(unique_ptr<Vecteur2D>&&);
	void setLaplacien(const unique_ptr<Vecteur2D>&);

	void setValue(const Vecteur2D&);
	void setValue(Vecteur2D*);
	void setValue(unique_ptr<Vecteur2D>&&);
	void setValue(const unique_ptr<Vecteur2D>&);
	/* data */
};