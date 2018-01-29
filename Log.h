/*************************************************************************
                           Log  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Log> (fichier Log.h) ----------------
#if ! defined ( Log_H )
#define Log_H

//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Log>
//
//
//------------------------------------------------------------------------

class Log
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
    //Log & operator = ( const Log & unLog );
    // Mode d'emploi :
    //
    // Contrat :
    //
    string GetExtension();
    string GetCible();
    int GetHeure();

    friend ostream & operator << ( ostream & flux, const Log & unLog );


//-------------------------------------------- Constructeurs - destructeur
    Log ( const Log & unLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Log (string ligneFichier = "");
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Log ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string referent;
	string adresseIP;
	string nom_visiteur;
	string pseudo;
	string date;
	int heure;
	string methode;
	string cible;
	string protocole;
	int status_code;
	int nbOctet;
	string source;
	string id_client_navigateur;
};

//-------------------------------- Autres définitions dépendantes de <Log>

#endif // Log_H

