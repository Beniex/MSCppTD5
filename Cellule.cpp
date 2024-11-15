/***************************************************************************
                          Cellule  -  description
                             -------------------
    date                 : 10 dec. 2018
    copyright            : (C) 2008 par pcoquard
*************************************************************************/
#include <iostream>
using namespace std;
#include <stdexcept>
#include <cassert>

#include "Cellule.h"
#define DEBUG

//Les Constructeurs
////////////////////////////////////////////////////////////////////////////
Cellule::Cellule()
{
#ifdef DEBUG
cout << "Cellule :: Constructeur 1"<<endl;
#endif
		maValeur=0;
		maPresence=false;
}

////////////////////////////////////////////////////////////////////////////
Cellule::Cellule(double val)
{
#ifdef DEBUG
cout << "Cellule :: Constructeur par valeur"<<endl;
#endif
		maValeur=val;
		maPresence=true;
}

////////////////////////////////////////////////////////////////////////////
// Les Get et les Set
////////////////////////////////////////////////////////////////////////////

double	Cellule::GetValeur() const
{
#ifdef DEBUG
cout <<"Cellule::GetValeur()"<<endl;
#endif
  return maValeur;
}

//////////////////////////////////////////////////////////////////////
void	Cellule::SetValeur(double v)
{
#ifdef DEBUG
cout <<"Cellule::SetValeur()"<<endl;
#endif
	if (!( v >=0 && v <= 20 )) throw logic_error( "Cellule::SetValeur : valeur de la note illegale" );
	maPresence = true;
	maValeur = v;
}

//////////////////////////////////////////////////////////////////////
bool Cellule::EstPresent() const
{
#ifdef DEBUG
cout <<"Cellule::EstPresent()"<<endl;
#endif
	return maPresence;
}

// Surcharge du comparateur
//////////////////////////////////////////////////////////////////////
bool Cellule::operator  == (const Cellule & cel)
{
#ifdef DEBUG
cout <<"Cellule::operateur =="<<endl;
#endif
	return (  (maPresence==false && cel.maPresence==false) ||
		  (maPresence==true  && cel.maPresence==true && maValeur == cel.maValeur) );
}

//////////////////////////////////////////////////////////////////////
void 	Cellule:: 	Afficher() const
{
#ifdef DEBUG
cout <<"Cellule::Afficher() "<<endl;
#endif
	if(maPresence==true)
		cout<<maValeur;
	else
		cout<<"Abs";
}

////////////////////////////////////////////////////////////////////////////
void  Cellule::	Saisir()
{
#ifdef DEBUG
cout <<"Cellule::Saisir()"<<endl;
#endif
		double temp;
		cout << "Quelle Note ?: ";
		cin>> temp; cin.ignore(80,'\n');
		// en phase de debogage
		assert (temp >=0 && temp <= 20 && cin.good());
		// en phase de production
		//if (!( temp >=0 && temp <= 20 && cin.good() )) throw logic_error( "Cellule::Saisir : valeur de la note illegale" );
		SetValeur(temp);
		maPresence=true;
}

