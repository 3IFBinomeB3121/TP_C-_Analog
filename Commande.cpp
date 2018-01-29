/*************************************************************************
                           Commande  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Commande> (fichier Commande.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Commande.h"
#include "Stockage.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Commande::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Commande::Choisir()
{
    // 3 methodes qui retourne un booleen et en fonction du nombre d'argument verifie si l'option est bonne ou non
    // Si arg > 1 appelle des méthodes et si tous les booleens sont faux alors retourne une erreur "option" inconnue
    // Sinon si arg = 1 afficher top 10
    bool fichierLogValide = VerifierExtensionLog(option[nombreArg-1]);
    if (fichierLogValide)
    {
        int tracerGraphe;
        bool exclure;
        int optionHeure;
        if (nombreArg > 2)
        {
            if (nombreArg <= 7)
            {
                tracerGraphe = OptTracerGraphe();
                exclure = OptExclure();
                optionHeure = OptHeure();
            }
            else
            {
                cerr << "Trop d'options rentrées" << endl;
            }

        }
        else if (nombreArg == 2)
        {
            // Création TopTen : veut dire qu'il n'y a pas eu d'option
            Stockage S;
            S.RemplirMap(-1,"anonyme.log");
			S.AfficherTop();
        }
        else
        {
            cerr << "Problème : aucune option détectée";
        }

        switch (nombreArg)
        {
            case 3:
            {
                Stockage stockExclus;
                stockExclus.RemplirMapExclus("anonyme.log");
                stockExclus.AfficherTop();
                // Ne peut être que exclure
                break;
            }

            case 4:
            {
                if (tracerGraphe)
                {
                    string nomFichierDot = option[tracerGraphe+1];
                    bool valideExt = VerifierExtensionDot(nomFichierDot);
                    if (valideExt)
                    {
                        //Tracer graphe
                    }
                    else
                    {
                        cout << "extension du fichier n'est pas valide (ce n'est pas un fichier dot)" << endl;
                    }

                }
                else if (optionHeure)
                {
                    int valideHeure = VerifierHeure(optionHeure);
                    if (valideHeure != -1)
                    {
                        // Afficher top 10 pour l'heure.
                        Stockage stockHeure;
                        stockHeure.RemplirMap(valideHeure);
                    }
                    else
                    {
                        cerr << "heure non valide" << endl;
                    }
                }
                else
                {
                    cerr << "aucune option connue" << endl;
                }
                break;
            }


            case 5:
                {
                    // Ne peut être que exclure et soit heure soit graphe sinon options inconnues
                    if (exclure && tracerGraphe)
                    {

                    }
                    else if (exclure && optionHeure)
                    {
                        int valideHeure = VerifierHeure(optionHeure);
                        if (valideHeure != -1)
                        {
                            // Afficher top 10 pour l'heure.
                            Stockage stockHeureExclus;
                            stockHeureExclus.RemplirMap(valideHeure);
                            stockHeureExclus.AfficherTop();
                        }
                        else
                        {
                            cerr << "heure non valide" << endl;
                        }
                    }
                    else
                    {
                        cerr << "option inconnue";
                    }
                    break;
                }

            case 6:
            {
                int valideH = VerifierHeure(optionHeure);
                string nomFichierDot = option[tracerGraphe+1];
                bool valideExtension = VerifierExtensionDot(nomFichierDot);
                if (valideExtension && valideH)
                {
                    //Tracer graphe en fonction de l'heure choisie
                }
                else
                {
                    cout << "erreur dans l'extension du fichier Dot ou l'heure choisie" << endl;
                }

                // Forcement heure et graphe sinon options inconnues
                break;
            }

            case 7:
            {
                // obligatoirement les 3 ou erreurs options inconnues
                int valideHeu = VerifierHeure(optionHeure);
                string nomFichierDot = option[tracerGraphe+1];
                bool valideExtent = VerifierExtensionDot(nomFichierDot);
                if (valideExtent && valideHeu)
                {
                    //Tracer graphe en fonction de l'heure choisie et avec exclus
                }
                else
                {
                    cout << "erreur dans l'extension du fichier Dot ou l'heure choisie" << endl;
                }
                break;
            }
        }
    }
    else
    {
        cerr << "Fichier passé en option n'est pas du type Log" << endl;
    }
}


//------------------------------------------------- Surcharge d'opérateurs
Commande & Commande::operator = ( const Commande & unCommande )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Commande::Commande ( const Commande & unCommande )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Commande>" << endl;
#endif
} //----- Fin de Commande (constructeur de copie)


Commande::Commande (int nbArg, char ** arg)
: nombreArg(nbArg)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Commande>" << endl;
#endif
	cout << "Trace 1" << endl;
	option = new char*[nbArg];
	/*int i;
	for (i=0; i<nbArg; i++)
    {
        strcpy(option[i],arg[i]);
    }*/
    option = arg;
    cout << "trace 2" << endl;
} //----- Fin de Commande


Commande::~Commande ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Commande>" << endl;
#endif
	//delete [] option;
} //----- Fin de ~Commande


//------------------------------------------------------------------ PRIVE
bool Commande::VerifierExtensionLog(string nomFichierLog)
{
    stringstream ss(nomFichierLog);
    string nom;
    string extension;
    getline(ss,nom,'.');
    getline(ss,extension);
    if (extension == "log")
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Commande::OptExclure()
{
    int i;
    for (i=1; i < nombreArg; i+=2)
    {
        if (option[i][1] == 'e')
        {
            return true;
        }
    }
    return false;
    /*if (nombreArg==2 && option[1][1] == 'e')
    {
        return true;
    }
    // Pas de cas nombreArg=3 ou 5 car les deux autres options prennent deux arguments donc pas possible
    else if (nombreArg == 4 && (option[1][1] == 'e' || option[3][1] == 'e'))
    {
        return true;
    }
    else if (nombreArg==6 && (option[1][1] == 'e' || option[3][1] == 'e' || option[5][1] == 'e'))
    {
        return true;
    }
    else
    {
        return false;
    }*/
}

int Commande::VerifierHeure(int horaire) // Retourne l'heure si elle est valide sinon -1
{
    int premChiffre = (int) option[horaire+1][0];
    int deuxChiffre = (int) option[horaire+1][1];
    int calculHeure = premChiffre*10 + deuxChiffre;
    if (0<= calculHeure && calculHeure<24)
    {
        return calculHeure;
    }
    else
    {
        return -1;
    }
}

bool Commande::VerifierExtensionDot(string nomFichierDot)
{
    stringstream ss(nomFichierDot);
    string nom;
    string extension;
    // faire attention si fichier relatif
    getline(ss,nom,'.');
    getline(ss,extension);
    if (extension == "dot")
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Commande::OptTracerGraphe()
// Retourne l'indice ou se trouve l'option (pour pouvoir recuperer le nom du fichier dans choisir)
// Sinon retourne 0 si pas d'option
{
    int i;
    for (i=1; i<nombreArg-1; i++)
    {
        if (option[i][1] == 'g')
        {
            return i;
        }
    }
    return 0;
}

int Commande::OptHeure()
// Retourne l'indice ou se trouve l'option (pour pouvoir recuperer l'heure dans Choisir)
// Sinon retourne 0 si pas d'option
{
    int i;
    for (i=1; i<nombreArg-1; i++)
    {
        if (option[i][1] == 't')
        {
            return i;
        }
    }
    return 0;
}

//----------------------------------------------------- Méthodes protégées

