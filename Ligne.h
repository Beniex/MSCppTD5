/***************************************************************************
                          Ligne  -  description
                             -------------------
    début                : 15 11 2024
    copyright            : Benoit Exbrayat
*************************************************************************/
#include <vector>
#include "Cellule.h"
#include <map>

#ifndef __LigneI
#define __LigneI


class Ligne: public std::map<std::string, Cellule> 
	{
  	public:

		//Constructeurs
		Ligne();		
		Ligne(const std::vector<std::string>& m);	

		//Methodes
        
        double  Moyenne() const; 

		// Operateurs
		bool 	operator == (const Cellule & champ);

		//Methodes pour effectuer des tests uniquement
		void	Afficher() const;	// Afficher le contenu
		void	Saisir();		// avec controle note entre 0 et 20
        void    AfficherMatieres () const;
        void    AfficherNotes();


};
#endif
