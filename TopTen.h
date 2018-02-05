/*************************************************************************
                           TopTen  -  description
                             -------------------
                             -------------------
    d�but                : 10/01/2018
    copyright            : (C) 2018 par Christophe ETIENNE & William Occeli
    e-mail               : christophe.etienne@insa-lyon.fr
                           william.occeli@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TopTen> (fichier TopTen.h) ----------------
#if ! defined ( TopTen_H )
#define TopTen_H

//--------------------------------------------------- Interfaces utilis�es

#include <string>
#include <map>
#include <unordered_map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <TopTen>
// Cette classe permet de construire un Top 10 des urls de document les
// plus consult�es dans un fichier de log Apache.
// TopTen est une structure de donn�es de type arbre binaire de recherche.
//
//------------------------------------------------------------------------

class TopTen
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

//------------------------------------------------- Surcharge d'op�rateurs
    TopTen & operator = ( const TopTen & unTopTen );
    // Mode d'emploi : La surchage d'operator = est juste d�clar�.
    //
    // Contrat :
    //

    friend ostream & operator << ( ostream & flux, const TopTen & unTopTen);
    // Mode d'emploi : Surcharge de la fonction non membre operator <<
    // d�clar�e amie de la classe TopTen.
    // L'affichage pour un objet de la classe TopTen est format� de la mani�re suivante:
    // Affichage sous forme de classement ordonn� croissant (1 � 10) des dix urls de document
    // les plus consult�es avec leur nombre de hits. Une url par ligne avec
    // son num�ro dans le classement devant.
    // Le premier param�tre est une r�f�rence sur un objet de type ostream.
    // Le second param�tre est une r�f�rence constante sur un objet de type TopTen qui est l'objet
    // dont on souhaite afficher le Top 10.
    // Retourne une r�f�rence sur un objet de type ofstream qui est le flux manipul�.
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    TopTen ( const TopTen & unTopTen );
    // Mode d'emploi (constructeur de copie) : Le constructeur de copie
    // de TopTen est juste d�clar�.
    //
    // Contrat :
    //

    TopTen ( const unordered_map<string,int> unM );
    // Mode d'emploi : Construit un objet de type TopTen en initialisant
    // l'attribut mmTop gr�ce au param�tre unM. Les cl�s de mmTop sont des entiers
    // repr�sentant le nombre de hits de l'url du document consult�e associ�e (en valeur).
    // Le param�tre unM est une unordered_map constante avec pour cl� un string repr�sentant l'url du
    // document consult�e et en valeur le nombre de hits.
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
//----------------------------------------------------- M�thodes prot�g�es

//----------------------------------------------------- Attributs prot�g�s

    multimap<int,string> mmTop;

};

//-------------------------------- Autres d�finitions d�pendantes de <TopTen>

#endif // TopTen_H

