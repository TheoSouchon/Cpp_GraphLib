#pragma once
#include "CGraph.h"
#include "CLexicalParseur.h"
#include "CSyntaxParseur.h"
#define  pbOuvertureFichier 6
#define pbLectureValGraph 7
#define pbSyntaxFichier 8
class CParseurGraph
{
private:
	char* pcPARNomFichier;
	CLexicalParseur PARLexicalParseur;
	CSyntaxParseur PARSyntaxParseur;
public:
	/*
	Constructeur par d�fault, initialise pcPARNomFichier � nullptr et initialise les parseurs
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialis�
	*/
	CParseurGraph();

	/*
	Constructeur de confort, initialise les parseurs avec le chemin du fichier
	Entree :
		- char* : pcNomFichier
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialis� avec le chemin du fichier
	*/
	CParseurGraph(char* pcNomFichier);

	/*
	Getteur de pcPARNomFichier
	Entree : /
	Preconditions : /
	Sortie :
		-
	Postconditions :
		- La valeur de pcPARNomFichier est retourn�e
	*/
	char* PARLireNomFicher() { return pcPARNomFichier; };

	/*
	Setteur de pcPARNomFichier
	Entree : /
	Preconditions : /
	Sortie :
		-
	Postconditions :
		- pcPARNomFichier a �t� modifi�
	*/
	void PARModifNomFichier(char* pcNomFichier) { pcPARNomFichier=pcNomFichier; };


	/*
	Construit un graph selon un fichier
	Entree : /
	Precondition : /
	Sortie :
		- CGraph : le graph construit � partir du fichier
	Postconditions :
		- le graph est construit et renvoy� OU
		- Erreur 6 : pbOuvertureFichier OU
		- Erreur 7 : pbLectureValGraph OU
		- Erreur 8 : pbSyntaxFichier
	*/
	CGraph PARConstruireGraph();

};

