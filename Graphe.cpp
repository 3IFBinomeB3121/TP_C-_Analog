/*************************************************************************
                           Graphe  -  description
                             -------------------
    début                : 10/01/2018
    copyright            : (C) 2018 par Christophe ETIENNE & William Occelli
    e-mail               : christophe.etienne@insa-lyon.fr
                           william.occelli@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Graphe> (fichier Graphe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Graphe.h"
#include "Log.h"
#include "Logfile.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Graphe::RemplirGrapheSansCond(string nomFichier)
{
	Logfile lf(nomFichier);
	if (lf.is_open())
	{
		int compteur = 0;
		pair<map<string,int>::iterator,bool> elmt;
		while (!lf.eof())
		{
			Log newLog = lf.LireLog();
			string source = newLog.GetSource();
			string cible = newLog.GetCible();
			elmt = noeud.insert(make_pair(source,compteur));
			if (elmt.second)
			{
				compteur++;  // S'il a bien été ajouté on incrémente le compteur
			}
			elmt = noeud.insert(make_pair(cible,compteur));
			if (elmt.second)
			{
				compteur++;
			}
			if (arc.find(source) != arc.end())
			{
				multimap<string,pair<string,int>>::iterator mmitLow;
				multimap<string,pair<string,int>>::iterator mmitUp = arc.upper_bound(source);
				bool present = false;
				for (mmitLow = arc.lower_bound(source); mmitLow != mmitUp; mmitLow++)
				{
					if (mmitLow->second.first == cible)
					{
						present = true;
					}
				}
				if (!present)
				{
					pair <string, int> p = make_pair (cible, 1);
					arc.insert( pair<string,pair<string,int>> ( source , p ));
				}
				else
				{
					arc.find(source)->second.second++;
				}
			}
			else
			{
				pair <string, int> p = make_pair (cible, 1);
				arc.insert( pair<string,pair<string,int>> ( source , p ));
			}
		}
	}
	else
	{
		cerr << "erreur lors de l'ouverture du fichier" << endl;
	}
} // Fin de RemplirGrapheSansCond

void Graphe::RemplirGrapheHeure(int heureChoisie, string nomFichier)
{
    Logfile lf(nomFichier);
	if (lf.is_open() && heureChoisie != -1)
	{
		int compteur = 0;
		pair<map<string,int>::iterator,bool> elmt;
		while (!lf.eof())
		{
			Log newLog = lf.LireLog();
			string source = newLog.GetSource();
			string cible = newLog.GetCible();
			int heureAverif = newLog.GetHeure();
			if (heureAverif == heureChoisie)
            {
                elmt = noeud.insert(make_pair(source,compteur));
                if (elmt.second)
                {
                    compteur++;
                }
                elmt = noeud.insert(make_pair(cible,compteur));
                if (elmt.second)
                {
                    compteur++;
                }
                if (arc.find(source) != arc.end())
                {
                    multimap<string,pair<string,int>>::iterator mmitLow;
                    multimap<string,pair<string,int>>::iterator mmitUp = arc.upper_bound(source);
                    bool present = false;
                    for (mmitLow = arc.lower_bound(source); mmitLow != mmitUp; mmitLow++)
                    {
                        if (mmitLow->second.first == cible)
                        {
                            present = true;
                        }
                    }
                    if (!present)
                    {
                        pair <string, int> p = make_pair (cible, 1);
                        arc.insert( pair<string,pair<string,int>> ( source , p ));
                    }
                    else
                    {
                        arc.find(source)->second.second++;
                    }
                }
                else
                {
                    pair <string, int> p = make_pair (cible, 1);
                    arc.insert( pair<string,pair<string,int>> ( source , p ));
                }
            }
		}
	}
	else
	{
		cerr << "erreur lors de l'ouverture du fichier ou dans l'heure rentrée en option" << endl;
	}
} // Fin de RemplirGrapheHeure

void Graphe::RemplirGrapheExclus(string nomFichier)
{
    Logfile lf(nomFichier);
	if (lf.is_open())
	{
		int compteur = 0;
		pair<map<string,int>::iterator,bool> elmt;
		while (!lf.eof())
		{
			Log newLog = lf.LireLog();
			string source = newLog.GetSource();
			string cible = newLog.GetCible();
			string extension = newLog.GetExtension();
			if (extension != "png" && extension != "css" && extension != "js" && extension != "jpg")
            {
                elmt = noeud.insert(make_pair(source,compteur));
                if (elmt.second)
                {
                    compteur++;
                }
                elmt = noeud.insert(make_pair(cible,compteur));
                if (elmt.second)
                {
                    compteur++;
                }
                if (arc.find(source) != arc.end())
                {
                    multimap<string,pair<string,int>>::iterator mmitLow;
                    multimap<string,pair<string,int>>::iterator mmitUp = arc.upper_bound(source);
                    bool present = false;
                    for (mmitLow = arc.lower_bound(source); mmitLow != mmitUp; mmitLow++)
                    {
                        if (mmitLow->second.first == cible)
                        {
                            present = true;
                        }
                    }
                    if (!present)
                    {
                        pair <string, int> p = make_pair (cible, 1);
                        arc.insert( pair<string,pair<string,int>> ( source , p ));
                    }
                    else
                    {
                        arc.find(source)->second.second++;
                    }
                }
                else
                {
                    pair <string, int> p = make_pair (cible, 1);
                    arc.insert( pair<string,pair<string,int>> ( source , p ));
                }
            }
		}
	}
	else
	{
		cerr << "erreur lors de l'ouverture du fichier" << endl;
	}
} // Fin de RemplirGrapheExclus

void Graphe::RemplirGrapheExclusHeure(int heureChoisie, string nomFichier)
{
    Logfile lf(nomFichier);
	if (lf.is_open() && heureChoisie != -1)
	{
		int compteur = 0;
		pair<map<string,int>::iterator,bool> elmt;
		while (!lf.eof())
		{
			Log newLog = lf.LireLog();
			string source = newLog.GetSource();
			string cible = newLog.GetCible();
			string extension = newLog.GetExtension();
			int heureAverif = newLog.GetHeure();
			if (heureAverif == heureChoisie && extension != "png" && extension != "css" && extension != "js" && extension != "jpg")
            {
                elmt = noeud.insert(make_pair(source,compteur));
                if (elmt.second)
                {
                    compteur++;
                }
                elmt = noeud.insert(make_pair(cible,compteur));
                if (elmt.second)
                {
                    compteur++;
                }
                if (arc.find(source) != arc.end())
                {
                    multimap<string,pair<string,int>>::iterator mmitLow;
                    multimap<string,pair<string,int>>::iterator mmitUp = arc.upper_bound(source);
                    bool present = false;
                    for (mmitLow = arc.lower_bound(source); mmitLow != mmitUp; mmitLow++)
                    {
                        if (mmitLow->second.first == cible)
                        {
                            present = true;
                        }
                    }
                    if (!present)
                    {
                        pair <string, int> p = make_pair (cible, 1);
                        arc.insert( pair<string,pair<string,int>> ( source , p ));
                    }
                    else
                    {
                        arc.find(source)->second.second++;
                    }
                }
                else
                {
                    pair <string, int> p = make_pair (cible, 1);
                    arc.insert( pair<string,pair<string,int>> ( source , p ));
                }
            }
		}
	}
	else
	{
		cerr << "erreur lors de l'ouverture du fichier ou dans l'heure passé en option" << endl;
	}
} // Fin de RemplirGrapheExclusHeure

void Graphe::CreerFichier (string nomFichierDot)
{
	if (nomFichierDot != "")
	{
		ofstream fichier;
		fichier.open((char*)nomFichierDot.c_str(), ios::out);

		if (fichier.is_open())
		{
			fichier << "digraph {\r\n";
			map<string,int>::const_iterator citNoeud;
			for (citNoeud = noeud.begin(); citNoeud != noeud.cend(); citNoeud++)
			{
				fichier << "\tnode" << citNoeud->second << "[label=\"" << citNoeud->first << "\"];\r\n";
			}

			multimap<string,pair<string,int>>::const_iterator citArc;
			for (citArc = arc.cbegin(); citArc != arc.cend(); citArc++)
			{
				map<string,int>::const_iterator citSource = noeud.find(citArc->first);
				map<string,int>::const_iterator citCible = noeud.find(citArc->second.first);
				fichier << "\tnode" << citSource->second << " -> node" << citCible->second << " [label=\"" << citArc->second.second << "\"];\r\n";
			}
			fichier << "}";
		}
		else
		{
			cerr << "Problème dans l'ouverture du fichier" << endl;
		}
		fichier.close();
		if (existe)
        {
            cout << "Les données du fichier " << nomFichierDot << " ont été écrasés." << endl;
		}
		else
        {
            cout << "fichier " << nomFichierDot << " créé" << endl;
        }
	}
	else
	{
		cerr << "Fichier non précisé" << endl;
	}
} // Fin de CreerFichier

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Graphe::Graphe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Graphe>" << endl;
#endif


} //----- Fin de Graphe


Graphe::~Graphe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Graphe>" << endl;
#endif
} //----- Fin de ~Graphe

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

