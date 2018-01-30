COMP=g++
EDL=g++
LIBS=
RM=rm
CLEAN=raz
EXEC=analog
CXXFLAGS=-W -std=c++11 -std=gnu++11  -Wall -ansi -pedantic -D MAP
EDLFLAGS=
RMFLAGS = -f
OBJ=main.o Logfile.o Log.o Stockage.o Commande.o Graphe.o TopTen.o 

#Création de l’éxécutable AnalyseLog
$(EXEC) : $(OBJ)
	echo  "EDL de $(EXEC)"
	$(EDL) -o $(EXEC) $(OBJ)

#Création de main.o
main.o : main.cpp Commande.h Stockage.h Logfile.h Log.h
	echo "Comp de main"
	$(COMP) -c main.cpp $(CXXFLAGS)

#Créer un fichier objet Logfile.o
Logfile.o : Logfile.cpp Logfile.h Log.h
	echo "Compilation de Logfile" 
	$(COMP) -c Logfile.cpp $(CXXFLAGS)

#Créer un fichier objet Log.o
Log.o : Log.cpp Log.h 
	echo "Compilation de Log" 
	$(COMP) -c Log.cpp $(CXXFLAGS)

#Créer un fichier objet Commande.o
Commande.o : Commande.cpp Commande.h 
	echo "Compilation de Commande" 
	$(COMP) -c Commande.cpp $(CXXFLAGS)

#Créer un fichier objet Stockage.o
Stockage.o : Stockage.cpp Stockage.h
	echo "Compilation de Stockage" 
	$(COMP) -c Stockage.cpp $(CXXFLAGS)

#Créer un fichier objet TopTen.o
TopTen.o : TopTen.cpp TopTen.h
	echo "Compilation de TopTen"
	$(COMP) -c TopTen.cpp $(CXXFLAGS)

#Créer un fichier objet Graphe.o
Graphe.o : Graphe.cpp Graphe.h
	echo "Compilation de Graphe"
	$(COMP) -c Graphe.cpp $(CXXFLAGS)

.PHONY: $(CLEAN) mrproper

$(CLEAN):
	$(RM) $(RMFLAGS) $(EXEC) $(OBJ) corc

mrproper: clean
	$(RM) $(RMFLAGS) $(EXEC)
