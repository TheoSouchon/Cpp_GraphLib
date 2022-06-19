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
	Constructeur par défault, initialise à non-orienté,le nombre de sommet à 0 et la liste de CSommet à 0
	Entree : /
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialisé
	*/
	CGraph();

	/*
	Constructeur de confort, crée un arc orienté ou non selon la valeur du paramètre passé
	Entree :
		- bOriente : true si le graph est orienté, false sinon
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialisé avec son type d'orientation
	*/
	CGraph(bool bOriente);

	/*
	Constructeur de confort, crée un arc orienté ou non avec les valeurs de sommets passés en paramètre
	Entree :
		- bOriente : true si le graph est orienté, false sinon
		- puiSommets : liste des valeurs des sommets à ajouter
		- uiNbSommets : nombre de sommets de la liste des sommets
	Preconditions : 
		- Il y a au moins uiNbSommets éléments dans puiSommets
	Sortie : /
	Postconditions :
		- L'objet est initialisé avec son type d'orientation et les sommets passés en paramètre OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 4 : SommetDejaPresent
	*/
	CGraph(bool bOriente, unsigned int* puiSommets, unsigned int uiNbSommets);

	/*
	Constructeur de confort, crée un arc orienté ou non avec les valeurs d'arcs passés en paramètre
	Entree :
		- bOriente : true si le graph est orienté, false sinon
		- puiDeparts : liste des valeurs de départ des arcs à ajouter
		- puiArivees : liste des valeurs d'arrivée des arcs à ajouter
		- uiNbArcs : nombre de valeurs des listes d'arcs
	Preconditions : 
		- Il y a au moins uiNbArcs éléments dans puiDeparts et puiArivees
	Sortie : /
	Postconditions :
		- L'objet est initialisé avec son type d'orientation, les sommets et les arcs passés en paramètre OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 2 : ArcDejaPresent
	*/
	CGraph(bool bOriente, unsigned int* puiDeparts, unsigned int* puiArivees, unsigned int uiNbArcs);

	/*
	Constructeur de confort, crée un arc orienté ou non avec les valeurs de sommets et les valeurs d'arcs passés en paramètre
	Entree :
		- bOriente : true si le graph est orienté, false sinon
		- puiSommets : liste des valeurs des sommets à ajouter
		- uiNbSommets : nombre de valeurs de la liste des sommets
		- puiDeparts : liste des valeurs de départ des arcs à ajouter
		- puiArivees : liste des valeurs d'arrivée des arcs à ajouter
		- uiNbArcs : nombre de valeurs des listes d'arcs
	Preconditions : 
		- Il y a au moins uiNbSommets éléments dans puiSommets ET
		- Il y a au moins uiNbArcs éléments dans puiDeparts et puiArivees
	Sortie : /
	Postconditions :
		- L'objet est initialisé avec son type d'orientation, les sommets et les arcs passés en paramètre OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 2 : ArcDejaPresent OU
		- Erreur 4 : SommetDejaPresent OU
		- Erreur 5 : SommetInexistant
	*/
	CGraph(bool bOriente, unsigned int* puiSommets, unsigned int uiNbSommets, unsigned int* puiDeparts, unsigned int* puiArivees, unsigned int uiNbArcs);

	/*
	Constructeur de recopie
	Entree : 
		- GRA1 : IN, Graph à recopier
	Preconditions : /
	Sortie : /
	Postconditions :
		- L'objet est initialisé et contient les mêmes valeurs que GRA1 OU
		- Erreur 1 : AllocationRatee, l'allocation d'un pointeur a échouée
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
		- l'attribut bGRAOriente est retourné
	*/
	bool GRAEstOriente() { return bGRAOriente; }


	// Accesseurs des sommets

	unsigned int GRALireNbSommets() { return uiGRANbSommets; }

	/*
	Ajoute un sommet au graph
	Entree :
		- uiEntrant : Valeur du sommet à ajouter
	Precondition : /
	Sortie : /
	Postconditions :
		- Le sommet a bien été ajouté OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 4 : SommetDejaPresent
	*/
	void GRAAjouterSommet(unsigned int uiValeur);

	/*
	Verifie si le sommet est déjà présent
	Entree :
		- uiSommet : Valeur du sommet
	Precondition : /
	Sortie :
		- bool : true si le sommet est déjà présent, false sinon
	Postconditions :
		- bool envoyé
	*/
	bool GRAContientSommet(unsigned int uiSommet);

	/*
	Modifie la valeur d'un sommet
	Entree :
		- uiAncienneValeur : numéro du sommet à modifier
		- uiNouvelleValeur : nouveau numéro du sommet
	Precondition : /
	Sortie : /
	Postconditions :
		- Le sommet à été modifié OU
		- Erreur 4 : SommetDejaPresent OU
		- Erreur 5 : SommetInexistant
	*/
	void GRAModifierSommet(unsigned int uiAncienneValeur,unsigned int uiNouvelleValeur);

	/*
	Supprimer un sommet
	Entree :
		- uiValeur : Valeur du sommet à supprimer
	Precondition : /
	Sortie : /
	Postconditions :
		- Le sommet a été supprimé OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 5 : SommetInexistant
	*/
	void GRASupprimerSommet(unsigned int uiValeur);


	/*
	Cherche l'indice d'un sommet
	Entree :
		- uiValeur : numéro du sommet à chercher
	Precondition : /
	Sortie :
		- unsigned int : l'indice du sommet cherché
	Postconditions :
		- L'indice du sommet a été retourné OU
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
		- La liste des valeurs des sommets est renvoyée OU
		- Erreur 1 : AllocationRatee
	*/
	unsigned int* GRALireValeursSommets();


	// Accesseurs des arcs

	/*
	Regarde si le graph contient l'arc spécifié
	Entree :
		- uiDepart : IN, Valeur du sommet de départ
		- uiArrivee : IN, Valeur du sommet d'arrivée
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a bien été ajouté OU
		- Erreur 5 : SommetInexistant
	*/
	bool GRAContientArc(unsigned int uiDepart, unsigned int uiArrivee);


	/*
	Ajouter un arc
	Entree :
		- uiDepart : IN, Valeur du sommet de départ
		- uiArrivee : IN, Valeur du sommet d'arrivée
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a bien été ajouté OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 2 : ArcDejaPresent OU
		- Erreur 5 : SommetInexistant
	*/
	void GRAAjouterArc(unsigned int uiDepart, unsigned int uiArrivee);


	/*
	Modifier le départ d'un arc
	Entree :
		- uiDepart : Valeur du sommet de départ inital
		- uiArrivee : Valeur du sommet d'arrivée
		- uiNouvDepart : Valeur du nouveau sommet de départ
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a bien été modifié OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 2 : ArcDejaPresent OU
		- Erreur 3 : ArcInexistant OU
		- Erreur 5 : SommetInexistant
	*/
	void GRAModifierDepartArc(unsigned int uiDepart, unsigned int uiArrivee, unsigned int uiNouvDepart);

	/*
	Modifier l'arrivee d'un arc
	Entree :
		- uiDepart : Valeur du sommet de départ inital
		- uiArrivee : Valeur du sommet d'arrivée
		- uiNouvArrivee : Valeur du nouveau sommet d'arrivée
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a bien été modifié OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 2 : ArcDejaPresent OU
		- Erreur 3 : ArcInexistant OU
		- Erreur 5 : SommetInexistant
	*/
	void GRAModifierArriveeArc(unsigned int uiDepart, unsigned int uiArrivee, unsigned int uiNouvArrivee);

	/*
	Supprime un arc
	Entree :
		- uiDepart : départ de l'arc à supprimer
		- uiArrivee : destination de l'arc à supprimer
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a été modifié OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 3 : ArcInexistant
	*/
	void GRASupprimerArc(unsigned int uiDepart,unsigned int uiArrivee);


	/*
	Inverse un arc
	Entree :
		- uiDepart : départ de l'arc à inverser
		- uiArrivee : destination de l'arc à inverser
	Precondition : /
	Sortie : /
	Postconditions :
		- L'arc a été modifié OU
		- Erreur 1 : AllocationRatee OU
		- Erreur 2 : ArcDejaPresent OU
		- Erreur 3 : ArcInexistant OU
		- Erreur 5 : SommetInexistant
	*/
	void GRAInverserArc(unsigned int uiDepart, unsigned int uiArrivee);


	// OPERATEURS

	/*
	Opérateur = entre 2 graphs
	Entree :
		- GRA1 : IN, Graph à recopier
	Preconditions : /
	Sortie : 
		- CGraph : une copie de l'objet courrant contenant les mêmes valeurs que GRA1
	Postconditions :
		- L'objet est initialisé, renvoyé et contient les mêmes valeurs que GRA1 OU
		- Erreur 1 : AllocationRatee, l'allocation d'un pointeur a échouée
	*/
	CGraph operator=(CGraph GRA1);


	// AUTRES METHODES

	/*
	Affiche le graph dans la console
	Entree : /
	Precondition : /
	Sortie : /
	Postcondition :
		- Le graph est affiché dans la console
	*/
	void GRAAfficher();

};

