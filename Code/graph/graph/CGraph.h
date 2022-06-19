#pragma once
#include "CSommet.h"
#include <iostream>
#define SommetDejaPresent 4
#define SommetInexistant 5

class CGraph
{
private:
	bool bGRAOriente;
	unsigned int uiGRANbSommets;
	CSommet** ppSOMGRASommets;

public:
	/*
	Constructeur par d�fault, initialise � non-orient�,le nombre de sommet � 0 et la liste de CSommet � 0
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialis�
	*/
	CGraph();

	/*
	Constructeur de confort, cr�e un arc orient� ou non selon la valeur du param�tre pass�
	Entree :
		- bOriente : true si le graph est orient�, false sinon
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialis� avec son type d'orientation
	*/
	CGraph(bool bOriente);

	/*
	Constructeur de confort, cr�e un arc orient� ou non avec les valeurs de sommets pass�s en param�tre
	Entree :
		- bOriente : true si le graph est orient�, false sinon
		- puiSommets : liste des valeurs des sommets � ajouter
		- uiNbSommets : nombre de sommets de la liste des sommets
	Preconditions : 
		- Il y a au moins uiNbSommets �l�ments dans puiSommets
	Sortie : /
	Postconditions :
		- L'objet est initialis� avec son type d'orientation et les sommets pass�s en param�tre OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 4 : SommetDejaPresent
	*/
	CGraph(bool bOriente, unsigned int* puiSommets, unsigned int uiNbSommets);

	/*
	Constructeur de confort, cr�e un arc orient� ou non avec les valeurs d'arcs pass�s en param�tre
	Entree :
		- bOriente : true si le graph est orient�, false sinon
		- puiDeparts : liste des valeurs de d�part des arcs � ajouter
		- puiArivees : liste des valeurs d'arriv�e des arcs � ajouter
		- uiNbArcs : nombre de valeurs des listes d'arcs
	Preconditions : 
		- Il y a au moins uiNbArcs �l�ments dans puiDeparts et puiArivees
	Sortie : /
	Postconditions :
		- L'objet est initialis� avec son type d'orientation, les sommets et les arcs pass�s en param�tre OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 2 : ArcDejaPresent
	*/
	CGraph(bool bOriente, unsigned int* puiDeparts, unsigned int* puiArivees, unsigned int uiNbArcs);

	/*
	Constructeur de confort, cr�e un arc orient� ou non avec les valeurs de sommets et les valeurs d'arcs pass�s en param�tre
	Entree :
		- bOriente : true si le graph est orient�, false sinon
		- puiSommets : liste des valeurs des sommets � ajouter
		- uiNbSommets : nombre de valeurs de la liste des sommets
		- puiDeparts : liste des valeurs de d�part des arcs � ajouter
		- puiArivees : liste des valeurs d'arriv�e des arcs � ajouter
		- uiNbArcs : nombre de valeurs des listes d'arcs
	Preconditions : 
		- Il y a au moins uiNbSommets �l�ments dans puiSommets ET
		- Il y a au moins uiNbArcs �l�ments dans puiDeparts et puiArivees
	Sortie : /
	Postconditions :
		- L'objet est initialis� avec son type d'orientation, les sommets et les arcs pass�s en param�tre OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 2 : ArcDejaPresent OU
		- Erreur 4 : SommetDejaPresent OU
		- Erreur 5 : SommetInexistant
	*/
	CGraph(bool bOriente, unsigned int* puiSommets, unsigned int uiNbSommets, unsigned int* puiDeparts, unsigned int* puiArivees, unsigned int uiNbArcs);

	/*
	Constructeur de recopie
	Entree : 
		- GRA1 : IN, Graph � recopier
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialis� et contient les m�mes valeurs que GRA1 OU
		- Erreur 1 : AllocationRatee, l'allocation d'un pointeur a �chou�e
	*/
	CGraph(const CGraph &GRA1);


	/* Destructeur*/
	~CGraph();


	// ACCESSEURS

	/*
	Accesseur en lecture de bGRAOriente
	Entree : /
	Preconditions : /
	Sortie :
		- bool : bGRAOriente
	Postconditions :
		- l'attribut bGRAOriente est retourn�
	*/
	bool GRAEstOriente() { return bGRAOriente; }


	// Accesseurs des sommets

	unsigned int GRALireNbSommets() { return uiGRANbSommets; }

	/*
	Ajoute un sommet au graph
	Entree :
		- uiEntrant : Valeur du sommet � ajouter
	Precondition : /
	Sortie : /
	Postconditions :
		- Le sommet a bien �t� ajout� OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 4 : SommetDejaPresent
	*/
	void GRAAjouterSommet(unsigned int uiValeur);

	/*
	Verifie si le sommet est d�j� pr�sent
	Entree :
		- uiSommet : Valeur du sommet
	Precondition : /
	Sortie :
		- bool : true si le sommet est d�j� pr�sent, false sinon
	Postconditions :
		- bool envoy�
	*/
	bool GRAContientSommet(unsigned int uiSommet);

	/*
	Modifie la valeur d'un sommet
	Entree :
		- uiAncienneValeur : num�ro du sommet � modifier
		- uiNouvelleValeur : nouveau num�ro du sommet
	Precondition : /
	Sortie : /
	Postconditions :
		- Le sommet � �t� modifi� OU
		- Erreur 4 : SommetDejaPresent OU
		- Erreur 5 : SommetInexistant
	*/
	void GRAModifierSommet(unsigned int uiAncienneValeur,unsigned int uiNouvelleValeur);

	/*
	Supprimer un sommet
	Entree :
		- uiValeur : Valeur du sommet � supprimer
	Precondition : /
	Sortie : /
	Postconditions :
		- Le sommet a �t� supprim� OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 5 : SommetInexistant
	*/
	void GRASupprimerSommet(unsigned int uiValeur);


	/*
	Cherche l'indice d'un sommet
	Entree :
		- uiValeur : num�ro du sommet � chercher
	Precondition : /
	Sortie :
		- unsigned int : l'indice du sommet cherch�
	Postconditions :
		- L'indice du sommet a �t� retourn� OU
		- Erreur 5 : SommetInexistant
	*/
	unsigned int GRAIndiceSommet(unsigned int uiValeur);


	/*
	Renvoie la liste des valeurs des sommets
	Entree : /
	Precondition : /
	Sortie :
		- unsigned int* : la liste des valeurs des sommets
	Postconditions :
		- La liste des valeurs des sommets est renvoy�e OU
		- Erreur 1 : AllocationRatee
	*/
	unsigned int* GRALireValeursSommets();


	// Accesseurs des arcs

	/*
	Regarde si le graph contient l'arc sp�cifi�
	Entree :
		- uiDepart : IN, Valeur du sommet de d�part
		- uiArrivee : IN, Valeur du sommet d'arriv�e
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a bien �t� ajout� OU
		- Erreur 5 : SommetInexistant
	*/
	bool GRAContientArc(unsigned int uiDepart, unsigned int uiArrivee);


	/*
	Ajouter un arc
	Entree :
		- uiDepart : IN, Valeur du sommet de d�part
		- uiArrivee : IN, Valeur du sommet d'arriv�e
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a bien �t� ajout� OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 2 : ArcDejaPresent OU
		- Erreur 5 : SommetInexistant
	*/
	void GRAAjouterArc(unsigned int uiDepart, unsigned int uiArrivee);


	/*
	Modifier le d�part d'un arc
	Entree :
		- uiDepart : Valeur du sommet de d�part inital
		- uiArrivee : Valeur du sommet d'arriv�e
		- uiNouvDepart : Valeur du nouveau sommet de d�part
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a bien �t� modifi� OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 2 : ArcDejaPresent OU
		- Erreur 3 : ArcInexistant OU
		- Erreur 5 : SommetInexistant
	*/
	void GRAModifierDepartArc(unsigned int uiDepart, unsigned int uiArrivee, unsigned int uiNouvDepart);

	/*
	Modifier l'arrivee d'un arc
	Entree :
		- uiDepart : Valeur du sommet de d�part inital
		- uiArrivee : Valeur du sommet d'arriv�e
		- uiNouvArrivee : Valeur du nouveau sommet d'arriv�e
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a bien �t� modifi� OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 2 : ArcDejaPresent OU
		- Erreur 3 : ArcInexistant OU
		- Erreur 5 : SommetInexistant
	*/
	void GRAModifierArriveeArc(unsigned int uiDepart, unsigned int uiArrivee, unsigned int uiNouvArrivee);

	/*
	Supprime un arc
	Entree :
		- uiDepart : d�part de l'arc � supprimer
		- uiArrivee : destination de l'arc � supprimer
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a �t� modifi� OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 3 : ArcInexistant
	*/
	void GRASupprimerArc(unsigned int uiDepart,unsigned int uiArrivee);


	/*
	Inverse un arc
	Entree :
		- uiDepart : d�part de l'arc � inverser
		- uiArrivee : destination de l'arc � inverser
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a �t� modifi� OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 2 : ArcDejaPresent OU
		- Erreur 3 : ArcInexistant OU
		- Erreur 5 : SommetInexistant
	*/
	void GRAInverserArc(unsigned int uiDepart, unsigned int uiArrivee);


	// OPERATEURS

	/*
	Op�rateur = entre 2 graphs
	Entree :
		- GRA1 : IN, Graph � recopier
	Preconditions : /
	Sortie : 
		- CGraph : une copie de l'objet courrant contenant les m�mes valeurs que GRA1
	Postconditions :
		- L'objet est initialis�, renvoy� et contient les m�mes valeurs que GRA1 OU
		- Erreur 1 : AllocationRatee, l'allocation d'un pointeur a �chou�e
	*/
	CGraph operator=(CGraph GRA1);


	// AUTRES METHODES

	/*
	Affiche le graph dans la console
	Entree : /
	Precondition : /
	Sortie : /
	Postcondition :
		- Le graph est affich� dans la console
	*/
	void GRAAfficher();

};

