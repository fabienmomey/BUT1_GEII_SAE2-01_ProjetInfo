#ifndef LIB_VAISSEAU3_H_INCLUDED
#define LIB_VAISSEAU3_H_INCLUDED

#include "lib_vaisseau2.h"

/**
    ------------------------------------------------------------------------------------
    | Complément à la librairie permettant de manipuler des variables de type Vaisseau |
    | => Ajout des fonctions AttaquerBasic et AttaquerSpecial                          |
    ------------------------------------------------------------------------------------
 **/

 /*
    {
        R   :   Fonction permettant à un Vaisseau d'attaquer un autre Vaisseau cible avec son attaque basique.
                Le Vaisseau attaquant va infliger des dégâts égaux au nombre de sa puissance de feu standard.
                Le Vaisseau cible va donc subir les dégâts infligés.
        E   :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau attaquant)
        E/S :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau cible)
        S   :   vide
    }
    AttaquerBasic   :   la fonction (1 pointeur sur Vaisseau, 1 pointeur sur Vaisseau) -> vide
*/
void AttaquerBasic (const Vaisseau*, Vaisseau*) ;

 /*
    {
        R   :   Fonction permettant à un Vaisseau d'attaquer un autre Vaisseau cible avec son attaque spéciale.
                Le Vaisseau attaquant va infliger des dégâts égaux au nombre de sa puissance de feu standard.
                Le Vaisseau cible va donc subir les dégâts infligés.
        E   :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau attaquant)
        E/S :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau cible)
        S   :   vide
    }
    AttaquerSpecial   :   la fonction (1 pointeur sur Vaisseau, 1 pointeur sur Vaisseau) -> vide
*/
void AttaquerSpecial (const Vaisseau*, Vaisseau*) ;

#endif // LIB_VAISSEAU3_H_INCLUDED
