#include "CSommet.h"
#include <iostream>

/*
Constructeur par défault, initialise le numéro à -1 et les pointeurs sur les arcs à nullptr
Entree : /
Preconditions : /
Sortie : /
Postconditions :
	- L'objet est initialisé
*/
CSommet::CSommet()
{
	iSOMNumber = -1;
	uiSOMNbEntrant = 0;
	uiSOMNbSortant = 0;
	ppARCSOMEntrant = nullptr;
	ppARCSOMSortant = nullptr;
}

/*
Constructeur de confort, initialise le numéro à celui passé et les pointeurs sur les arcs à nullptr
Entree :
	- unsigned int : iSOMNumber
Preconditions : /
Sortie : /
Postconditions :
	- L'objet est initialisé
*/
CSommet::CSommet(unsigned int uiNumber)
{
	iSOMNumber = uiNumber;
	uiSOMNbEntrant = 0;
	uiSOMNbSortant = 0;
	ppARCSOMEntrant = nullptr;
	ppARCSOMSortant = nullptr;
}


/*
Constructeur de recopie
Entree : /
Preconditions : /
Sortie : /
Postconditions :
	- L'objet est initialisé et contient les mêmes valeurs que SOM1 OU
	- Erreur 2 : Pointeur_Null, l'allocation d'un pointeur a échouée
*/
CSommet::CSommet(const CSommet& SOM1)
{
	iSOMNumber = SOM1.iSOMNumber;
	ppARCSOMEntrant = (CArc**)malloc(SOM1.uiSOMNbEntrant * sizeof(CArc*));
	ppARCSOMSortant = (CArc**)malloc(SOM1.uiSOMNbSortant * sizeof(CArc*));

	if (ppARCSOMEntrant == nullptr || ppARCSOMSortant == nullptr) {
		throw CException(AllocationRatee);
	}

	for (unsigned int uiBoucle = 0; uiBoucle < SOM1.uiSOMNbEntrant; uiBoucle++)
	{
		ppARCSOMEntrant[uiBoucle] = new CArc(*SOM1.ppARCSOMEntrant[uiBoucle]);
	}

	for (unsigned int uiBoucle = 0; uiBoucle < SOM1.uiSOMNbSortant; uiBoucle++)
	{
		ppARCSOMSortant[uiBoucle] = new CArc(*SOM1.ppARCSOMSortant[uiBoucle]);
	}

	uiSOMNbEntrant = SOM1.uiSOMNbEntrant;
	uiSOMNbSortant = SOM1.uiSOMNbSortant;
}



/* Destructeur */
CSommet::~CSommet()
{
	//delete les élements dans la liste des arcs entrants
	for (unsigned int uiBoucle = 0; uiBoucle < uiSOMNbEntrant; uiBoucle++)
	{
		if (ppARCSOMEntrant[uiBoucle] != nullptr) {
			delete ppARCSOMEntrant[uiBoucle];
		}
	}

	//delete les élements dans la liste des arcs sortants
	for (unsigned int uiBoucle = 0; uiBoucle < uiSOMNbSortant; uiBoucle++)
	{
		if (ppARCSOMSortant[uiBoucle] != nullptr) {
			delete ppARCSOMSortant[uiBoucle];
		}
	}
	//free les listes
	free(ppARCSOMEntrant);
	free(ppARCSOMSortant);
}



// GETTEURS ET SETTEURS


// Getteurs et setteurs sur les arcs entrants

/*
Ajouter un arc entrant
Entree :
	- uiEntrant : Numéro du sommet entrant
Precondition : /
Sortie : /
Postconditions :
	- L'arc entrant a bien été ajouté OU
	- Erreur 1 : AllocationRatee OU
	- Erreur 2 : ArcDejaPresent
*/
void CSommet::SOMAjouterArcEntrant(unsigned int uiEntrant)
{
	//si l'arc n'est pas déjà existant
	if (!SOMContientArcEntrant(uiEntrant)) {
		ppARCSOMEntrant = (CArc**)realloc(ppARCSOMEntrant, (uiSOMNbEntrant+1) * sizeof(CArc*));
		if (ppARCSOMEntrant == nullptr) {
			throw CException(AllocationRatee);
		}
		uiSOMNbEntrant++;
		ppARCSOMEntrant[uiSOMNbEntrant-1] = new CArc(uiEntrant);
	}
	else {
		throw CException(ArcDejaPresent);
	}
	
}

/*
Verifie si l'arc entrant est présent dans la liste des sommets entrants
Entree :
	- uiEntrant : Nom du sommet entrant
Precondition : /
Sortie :
	- bool : true si l'arc est déjà présent, false sinon
Postconditions :
	- bool retourné
*/
bool CSommet::SOMContientArcEntrant(unsigned int uiEntrant)
{
	for (unsigned int uiBoucle = 0; uiBoucle < uiSOMNbEntrant; uiBoucle++) {
		if (ppARCSOMEntrant[uiBoucle] != nullptr) {
			if(ppARCSOMEntrant[uiBoucle]->ARCLireDestination()== uiEntrant) {
				return true;
			}
		}
	}
	return false;
}

/*
Modifie un arc entrant
Entree :
	- uiDestination : destination de l'arc à modifier
	- uiNouvelleDestination : nouveau numéro de l'arc
Precondition : /
Sortie : /
Postconditions :
	- L'arc a été modifié OU
	- Erreur 2 : ArcDejaPresent OU
	- Erreur 3 : ArcInexistant
*/
void CSommet::SOMModifierArcEntrant(unsigned int uiDestination, unsigned int uiNouvelleDestination)
{
	if (SOMContientArcEntrant(uiNouvelleDestination)) {
		throw CException(ArcDejaPresent);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiSOMNbEntrant; uiBoucle++) {
		if (ppARCSOMEntrant[uiBoucle] != nullptr) {
			if (ppARCSOMEntrant[uiBoucle]->ARCLireDestination() == uiDestination) {
				ppARCSOMEntrant[uiBoucle]->ARCModifierDestination(uiNouvelleDestination);
				return;
			}
		}
	}
	throw CException(ArcInexistant);
}


/*
Supprime un arc entrant
Entree :
	- uiDestination : destination de l'arc à supprimer
Precondition : /
Sortie : /
Postconditions :
	- L'arc a été modifié OU
	- Erreur 1 : AllocationRatee OU
	- Erreur 3 : ArcInexistant
*/
void CSommet::SOMSupprArcEntrant(unsigned int uiDestination)
{
	if (!SOMContientArcEntrant(uiDestination)) {
		throw CException(ArcInexistant);
	}

	unsigned int index = SOMIndiceArcEntrant(uiDestination);
	delete ppARCSOMEntrant[index];
	//déplacement des éléments
	for (unsigned int uiBoucle = index; uiBoucle < uiSOMNbEntrant - 1; uiBoucle++) {
		ppARCSOMEntrant[uiBoucle] = ppARCSOMEntrant[uiBoucle + 1];
	}

	CArc** ppARCTmp = nullptr;
	//on ne peut pas realloc une taille de 0
	uiSOMNbEntrant--;
	if (uiSOMNbEntrant == 0) {
		free(ppARCSOMEntrant);
	}
	else {
		//Réallocation
		ppARCTmp = (CArc**)realloc(ppARCSOMEntrant, (uiSOMNbEntrant) * sizeof(CArc*));
		if (ppARCTmp == nullptr) {
			throw CException(AllocationRatee);
		}
	}
	ppARCSOMEntrant = ppARCTmp;	
}


/*
Cherche l'indice d'un arc entrant
Entree :
	- uiDestination : numéro de l'arc à chercher
Precondition : /
Sortie :
	- unsigned int : l'indice de l'élément cherché
Postconditions :
	- L'indice a été retourné OU
	- Erreur 3 : ArcInexistant 
*/
unsigned int CSommet::SOMIndiceArcEntrant(unsigned int uiDestination)
{
	for (unsigned int uiBoucle = 0; uiBoucle < uiSOMNbEntrant; uiBoucle++) {
		if (ppARCSOMEntrant[uiBoucle] != nullptr) {
			if (ppARCSOMEntrant[uiBoucle]->ARCLireDestination() == uiDestination) {
				return uiBoucle;
			}
		}
	}
	throw CException(ArcInexistant);
}


// Getteurs et setteurs sur les arcs sortants


/*
Ajouter un arc sortant
Entree :
	- uiSortant : Nom du sommet sortant
Precondition : /
Sortie : /
Postconditions :
	- L'arc sortant a bien été ajouté OU
	- Erreur 1 : AllocationRatee OU
	- Erreur 2 : ArcDejaPresent
*/
void CSommet::SOMAjouterArcSortant(unsigned int uiSortant)
{
	//si l'arc n'est pas déjà existant
	if (SOMContientArcSortant(uiSortant)) {
		throw CException(ArcDejaPresent);
	}
	ppARCSOMSortant = (CArc**)realloc(ppARCSOMSortant, (uiSOMNbSortant + 1) * sizeof(CArc*));
	if (ppARCSOMSortant == nullptr) {
		throw CException(AllocationRatee);
	}
	uiSOMNbSortant++;
	ppARCSOMSortant[uiSOMNbSortant - 1] = new CArc(uiSortant);
}

/*
Verifie si l'arc est déjà présent dans la liste des arcs sortants
Entree :
	- uiSortant : Nom du sommet sortant
Precondition : /
Sortie :
	- bool : true si l'arc est déjà présent, false sinon
Postconditions :
	- bool renvoyé
*/
bool CSommet::SOMContientArcSortant(unsigned int uiSortant)
{
	for (unsigned int uiBoucle = 0; uiBoucle < uiSOMNbSortant; uiBoucle++) {
		if (ppARCSOMSortant[uiBoucle] != nullptr) {
			if (ppARCSOMSortant[uiBoucle]->ARCLireDestination() == uiSortant) {
				return true;
			}
		}
	}
	return false;
}

/*
Modifie un arc sortant
Entree :
	- uiDestiant : numéro de l'arc à modifier
	- uiNouvelleDestination : nouveau numéro de l'arc
Precondition : /
Sortie : /
Postconditions :
	- L'arc a été modifié OU
	- Erreur 2 : ArcDejaPresent OU
	- Erreur 3 : ArcInexistant
*/
void CSommet::SOMModifierArcSortant(unsigned int uiDestination, unsigned int uiNouvelleDestination)
{
	if (SOMContientArcSortant(uiNouvelleDestination)) {
		throw CException(ArcDejaPresent);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiSOMNbSortant; uiBoucle++) {
		if (ppARCSOMSortant[uiBoucle] != nullptr) {
			if (ppARCSOMSortant[uiBoucle]->ARCLireDestination() == uiDestination) {
				ppARCSOMSortant[uiBoucle]->ARCModifierDestination(uiNouvelleDestination);
				return;
			}
		}
	}
	throw CException(ArcInexistant);
}

/*
Supprime un arc sortant
Entree :
	- uiDestination : destination de l'arc à supprimer
Precondition : /
Sortie : /
Postconditions :
	- L'arc a été supprimé OU
	- Erreur 1 : AllocationRatee OU
	- Erreur 3 : ArcInexistant
*/
void CSommet::SOMSupprArcSortant(unsigned int uiDestination)
{
	if (!SOMContientArcSortant(uiDestination)) {
		throw CException(ArcInexistant);
	}

	unsigned int index = SOMIndiceArcSortant(uiDestination);
	delete ppARCSOMSortant[index];
	//déplacement des éléments
	for (unsigned int uiBoucle = index; uiBoucle < uiSOMNbSortant-1; uiBoucle++) {
		ppARCSOMSortant[uiBoucle] = ppARCSOMSortant[uiBoucle + 1];
	}

	CArc** ppARCTmp = nullptr;
	//on ne peut pas realloc une taille de 0
	uiSOMNbSortant--;
	if (uiSOMNbSortant == 0) {
		free(ppARCSOMSortant);
	}
	else {
		//Réallocation
		ppARCTmp = (CArc**)realloc(ppARCSOMSortant, (uiSOMNbSortant) * sizeof(CArc*));
		if (ppARCTmp == nullptr) {
			throw CException(AllocationRatee);
		}
	}
	ppARCSOMSortant = ppARCTmp;
	
}

/*
Cherche l'indice d'un arc sortant
Entree :
	- uiDestination : numéro de l'arc à chercher
Precondition : /
Sortie :
	- unsigned int : l'indice de l'élément cherché
Postconditions :
	- L'indice a été retourné OU
	- Erreur 3 : ArcInexistant
*/
unsigned int CSommet::SOMIndiceArcSortant(unsigned int uiDestination)
{
	for (unsigned int uiBoucle = 0; uiBoucle < uiSOMNbSortant; uiBoucle++) {
		if (ppARCSOMSortant[uiBoucle] != nullptr) {
			if (ppARCSOMSortant[uiBoucle]->ARCLireDestination() == uiDestination) {
				return uiBoucle;
			}
		}
	}
	throw CException(ArcInexistant);
}



// OPERATEURS


/*
Opérateur = entre 2 sommets
Entree :
	- SOMIn : Sommet contenant les informations à copier
Precondition : /
Sortie :
	- CSommet : Une copie de l'objet courrant qui contient les valeurs de SOMIn
Postconditions :
	- Le sommet en entrée a bien été recopié et une copie a été renvoyée OU
	- Erreur 1 : AllocationRatee
*/
CSommet CSommet::operator=(CSommet SOMIn)
{
	for (unsigned int uiBoucle = 0; uiBoucle < uiSOMNbEntrant; uiBoucle++) {
		if (ppARCSOMEntrant[uiBoucle] != nullptr) {
			delete ppARCSOMEntrant[uiBoucle];
		}
	}
	free(ppARCSOMEntrant);


	for (unsigned int uiBoucle2 = 0; uiBoucle2 < uiSOMNbSortant; uiBoucle2++) {
		if (ppARCSOMSortant[uiBoucle2] != nullptr) {
			delete ppARCSOMSortant[uiBoucle2];
		}
	}
	free(ppARCSOMSortant);

	iSOMNumber = SOMIn.iSOMNumber;
	uiSOMNbEntrant = SOMIn.uiSOMNbEntrant;
	uiSOMNbSortant = SOMIn.uiSOMNbSortant;

	ppARCSOMEntrant = (CArc**)malloc(uiSOMNbEntrant * sizeof(CArc*));
	ppARCSOMSortant = (CArc**)malloc(uiSOMNbSortant * sizeof(CArc*));

	if (ppARCSOMEntrant == nullptr || ppARCSOMSortant == nullptr) {
		throw CException(AllocationRatee);
	}

	for (unsigned int uiBoucle3 = 0; uiBoucle3 < uiSOMNbEntrant; uiBoucle3++) {
		ppARCSOMEntrant[uiBoucle3] = new CArc(*SOMIn.ppARCSOMEntrant[uiBoucle3]);
	}
	for (unsigned int uiBoucle4 = 0; uiBoucle4 < uiSOMNbSortant; uiBoucle4++) {
		ppARCSOMSortant[uiBoucle4] = new CArc(*SOMIn.ppARCSOMSortant[uiBoucle4]);
	}
	return *this;
}



// AUTRES METHODES


/*
Affiche les éléments d'un sommet dans la console
Entree : /
Precondition : /
Sortie : /
Postconditions :
	- Le sommet est affichée dans la console
*/
void CSommet::SOMAfficher()
{
	std::cout << "Destinations du sommet " << iSOMNumber << " : [";
	for (unsigned int uiBoucle = 0; uiBoucle < uiSOMNbSortant; uiBoucle++) {
		std::cout << "  " << ppARCSOMSortant[uiBoucle]->ARCLireDestination();
	}
	std::cout << "  ]\n";
}

