/*************************************************************************
                           Logfile  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
// type Logfile::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

Log Logfile::LireLog()
{
	string ligne;
	getline(fichier,ligne);
	Log unLog(ligne);
	return unLog;
}

bool Logfile::eof()
{
	return fichier.eof();
}

 bool Logfile::is_open()
 {
     return fichier.is_open();
 }




//------------------------------------------------- Surcharge d'opérateurs
//Logfile & Logfile::operator = ( const Logfile & unLogfile )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Logfile::Logfile ( const Logfile & unLogfile )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Logfile>" << endl;
#endif
} //----- Fin de Logfile (constructeur de copie)


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

