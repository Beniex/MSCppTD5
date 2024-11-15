#include <iostream>
using namespace std;
#include <stdexcept>
#include <cassert>

#include "Ligne.h"
#include "Cellule.h"


#define DEBUG


Ligne::Ligne()
{
#ifdef DEBUG
cout << "Ligne :: Constructeur 1"<<endl;
#endif
    const std::map<std::string, Cellule > ligne; 

}

////////////////////////////////////////////////////////////////////////////
Ligne::Ligne(const std ::vector<std ::string>& m)
{
#ifdef DEBUG
cout << "Ligne :: Constructeur par valeur"<<endl;
#endif

    for (size_t i = 0; i < m.size(); ++i) {
            (*this)[m[i]]= Cellule(); 
        }

}



void	Ligne::Afficher() const {
 for (auto it = (*this).begin(); it != (*this).end(); ++it) {
        cout << "Matiere : " << it->first << std::endl;  
        it->second.Afficher(); 
    }
}

void	Ligne::AfficherMatieres() const {
 for (auto it = (*this).begin(); it != (*this).end(); ++it) {
        cout << "Matiere : " << it->first << std::endl;  

    }
}

void	Ligne::Saisir(){
     for (auto it = (*this).begin(); it != (*this).end(); ++it) {
        cout << "Matiere : " << it->first << std::endl;
        it->second.Saisir();   
    }
};


void    Ligne::AfficherNotes(){
         for (auto it = (*this).begin(); it != (*this).end(); ++it) {
        it->second.Afficher();   
    }
};

double  Ligne::Moyenne() const{

    double somme_notes = 0;  
    double nb_notes = 0; 
    for (auto it = (*this).begin(); it != (*this).end(); ++it) {
        somme_notes = somme_notes + it->second.GetValeur();
        nb_notes++;    
    }
    return somme_notes / nb_notes; 

}