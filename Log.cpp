/*************************************************************************
                           Log  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Log> (fichier Log.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Log.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Log::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Log::GetExtension()
{
    stringstream ss(cible);
    string debut;
    string extension;
    getline(ss,debut,'.');
    getline(ss,extension);
    return extension;
}

string Log::GetCible()
{
    return cible;
}

string Log::GetSource()
{
    return source;
}

int Log::GetHeure()
{
    return heure;
}
//------------------------------------------------- Surcharge d'opérateurs





//-------------------------------------------- Constructeurs - destructeur



Log::Log (string ligneFichier)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Log>" << endl;
#endif
	stringstream ss(ligneFichier);
	getline(ss,adresseIP,' ');
	getline(ss,nom_visiteur,' ');
	getline(ss,pseudo,' ');
	ss.get();
	getline(ss,date,':');
	ss>>heure;
	ss.get();
	ss.get();ss.get();ss.get();ss.get();ss.get();ss.get(); // On saute tous les caractères jusqu'a avant '+'
	char signe = ' ';
	ss.get(signe);
	int fuseau;
	ss>>fuseau;
	fuseau = fuseau/100;
	ss.get();ss.get();ss.get();
	getline(ss,methode,' ');
	getline(ss,cible,' ');
	getline(ss,protocole,'"');
	ss.get();
	ss>>status_code;
	ss.get();
	ss>>nbOctet;
	ss.get();ss.get();
	if (ss.peek() == '-')
	{
		referent = "referentInconnu";
		source = "unknown";
		ss.get();ss.get();
	}
	else 
	{
		string recupProtocole;
		getline(ss,recupProtocole,'/');
		ss.get(); // On saute le deuxième slash
		getline(ss,referent,'/');
		referent = recupProtocole + "//" + referent;
		getline(ss,source,'"');
		source = "/" + source;
	}
	ss.get();ss.get();
	getline(ss,id_client_navigateur,'"');

	if (signe=='-')
	{
		heure = heure + fuseau;
	}
	else
	{
		heure = heure - fuseau;
	}
} //----- Fin de Log


Log::~Log ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Log>" << endl;
#endif
} //----- Fin de ~Log


ostream & operator << (ostream & flux, const Log & unLog)
// Algorithme :
//
{
	flux << unLog.referent << endl;
	flux << unLog.adresseIP << endl;
	flux << unLog.nom_visiteur << endl;
	flux << unLog.pseudo << endl;
	flux << unLog.date << endl;
	flux << unLog.heure << endl;
	flux << unLog.methode << endl;
	flux << unLog.cible << endl;
	flux << unLog.protocole << endl;
	flux << unLog.status_code << endl;
	flux << unLog.nbOctet << endl;
	flux << unLog.source << endl;
	flux << unLog.id_client_navigateur << endl;
	return flux;

}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

