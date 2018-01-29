/*************************************************************************
                           TopTen  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <TopTen> (fichier TopTen.h) ----------------
#if ! defined ( TopTen_H )
#define TopTen_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <map>
#include <unordered_map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TopTen>
//
//
//------------------------------------------------------------------------

class TopTen
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
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
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    multimap<int,string> mmTop;

};

//-------------------------------- Autres définitions dépendantes de <TopTen>

#endif // TopTen_H

