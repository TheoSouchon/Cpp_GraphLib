#include "CGraph.h"

/*
Constructeur par défault, initialise à non-orienté,le nombre de sommet à 0 et la liste de CSommet à 0
Entree : /
Preconditions : /
Sortie : /
Postconditions :
	- L'objet est initialisé
*/
CGraph::CGraph()
{
	bGRAOriente = false;
	uiGRANbSommets = 0;
	ppSOMGRASommets = nullptr;
}

/*
Constructeur de confort
Entree :
	- unsigned int : bOriente
Preconditions : /
Sortie : /
Postconditions :
	- L'objet est initialisé avec son type orientation
*/
CGraph::CGraph(bool bOriente)
{
	bGRAOriente = bOriente;
	uiGRANbSommets = 0;
	ppSOMGRASommets = nullptr;
}

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
CGraph::CGraph(bool bOriente, unsigned int* puiSommets, unsigned int uiNbSommets) {
	bGRAOriente = bOriente;
	for (unsigned int uiBoucle = 0; uiBoucle < uiNbSommets; uiBoucle++) {
		GRAAjouterSommet(puiSommets[uiBoucle]);
	}
}

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
CGraph::CGraph(bool bOriente, unsigned int* puiDeparts, unsigned int* puiArivees, unsigned int uiNbArcs) {
	bGRAOriente = bOriente;
	for (unsigned int uiBoucle = 0; uiBoucle < uiNbArcs; uiBoucle++) {
		if (!GRAContientSommet(puiDeparts[uiBoucle])) {
			GRAAjouterSommet(puiDeparts[uiBoucle]);
		}
		if (!GRAContientSommet(puiArivees[uiBoucle])) {
			GRAAjouterSommet(puiArivees[uiBoucle]);
		}
		GRAAjouterArc(puiDeparts[uiBoucle], puiArivees[uiBoucle]);
	}
}

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
CGraph::CGraph(bool bOriente, unsigned int* puiSommets, unsigned int uiNbSommets, unsigned int* puiDeparts, unsigned int* puiArivees, unsigned int uiNbArcs) {
	bGRAOriente = bOriente;
	unsigned int uiBoucle;
	for (uiBoucle = 0; uiBoucle < uiNbSommets; uiBoucle++) {
		GRAAjouterSommet(puiSommets[uiBoucle]);
	}
	for (uiBoucle = 0; uiBoucle < uiNbArcs; uiBoucle++) {
		GRAAjouterArc(puiDeparts[uiBoucle], puiArivees[uiBoucle]);
	}
}


/*
Constructeur de recopie
Entree : /
Preconditions : /
Sortie : /
Postconditions :
	- L'objet est initialisé et contient les mêmes valeurs que GRA1 OU
	- Erreur 2 : Pointeur_Null, l'allocation d'un pointeur a échouée
*/
CGraph::CGraph(const CGraph& GRA1)
{
	bGRAOriente = GRA1.bGRAOriente;
	ppSOMGRASommets = (CSommet**)malloc(GRA1.uiGRANbSommets *sizeof(CSommet*));
	if (ppSOMGRASommets == nullptr) {
		throw CException(AllocationRatee);
	}

	for (unsigned int uiBoucle = 0; uiBoucle < GRA1.uiGRANbSommets; uiBoucle++)
	{
		ppSOMGRASommets[uiBoucle] = new CSommet(*GRA1.ppSOMGRASommets[uiBoucle]);
	}
	uiGRANbSommets = GRA1.uiGRANbSommets;
}

/* Destructeur*/
CGraph::~CGraph() {
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommets; uiBoucle++) {
		if (ppSOMGRASommets[uiBoucle] != nullptr) {
			delete ppSOMGRASommets[uiBoucle];
		}
	}
	free(ppSOMGRASommets);
}


// ACCESSEURS

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
void CGraph::GRAAjouterSommet(unsigned int uiValeur)
{
	//si l'arc n'est pas déjà existant
	if (GRAContientSommet(uiValeur)) {
		throw CException(SommetDejaPresent);
	}
	ppSOMGRASommets = (CSommet**)realloc(ppSOMGRASommets, (uiGRANbSommets + 1) * sizeof(CSommet*));
	if (ppSOMGRASommets == nullptr) {
		throw CException(AllocationRatee);
	}
	uiGRANbSommets++;
	ppSOMGRASommets[uiGRANbSommets - 1] = new CSommet(uiValeur);
}

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
bool CGraph::GRAContientSommet(unsigned int uiSommet)
{
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommets; uiBoucle++)
	{
		if (ppSOMGRASommets[uiBoucle] != nullptr) {
			
			CSommet* test = ppSOMGRASommets[uiBoucle];
			int testi = ppSOMGRASommets[uiBoucle]->SOMLireValeur();
			if (testi == uiSommet) {
				return true;
			}
		}
	}
	return false;
}

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
void CGraph::GRAModifierSommet(unsigned int uiAncienneValeur, unsigned int uiNouvelleValeur)
{
	if (GRAContientSommet(uiNouvelleValeur)) {
		throw CException(SommetDejaPresent);
	}
	else if (!GRAContientSommet(uiAncienneValeur)) {
		throw CException(SommetInexistant);
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommets; uiBoucle++) {
		if (ppSOMGRASommets[uiBoucle] != nullptr) {
			if (ppSOMGRASommets[uiBoucle]->SOMLireValeur() == uiAncienneValeur) {
				ppSOMGRASommets[uiBoucle]->SOMModifierValeur(uiNouvelleValeur);

				//modifier tous les entrants avec la nouvelle valeur
				for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommets; uiBoucle++)
				{
					if (ppSOMGRASommets[uiBoucle] != nullptr) {
						if (ppSOMGRASommets[uiBoucle]->SOMContientArcSortant(uiAncienneValeur)) {
							ppSOMGRASommets[uiBoucle]->SOMModifierArcSortant(uiAncienneValeur, uiNouvelleValeur);
						}
					}
				}
				//modifier tous les sortants avec la nouvelle valeur
				for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommets; uiBoucle++)
				{
					if (ppSOMGRASommets[uiBoucle] != nullptr) {
						if (ppSOMGRASommets[uiBoucle]->SOMContientArcEntrant(uiAncienneValeur)) {
							ppSOMGRASommets[uiBoucle]->SOMModifierArcEntrant(uiAncienneValeur, uiNouvelleValeur);
						}
					}
				}
				return;
			}
		}
	}
}

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
void CGraph::GRASupprimerSommet(unsigned int uiValeur)
{
	if (!GRAContientSommet(uiValeur)) {
		throw CException(SommetInexistant);
	}
	unsigned int index = GRAIndiceSommet(uiValeur);
	delete ppSOMGRASommets[index];
	//déplacement des éléments
	for (unsigned int uiBoucle = index; uiBoucle < uiGRANbSommets - 1; uiBoucle++) {
		ppSOMGRASommets[uiBoucle] = ppSOMGRASommets[uiBoucle + 1];
	}

	CSommet** ppARCTmp = nullptr;
	//on ne peut pas realloc une taille de 0
	uiGRANbSommets--;
	if (uiGRANbSommets == 0) {
		free(ppSOMGRASommets);
	}
	else {
		//Réallocation
		ppARCTmp = (CSommet**)realloc(ppSOMGRASommets, (uiGRANbSommets) * sizeof(CSommet*));
		if (ppARCTmp == nullptr) {
			throw CException(AllocationRatee);
		}
	}
	ppSOMGRASommets = ppARCTmp;

	//supprimer tous les arcs entrant vers uiValeur
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommets; uiBoucle++)
	{
		if (ppSOMGRASommets[uiBoucle]!=nullptr) {
			if (ppSOMGRASommets[uiBoucle]->SOMContientArcSortant(uiValeur)) {
				ppSOMGRASommets[uiBoucle]->SOMSupprArcSortant(uiValeur);
			}
		}
	}
}

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
unsigned int CGraph::GRAIndiceSommet(unsigned int uiValeur)
{
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommets; uiBoucle++) {
		if (ppSOMGRASommets[uiBoucle] != nullptr) {
			if (ppSOMGRASommets[uiBoucle]->SOMLireValeur() == uiValeur) {
				return uiBoucle;
			}
		}
	}
	throw CException(SommetInexistant);
}


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
unsigned int* CGraph::GRALireValeursSommets() {
	unsigned int* puiValeursSommets = (unsigned int*) malloc (uiGRANbSommets * sizeof(unsigned int));
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommets; uiBoucle++) {
		puiValeursSommets[uiBoucle] = ppSOMGRASommets[uiBoucle]->SOMLireValeur();
	}
	return puiValeursSommets;
}



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
bool CGraph::GRAContientArc(unsigned int uiDepart, unsigned int uiArrivee) {
	unsigned int uiIndexDepart = GRAIndiceSommet(uiDepart);
	return ppSOMGRASommets[uiIndexDepart]->SOMContientArcSortant(uiArrivee);
}



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
void CGraph::GRAAjouterArc(unsigned int uiDepart, unsigned int uiArrivee)
{
	unsigned int uiIndexDepart = GRAIndiceSommet(uiDepart);
	unsigned int uiIndexArrivee = GRAIndiceSommet(uiArrivee);

	ppSOMGRASommets[uiIndexDepart]->SOMAjouterArcSortant(uiArrivee);
	ppSOMGRASommets[uiIndexArrivee]->SOMAjouterArcEntrant(uiDepart);

	//si le graph est non-orienté on supprime aussi l'arc en sens inverse
	if (!bGRAOriente && uiDepart != uiArrivee) {
		ppSOMGRASommets[uiIndexDepart]->SOMAjouterArcEntrant(uiArrivee);
		ppSOMGRASommets[uiIndexArrivee]->SOMAjouterArcSortant(uiDepart);
	}
}



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
void CGraph::GRAModifierDepartArc(unsigned int uiDepart, unsigned int uiArrivee, unsigned int uiNouvDepart)
{
	unsigned int uiIndexDepart = GRAIndiceSommet(uiDepart);
	unsigned int uiIndexArrivee = GRAIndiceSommet(uiArrivee);
	unsigned int uiIndexNouvDepart = GRAIndiceSommet(uiNouvDepart);
	
	// On supprime l'arc sortant dans le sommet de départ
	ppSOMGRASommets[uiIndexDepart]->SOMSupprArcSortant(uiArrivee);
	if (uiDepart != uiNouvDepart) {
		// On modifie l'arc entrant dans le sommet d'arrivée
		ppSOMGRASommets[uiIndexArrivee]->SOMModifierArcEntrant(uiDepart, uiNouvDepart);
	}
	// On ajoute l'arc sortant dans le nouveau sommet de départ
	ppSOMGRASommets[uiIndexNouvDepart]->SOMAjouterArcSortant(uiArrivee);
	
	// Le deuxième arc en sens inverse si non-orienté
	if (!bGRAOriente) {
		// On supprime l'arc entrant dans le sommet de départ
		ppSOMGRASommets[uiIndexDepart]->SOMSupprArcEntrant(uiArrivee);

		if (uiDepart == uiNouvDepart ||uiArrivee == uiNouvDepart) {
			ppSOMGRASommets[uiIndexArrivee]->SOMSupprArcSortant(uiDepart);
		}
		else {
			// On modifie l'arc sortant dans le sommet d'arrivée
			ppSOMGRASommets[uiIndexArrivee]->SOMModifierArcSortant(uiDepart, uiNouvDepart);
			// On ajoute l'arc entrant dans le nouveau sommet de départ
			ppSOMGRASommets[uiIndexNouvDepart]->SOMAjouterArcEntrant(uiArrivee);
		}
	}
}

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
void CGraph::GRAModifierArriveeArc(unsigned int uiDepart, unsigned int uiArrivee, unsigned int uiNouvArrivee)
{
	unsigned int uiIndexDepart = GRAIndiceSommet(uiDepart);
	unsigned int uiIndexArrivee = GRAIndiceSommet(uiArrivee);
	unsigned uiIndexNouvArrivee = GRAIndiceSommet(uiNouvArrivee);

	// On supprime l'arc entrant dans le sommet d'arrivee
	ppSOMGRASommets[uiIndexArrivee]->SOMSupprArcEntrant(uiDepart);
	if (uiArrivee != uiNouvArrivee) {
		// On modifie l'arc sortant dans le sommet de départ
		ppSOMGRASommets[uiIndexDepart]->SOMModifierArcSortant(uiArrivee, uiNouvArrivee);
	}
	// On ajoute l'arc entrant dans le nouveau sommet d'arrivée
	ppSOMGRASommets[uiIndexNouvArrivee]->SOMAjouterArcEntrant(uiDepart);

	// Le deuxième arc en sens inverse si non-orienté
	if (!bGRAOriente) {
		// On supprime l'arc sortant dans le sommet d'arrivee
		ppSOMGRASommets[uiIndexArrivee]->SOMSupprArcSortant(uiDepart);
		if (uiDepart == uiNouvArrivee || uiArrivee == uiNouvArrivee) {
			ppSOMGRASommets[uiIndexDepart]->SOMSupprArcEntrant(uiArrivee);

		}
		else {
			// On modifie l'arc entrant dans le sommet de depart
			ppSOMGRASommets[uiIndexDepart]->SOMModifierArcEntrant(uiArrivee, uiNouvArrivee);
			// On ajoute l'arc sortant dans le nouveau sommet d'arrivee
			ppSOMGRASommets[uiIndexNouvArrivee]->SOMAjouterArcSortant(uiDepart);
		}
	}
}

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
void CGraph::GRASupprimerArc(unsigned int uiDepart, unsigned int uiArrivee)
{
	unsigned int uiIndexDepart = GRAIndiceSommet(uiDepart);
	unsigned int uiIndexArrivee = GRAIndiceSommet(uiArrivee);
	
	ppSOMGRASommets[uiIndexDepart]->SOMSupprArcSortant(uiArrivee);
	ppSOMGRASommets[uiIndexArrivee]->SOMSupprArcEntrant(uiDepart);

	//si le graph est non-orienté on supprime aussi l'arc en sens inverse
	if (!bGRAOriente && uiDepart != uiArrivee) {
		ppSOMGRASommets[uiIndexDepart]->SOMSupprArcEntrant(uiArrivee);
		ppSOMGRASommets[uiIndexArrivee]->SOMSupprArcSortant(uiDepart);
	}
}


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
void CGraph::GRAInverserArc(unsigned int uiDepart, unsigned int uiArrivee) {
	GRASupprimerArc(uiDepart, uiArrivee);
	GRAAjouterArc(uiArrivee, uiDepart);
}





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
CGraph CGraph::operator=(CGraph GRA1) {
	// Destruction de l'objet courrant
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommets; uiBoucle++) {
		if (ppSOMGRASommets[uiBoucle] != nullptr) {
			delete ppSOMGRASommets[uiBoucle];
		}
	}
	free(ppSOMGRASommets);
	// Recopie de GRA1 dans l'objet courrant
	bGRAOriente = GRA1.bGRAOriente;
	ppSOMGRASommets = (CSommet**)malloc(GRA1.uiGRANbSommets * sizeof(CSommet*));
	if (ppSOMGRASommets == nullptr) {
		throw CException(AllocationRatee);
	}

	for (unsigned int uiBoucle = 0; uiBoucle < GRA1.uiGRANbSommets; uiBoucle++)
	{
		ppSOMGRASommets[uiBoucle] = new CSommet(*GRA1.ppSOMGRASommets[uiBoucle]);
	}
	uiGRANbSommets = GRA1.uiGRANbSommets;
	return *this;
}


/*
Affiche le graph dans la console
Entree : /
Precondition : /
Sortie : /
Postcondition :
	- Le graph est affiché dans la console
*/
void CGraph::GRAAfficher() {
	if (bGRAOriente) {
		std::cout << "Le graphique est oriente, voici la liste de ses sommets et de leurs destinations :\n";
	}
	else {
		std::cout << "Le graphique est non oriente, voici la liste de ses sommets et de leurs destinations :\n";
	}
	for (unsigned int uiBoucle = 0; uiBoucle < uiGRANbSommets; uiBoucle++) {
		ppSOMGRASommets[uiBoucle]->SOMAfficher();
	}
}

