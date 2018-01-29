/*************************************************************************
                           TopTen  -  description
                             -------------------
    d�but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TopTen> (fichier TopTen.h) ----------------
#if ! defined ( TopTen_H )
#define TopTen_H

//--------------------------------------------------- Interfaces utilis�es

#include <string>
#include <map>
#include <unordered_map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <TopTen>
//
//
//------------------------------------------------------------------------

class TopTen
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste des param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs
    TopTen & operator = ( const TopTen & unTopTen );
    // Mode d'emploi :
    //
    // Contrat :
    //

    friend ostream & operator << ( ostream & flux, const TopTen & unTopTen);

//-------------------------------------------- Constructeurs - destructeur
    TopTen ( const TopTen & unTopTen );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    TopTen ( const unordered_map<string,int> unM );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~TopTen ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

    multimap<int,string> mmTop;

};

//-------------------------------- Autres d�finitions d�pendantes de <TopTen>

#endif // TopTen_H

