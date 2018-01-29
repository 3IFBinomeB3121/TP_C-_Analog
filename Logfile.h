/*************************************************************************
                           Logfile  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Logfile> (fichier Logfile.h) ----------------
#if ! defined ( Logfile_H )
#define Logfile_H

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
#include "Log.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Logfile>
//
//~
//------------------------------------------------------------------------

class Logfile
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Log LireLog();
    bool eof();
    bool is_open();


//------------------------------------------------- Surcharge d'opérateurs
    Logfile & operator = ( const Logfile & unLogfile );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Logfile ( const Logfile & unLogfile );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Logfile (string nomFichier = "");
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Logfile ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	ifstream fichier;
};

//-------------------------------- Autres définitions dépendantes de <Logfile>

#endif // Logfile_H

