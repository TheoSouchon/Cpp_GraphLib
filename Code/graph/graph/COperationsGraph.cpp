#include "COperationsGraph.h"


CGraph COperationsGraph::OPGInverserGraph(CGraph GRA1) {
	if (!GRA1.GRAEstOriente()) {
		return GRA1;
	}
	// On crée un nouveau graph qui contiendra le graph inversé
	CGraph GRAInverse = new CGraph(true);

	unsigned int* puiValeursSommets = GRA1.GRALireValeursSommets();
	unsigned int uiBoucle, uiBoucle2;

	// On ajoute les sommets
	for (uiBoucle = 0; uiBoucle < GRA1.GRALireNbSommets(); uiBoucle++) {
		GRAInverse.GRAAjouterSommet(puiValeursSommets[uiBoucle]);
	}
	// On ajoute les arcs
	for (uiBoucle = 0; uiBoucle < GRA1.GRALireNbSommets(); uiBoucle++) {
		for (uiBoucle2 = 0; uiBoucle2 < GRA1.GRALireNbSommets(); uiBoucle2++) {
			if (GRA1.GRAContientArc(puiValeursSommets[uiBoucle], puiValeursSommets[uiBoucle2])) {
				GRAInverse.GRAAjouterArc(puiValeursSommets[uiBoucle2], puiValeursSommets[uiBoucle]);
			}
		}
	}
	free(puiValeursSommets);
	return GRAInverse;

}