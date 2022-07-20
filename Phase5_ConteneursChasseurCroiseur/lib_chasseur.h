#ifndef LIB_CHASSEUR_H_INCLUDED
#define LIB_CHASSEUR_H_INCLUDED

#include "lib_vaisseau.h"

struct Chasseur {
    Vaisseau    m_vaisseau                ;
    int         m_puissance_feu_torpilles ;
} ;

void AfficherCarac (const Chasseur*) ;

#endif // LIB_CHASSEUR_H_INCLUDED
