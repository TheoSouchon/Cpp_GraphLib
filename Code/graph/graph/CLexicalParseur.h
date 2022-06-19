#pragma once
#define pbOuvertureFichier 6
#define pbLectureValGraph 7
#define pbSyntaxFichier 8

class CLexicalParseur
{
private:
	char* pcLEXNomFichier;

public:
	/*
	Constructeur par d�fault, initialise pcLEXNomFichier � nullptr
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialis�
	*/
	CLexicalParseur() { pcLEXNomFichier = nullptr; };

	/*
	Constructeur de confort
	Entree :
		- pcNomFichier : chemin du fichier
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialis� avec le chemin du fichier
	*/
	CLexicalParseur(char* pcNomFichier) { pcLEXNomFichier = pcNomFichier; };

	/*
	Getteur de pcLEXNomFichier
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- La valeur de pcLEXNomFichier est retourn�e
	*/
	char* LEXLireNomFichier() { return pcLEXNomFichier; };

	/*
	Setteur de pcLEXNomFichier
	Entree : 
		- pcNomFichier : chemin du fichier
	Preconditions : /
	Sortie : /
	Postconditions :
		- pcPARNomFichier a �t� modifi�
	*/
	void LEXModifierNomFichier(char* pcNomFichier) { pcLEXNomFichier = pcNomFichier; };

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
	int LEXLireAttribut(unsigned int uiNumLigne, char cSperator); //lexical

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
	int LEXLireAttributEntreSeparateur(unsigned int uiNumLigne, char cSeparator1, char cSeparator2); //lexical

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
	int LEXLireAttributApresSeparateur(unsigned int uiNumLigne, char cSeparator1, char cSeparator2); //lexical

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
	CLexicalParseur operator=(CLexicalParseur LEX1);
};

