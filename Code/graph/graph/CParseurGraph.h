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
	Constructeur par défault, initialise pcPARNomFichier à nullptr et initialise les parseurs
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialisé
	*/
	CParseurGraph();

	/*
	Constructeur de confort, initialise les parseurs avec le chemin du fichier
	Entree :
		- char* : pcNomFichier
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialisé avec le chemin du fichier
	*/
	CParseurGraph(char* pcNomFichier);

	/*
	Getteur de pcPARNomFichier
	Entree : /
	Preconditions : /
	Sortie :
		-
	Postconditions :
		- La valeur de pcPARNomFichier est retournée
	*/
	char* PARLireNomFicher() { return pcPARNomFichier; };

	/*
	Setteur de pcPARNomFichier
	Entree : /
	Preconditions : /
	Sortie :
		-
	Postconditions :
		- pcPARNomFichier a été modifié
	*/
	void PARModifNomFichier(char* pcNomFichier) { pcPARNomFichier=pcNomFichier; };


	/*
	Construit un graph selon un fichier
	Entree : /
	Precondition : /
	Sortie :
		- CGraph : le graph construit à partir du fichier
	Postconditions :
		- le graph est construit et renvoyé OU
		- Erreur 6 : pbOuvertureFichier OU
		- Erreur 7 : pbLectureValGraph OU
		- Erreur 8 : pbSyntaxFichier
	*/
	CGraph PARConstruireGraph();

};

