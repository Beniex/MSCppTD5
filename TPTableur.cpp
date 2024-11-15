//============================================================================
// Name        : TPTableur.cpp
// Author      : psc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include <stdexcept>
#include <vector>
#include <string>
#include <map>

#include "Cellule.h"
//#include "Ligne.h"
//#include "Feuille.h"

void TCellule ()
{
  cout << "Test Cellule"<< endl;
  try {
    Cellule c1;
    cout << "cellule construite par defaut :" ;
    c1.Afficher();
    cout << endl;

    Cellule c2( 4);
    cout << "cellule qui doit valoir 4 : " ;
    c2.Afficher();
    cout << endl;

    Cellule c3(4);
    if ( c2 == c3 ) cout << "Gagné"; else cout << "Perdu";
    cout << endl;

    Cellule c6(5);
    if ( c2 == c6 ) cout << "Gagné"; else cout << "Perdu";
    cout << endl;

    Cellule c4;
    c4 = c2;
    cout << "Comparaison de deux cellules identiques "<<endl;
    if ( c2 == c4 ) cout << "Gagné"; else cout << "Perdu";
    cout << endl;

    cout << "SAISIE d'une cellule : "<<endl;
    Cellule c5;
    c5.Saisir();
    cout << "Apres saisie" <<endl;
    c5.Afficher();
    cout << endl;

    cout << "eleve present ? :" << endl;
    cout << ( c1.EstPresent ()? "c1 PRESENT" : "c1 ABSENT" )<< endl;
    cout << ( c2.EstPresent ()? "c2 PRESENT" : "c2 ABSENT" )<< endl;
  }
  catch (exception & exc) {
        cerr << "Exception: " << exc.what() << endl;
  }
}

/*
void TLigne ()
{

vector<string> lib;
lib.push_back("MATHS");
lib.push_back("PHYSIQUE");
lib.push_back("CHIMIE");

Ligne l2(lib);
l2.Afficher();
l2.Saisir();
l2.AfficherMatieres();
l2.AfficherNotes();

cout << "moyenne : " << l2.Moyenne() << endl;
}
*/

/*

void TFeuille ()
{

string tab_eleves[] = {"DUPOND","DURANT", "DUBOIS"};
string tab_matieres[] = {"MATHS","PHYSIQUE", "CHIMIE", "INFORMATIQUE"};
vector<string> v_e( tab_eleves, tab_eleves+3);
vector<string> v_m( tab_matieres, tab_matieres+4);
Feuille f2(v_e, v_m);
f2.Afficher();

f2.Saisir();
f2.Afficher();

f2.ModifierCellule("DUPOND","PHYSIQUE");
f2.ModifierCellule();
f2.Afficher();

cout << "inserer une nouvelle matière : " << endl;
f2.InsererLibelleColonne();
f2.Afficher();

cout << "inserer un nouvel etudiant : " << endl;
f2.InsererLibelleLigne();
f2.Afficher();

}
*/

/*

void TMoyennes ()
{

string tab_eleves[] = {"DUPOND","DURANT", "DUBOIS"};
string tab_matieres[] = {"MATHS","PHYSIQUE", "CHIMIE"};
vector<string> v_e( tab_eleves, tab_eleves+3);
vector<string> v_m( tab_matieres, tab_matieres+3);
Feuille f2(v_e, v_m);
f2.Afficher();

string etud;
cout << "Quel etudiant ?" << endl;
cin >> etud;
f2.ModifierCellule(etud,"MATHS");
f2.ModifierCellule(etud,"PHYSIQUE");
f2.ModifierCellule(etud,"CHIMIE");
cout << "resultats :" << f2.MoyenneEtudiant(etud)<< endl;

string mat;
cout << "Quelle matiere  ?" << endl;
cin >> mat;
f2.ModifierCellule("DUBOIS", mat);
f2.ModifierCellule("DURANT", mat);
f2.ModifierCellule("DUPOND", mat);
cout << "resultats :" << f2.MoyenneMatiere(mat)<< endl;
}
*/


int main() {
cout << "!!!Hello TPTableur !!! " << endl;
TCellule();
//TLigne();
//TFeuille();
//TMoyennes();
cout << "!!!Bye TPTableur !!! " << endl;
return 0;
}
