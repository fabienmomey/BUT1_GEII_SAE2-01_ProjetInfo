#include <iostream>
#include <string.h> // Librairie C de fonctions permettant de manipuler les chaînes de caractères [https://www.cplusplus.com/reference/cstring/]
#include "lib_vaisseau.h"

using namespace std ;

/**
   Aide syntaxe langage C++ : "lecture" des champs d'un pointeur vers structure
   - Exemple avec une variable input_vaisseau de type Vaisseau*

       (*input_vaisseau).m_nom // (ou tout autre champ de la structure)

               OU

       input_vaisseau->m_nom

   Ces 2 syntaxes sont équivalentes et permettent donc de lire (ou écrire) dans le champ concerné
   contenu à l'adresse pointée par la variable input_vaisseau.
 **/

void AffecterCarac (Vaisseau* output_vaisseau, const char* input_nom, const int input_coque, const int input_feu)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */

    // Affectation de la classe du Vaisseau par appel de la fonction AffecterClasse
    AffecterClasse(output_vaisseau, "Vaisseau") ;

    // Affectation du nom du Vaisseau par appel de la fonction AffecterNom
    AffecterNom(output_vaisseau, input_nom) ;

    // Affectation de la résistance de coque au Vaisseau par appel de la fonction AffecterResistanceCoque
    AffecterResistanceCoque(output_vaisseau, input_coque) ;

    // Affectation de la puissance de feu au Vaisseau par appel de la fonction AffecterPuissanceFeu
    AffecterPuissanceFeu(output_vaisseau, input_feu) ;
}

void AfficherCarac (const Vaisseau* input_vaisseau)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */

    /// Affichage des caractéristiques du Vaisseau déclaré pour vérification
    cout << endl << "[" << endl ;
    cout << "\tVaisseau " << input_vaisseau->m_nom << " de classe " << input_vaisseau->m_classe << " : " << endl ;
    cout << "\t| Resistance de coque (" << input_vaisseau->m_resistance_coque << ")" << endl ;
    cout << "\t| Puissance de feu (" << input_vaisseau->m_puissance_feu << ")" << endl ;
    if (input_vaisseau->m_resistance_coque <= 0)
    {
        cout << "\t| => ****************************" << endl ;
        cout << "\t| => %%%%% VAISSEAU DETRUIT %%%%%" << endl ;
        cout << "\t| => %%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl ;
    }
    cout << "\t|_________________" << endl ;
    cout << "]" << endl ;
}

void AffecterClasse (Vaisseau* output_vaisseau, const char* input_classe)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */

    // Affectation du nom du Vaisseau
    strcpy(output_vaisseau->m_classe, input_classe) ;
    /// La fonction STRCPY de la librairie CSTRING permet de copier une chaîne de caractères source (2ème argument E)
    /// dans une chaîne de caractères destination (1er argument E/S)
    /// Attention la chaîne destination doit être assez longue (nombre de caractères suffisant) pour contenir la chaîne source
}

void AffecterNom (Vaisseau* output_vaisseau, const char* input_nom)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */

    // Affectation du nom du Vaisseau
    strcpy(output_vaisseau->m_nom, input_nom) ;
}

void AffecterResistanceCoque (Vaisseau* output_vaisseau, const int input_coque)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */

    // Affectation de la résistance de coque au Vaisseau (mise à zéro en cas de valeur négative)
    if (input_coque >= 0)
    {
        output_vaisseau->m_resistance_coque = input_coque ;
    }
    else
    {
        output_vaisseau->m_resistance_coque = 0 ;
    }
}

void AffecterPuissanceFeu (Vaisseau* output_vaisseau, const int input_feu)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */

    // Affectation de la puissance de feu au Vaisseau (mise à zéro en cas de valeur négative)
    if (input_feu >= 0)
    {
        output_vaisseau->m_puissance_feu = input_feu ;
    }
    else
    {
        output_vaisseau->m_puissance_feu = 0 ;
    }
}

const char* RenvoyerClasse (const Vaisseau* input_vaisseau)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */

    return input_vaisseau -> m_classe ;
}

const char* RenvoyerNom (const Vaisseau* input_vaisseau)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */

    return input_vaisseau -> m_nom ;
}

int RenvoyerResistanceCoque (const Vaisseau* input_vaisseau)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */

    return input_vaisseau -> m_resistance_coque ;
}

int RenvoyerPuissanceFeu (const Vaisseau* input_vaisseau)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */

    return input_vaisseau -> m_puissance_feu ;
}
