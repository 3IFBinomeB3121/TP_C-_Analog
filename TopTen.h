/*************************************************************************
                           TopTen  -  description
                             -------------------
                             -------------------
    début                : 10/01/2018
    copyright            : (C) 2018 par Christophe ETIENNE & William Occeli
    e-mail               : christophe.etienne@insa-lyon.fr
                           william.occeli@insa-lyon.fr
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
// Cette classe permet de construire un Top 10 des urls de document les
// plus consultées dans un fichier de log Apache.
// TopTen est une structure de données de type arbre binaire de recherche.
//
//------------------------------------------------------------------------

class TopTen
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

//------------------------------------------------- Surcharge d'opérateurs
    TopTen & operator = ( const TopTen & unTopTen );
    // Mode d'emploi : La surchage d'operator = est juste déclaré.
    //
    // Contrat :
    //

    friend ostream & operator << ( ostream & flux, const TopTen & unTopTen);
    // Mode d'emploi : Surcharge de la fonction non membre operator <<
    // déclarée amie de la classe TopTen.
    // L'affichage pour un objet de la classe TopTen est formaté de la manière suivante:
    // Affichage sous forme de classement ordonné croissant (1 à 10) des dix urls de document
    // les plus consultées avec leur nombre de hits. Une url par ligne avec
    // son numéro dans le classement devant.
    // Le premier paramètre est une référence sur un objet de type ostream.
    // Le second paramètre est une référence constante sur un objet de type TopTen qui est l'objet
    // dont on souhaite afficher le Top 10.
    // Retourne une référence sur un objet de type ofstream qui est le flux manipulé.
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    TopTen ( const TopTen & unTopTen );
    // Mode d'emploi (constructeur de copie) : Le constructeur de copie
    // de TopTen est juste déclaré.
    //
    // Contrat :
    //

    TopTen ( const unordered_map<string,int> unM );
    // Mode d'emploi : Construit un objet de type TopTen en initialisant
    // l'attribut mmTop grâce au paramètre unM. Les clés de mmTop sont des entiers
    // représentant le nombre de hits de l'url du document consultée associée (en valeur).
    // Le paramètre unM est une unordered_map constante avec pour clé un string représentant l'url du
    // document consultée et en valeur le nombre de hits.
    //
    // Contrat :
    //

    TopTen ();
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

