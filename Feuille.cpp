#include <iostream>
using namespace std;
#include <stdexcept>
#include <cassert>

#include "Cellule.h"
#include "Ligne.h"
#include "Feuille.h"





Feuille::Feuille()
{
#ifdef DEBUG
cout << "Feuille :: Constructeur 1"<<endl;
#endif
     const std::map<std::string, Ligne > feuille; 
     this->titreFeuille =""; 
}


Feuille::Feuille(const std ::vector<std ::string>& etudiants, const std ::vector<std ::string>& matieres) 
{
#ifdef DEBUG
cout << "Feuille :: Constructeur par valeur"<<endl;
#endif

    for (size_t i = 0; i < etudiants.size(); ++i) {
            (*this)[etudiants[i]]= Ligne(matieres) ; 
        }
     

}

void	Feuille:: Afficher() const{
    for (auto it = (*this).begin(); it != (*this).end(); ++it) {
        cout << "Etudiant : " << it->first << std::endl;
        it->second.Afficher();   
    }
}


void    Feuille::AfficherEnTetes() const{
    vector<string> matieresActuelles ;
    Ligne premiereLigne = (*this).begin()->second ; 
   for (auto it = premiereLigne.begin(); it != premiereLigne.end(); ++it) {
        matieresActuelles.push_back(it->first); 
    }
    
}

void    Feuille::AfficherModeTableur() const{
    (*this).AfficherEnTetes();
}

 

void	Feuille:: Saisir() {
    for (auto it = (*this).begin(); it != (*this).end(); ++it) {
        cout << "Etudiant : " << it->first << std::endl;
        it->second.Saisir();   
    }

}

void   Feuille:: ModifierCellule(string etudiant, string matiere){
    auto iteratorFeuille = (*this).find(etudiant);  
    auto iteratorLigne = iteratorFeuille->second.find(matiere); // iteratorFeuille->second est un objet Ligne 
    iteratorLigne->second.Saisir(); 
}	

void    Feuille::InsererLibelleColonne(){
    string newMatiereName;
	cout << "Quelle est la nouvelle matiere?: ";
	cin>> newMatiereName; cin.ignore(80,'\n');
    for (auto it = (*this).begin(); it != (*this).end(); ++it) {
        it->second[newMatiereName] = Cellule(); 
    }
} 

void    Feuille::InsererLibelleLigne(){
    string newEtudiantName;
	cout << "Quelle est le nouvel etudiant?: ";
	cin>> newEtudiantName; cin.ignore(80,'\n');
    vector<string> matieresActuelles ;
    Ligne premiereLigne = (*this).begin()->second ; 
   for (auto it = premiereLigne.begin(); it != premiereLigne.end(); ++it) {
        matieresActuelles.push_back(it->first); 
    }
    (*this)[newEtudiantName] = Ligne(matieresActuelles);  
} 

double  Feuille::MoyenneEtudiant(std::string etudiant){

    auto iteratorEtudiant= (*this).find(etudiant); 
    return iteratorEtudiant->second.Moyenne(); 
    
} 

double  Feuille::MoyenneMatiere(std::string matiere){
    double somme_notes =0; 
    int nb_notes = 0; 
    for (auto it = (*this).begin(); it != (*this).end(); ++it) { //itération sur les clés de la feuille
        Ligne ligne = it->second;
        auto iteratorLigne = ligne.find(matiere) ;  //iterateur qui point sur le couple matiere Cellule
        somme_notes = somme_notes + iteratorLigne->second.GetValeur(); //iteratorLigne first est matiere et le second est Cellule
        nb_notes++;   
    }
     
    return somme_notes / nb_notes; 

    
} 
