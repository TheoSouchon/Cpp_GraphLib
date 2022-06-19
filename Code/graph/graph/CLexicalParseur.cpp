
#include "CLexicalParseur.h"
#include "CException.h"
#include <fstream>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

/*
Lit la valeur d'une ligne après un séparateur
Entree :
	- uiNumLigne : numéro de ligne attendu dans le fichier
	- cSeparateur : caractère séparateur de lecture pour la ligne lu
Precondition : /
Sortie :
	- int : la valeur lue
Postconditions :
	- La valeur lue est retournée OU
	- Erreur 6 : pbOuvertureFichier OU
	- Erreur 7 : pbLectureValGraph
*/
int CLexicalParseur::LEXLireAttribut(unsigned int uiNumLigne, char cSperator)
{
	ifstream MonFichier(pcLEXNomFichier);
	char cLigne[255];
	if (!MonFichier.is_open()) {
		throw CException(pbOuvertureFichier);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiNumLigne - 1; uiBoucle++)
	{
		MonFichier.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	MonFichier.ignore(numeric_limits<streamsize>::max(), cSperator);
	MonFichier.getline(cLigne, sizeof(cLigne));

	for (unsigned int uiBoucle = 0; uiBoucle < 255; uiBoucle++) {
		if (cLigne[uiBoucle] == 32) {
			cLigne[uiBoucle] = 0;
		}
	}

	int iNum = 0;
	try {
		iNum = stoi(cLigne);
	}
	catch (...) {
		throw CException(pbLectureValGraph);
	}
	return iNum;
}

/*
lit la valeur d'une ligne entre 2 séparateurs
Entree :
	- uiNumLigne : numéro de ligne attendu dans le fichier
	- cSeparateur1 : caractère séparateur de début de lecture
	- cSeparateur2 : caractère séparateur de fin de lecture
Precondition : /
Sortie :
	- int : la valeur lu
Postconditions : 
	- La valeur lue est retournée OU
	- Erreur 6 : pbOuvertureFichier OU
	- Erreur 7 : pbLectureValGraph
*/
int CLexicalParseur::LEXLireAttributEntreSeparateur(unsigned int uiNumLigne, char cSeparator1, char cSeparator2)
{
	ifstream MonFichier(pcLEXNomFichier);
	char cLigne[255];
	if (!MonFichier.is_open()) {
		throw CException(pbOuvertureFichier);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiNumLigne - 1; uiBoucle++)
	{
		MonFichier.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	MonFichier.ignore(numeric_limits<streamsize>::max(), cSeparator1);
	MonFichier.getline(cLigne, sizeof(cLigne), (int)cSeparator2);

	int iNum = 0;
	try {
		iNum = stoi(cLigne);
	}
	catch (...) {
		throw CException(pbLectureValGraph);
	}
	return iNum;
}

/*
lit la valeur d'une ligne en ignorant jusqu'à un certain séparateur
Entree :
	- uiNumLigne : numéro de ligne attendu dans le fichier
	- cSeparateur1 : caractère séparateur ignoré
	- cSeparateur2 : caractère séparateur de fin de lecture
Precondition : /
Sortie :
	- int : la valeur lu
Postconditions : 
	- La valeur lue est retournée OU
	- Erreur 6 : pbOuvertureFichier OU
	- Erreur 7 : pbLectureValGraph
*/
int CLexicalParseur::LEXLireAttributApresSeparateur(unsigned int uiNumLigne, char cSeparator1, char cSeparator2)
{
	ifstream MonFichier(pcLEXNomFichier);
	char cLigne[255];
	if (!MonFichier.is_open()) {
		throw CException(pbOuvertureFichier);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiNumLigne - 1; uiBoucle++)
	{
		MonFichier.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	MonFichier.ignore(numeric_limits<streamsize>::max(), cSeparator1);
	MonFichier.ignore(numeric_limits<streamsize>::max(), cSeparator2);
	MonFichier.getline(cLigne, sizeof(cLigne));

	int iNum = 0;
	try {
		iNum = stoi(cLigne);
	}
	catch (...) {
		throw CException(pbLectureValGraph);
	}
	return iNum;
}


/*
Opérateur = entre 2 CLexicalParseur
Entree :
	- LEX1 : CLexicalParseur à recopier
Preconditions : /
Sortie :
	- CLexicalParseur : une copie de l'objet courrant contenant les mêmes valeurs que LEX1
Postconditions :
	- L'objet est initialisé, renvoyé et contient les mêmes valeurs que LEX1 OU
	- Erreur 1 : AllocationRatee, l'allocation d'un pointeur a échouée
*/
CLexicalParseur CLexicalParseur::operator=(CLexicalParseur LEX1)
{
	LEXModifierNomFichier(LEX1.LEXLireNomFichier());
	return *this;
}


