#pragma once

class CArc
{
private:
	int iARCDestination;

public:

	/*
	Constructeur par d�fault, initialise la destination � -1
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialis�
	*/
	CArc() { iARCDestination = -1;  }


	/*
	Constructeur de confort, initialise la destination � uiDestination
	Entree : 
		- uiDestination : IN, destination de l'arc
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialis� et sa destination vaut uiDestination
	*/
	CArc(unsigned int uiDestination) { iARCDestination = uiDestination; }


	/*
	Constructeur de recopie
	Entree :
		- ARC1 : IN, arc � copier
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialis� et sa destination vaut celle de ARC1
	*/
	CArc(const CArc &ARC1) { iARCDestination = ARC1.iARCDestination; }


	/*
	Getteur de uiARCDestination
	Entree : /
	Preconditions : /
	Sortie : 
		- 
	Postconditions :
		- La valeur de uiARCDestination est retourn�e
	*/
	int ARCLireDestination() { return iARCDestination; }


	/*
	Setteur de uiARCDestination
	Entree : /
	Preconditions : /
	Sortie :
		-
	Postconditions :
		- La valeur de uiARCDestination est modifi�
	*/
	void ARCModifierDestination(unsigned int uiDestination) { iARCDestination = uiDestination; }


	/*
	Op�rateur =
	Entree :
		- ARC1 : IN, arc � copier
	Preconditions : /
	Sortie : 
		- CArc : une copie de l'objet courrant
	Postconditions :
		- L'objet est initialis�, sa destination vaut celle de ARC1 et une copie en est retourn�e
	*/
	CArc operator=(CArc ARC1) { return (iARCDestination = ARC1.iARCDestination); }
};

