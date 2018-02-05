/*************************************************************************
                           Logfile  -  description
                             -------------------
    début                : 10/01/2018
    copyright            : (C) 2018 par Christophe ETIENNE & William Occelli
    e-mail               : christophe.etienne@insa-lyon.fr
                           william.occelli@insa-lyon.fr
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
// La classe Logfile permet de lire des données à partir d'un fichier
// de log Apache.
//
//------------------------------------------------------------------------

class Logfile
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    Log LireLog();
    // Mode d'emploi : Cette méthode permet de lire une ligne
    // d'un fichier de log Apache. Elle lit la ligne où l'on se trouve
    // dans le fichier au moment de l'appel.
    // Elle retourne un objet de type Log contenant les différentes
    // informations de la ligne lue.
    //
    // Contrat :
    //

    bool eof();
    // Mode d'emploi : Vérifie si eofbit est levé.
    // Retourne true si le bit d'état d'erreur eofbit est levé  pour le flux
    // et false sinon.
    // Le drapeau est levé pour toutes opérations d'entrée quand la fin du
    // fichier est atteinte dans la séquence associée au flux.
    //
    // Contrat :
    //

    bool is_open();
    // Mode d'emploi : Vérifie si un fichier est ouvert
    // Retourne vrai si un fichier est ouvert et associé à cet objet de flux,
    // false sinon.
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Logfile & operator = ( const Logfile & unLogfile );
    // Mode d'emploi : La surchage d'operator = est juste déclaré.
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Logfile ( const Logfile & unLogfile );
    // Mode d'emploi (constructeur de copie) : Le constructeur de copie
    // de Logfile est juste déclaré.
    //
    // Contrat :
    //

    Logfile (string nomFichier = "");
    // Mode d'emploi : Construit un objet Logfile qui est associé
    // avec le fichier passé en paramètre.
    // Si aucun fichier n'est précisé, affiche un message d'erreur.
    //
    // Contrat :
    //

    virtual ~Logfile ( );
    // Mode d'emploi : Ferme le fichier actuellement associé avec l'objet, le dissociant
    // du flux.
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

