#include <iostream>
#include "lib_vaisseau2.h"

using namespace std ;

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

