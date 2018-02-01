using namespace std;
#include <iostream>
#include "Commande.h"
#include "Log.h"
#include "Logfile.h"

int main(int argc, char **argv)
{
	/*Logfile lf("quinzeTest.log");
	Log newlog = lf.LireLog();
	cout << newlog;*/
	Commande C(argc, argv);
	C.Choisir();
	return 0;
}

