#pragma once
#define  pbOuvertureFichier 6
#define pbLectureValGraph 7
#define pbSyntaxFichier 8

class CSyntaxParseur
{
private:
	char* pcSYNNomFichier;
public:
	/*
	Constructeur par défault, initialise pcSYNNomFichier à nullptr
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialisé
	*/
	CSyntaxParseur() { pcSYNNomFichier = nullptr; };

	/*
	Constructeur de confort
	Entree :
		- pcNomFichier : chemin du fichier
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialisé avec le chemin du fichier
	*/
	CSyntaxParseur(char* pcNomFichier) { pcSYNNomFichier = pcNomFichier; };

	/*
	Getteur de pcSYNNomFichier
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- La valeur de pcSYNNomFichier est retournée
	*/
	char* SYNLireNomFichier() { return pcSYNNomFichier; };

	/*
	Setteur de pcSYNNomFichier
	Entree : 
		- pcNomFichier : chemin du fichier
	Preconditions : /
	Sortie : /
	Postconditions :
		- pcSYNNomFichier a été modifié
	*/
	void SYNModifierNomFichier(char* pcNomFichier) { pcSYNNomFichier = pcNomFichier; };

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
	bool SYNComparerCase(char* pcChaineRecu, char* pcChaineAttendu); //syntax

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
	bool SYNVerifSyntaxLigneExact(char* pcChaineAttendu, unsigned int uiNumLigne); //syntax

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
	bool SYNVerifSyntaxLignePartielle(char* pcChaineAttendu, unsigned int uiNumLigne, char cSeparateur); //syntax

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
	bool SYNVerifSyntaxEntreSeparateur(char* pcChaineAttendu, unsigned int uiNumLigne, char cSeparateur1, char cSeparateur2); //syntax

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
	CSyntaxParseur operator=(CSyntaxParseur SYN1);
};

