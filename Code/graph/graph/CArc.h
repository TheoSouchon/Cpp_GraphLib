#pragma once

class CArc
{
private:
	int iARCDestination;

public:

	/*
	Constructeur par défault, initialise la destination à -1
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialisé
	*/
	CArc() { iARCDestination = -1;  }


	/*
	Constructeur de confort, initialise la destination à uiDestination
	Entree : 
		- uiDestination : IN, destination de l'arc
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialisé et sa destination vaut uiDestination
	*/
	CArc(unsigned int uiDestination) { iARCDestination = uiDestination; }


	/*
	Constructeur de recopie
	Entree :
		- ARC1 : IN, arc à copier
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialisé et sa destination vaut celle de ARC1
	*/
	CArc(const CArc &ARC1) { iARCDestination = ARC1.iARCDestination; }


	/*
	Getteur de uiARCDestination
	Entree : /
	Preconditions : /
	Sortie : 
		- 
	Postconditions :
		- La valeur de uiARCDestination est retournée
	*/
	int ARCLireDestination() { return iARCDestination; }


	/*
	Setteur de uiARCDestination
	Entree : /
	Preconditions : /
	Sortie :
		-
	Postconditions :
		- La valeur de uiARCDestination est modifié
	*/
	void ARCModifierDestination(unsigned int uiDestination) { iARCDestination = uiDestination; }


	/*
	Opérateur =
	Entree :
		- ARC1 : IN, arc à copier
	Preconditions : /
	Sortie : 
		- CArc : une copie de l'objet courrant
	Postconditions :
		- L'objet est initialisé, sa destination vaut celle de ARC1 et une copie en est retournée
	*/
	CArc operator=(CArc ARC1) { return (iARCDestination = ARC1.iARCDestination); }
};

