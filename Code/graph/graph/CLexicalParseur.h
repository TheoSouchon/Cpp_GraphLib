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
	Constructeur par défault, initialise pcLEXNomFichier à nullptr
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialisé
	*/
	CLexicalParseur() { pcLEXNomFichier = nullptr; };

	/*
	Constructeur de confort
	Entree :
		- pcNomFichier : chemin du fichier
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialisé avec le chemin du fichier
	*/
	CLexicalParseur(char* pcNomFichier) { pcLEXNomFichier = pcNomFichier; };

	/*
	Getteur de pcLEXNomFichier
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- La valeur de pcLEXNomFichier est retournée
	*/
	char* LEXLireNomFichier() { return pcLEXNomFichier; };

	/*
	Setteur de pcLEXNomFichier
	Entree : 
		- pcNomFichier : chemin du fichier
	Preconditions : /
	Sortie : /
	Postconditions :
		- pcPARNomFichier a été modifié
	*/
	void LEXModifierNomFichier(char* pcNomFichier) { pcLEXNomFichier = pcNomFichier; };

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
	int LEXLireAttribut(unsigned int uiNumLigne, char cSperator); //lexical

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
	int LEXLireAttributEntreSeparateur(unsigned int uiNumLigne, char cSeparator1, char cSeparator2); //lexical

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
	int LEXLireAttributApresSeparateur(unsigned int uiNumLigne, char cSeparator1, char cSeparator2); //lexical

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
	CLexicalParseur operator=(CLexicalParseur LEX1);
};

