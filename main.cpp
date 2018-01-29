using namespace std;
#include <iostream>
#include "Commande.h"
#include "Stockage.h"
#include "Log.h"
#include "Logfile.h"

int main(int argc, char **argv)
{
	cout << argc << endl;
	int i = 0;
	for (i=0; i<argc; i++)
	{
		cout << argv[i] << endl;
	}
	Commande C(argc, argv);
	C.Choisir();
	return 0;
}

