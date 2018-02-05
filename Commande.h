/*************************************************************************
                           Commande  -  description
                             -------------------
    début                : 10/01/2018
    copyright            : (C) 2018 par Christophe ETIENNE & William Occelli
    e-mail               : christophe.etienne@insa-lyon.fr
                           william.occelli@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Commande> (fichier Commande.h) ----------------
#if ! defined ( Commande_H )
#define Commande_H

//--------------------------------------------------- Interfaces utilisées

using namespace std;
#include <string.h>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Commande>
// La classe <Commande> permet de récupérer le nombre d'options passées en ligne de commande
// sur le shell par l'utilisateur et leur valeur. A partir de ces paramètres, elle les analyse
// et construit une réponse en fonction de celles-ci.
// Pour construire une réponse, les options passées en paramètre doivent être valides.
// Les trois options facultatives possibles sont:
// '-t heure', '-g nomfichier.dot' et '-e'. Celles-ci peuvent être combinées et
// placées dans un ordre quelconque entre elles. En revanche, le seul paramètre obligatoire est
// le nom du fichier dont on analyse les logs  et doit être d'extension .log, exister et être placé en dernier.
// '-t heure' : Permet de ne prendre en compte que les hits qui sont dans le créneau horaire correspondant
// à l'intervalle [heure, heure+1[
// '-g nomfichier.dot' : Permet de produire un fichier au format GraphViz du graphe analysé.
// '-e' : Permet d'exclure tous les documents qui ont une extension jpg, png, css ou js.
// Quand il n'y a aucune option, seul un affichage du top 10 sans filtre des documents les plus consultés
// est affiché.
// Les différentes réponses possibles sont donc le remplissage d'un fichier .dot à partir du fichier de logs analysé,
// l'affichage d'un top 10 des url des documents les plus consultés, le mélange des deux ou un message d'erreur.
// Ces réponses, en fonction des options, sont renvoyées de manière filtrées ou non.
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
    // Mode d'emploi :
    // La méthode Choisir permet de déterminer quelles
    // options l'utilisateur a rentré et si elles sont valides, construit la
    // réponse adéquate. Les différentes options à déterminer sont : '-e',
    // '-g nomfichier.dot' et '-t heure'. L'ordre n'est pas pris en compte mais
    // en cas d'options différentes ou de nombre trop élevé ou trop faible, un
    // message d'erreur est retourné.
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Commande & operator = ( const Commande & unCommande );
    // Mode d'emploi :
    // La surchage d'operator = est juste déclaré.
    //
    // Contrat :
    //




//-------------------------------------------- Constructeurs - destructeur
    Commande ( const Commande & unCommande );
    // Mode d'emploi (constructeur de copie) : Le constructeur de copie
    // est juste déclaré.
    //
    // Contrat :
    //


    Commande (int nbArg, char ** arg);
    // Mode d'emploi : Ce constructeur construit un objet
    // de la classe commande. Il initialise l'attribut nombreArg grâce
    // au paramètre nbArg qui est un entier représentant le nombre de paramètres passés en
    // ligne de commande. Il initialise aussi l'attribut option en réalisant une copie en surface
    // du paramètre <arg> qui représente un tableau de pointeurs de caractère comportant
    // les valeurs des différents paramètres.
    //
    // Contrat :
    //

    virtual ~Commande ( );
    // Mode d'emploi : Ce destructeur libére la totalité des ressources (mémoire)
    // occupées par notre objet Commande.
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

    bool OptExclure();
    // Mode d'emploi :
    // Cette méthode permet de déterminer si l'option '-e'
    // a été rentrée en ligne de commande.
    // Renvoie un booléen : true si l'option a été rentrée, false sinon.
    //
    // Contrat :
    //

    int OptTracerGraphe();
    // Mode d'emploi :
    // Cette méthode permet de déterminer si l'option '-g nomFichier.dot'
    // a été rentrée en ligne de commande.
    // Renvoie un entier correspondant à l'indice dans le tableau d'options
    // où l'élément '-g' a été détecté.
    // S'il n'est pas détecté, renvoie 0.
    //
    // Contrat :
    //
    int OptHeure();
    // Mode d'emploi :
    // Cette méthode permet de déterminer si l'option '-t heure'
    // a été rentrée en ligne de commande.
    // Renvoie un entier correspondant à l'indice dans le tableau d'options
    // où l'élément '-t' a été détecté.
    // S'il n'est pas détecté, renvoie 0.
    //
    // Contrat :
    //


    int VerifierHeure(int horaire);
    // Mode d'emploi :
    // Cette méthode vérifie si l'heure passée en option
    // après '-t' est valide. Une heure valide est comprise
    // entre 0 et 23.
    // Le paramètre <horaire> est un entier qui correspond à l'heure spécifiée par
    // l'utilisateur en ligne de commande.
    // Retourne un entier correspondant à l'heure si elle est valide,
    // sinon retourne -1.
    //
    // Contrat :
    //

    bool VerifierExtensionDot(string nomFichierDot);
    // Mode d'emploi :
    // Cette méthode vérifie si le fichier passé en option
    // après '-g' est valide. Un fichier est valide si son extension
    // est '.dot'.
    // Le paramètre <nomFichierDot> est une chaîne de caractère qui
    // correspond au nom du fichier spécifié par l'utilisateur en
    // ligne de commande.
    // Retourne un booléen : true si le fichier est valide, false sinon.
    //
    // Contrat :
    //

    bool VerifierExtensionLog(string nomFichierLog);
    // Mode d'emploi :
    // Cette méthode vérifie si le fichier contenant les logs apache passé en dernier paramètre dans
    // la ligne de commande est valide. Un fichier est valide si son extension
    // est '.log'.
    // Le paramètre <nomFichierLog> est une chaîne de caractère qui
    // correspond au nom du fichier spécifié par l'utilisateur en
    // ligne de commande.
    // Retourne un booléen : true si le fichier est valide, false sinon.
    //
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés
	char** option;
	int nombreArg;
};

//-------------------------------- Autres définitions dépendantes de <Commande>

#endif // Commande_H

