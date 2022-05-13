#include <iostream>
#include "lib_vaisseau2.h"

using namespace std ;

void SubirDegatsCoque (Vaisseau* output_vaisseau, const int input_degats)
{
    /* Déclaration des variables locales */
    int local_new_coque ;

    /* Algorithme local */
    /// Calcul de la nouvelle résistance de coque du Vaisseau cible (on ôte les points de dégâts donnés en entrée)
    local_new_coque = RenvoyerResistanceCoque(output_vaisseau) - input_degats ;
    /// Mise à zéro de la résistance de coque si elle devient inférieure à zéro (Vaisseau détruit)
    if (local_new_coque <= 0)
    {
        local_new_coque = 0 ;
    }
    /// Affectation de la nouvelle résistance de coque au Vaisseau cible
    AffecterResistanceCoque(output_vaisseau, local_new_coque) ;
}

