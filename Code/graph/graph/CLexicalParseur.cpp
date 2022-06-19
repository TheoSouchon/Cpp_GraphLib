
#include "CLexicalParseur.h"
#include "CException.h"
#include <fstream>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

/*
Lit la valeur d'une ligne apr�s un s�parateur
Entree :
	- uiNumLigne : num�ro de ligne attendu dans le fichier
	- cSeparateur : caract�re s�parateur de lecture pour la ligne lu
Precondition : /
Sortie :
	- int : la valeur lue
Postconditions :
	- La valeur lue est retourn�e OU
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
lit la valeur d'une ligne entre 2 s�parateurs
Entree :
	- uiNumLigne : num�ro de ligne attendu dans le fichier
	- cSeparateur1 : caract�re s�parateur de d�but de lecture
	- cSeparateur2 : caract�re s�parateur de fin de lecture
Precondition : /
Sortie :
	- int : la valeur lu
Postconditions : 
	- La valeur lue est retourn�e OU
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
lit la valeur d'une ligne en ignorant jusqu'� un certain s�parateur
Entree :
	- uiNumLigne : num�ro de ligne attendu dans le fichier
	- cSeparateur1 : caract�re s�parateur ignor�
	- cSeparateur2 : caract�re s�parateur de fin de lecture
Precondition : /
Sortie :
	- int : la valeur lu
Postconditions : 
	- La valeur lue est retourn�e OU
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
Op�rateur = entre 2 CLexicalParseur
Entree :
	- LEX1 : CLexicalParseur � recopier
Preconditions : /
Sortie :
	- CLexicalParseur : une copie de l'objet courrant contenant les m�mes valeurs que LEX1
Postconditions :
	- L'objet est initialis�, renvoy� et contient les m�mes valeurs que LEX1 OU
	- Erreur 1 : AllocationRatee, l'allocation d'un pointeur a �chou�e
*/
CLexicalParseur CLexicalParseur::operator=(CLexicalParseur LEX1)
{
	LEXModifierNomFichier(LEX1.LEXLireNomFichier());
	return *this;
}


