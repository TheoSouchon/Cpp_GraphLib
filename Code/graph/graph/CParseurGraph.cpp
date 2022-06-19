#include "CParseurGraph.h"
using namespace std;
#include <fstream>
#include <string.h>
#include <iostream>
#include <string>


/*
Constructeur par défault, initialise pcPARNomFichier à nullptr et initialise les parseurs
Entree : /
Preconditions : /
Sortie : /
Postconditions :
	- L'objet est initialisé
*/
CParseurGraph::CParseurGraph() {
	pcPARNomFichier = nullptr;
	CLexicalParseur PARLexicalParseur();
	CSyntaxParseur PARSyntaxParseur();
}


/*
Constructeur de confort, initialise les parseurs avec le chemin du fichier
Entree :
	- char* : pcNomFichier
Preconditions : /
Sortie : /
Postconditions :
	- L'objet est initialisé avec le chemin du fichier
*/
CParseurGraph::CParseurGraph(char* pcNomFichier) {
	pcPARNomFichier = pcNomFichier;
	PARLexicalParseur = CLexicalParseur(pcNomFichier);
	PARSyntaxParseur = CSyntaxParseur(pcNomFichier);
}

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
CGraph CParseurGraph::PARConstruireGraph()
{
	CGraph GRA1(true);
	//verif syntax nbSommets
	char pcArg0[] = "NBSommets";
	PARSyntaxParseur.SYNVerifSyntaxLignePartielle(pcArg0,1,'=');

	//verif syntax NbArcs
	char pcArg1[] = "NBArcs";
	PARSyntaxParseur.SYNVerifSyntaxLignePartielle(pcArg1, 2, '='); //avant le séparateur

	//lire attribut nbSommets
	int iNbSommet = PARLexicalParseur.LEXLireAttribut(1,'='); //après le séparateur

	//lire attribut nbArcs
	int iNbArc = PARLexicalParseur.LEXLireAttribut(2, '=');

	//verif syntax Sommets
	char pcArg2[] = "Sommets=[";
	PARSyntaxParseur.SYNVerifSyntaxLigneExact(pcArg2, 3);

	// verif syntax encapsulation ("]")
	char pcArg3[] = "]";
	char pcArg4[] = "]";
	bool b1 = PARSyntaxParseur.SYNVerifSyntaxLigneExact(pcArg3, 4 + iNbSommet);
	bool b2 = PARSyntaxParseur.SYNVerifSyntaxLigneExact(pcArg4, 6 + iNbSommet + iNbArc);

	//(nbSommets fois : verif syntax DefSommet + lire sommet)
	for (unsigned int uiBoucle = 4; uiBoucle < 4+iNbSommet; uiBoucle++)
	{
		char pcArg5[] = "Numero";
		PARSyntaxParseur.SYNVerifSyntaxLignePartielle(pcArg5, uiBoucle, '=');
		unsigned int uiNumSommet = PARLexicalParseur.LEXLireAttribut(uiBoucle,'=');
		GRA1.GRAAjouterSommet(uiNumSommet);
	}

	// verif syntax Arcs=[
	char pcArg6[] = "Arcs=[";
	PARSyntaxParseur.SYNVerifSyntaxLigneExact(pcArg6, 8);

	//(nbArcs fois : verif syntax DefArcs + lire arc)
	for (unsigned int uiBoucle2 = 6 + iNbSommet; uiBoucle2 < 6 + iNbSommet + iNbArc; uiBoucle2++)
	{
		char pcArg7[] = "Debut";
		PARSyntaxParseur.SYNVerifSyntaxLignePartielle(pcArg7, uiBoucle2, '=');
		char pcArg8[] = " ";
		PARSyntaxParseur.SYNVerifSyntaxEntreSeparateur(pcArg8, uiBoucle2, ',', 'F');
		char pcArg9[] = "Fin";
		PARSyntaxParseur.SYNVerifSyntaxEntreSeparateur(pcArg9, uiBoucle2, ' ', '=');

		unsigned int uiSommetArcDebut = PARLexicalParseur.LEXLireAttributEntreSeparateur(uiBoucle2, '=',',');
		unsigned int uiSommetArcFin = PARLexicalParseur.LEXLireAttributApresSeparateur(uiBoucle2, 'n','=');
		GRA1.GRAAjouterArc(uiSommetArcDebut, uiSommetArcFin);
	}
	
	//GRA1.GRAAfficher();
	return GRA1;
}