/*************************************************************************
                           Stockage  -  description
                             -------------------
    début                : 10/01/2018
    copyright            : (C) 2018 par Christophe ETIENNE & William Occelli
    e-mail               : christophe.etienne@insa-lyon.fr
                           william.occelli@insa-lyon.fr
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
// Cette classe stocke chacune des URLs des documents consultés apparaissant dans le fichier
// log Apache ainsi que le nombre de fois ou ceux-ci sont consultés.
// Stockage est une structure de données de type table de hachage. Elle possède
// plusieurs méthodes permettant de stocker tous les documents consultés ou alors
// seulement certains documents en fonction des options rentrées en ligne de commande.
// De plus, elle possède une méthode permettant d'afficher le top 10 des url des
// documents les plus consultés.
//
//------------------------------------------------------------------------

class Stockage
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void AfficherTop();
    // Mode d'emploi : Méthode permettant d'afficher le top 10 des urls des documents
    // les plus consultés dans le fichier de log Apache passé en ligne de commande.
    // En cas d'égalité dans le nombre de hits, elle affiche par ordre décroissant
    // de lecture du fichier log.
    //
    // Contrat :
    //

    void RemplirMapExclusHeure(int heureChoisie = -1, string nomFichier = "");
    // Mode d'emploi : Méthode permettant de remplir l'attribut stockLog qui est
    // une unordered_map. Elle la remplit avec pour clé l'url du document recherché
    // et initialise sa valeur à 1. En cas d'ajout d'une url existante, la valeur est
    // incrémentée de 1. Elle ne stocke que les informations pour lesquelles l'heure de
    // la recherche correspond à l'heure passée en paramètre et dont l'extension
    // du document recherché n'est pas '.jpg', '.png', '.css' ou '.js'.
    // Le paramètre <nomFichier> est le nom du fichier de log Apache  à analyser
    // écrit par l'utilisateur en ligne de commande.
    // Le paramètre heureChoisie est l'heure spécifiée par l'utilisateur en ligne
    // de commande après l'option '-t'.
    //
    // Contrat :
    //

    void RemplirMapExclus(string nomFichier = "");
    // Mode d'emploi : Méthode permettant de remplir l'attribut stockLog qui est
    // une unordered_map. Elle la remplit avec pour clé l'url du document recherché
    // et initialise sa valeur à 1. En cas d'ajout d'une url existante, la valeur est
    // incrémentée de 1. Elle ne stocke pas les informations pour lesquelles l'extension
    // du document recherché est '.jpg', '.png', '.css' ou '.js'.
    //
    // Le paramètre <nomFichier> est le nom du fichier de log Apache  à analyser
    // écrit par l'utilisateur en ligne de commande.
    //
    // Contrat :
    //

    void RemplirMapSansCond(string nomFichier = "");
    // Mode d'emploi : Méthode permettant de remplir l'attribut stockLog qui est
    // une unordered_map. Elle la remplit avec pour clé l'url du document recherché
    // et initialise sa valeur à 1. En cas d'ajout d'une url existante, la valeur est
    // incrémentée de 1.
    //
    // Le paramètre <nomFichier> est le nom du fichier de log Apache  à analyser
    // écrit par l'utilisateur en ligne de commande.
    //
    // Contrat :
    //

    void RemplirMapHeure(int heureChoisie = -1, string nomFichier = "");
    // Mode d'emploi : Méthode permettant de remplir l'attribut stockLog qui est
    // une unordered_map. Elle la remplit avec pour clé l'url du document recherché
    // et initialise sa valeur à 1. En cas d'ajout d'une url existante, la valeur est
    // incrémentée de 1. Elle ne stocke que les informations pour lesquelles l'heure de
    // la recherche correspond à l'heure passée en paramètre.
    // Le paramètre <nomFichier> est le nom du fichier de log Apache  à analyser
    // écrit par l'utilisateur en ligne de commande.
    // Le paramètre heureChoisie est l'heure spécifiée par l'utilisateur en ligne
    // de commande après l'option '-t'.
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Stockage & operator = ( const Stockage & unStockage );
    // Mode d'emploi : La surchage d'operator = est juste déclaré.
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Stockage ( const Stockage & unStockage );
    // Mode d'emploi (constructeur de copie) : Le constructeur de copie
    // de Stockage est juste déclaré.
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

