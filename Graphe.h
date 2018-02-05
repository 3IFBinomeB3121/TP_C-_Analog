/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : 10/01/2018
    copyright            : (C) 2018 par Christophe ETIENNE & William Occeli
    e-mail               : christophe.etienne@insa-lyon.fr
                           william.occeli@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Graphe> (fichier Graphe.h) ----------------
#if ! defined ( Graphe_H )
#define Graphe_H

//--------------------------------------------------- Interfaces utilisées

#include <string>
#include <map>
#include <fstream>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Graphe>
// La classe Graphe permet de produire un fichier au format Graphviz du fichier
// de lof Apache analysé. Chaque document apparait sous la forme d'un noeud
// et chaque arc du graphe indique le nombre de parcours associés.
// Elle possède deux attributs qui s'appuie chacun sur la structure de
// données table de hachage.
//
//------------------------------------------------------------------------

class Graphe
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void RemplirGrapheSansCond(string nomFichier = "");
    // Mode d'emploi : Cette méthode permet de remplir les attributs
    // noeud et arc à partir d'un fichier de log Apache passé en paramètre.
    // Le remplissage des informations se fait sans condition. Les informations
    // stockées sont:
    // - Pour noeud, l'url du document consulté comme clé associé avec un id unique en valeur.
    // - Pour arc, l'url du document sur lequel on se trouvait quand on a effectué la requête
    // et en valeur l'url du document qu'on consulte et le nombre de fois ou on le consulte en
    // empruntant le même parcours.
    // Le paramètre <nomFichier> est une string correspondant au
    // nom du fichier log Apache pour lequel on souhaite récupérer les informations.
    // Si aucun nom de fichier n'est précisé, affiche un message d'erreur.
    //
    // Contrat :
    //

    void RemplirGrapheHeure(int heureChoisie, string nomFichier = "");
    // Mode d'emploi : Cette méthode permet de remplir les attributs
    // noeud et arc à partir d'un fichier de log Apache passé en paramètre.
    // Le remplissage des informations est filtré en fonction de l'heure
    // où on a effectué la requête. Cette heure est spécifié par l'utilisateur
    // en option dans la ligne de commande.
    // Les informations stockées sont:
    // - Pour noeud, l'url du document consulté comme clé associé avec un id unique en valeur.
    // - Pour arc, l'url du document sur lequel on se trouvait quand on a effectué la requête
    // et en valeur l'url du document qu'on consulte et le nombre de fois ou on le consulte en
    // empruntant le même parcours.
    // Le paramètre <nomFichier> est une string correspondant au
    // nom du fichier log Apache pour lequel on souhaite récupérer les informations.
    // Si aucun nom de fichier n'est précisé, affiche un message d'erreur.
    //
    // Contrat :
    //

    void RemplirGrapheExclus(string nomFichier = "");
    // Mode d'emploi : Cette méthode permet de remplir les attributs
    // noeud et arc à partir d'un fichier de log Apache passé en paramètre.
    // Le remplissage des informations est filtré en fonction de l'extension du document
    // consulté. Les informations ne sont pas retenues si l'extension est '.jpg', '.png',
    // '.css' ou '.js'.
    // Les informations stockées sont:
    // - Pour noeud, l'url du document consulté comme clé associé avec un id unique en valeur.
    // - Pour arc, l'url du document sur lequel on se trouvait quand on a effectué la requête
    // et en valeur l'url du document qu'on consulte et le nombre de fois ou on le consulte en
    // empruntant le même parcours.
    // Le paramètre <nomFichier> est une string correspondant au
    // nom du fichier log Apache pour lequel on souhaite récupérer les informations.
    // Si aucun nom de fichier n'est précisé, affiche un message d'erreur.
    //
    // Contrat :
    //

    void RemplirGrapheExclusHeure(int heureChoisie, string nomFichier = "");
    // Mode d'emploi : Cette méthode permet de remplir les attributs
    // noeud et arc à partir d'un fichier de log Apache passé en paramètre.
    // Le remplissage des informations est filtré en fonction de l'extension du document
    // consulté et de l'heure à laquelle la requête est effectuée.
    // Les informations ne sont pas retenues si l'extension est '.jpg', '.png',
    // '.css' ou '.js' et si l'heure est différente de celle spécifié par l'utilisateur
    // en option dans la ligne de commande.
    // Les informations stockées sont:
    // - Pour noeud, l'url du document consulté comme clé associé avec un id unique en valeur.
    // - Pour arc, l'url du document sur lequel on se trouvait quand on a effectué la requête
    // et en valeur l'url du document qu'on consulte et le nombre de fois ou on le consulte en
    // empruntant le même parcours.
    // Le paramètre <nomFichier> est une string correspondant au
    // nom du fichier log Apache pour lequel on souhaite récupérer les informations.
    // Si aucun nom de fichier n'est précisé, affiche un message d'erreur.
    //
    // Contrat :
    //

    void CreerFichier (string nomFichierDot = "");
    // Mode d'emploi : Cette méthode crée un fichier au format GraphViz
    // avec pour nom celui passé en paramètre. Si le nom du fichier
    // existe déja, elle écrase les données de celui-ci et les remplace
    // par les nouvelles.
    // Le paramètre <nomFichierDot> est le nom du fichier avec l'extension .dot
    // que l'utilisateur a spécifié en option dans la ligne de commande.
    // Si aucun fichier n'est spécifié, un message d'erreur s'affiche.
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Graphe & operator = ( const Graphe & unGraphe );
    // Mode d'emploi : La surchage d'operator = est juste déclaré.
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Graphe ( const Graphe & unGraphe );
    // Mode d'emploi (constructeur de copie) : Le constructeur par défaut
    // de Graphe est juste déclaré.
    //
    // Contrat :
    //

    Graphe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Graphe ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

	multimap<string,pair<string,int>> arc;
	map<string,int> noeud;

};

//-------------------------------- Autres définitions dépendantes de <Graphe>

#endif // Graphe_H

