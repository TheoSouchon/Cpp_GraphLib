#include <iostream>
#include "CSommet.h"
#include "CGraph.h"
#include "CParseurGraph.h"
#include "COperationsGraph.h"


int main(int argc, char* argv[])
{

    if (argc < 2) {
        printf("Aucun chemin de fichier passe en paramètre, fin du programme\n\n");
        return 0;
    }

    try {
        CParseurGraph PAR1(argv[1]);
        CGraph GRA1 = PAR1.PARConstruireGraph();
        GRA1.GRAAfficher();
        COperationsGraph OPG1;
        CGraph GRAInverse = OPG1.OPGInverserGraph(GRA1);
        GRAInverse.GRAAfficher();

    }
    catch (CException EXCE) {
        std::cout << "\n\nErreur " << EXCE.EXCGetValeur() << "\n\n\n";
    }

}