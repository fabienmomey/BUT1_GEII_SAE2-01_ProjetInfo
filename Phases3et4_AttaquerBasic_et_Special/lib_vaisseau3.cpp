#include <iostream>
#include "lib_vaisseau3.h"

using namespace std ;

void AttaquerBasic (const Vaisseau* input_attaquant, Vaisseau* output_cible)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */
    SubirDegatsCoque(output_cible, RenvoyerPuissanceFeu(input_attaquant)) ;
}

void AttaquerSpecial (const Vaisseau* input_attaquant, Vaisseau* output_cible)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */
    cout << endl << endl ;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl ;
    cout << "LE VAISSEAU " << RenvoyerNom(input_attaquant) << " N'A PAS D'ATTAQUE SPECIALE !" << endl ;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl ;
    cout << endl << endl ;
}
