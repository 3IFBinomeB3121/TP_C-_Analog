/*************************************************************************
                           TopTen  -  description
                             -------------------
    d�but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <TopTen> (fichier TopTen.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TopTen.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type TopTen::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode
ostream & operator << (ostream & flux, const TopTen & unTopTen)
{
    multimap<int,string>::const_reverse_iterator it;
    int compteur = 0;
    for (it = unTopTen.mmTop.crbegin( ); compteur < 10; ++it)
    {
        flux << it->second << " (" << it->first << " hits)" << endl;
        compteur++;
        flux << compteur <<endl;
    }
}

//------------------------------------------------- Surcharge d'op�rateurs
TopTen & TopTen::operator = ( const TopTen & unTopTen )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TopTen::TopTen ( const TopTen & unTopTen )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TopTen>" << endl;
#endif
} //----- Fin de TopTen (constructeur de copie)


TopTen::TopTen ( const unordered_map<string,int> unM )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TopTen>" << endl;
#endif
    // mmTop = new multimap();
    unordered_map<string,int>::const_iterator it;
    for (it = unM.cbegin( ); it != unM.cend( ); ++it)
    {
        mmTop.insert( pair<int,string>(it->second,it->first) );
    }

} //----- Fin de TopTen


TopTen::~TopTen ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TopTen>" << endl;
#endif
//    delete mmTop;

} //----- Fin de ~TopTen


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

