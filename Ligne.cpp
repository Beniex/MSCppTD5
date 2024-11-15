#include <iostream>
using namespace std;
#include <stdexcept>
#include <cassert>

#include "Ligne.h"


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