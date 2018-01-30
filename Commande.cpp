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
#include "Graphe.h"

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
            S.RemplirMapSansCond(option[nombreArg-1]);
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
                stockExclus.RemplirMapExclus(option[nombreArg-1]);
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
						// Faire methode pour exclus, heure et les 2 comme pour stockage ...
                        //Tracer graphe mais en stockant d'abord grace a stockage puis en faisant appel a remplir graphe
                        Stockage S;
                        S.RemplirMapSansCond(option[nombreArg-1]);
                        S.AfficherTop();
                        Graphe G;
                        G.RemplirGrapheSansCond(option[nombreArg-1]);
                        G.CreerFichier(nomFichierDot);
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
                        stockHeure.RemplirMapHeure(valideHeure,option[nombreArg-1]);
                        stockHeure.AfficherTop();
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
                        // Tracer graphe avec les fichiers exclus
                        string nomFichierDot = option[tracerGraphe+1];
                        bool valideExt = VerifierExtensionDot(nomFichierDot);
                        if (valideExt)
                        {
                            Stockage S;
                            S.RemplirMapExclus(option[nombreArg-1]);
                            S.AfficherTop();
                            Graphe G;
                            G.RemplirGrapheExclus(option[nombreArg-1]);
                            G.CreerFichier(nomFichierDot);
                        }
                        else
                        {
                            cerr << "Le fichier indiqué ne contient pas la bonne extension (dot)";
                        }

                    }
                    else if (exclure && optionHeure)
                    {
                        int valideHeure = VerifierHeure(optionHeure);
                        if (valideHeure != -1)
                        {
                            // Afficher top 10 pour l'heure.
                            Stockage stockHeureExclus;
                            stockHeureExclus.RemplirMapExclusHeure(valideHeure, option[nombreArg-1]);
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
                bool valideEx = VerifierExtensionDot(nomFichierDot);
                if (valideEx && valideH)
                {
                    //Tracer graphe en fonction de l'heure choisie
                    Stockage S;
                    S.RemplirMapHeure(valideH, option[nombreArg-1]);
                    Graphe G;
                    G.RemplirGrapheExclusHeure(valideH, option[nombreArg-1]);
                    G.CreerFichier(nomFichierDot);
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
                    Stockage S;
                    S.RemplirMapExclusHeure(valideHeu,option[nombreArg-1]);
                    S.AfficherTop();
                    Graphe G;
                    G.RemplirGrapheExclusHeure(valideHeu,option[nombreArg-1]);
                    G.CreerFichier(nomFichierDot);
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
	/*option = new char*[nbArg];
	int i;
	for (i=0; i<nbArg; i++)
    {
        strcpy(option[i],arg[i]);
    }*/
    option = arg;
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
	cout << option[horaire] << endl;
	cout << option[horaire+1] << endl;
    int heureAverif = stoi(option[horaire+1]);
    cout << "heure : " << heureAverif << endl;
    if (0<= heureAverif && heureAverif<24)
    {
        return heureAverif;
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

