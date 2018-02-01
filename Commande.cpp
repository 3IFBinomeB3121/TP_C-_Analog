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
#include <sstream>

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
            cerr << "Problème : aucune option détectée" << endl;
        }

        switch (nombreArg)
        {
            case 3:
            {
				if (exclure)
				{
					Stockage stockExclus;
					stockExclus.RemplirMapExclus(option[nombreArg-1]);
					cout << "Affichage avec les fichiers '.css', '.jpg', '.png' et '.js' exclus" << endl;
					stockExclus.AfficherTop();
					// Ne peut être que exclure
					break;
				}
				else
				{
					cout << "option rentrée non valide" << endl;
				}
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
                        cout << "fichier " << nomFichierDot << " créé" << endl;
                        G.RemplirGrapheSansCond(option[nombreArg-1]);
                        G.CreerFichier(nomFichierDot);
                    }
                    else
                    {
                        cerr << "extension du fichier n'est pas valide (ce n'est pas un fichier dot)" << endl;
                    }

                }
                else if (optionHeure)
                {
                    int valideHeure = VerifierHeure(optionHeure);
                    if (valideHeure != -1)
                    {
                        Stockage stockHeure;
                        stockHeure.RemplirMapHeure(valideHeure,option[nombreArg-1]);
                        cout << "Affichage pour un intervalle compris entre " << valideHeure<< "h00 et " << valideHeure << "h59" << endl;
                        stockHeure.AfficherTop();
                    }
                    else
                    {
                        cerr << "heure non valide" << endl;
                    }
                }
                else
                {
                    cerr << "aucune option connue ou option rentrée plusieurs fois" << endl;
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
                            cout << "Affichage avec les fichiers '.css', '.jpg', '.png' et '.js' exclus" << endl;
                            S.AfficherTop();
                            Graphe G;
                            cout << "fichier " << nomFichierDot << " créé" << endl;
                            G.RemplirGrapheExclus(option[nombreArg-1]);
                            G.CreerFichier(nomFichierDot);
                        }
                        else
                        {
                            cerr << "Le fichier indiqué ne contient pas la bonne extension (dot)" << endl;
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
                            cout << "Affichage avec les fichiers '.png', '.css', '.js' et '.jpg' exclus pour un horaire compris entre " << valideHeure << "h00 et " << valideHeure << "h59" << endl;
                            stockHeureExclus.AfficherTop();
                        }
                        else
                        {
                            cerr << "heure non valide" << endl;
                        }
                    }
                    else
                    {
                        cerr << "option inconnue ou options rentrées plusieurs fois" << endl;
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
                    cout << "Affichage pour un intervalle compris entre " << valideH << "h00 et " << valideH << "h59" << endl;
                    S.AfficherTop();
                    Graphe G;
                    cout << "fichier " << nomFichierDot << " créé" << endl;
                    G.RemplirGrapheExclusHeure(valideH, option[nombreArg-1]);
                    G.CreerFichier(nomFichierDot);
                }
                else
                {
                    cerr << "Erreur dans l'extension du fichier Dot , l'heure choisie ou les options rentrees" << endl;
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
                    cout << "Affichage avec les fichiers '.png', '.css', '.js' et '.jpg' exclus pour un horaire compris entre " << valideHeu << "h00 et " << valideHeu << "h59" << endl;
                    S.AfficherTop();
                    Graphe G;
                    cout << "fichier " << nomFichierDot << " créé" << endl;
                    G.RemplirGrapheExclusHeure(valideHeu,option[nombreArg-1]);
                    G.CreerFichier(nomFichierDot);
                }
                else
                {
                    cerr << "erreur dans l'extension du fichier Dot, l'heure choisie ou les options rentrees" << endl;
                }
                break;
            }
        }
    }
    else
    {
        cerr << "Fichier log passé en option n'a pas la bonne extension" << endl;
    }
}


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur


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
    string extension;
    ss.seekg(0,ss.end); // Permet de recuperer l'extension au cas ou il y aurait un chemin relatif ou absolu
    long taille = ss.tellg();
    ss.seekg(0);
    char * buffer = new char[taille-3];
    ss.read(buffer,taille-3);
    getline(ss,extension);
    delete [] buffer;
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
        if (strlen(option[i]) == 2 && option[i][1] == 'e')
        {
            return true;
        }
    }
    return false;
}

int Commande::VerifierHeure(int horaire) // Retourne l'heure si elle est valide sinon -1
{
    string heureAverif = option[horaire+1];
	stringstream ss(heureAverif);
	// Essaye de caster <unString> en un entier
	int nombre;
	ss >> nombre;
	// Renvoie -1 si impossible
	if (ss.fail())
	{
		return -1;
	}

	// Vérifie que <unString> ne contient qu'un entier
	string verif;
	ss >> verif;
	if (!verif.empty())
	{
		return -1;
	}
		
    if (0<= nombre && nombre<24)
    {
        return nombre;
    }
    else
    {
        return -1;
    }
}

bool Commande::VerifierExtensionDot(string nomFichierDot)
{
    stringstream ss(nomFichierDot);
    string extension;
    ss.seekg(0,ss.end); // Permet de recuperer l'extension au cas ou il y aurait un chemin relatif ou absolu
    long taille = ss.tellg();
    ss.seekg(0);
    char * buffer = new char[taille-3];
    ss.read(buffer,taille-3);
    getline(ss,extension);
    delete [] buffer;
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
        if (strlen(option[i]) == 2 && option[i][1] == 'g')
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
        if (strlen(option[i]) == 2 && option[i][1] == 't')
        {
            return i;
        }
    }
    return 0;
}

//----------------------------------------------------- Méthodes protégées

