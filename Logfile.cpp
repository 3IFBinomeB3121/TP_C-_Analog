/*************************************************************************
                           Logfile  -  description
                             -------------------
    début                : 10/01/2018
    copyright            : (C) 2018 par Christophe ETIENNE & William Occelli
    e-mail               : christophe.etienne@insa-lyon.fr
                           william.occelli@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Logfile> (fichier Logfile.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Logfile.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

Log Logfile::LireLog()
{
	string ligne;
	getline(fichier,ligne);
	Log unLog(ligne);
	return unLog;
} //----- Fin de LireLog

bool Logfile::eof()
{
	return fichier.eof();
} //----- Fin de eof

 bool Logfile::is_open()
 {
     return fichier.is_open();
 } //----- Fin de is_open

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Logfile::Logfile (string nomFichier)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Logfile>" << endl;
#endif
	if (nomFichier != "")
	{
		fichier.open((char*)nomFichier.c_str(), ios::in);
	}
	else
	{
		cerr << "Fichier non précisé" << endl;
	}
} //----- Fin de Logfile


Logfile::~Logfile ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Logfile>" << endl;
#endif
	if (fichier.is_open())
	{
		fichier.close();
	}
} //----- Fin de ~Logfile

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
