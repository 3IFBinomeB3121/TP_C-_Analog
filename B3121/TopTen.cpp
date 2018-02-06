/*************************************************************************
                           TopTen  -  description
                             -------------------
    début                : 10/01/2018
    copyright            : (C) 2018 par Christophe ETIENNE & William Occelli
    e-mail               : christophe.etienne@insa-lyon.fr
                           william.occelli@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TopTen> (fichier TopTen.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "TopTen.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs

ostream & operator << (ostream & flux, const TopTen & unTopTen)
{
    multimap<int,string>::const_reverse_iterator it;
    int compteur = 0;
    int nbLog = unTopTen.mmTop.size();
    if (nbLog>=10)
    {
        flux << "Affichage du TOP 10 : " << endl;
        for (it = unTopTen.mmTop.crbegin( ); compteur < 10; ++it)
        {
            flux << compteur+1 << ". " << it->second << " (" << it->first << " hits)" << endl;
            compteur++;
        }
    }
    else if (nbLog == 1)
    {
		flux << "Le fichier ne contient aucun log" << endl;
	}
	else
    {
        flux << "Affichage des " << nbLog-1 << " log que contient le fichier" << endl;
        for (it = unTopTen.mmTop.crbegin( );  compteur < nbLog-1; ++it)
        {
            flux << compteur+1 << ". " << it->second << " (" << it->first << " hits)" << endl;
            compteur++;
        }
    }
    return flux;
} //----- Fin de operator <<

//-------------------------------------------- Constructeurs - destructeur

TopTen::TopTen ( const unordered_map<string,int> unM )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TopTen>" << endl;
#endif
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

} //----- Fin de ~TopTen

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

