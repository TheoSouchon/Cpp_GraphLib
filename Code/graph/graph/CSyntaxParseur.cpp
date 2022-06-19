#include "CSyntaxParseur.h"
#include "CException.h"
#include <fstream>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

/*
définit si c'est acceptable selon notre case
Entree :
	- pcChaine : chaine à tester
	- pcChaineAttendu : chaine à laquelle on compare
Precondition : /
Sortie : true si la chaîne respecte la casse, false sinon
Postconditions :
	- Le bool est retourné
*/
bool CSyntaxParseur::SYNComparerCase(char* pcChaineRecu, char* pcChaineAttendu)
{
	int i = 0;
	int j = 0;
	//correspondance exacte
	if (strcmp(pcChaineRecu, pcChaineAttendu) == 0) {
		return true;
	}

	while (pcChaineAttendu[i] != '\0') {

		if (pcChaineAttendu[i] >= 'a' && pcChaineAttendu[i] <= 'z') {
			pcChaineAttendu[i] = pcChaineAttendu[i] - 32;
		}

		i++;
	}

	//correspondance entièrement en majuscule
	if (strcmp(pcChaineRecu, pcChaineAttendu) == 0) {
		return true;
	}


	while (pcChaineAttendu[j] != '\0') {


		if (pcChaineAttendu[j] >= 'A' && pcChaineAttendu[j] <= 'Z') {
			pcChaineAttendu[j] = pcChaineAttendu[j] + 32;
		}

		j++;
	}

	//correspondance entièrement en miniscule
	if (strcmp(pcChaineRecu, pcChaineAttendu) == 0) {
		return true;
	}
	return false;
}

/*
verifie la syntax d'une ligne selon une chaine
Entree :
	- pcChaineAttendu : chaine qui sert de comparateur
	- uiNumLigne : numéro de ligne attendu dans le fichier
Precondition : /
Sortie :
	- bool : true si la ligne correspond, false sinon
Postconditions :
	- Le bool est retourné OU
	- Erreur 6 : pbOuvertureFichier
	- Erreur 8 : pbSyntaxFichier
*/
bool CSyntaxParseur::SYNVerifSyntaxLigneExact(char* pcChaineAttendu, unsigned int uiNumLigne)
{
	ifstream MonFichier(pcSYNNomFichier);
	char cLigne[255];
	if (!MonFichier.is_open()) {
		throw CException(pbOuvertureFichier);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiNumLigne - 1; uiBoucle++)
	{
		MonFichier.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	MonFichier.getline(cLigne, sizeof(cLigne));
	
	//pour accepter les espaces après
	for  (unsigned int uiBoucle = 0; uiBoucle < 255; uiBoucle++)
	{
		if (cLigne[uiBoucle] == 32) {
			cLigne[uiBoucle] = 0;
		}
	}

	bool bRes = SYNComparerCase(cLigne, pcChaineAttendu);
	if (bRes) {
		return true;
	}
	else {
		throw CException(pbSyntaxFichier);
	}
}

/*
verifie la syntax d'une partie de ligne après un séparateur
Entree :
	- pcChaineAttendu : chaine qui sert de comparateur
	- uiNumLigne : numéro de ligne attendu dans le fichier
	- cSeparateur : caractère séparateur de lecture pour la ligne lue
Precondition : /
Sortie :
	- bool : true si la ligne correspond, false sinon
Postconditions :
	- Le bool est retourné OU
	- Erreur 6 : pbOuvertureFichier
	- Erreur 8 : pbSyntaxFichier
*/
bool CSyntaxParseur::SYNVerifSyntaxLignePartielle(char* pcChaineAttendu, unsigned int uiNumLigne, char cSeparateur)
{
	ifstream MonFichier(pcSYNNomFichier);
	char cLigne[255];
	if (!MonFichier.is_open()) {
		throw CException(pbOuvertureFichier);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiNumLigne - 1; uiBoucle++)
	{
		MonFichier.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	MonFichier.getline(cLigne, sizeof(cLigne), (int)cSeparateur);
	/*
	if (strcmp(cLigne, pcChaineAttendu) == 0) {
		return true;
	}
	return false;
	*/
	bool bRes = SYNComparerCase(cLigne, pcChaineAttendu);
	if (bRes) {
		return true;
	}
	else {
		throw CException(pbSyntaxFichier);
	}
}

/*
verifie la syntax d'une partie de ligne entre 2 séparateurs
Entree :
	- pcChaineAttendu : chaine qui sert de comparateur
	- uiNumLigne : numéro de ligne attendu dans le fichier
	- cSeparateur : caractère séparacteur de lecture pour le début de ligne
	- cSeparateur2 : caractère séparacteur de lecture pour la fin de ligne
Precondition : /
Sortie :
	- bool : true si la ligne correspond, false sinon
Postconditions :
	- Le bool est retourné OU
	- Erreur 6 : pbOuvertureFichier
	- Erreur 8 : pbSyntaxFichier
*/
bool CSyntaxParseur::SYNVerifSyntaxEntreSeparateur(char* pcChaineAttendu, unsigned int uiNumLigne, char cSeparateur1, char cSeparateur2)
{
	ifstream MonFichier(pcSYNNomFichier);
	char cLigne[255];
	if (!MonFichier.is_open()) {
		throw CException(pbOuvertureFichier);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiNumLigne - 1; uiBoucle++)
	{
		MonFichier.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	MonFichier.ignore(numeric_limits<streamsize>::max(), cSeparateur1);
	MonFichier.getline(cLigne, sizeof(cLigne), cSeparateur2);

	bool bRes = SYNComparerCase(cLigne, pcChaineAttendu);
	if (bRes) {
		return true;
	}
	else {
		throw CException(pbSyntaxFichier);
	}
}


/*
Opérateur = entre 2 CSyntaxParseur
Entree :
	- SYN1 : CSyntaxParseur à recopier
Preconditions : /
Sortie :
	- CSyntaxParseur : une copie de l'objet courrant contenant les mêmes valeurs que SYN1
Postconditions :
	- L'objet est initialisé, renvoyé et contient les mêmes valeurs que SYN1 OU
	- Erreur 1 : AllocationRatee, l'allocation d'un pointeur a échouée
*/
CSyntaxParseur CSyntaxParseur::operator=(CSyntaxParseur SYN1)
{
	SYNModifierNomFichier(SYN1.SYNLireNomFichier());
	return *this;
}
