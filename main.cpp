/*************************************************************************
                           Main  -  description
                             -------------------
    début                : 10/01/2018
    copyright            : (C) 2018 par Christophe ETIENNE & William Occeli
    e-mail               : christophe.etienne@insa-lyon.fr
                           william.occeli@insa-lyon.fr
*************************************************************************/

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel

#include "Commande.h"

int main(int argc, char **argv)
{
	Commande C(argc, argv);
	C.Choisir();
	return 0;
}

