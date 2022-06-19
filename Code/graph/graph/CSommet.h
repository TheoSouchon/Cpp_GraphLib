#pragma once
#include "CArc.h"
#include "CException.h"
#define AllocationRatee 1
#define ArcDejaPresent 2
#define ArcInexistant 3

class CSommet
{
private :
	int iSOMNumber;
	unsigned int uiSOMNbEntrant;
	unsigned int uiSOMNbSortant;
	CArc** ppARCSOMEntrant;
	CArc** ppARCSOMSortant;


public:


	// CONSTRUCTEURS ET DESTRUCTEUR


	/*
	Constructeur par défault, initialise le numéro à -1 et les pointeurs sur les arcs à nullptr
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialisé
	*/
	CSommet();

	/*
	Constructeur de confort, initialise le numéro à celui passé et les pointeurs sur les arcs à nullptr
	Entree :
		- unsigned int : iSOMNumber
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialisé
	*/
	CSommet(unsigned int iSOMNumber);


	/*
	Constructeur de recopie
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialisé et contient les mêmes valeurs que SOM1 OU
		- Erreur 2 : Pointeur_Null, l'allocation d'un pointeur a échouée
	*/
	CSommet(const CSommet &SOM1);


	/* Destructeur */
	~CSommet();



	// GETTEURS ET SETTEURS


	/*
	Accesseur en lecture de iSOMNumber
	Entree : /
	Preconditions : /
	Sortie :
		- int : iSOMNumber
	Postconditions :
		- l'attribut iSOMNumber est retourné
	*/
	int SOMLireValeur() const {	return iSOMNumber;	};


	/*
	Accesseur en lecture de uiSOMNbEntrant
	Entree : /
	Preconditions : /
	Sortie :
		- unsigned int : uiSOMNbEntrant
	Postconditions :
		- l'attribut uiSOMNbEntrant est retourné
	*/
	unsigned int SOMLireNbEntrant() const {	return uiSOMNbEntrant; };


	/*
	Accesseur en lecture de uiSOMNbSortant
	Entree : /
	Preconditions : /
	Sortie :
		- unsigned int : uiSOMNbSortant
	Postconditions :
		- l'attribut uiSOMNbSortant est retourné
	*/
	unsigned int SOMLireNbSortant() const {	return uiSOMNbSortant;	};


	/*
	Accesseur en écriture de iSOMNumber
	Entree : 
		- unsigned int : uiValeur
	Preconditions : /
	Sortie : /
	Postconditions :
		- l'attribut iSOMNumber est modifié
	*/
	void SOMModifierValeur(unsigned int uiValeur) {	iSOMNumber = uiValeur;	}


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
	void SOMAjouterArcEntrant(unsigned int uiEntrant);


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
	bool SOMContientArcEntrant(unsigned int uiEntrant);


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
	void SOMModifierArcEntrant(unsigned int uiDestination, unsigned int uiNouvelleDestination);

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
	void SOMSupprArcEntrant(unsigned int uiDestination);
	

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
	unsigned int SOMIndiceArcEntrant(unsigned int uiDestination);


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
	void SOMAjouterArcSortant(unsigned int uiSortant);


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
	bool SOMContientArcSortant(unsigned int uiSortant);


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
	void SOMModifierArcSortant(unsigned int uiDestination, unsigned int uiNouvelleDestination);


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
	void SOMSupprArcSortant(unsigned int uiDestination);



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
	unsigned int SOMIndiceArcSortant(unsigned int uiDestination);



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
	CSommet operator=(CSommet SOMIn);


	/*
	Affiche les éléments d'un sommet dans la console
	Entree : /
	Precondition : /
	Sortie : /
	Postconditions :
		- Le sommet est affichée dans la console
	*/
	void SOMAfficher();
};

