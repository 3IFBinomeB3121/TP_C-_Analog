/*************************************************************************
                           Stockage  -  description
                             -------------------
    début                : 10/01/2018
    copyright            : (C) 2018 par Christophe ETIENNE & William Occeli
    e-mail               : christophe.etienne@insa-lyon.fr
                           william.occeli@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Stockage> (fichier Stockage.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Stockage.h"
#include "TopTen.h"
#include "Logfile.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Stockage::RemplirMapExclus(string nomFichier)
{
    Logfile lf(nomFichier);
    if (lf.is_open())
    {
        while (!lf.eof())
        {
            Log newLog = lf.LireLog();
            string extension = newLog.GetExtension();
            string cible = newLog.GetCible();
            if (extension != "png" && extension != "css" && extension != "js" && extension != "jpg")
            {
                if (stockLog.find(cible) == stockLog.end())
                {
                    stockLog.insert(pair<string,int>(cible,1));
                }
                else
                {
                    stockLog.find(cible)->second++;
                }
            }
        }
    }
    else
    {
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    }
} //----- Fin de RemplirMapExclus

void Stockage::RemplirMapExclusHeure(int heureChoisie, string nomFichier)
{
    Logfile lf(nomFichier);
    if (lf.is_open() && heureChoisie!=-1 )
    {
        while (!lf.eof())
        {
            Log newLog = lf.LireLog();
            string extension = newLog.GetExtension();
            string cible = newLog.GetCible();
            int heureLog = newLog.GetHeure();
            if (heureLog == heureChoisie && extension != "png" && extension != "css" && extension != "js" && extension != "jpg")
            {
                if (stockLog.find(cible) == stockLog.end())
                {
                    stockLog.insert(pair<string,int>(cible,1));
                }
                else
                {
                    stockLog.find(cible)->second++;
                }
            }
        }
    }
    else
    {
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    }
} //----- Fin de RemplirMapExclusHeure

void Stockage::RemplirMapHeure(int heureChoisie, string nomFichier)
{
    Logfile lf(nomFichier);
    if (lf.is_open())
    {
        while (!lf.eof())
        {
            Log newLog = lf.LireLog();
            string cible = newLog.GetCible();
            int heureLog = newLog.GetHeure();
            if (heureChoisie == heureLog)
            {
                if (stockLog.find(cible) == stockLog.end())
                {
                    stockLog.insert(pair<string,int>(cible,1));
                }
                else
                {
                    stockLog.find(cible)->second++;
                }
            }
        }
    }
    else
    {
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    }
} //----- Fin de RemplirMapHeure

void Stockage::RemplirMapSansCond(string nomFichier)
{
    Logfile lf(nomFichier);
    if (lf.is_open())
    {
        while (!lf.eof())
        {
            Log newLog = lf.LireLog();
            string cible = newLog.GetCible();
            if (stockLog.find(cible) == stockLog.end())
            {
                stockLog.insert(pair<string,int>(cible,1));
            }
            else
            {
                stockLog.find(cible)->second++;
            }
        }
    }
    else
    {
        cerr << "Erreur lors de l'ouverture du fichier" << endl;
    }
} //----- Fin de RemplirMapSansCond

void Stockage::AfficherTop()
{
	if (stockLog.size() == 0)
	{
		cout << "Le fichier est vide et ne contient aucun log ou alors il n'existe pas" << endl;
	}
	else
	{
		TopTen ttexclu(stockLog);
		cout << ttexclu;
	}
} //----- Fin de AfficherTop

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Stockage::Stockage ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Stockage>" << endl;
#endif
} //----- Fin de Stockage

Stockage::~Stockage ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Stockage>" << endl;
#endif
} //----- Fin de ~Stockage

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

