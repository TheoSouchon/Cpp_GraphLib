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
	Constructeur par d�fault, initialise pcSYNNomFichier � nullptr
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialis�
	*/
	CSyntaxParseur() { pcSYNNomFichier = nullptr; };

	/*
	Constructeur de confort
	Entree :
		- pcNomFichier : chemin du fichier
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialis� avec le chemin du fichier
	*/
	CSyntaxParseur(char* pcNomFichier) { pcSYNNomFichier = pcNomFichier; };

	/*
	Getteur de pcSYNNomFichier
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- La valeur de pcSYNNomFichier est retourn�e
	*/
	char* SYNLireNomFichier() { return pcSYNNomFichier; };

	/*
	Setteur de pcSYNNomFichier
	Entree : 
		- pcNomFichier : chemin du fichier
	Preconditions : /
	Sortie : /
	Postconditions :
		- pcSYNNomFichier a �t� modifi�
	*/
	void SYNModifierNomFichier(char* pcNomFichier) { pcSYNNomFichier = pcNomFichier; };

	/*
	d�finit si c'est acceptable selon notre case
	Entree : 
		- pcChaine : chaine � tester
		- pcChaineAttendu : chaine � laquelle on compare
	Precondition : /
	Sortie : true si la cha�ne respecte la casse, false sinon
	Postconditions :
		- Le bool est retourn�
	*/
	bool SYNComparerCase(char* pcChaineRecu, char* pcChaineAttendu); //syntax

	/*
	verifie la syntax d'une ligne selon une chaine
	Entree :
		- pcChaineAttendu : chaine qui sert de comparateur
		- uiNumLigne : num�ro de ligne attendu dans le fichier
	Precondition : /
	Sortie :
		- bool : true si la ligne correspond, false sinon
	Postconditions :
		- Le bool est retourn� OU
		- Erreur 6 : pbOuvertureFichier
		- Erreur 8 : pbSyntaxFichier
	*/
	bool SYNVerifSyntaxLigneExact(char* pcChaineAttendu, unsigned int uiNumLigne); //syntax

	/*
	verifie la syntax d'une partie de ligne apr�s un s�parateur
	Entree :
		- pcChaineAttendu : chaine qui sert de comparateur
		- uiNumLigne : num�ro de ligne attendu dans le fichier
		- cSeparateur : caract�re s�parateur de lecture pour la ligne lue
	Precondition : /
	Sortie :
		- bool : true si la ligne correspond, false sinon
	Postconditions :
		- Le bool est retourn� OU
		- Erreur 6 : pbOuvertureFichier
		- Erreur 8 : pbSyntaxFichier
	*/
	bool SYNVerifSyntaxLignePartielle(char* pcChaineAttendu, unsigned int uiNumLigne, char cSeparateur); //syntax

	/*
	verifie la syntax d'une partie de ligne entre 2 s�parateurs
	Entree :
		- pcChaineAttendu : chaine qui sert de comparateur
		- uiNumLigne : num�ro de ligne attendu dans le fichier
		- cSeparateur : caract�re s�paracteur de lecture pour le d�but de ligne
		- cSeparateur2 : caract�re s�paracteur de lecture pour la fin de ligne
	Precondition : /
	Sortie :
		- bool : true si la ligne correspond, false sinon
	Postconditions :
		- Le bool est retourn� OU
		- Erreur 6 : pbOuvertureFichier
		- Erreur 8 : pbSyntaxFichier
	*/
	bool SYNVerifSyntaxEntreSeparateur(char* pcChaineAttendu, unsigned int uiNumLigne, char cSeparateur1, char cSeparateur2); //syntax

	/*
	Op�rateur = entre 2 CSyntaxParseur
	Entree :
		- SYN1 : CSyntaxParseur � recopier
	Preconditions : /
	Sortie :
		- CSyntaxParseur : une copie de l'objet courrant contenant les m�mes valeurs que SYN1
	Postconditions :
		- L'objet est initialis�, renvoy� et contient les m�mes valeurs que SYN1 OU
		- Erreur 1 : AllocationRatee, l'allocation d'un pointeur a �chou�e
	*/
	CSyntaxParseur operator=(CSyntaxParseur SYN1);
};

