#ifndef LIB_VAISSEAU2_H_INCLUDED
#define LIB_VAISSEAU2_H_INCLUDED

#include "lib_vaisseau.h"

/**
    ------------------------------------------------------------------------------------
    | Complément à la librairie permettant de manipuler des variables de type Vaisseau |
    ------------------------------------------------------------------------------------
 **/

/*
    {
        R   :   Fonction permettant à un Vaisseau de subir des dégâts à sa résistance de coque,
                autrement dit d'ôter un nombre entier de points de coque à ce Vaisseau cible
        E   :   1 entier (le nombre indiquant les dégâts de coque encaissés par le vaisseau)
        E/S :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau qui doit subir des dégâts)
        S   :   vide
    }
    SubirDegatsCoque   :   la fonction (1 pointeur sur Vaisseau, 1 entier) -> vide
*/
void SubirDegatsCoque (Vaisseau*, const int) ;

#endif // LIB_VAISSEAU2_H_INCLUDED
