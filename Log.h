/*************************************************************************
                           Log  -  description
                             -------------------
    début                : 10/01/2018
    copyright            : (C) 2018 par Christophe ETIENNE & William Occeli
    e-mail               : christophe.etienne@insa-lyon.fr
                           william.occeli@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Log> (fichier Log.h) ----------------
#if ! defined ( Log_H )
#define Log_H

//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Log>
// Permet de stocker toutes les informations d'une ligne de log, précedemment
// lue dans un fichier de log Apache. Les différentes informations stockées sont
// le référent, l'adresse IP, le nom d'utilisateur du visiteur, son pseudo,
// la date et l'heure (greenwich) de la requête, la méthode HTTP utilisée,
// l'url du document recherchée, l'url du document consulté,
// le protocole HTTP utilisée, le status code HTTP, la quantité de données
// transférées en octet et enfin l'identification du client navigateur.
//
//------------------------------------------------------------------------

class Log
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    string GetExtension();
    // Mode d'emploi : Cette méthode permet de récupérer
    // l'information concernant l'extension de l'url du document
    // consulté.
    // Retourne un string contenant l'extension de l'url du document
    // consulté.
    //
    // Contrat :
    //

    string GetCible();
    // Mode d'emploi : Cette méthode permet de récupérer
    // l'information concernant l'url du document à partir duquel on
    // effectue la requête.
    // Retourne un string contenant l'url du document à partir duquel
    // on effectue la requête.
    //
    // Contrat :
    //

    string GetSource();
    // Mode d'emploi : Cette méthode permet de récupérer
    // l'information concernant l'url du document consultée.
    // Retourne un string contenant l'url du document onsultée.
    //
    // Contrat :
    //

    int GetHeure();
    // Mode d'emploi : Cette méthode permet de récupérer
    // l'information concernant l'heure à laquelle on effectue la requête.
    // Retourne un entier correspondant à l'heure où la requête est effectuée.
    //
    // Contrat :
    //

    friend ostream & operator << ( ostream & flux, const Log & unLog );
    // Mode d'emploi : Surcharge de la fonction non membre operator <<
    // déclarée amie de la classe Log.
    // L'affichage pour un objet de la classe Log est formaté de la manière suivante:
    // Affichage de tous les attributs( les différentes inforamtions), un par ligne.
    // Le premier paramètre est une référence sur un objet de type ostream.
    // Le second paramètre est une référence constante sur un objet de type Log qui est
    // l'objet dont on souhaite affiché les informations.
    // Retourne une référence sur un objet de type ofstream qui est le flux manipulé.
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Log & operator = ( const Log & unLog );
    // Mode d'emploi : La surchage d'operator = est juste déclaré.
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Log ( const Log & unLog );
    // Mode d'emploi (constructeur de copie) : Le constructeur de copie
    // de Log est juste déclaré.
    //
    // Contrat :
    //

    Log (string ligneFichier = "");
    // Mode d'emploi : Construit un objet de type Log qui initialise tous les
    // attributs avec les informations contenues dans la ligne lue dans le fichier
    // de log Apache passé en paramètre.
    // Si aucun fichier n'est précisé, renvoie un message d'erreur.
    // Le paramètre <ligneFichier> est une string contenant la ligne dont on souhaite
    // récupérer les informations.
    //
    // Contrat :
    //

    virtual ~Log ( );
    // Mode d'emploi : Le destructeur de Log est juste déclaré.
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

