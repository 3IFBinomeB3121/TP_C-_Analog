/*************************************************************************
                           Stockage  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
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
// type Stockage::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

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
}

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
}

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
}

void Stockage::RemplirMapSansCond(string nomFichier)
{
    Logfile lf(nomFichier);
    if (lf.is_open() && heure != -1)
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

}

void Stockage::AfficherTop()
{
    TopTen ttexclu(stockLog);
    cout << ttexclu; // Surcharger operator <<*/
}

//------------------------------------------------- Surcharge d'opérateurs
Stockage & Stockage::operator = ( const Stockage & unStockage )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Stockage::Stockage ( const Stockage & unStockage )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Stockage>" << endl;
#endif
} //----- Fin de Stockage (constructeur de copie)


Stockage::Stockage ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Stockage>" << endl;
#endif

   // stockLog = new unordered_map<string, int>;

} //----- Fin de Stockage


Stockage::~Stockage ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Stockage>" << endl;
#endif
//	delete stockLog;
} //----- Fin de ~Stockage


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

