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
    else if (nbLog == 0)
    {
		flux << "Le fichier ne contient aucun log" << endl;
	}
	else
    {
        flux << "Affichage des " << nbLog << " log que contient le fichier" << endl;
        for (it = unTopTen.mmTop.crbegin( );  compteur < nbLog; ++it)
        {
            flux << compteur+1 << ". " << it->second << " (" << it->first << " hits)" << endl;
            compteur++;
        }
    }
    return flux;
}

//------------------------------------------------- Surcharge d'op�rateurs



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

//----------------------------------------------------- M�thodes prot�g�es

