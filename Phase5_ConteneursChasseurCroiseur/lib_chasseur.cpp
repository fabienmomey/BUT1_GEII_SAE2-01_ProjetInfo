#include <iostream>
#include <string.h> // Librairie C de fonctions permettant de manipuler les chaînes de caractères [https://www.cplusplus.com/reference/cstring/]
#include "lib_chasseur.h"

using namespace std ;

void AfficherCarac (const Chasseur* input_chasseur)
{
    /// Affichage des caractéristiques du Vaisseau déclaré pour vérification
    AfficherCarac(&(input_chasseur->m_vaisseau)) ;
    cout << "\t| Puissance de feu des torpilles (" << input_chasseur->m_puissance_feu_torpilles << ")" << endl ;
    cout << "\t|_________________" << endl ;
    cout << "]" << endl ;
}
