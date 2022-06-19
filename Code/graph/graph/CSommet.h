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
	Constructeur par d�fault, initialise le num�ro � -1 et les pointeurs sur les arcs � nullptr
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialis�
	*/
	CSommet();

	/*
	Constructeur de confort, initialise le num�ro � celui pass� et les pointeurs sur les arcs � nullptr
	Entree :
		- unsigned int : iSOMNumber
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialis�
	*/
	CSommet(unsigned int iSOMNumber);


	/*
	Constructeur de recopie
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialis� et contient les m�mes valeurs que SOM1 OU
		- Erreur 2 : Pointeur_Null, l'allocation d'un pointeur a �chou�e
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
		- l'attribut iSOMNumber est retourn�
	*/
	int SOMLireValeur() const {	return iSOMNumber;	};


	/*
	Accesseur en lecture de uiSOMNbEntrant
	Entree : /
	Preconditions : /
	Sortie :
		- unsigned int : uiSOMNbEntrant
	Postconditions :
		- l'attribut uiSOMNbEntrant est retourn�
	*/
	unsigned int SOMLireNbEntrant() const {	return uiSOMNbEntrant; };


	/*
	Accesseur en lecture de uiSOMNbSortant
	Entree : /
	Preconditions : /
	Sortie :
		- unsigned int : uiSOMNbSortant
	Postconditions :
		- l'attribut uiSOMNbSortant est retourn�
	*/
	unsigned int SOMLireNbSortant() const {	return uiSOMNbSortant;	};


	/*
	Accesseur en �criture de iSOMNumber
	Entree : 
		- unsigned int : uiValeur
	Preconditions : /
	Sortie : /
	Postconditions :
		- l'attribut iSOMNumber est modifi�
	*/
	void SOMModifierValeur(unsigned int uiValeur) {	iSOMNumber = uiValeur;	}


	/*
	Ajouter un arc entrant
	Entree :
		- uiEntrant : Num�ro du sommet entrant
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc entrant a bien �t� ajout� OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 2 : ArcDejaPresent
	*/
	void SOMAjouterArcEntrant(unsigned int uiEntrant);


	/*
	Verifie si l'arc entrant est pr�sent dans la liste des sommets entrants
	Entree :
		- uiEntrant : Nom du sommet entrant
	Precondition : /
	Sortie :
		- bool : true si l'arc est d�j� pr�sent, false sinon
	Postconditions :
		- bool retourn�
	*/
	bool SOMContientArcEntrant(unsigned int uiEntrant);


	/*
	Modifie un arc entrant
	Entree :
		- uiDestination : destination de l'arc � modifier
		- uiNouvelleDestination : nouveau num�ro de l'arc
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a �t� modifi� OU
		- Erreur 2 : ArcDejaPresent OU
		- Erreur 3 : ArcInexistant
	*/
	void SOMModifierArcEntrant(unsigned int uiDestination, unsigned int uiNouvelleDestination);

	/*
	Supprime un arc entrant
	Entree :
		- uiDestination : destination de l'arc � supprimer
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a �t� modifi� OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 3 : ArcInexistant
	*/
	void SOMSupprArcEntrant(unsigned int uiDestination);
	

	/*
	Cherche l'indice d'un arc entrant
	Entree :
		- uiDestination : num�ro de l'arc � chercher
	Precondition : /
	Sortie :
		- unsigned int : l'indice de l'�l�ment cherch�
	Postconditions :
		- L'indice a �t� retourn� OU
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
		- L'arc sortant a bien �t� ajout� OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 2 : ArcDejaPresent
	*/
	void SOMAjouterArcSortant(unsigned int uiSortant);


	/*
	Verifie si l'arc est d�j� pr�sent dans la liste des arcs sortants
	Entree :
		- uiSortant : Nom du sommet sortant
	Precondition : /
	Sortie :
		- bool : true si l'arc est d�j� pr�sent, false sinon
	Postconditions :
		- bool renvoy�
	*/
	bool SOMContientArcSortant(unsigned int uiSortant);


	/*
	Modifie un arc sortant
	Entree :
		- uiDestiant : num�ro de l'arc � modifier
		- uiNouvelleDestination : nouveau num�ro de l'arc
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a �t� modifi� OU
		- Erreur 2 : ArcDejaPresent OU
		- Erreur 3 : ArcInexistant
	*/
	void SOMModifierArcSortant(unsigned int uiDestination, unsigned int uiNouvelleDestination);


	/*
	Supprime un arc sortant
	Entree :
		- uiDestination : destination de l'arc � supprimer
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a �t� supprim� OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 3 : ArcInexistant
	*/
	void SOMSupprArcSortant(unsigned int uiDestination);



	/*
	Cherche l'indice d'un arc sortant
	Entree :
		- uiDestination : num�ro de l'arc � chercher
	Precondition : /
	Sortie : 
		- unsigned int : l'indice de l'�l�ment cherch�
	Postconditions :
		- L'indice a �t� retourn� OU
		- Erreur 3 : ArcInexistant
	*/
	unsigned int SOMIndiceArcSortant(unsigned int uiDestination);



	/*
	Op�rateur = entre 2 sommets
	Entree :
		- SOMIn : Sommet contenant les informations � copier
	Precondition : /
	Sortie :
		- CSommet : Une copie de l'objet courrant qui contient les valeurs de SOMIn
	Postconditions :
		- Le sommet en entr�e a bien �t� recopi� et une copie a �t� renvoy�e OU
		- Erreur 1 : AllocationRatee
	*/
	CSommet operator=(CSommet SOMIn);


	/*
	Affiche les �l�ments d'un sommet dans la console
	Entree : /
	Precondition : /
	Sortie : /
	Postconditions :
		- Le sommet est affich�e dans la console
	*/
	void SOMAfficher();
};

