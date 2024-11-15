#ifndef __FeuilleI
#define __FeuilleI
using namespace std;
#include <map>
#include "Ligne.h"
#include <vector>

class Feuille : public std::map<std::string, Ligne>
	{
  	public:

		//Constructeurs
		Feuille();		
		Feuille(const std::vector<std::string>& etudiants, const std::vector<std::string>& matieres);	

		//Methodes Moyennes
        double  MoyenneEtudiant(std::string etudiant); 
        double  MoyenneMatiere(std::string matiere); 

		// Operateurs
		bool 	operator == (const Feuille & champ);

		//Methodes pour effectuer des tests uniquement
		void	Afficher() const;	// Afficher le contenu
		void	Saisir();
        void    ModifierCellule(std::string, std::string); 	
        void    InsererLibelleColonne(); 
        void    InsererLibelleLigne(); 

	private:
		std::string      titreFeuille=""; 
};
#endif
