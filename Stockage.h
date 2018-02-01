/*************************************************************************
                           Stockage  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Stockage> (fichier Stockage.h) ----------------
#if ! defined ( Stockage_H )
#define Stockage_H

//--------------------------------------------------- Interfaces utilisées

#include <unordered_map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Stockage>
//
//
//------------------------------------------------------------------------

class Stockage
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void AfficherTop(); // Méthode qui va créer le top10 et l'afficher

    void RemplirMapExclusHeure(int heureChoisie = -1, string nomFichier = "");

    void RemplirMapExclus(string nomFichier = "");

    void RemplirMapSansCond(string nomFichier = "");

    void RemplirMapHeure(int heureChoisie = -1, string nomFichier = "");


//------------------------------------------------- Surcharge d'opérateurs
    Stockage & operator = ( const Stockage & unStockage );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Stockage ( const Stockage & unStockage );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Stockage ();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Stockage ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    unordered_map<string,int> stockLog;

};

//-------------------------------- Autres définitions dépendantes de <Stockage>

#endif // Stockage_H

