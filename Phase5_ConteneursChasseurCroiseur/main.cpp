#include <iostream>
#include "lib_chasseur.h"

using namespace std;

int main()
{
    Chasseur xwing ;
    Vaisseau faucon ;

    xwing.m_puissance_feu_torpilles = 100 ;
    xwing.m_vaisseau.m_resistance_coque = 0 ;

    AffecterClasse(&faucon, "Vaisseau") ;
    AffecterNom(&faucon, "faucon") ;
    AffecterResistanceCoque(&faucon, 0) ;

    AffecterClasse(&(xwing.m_vaisseau), "Chasseur") ;
    AffecterNom(&(xwing.m_vaisseau), "xwing") ;

    AfficherCarac(&faucon) ;

    AfficherCarac(&xwing) ;

    return 0;
}
