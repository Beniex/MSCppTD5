/***************************************************************************
                          Cellule  -  description
                             -------------------
    début                : 10 déc. 2018
    copyright            : (C) 2008 par pcoquard
*************************************************************************/

//---------- Interface de la classe <Cellule> (fichier Cellule.h) ------
#ifndef __CellI
#define __CellI

class Cellule
	{
  	public:

		//Constructeurs
		Cellule();		// élève absent, maValeur non exploitable
		Cellule(double val);	// élève présent et maValeur initialisée à val

		//Methodes
		double	GetValeur() const;	// retourne maValeur
		void	SetValeur(double v);	// avec controle note entre 0 et 20
		bool 	EstPresent() const;	// retourne vrai si élève present

		// Operateurs
		bool 	operator == (const Cellule & champ);

		//Methodes pour effectuer des tests uniquement
		void	Afficher() const;	// Afficher le contenu
		void	Saisir();		// avec controle note entre 0 et 20

	private:
		double   		maValeur; 	// la note
		bool	 		maPresence;	// la presence
};
#endif
