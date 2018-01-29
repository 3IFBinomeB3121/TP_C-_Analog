/*************************************************************************
                           Commande  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Commande> (fichier Commande.h) ----------------
#if ! defined ( Commande_H )
#define Commande_H

//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <string.h>
#include <sstream>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Commande>
//
//
//------------------------------------------------------------------------

class Commande
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void Choisir();
    bool OptExclure();
    int OptTracerGraphe();
    int OptHeure();
    int VerifierHeure(int horaire);
    bool VerifierExtensionDot(string nomFichierDot);
    bool VerifierExtensionLog(string nomFichierLog);


//------------------------------------------------- Surcharge d'opérateurs
    Commande & operator = ( const Commande & unCommande );
    // Mode d'emploi :
    //
    // Contrat :
    //




//-------------------------------------------- Constructeurs - destructeur
    Commande ( const Commande & unCommande );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //


    Commande (int nbArg, char ** arg);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Commande ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	char** option;
	int nombreArg;
};

//-------------------------------- Autres définitions dépendantes de <Commande>

#endif // Commande_H

