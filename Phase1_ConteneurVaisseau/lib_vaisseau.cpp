#include <iostream>
#include <string.h> // Librairie C de fonctions permettant de manipuler les chaînes de caractères [https://www.cplusplus.com/reference/cstring/]
#include "lib_vaisseau.h"

using namespace std ;

/**
    ---------------------------------------------------------------------------------------------------
    | Définition des fonctions de la librairie permettant de manipuler des variables de type Vaisseau |
    ---------------------------------------------------------------------------------------------------
 **/

 /**
    Aide syntaxe langage C++ : "lecture" des champs d'un pointeur vers structure
    - Exemple avec une variable input_vaisseau de type Vaisseau*

        (*input_vaisseau).m_nom // (ou tout autre champ de la structure)

                OU

        input_vaisseau->m_nom

    Ces 2 syntaxes sont équivalentes et permettent donc de lire (ou écrire) dans le champ concerné
    contenu à l'adresse pointée par la variable input_vaisseau.
  **/

/*
    {
        R   :   Fonction permettant d'affecter des valeurs à toutes les caractéristiques d'un Vaisseau
                |
                | Cette fonction DOIT ÊTRE IMPÉRATIVEMENT APPELÉE après déclaration d'une variable de type Vaisseau
                | afin d'initialiser les valeurs de ses champs.
                |    Remarque : le champ m_classe de la structure ne peut être changé car il dépend directement du type de Vaisseau
                |    => ici la fonction donnera la valeur "Vaisseau" au champ m_classe de toute variable de type Vaisseau
                |__________________________________________________________________________________________________________________

        E   :   1 chaîne de caractères (la valeur du nom du vaisseau), 2 entiers (la valeur de résistance de coque / la valeur de puissance de feu)
        E/S :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau auquel on affecte les valeurs données en entrée)
        S   :   vide
    }
    AffecterCarac   :   la fonction (1 pointeur sur Vaisseau, 1 chaîne de caractères, 1 entier, 1 entier) -> vide
 */
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

  /*
    {
        R   :   Fonction permettant d'afficher toutes les caractéristiques d'un Vaisseau
                => affiche un message dédié si le vaisseau est détruit (résistance de coque tombée à 0)
        E   :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau dont on souhaite afficher les caractéristiques)
        E/S :   vide
        S   :   vide
    }
    AfficherCarac   :   la fonction (1 pointeur sur Vaisseau) -> vide
 */
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
        cout << "\t| => %%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl ;
        cout << "\t| => %%%%% VAISSEAU DETRUIT %%%%%" << endl ;
        cout << "\t| => %%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl ;
    }
    cout << "\t|_________________" << endl ;
    cout << "]" << endl ;
 }

 /*
    {
        R   :   Fonction permettant d'affecter une valeur à la caractérisitque "m_classe" d'un Vaisseau
                |
                | Cette fonction permet de modifier la classe d'un Vaisseau quand ce dernier sera un Vaisseau spécialisé.
                | ELLE NE DOIT PAS SE SUBSTITUER à l'appel obligatoire de la fonction AffecterCarac après déclaration
                | d'une variable de type Vaisseau.
                |________________________________________________________________________________________________________

        E   :   1 chaîne de caractères (la valeur de la classe du vaisseau)
        E/S :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau auquel on affecte la valeur donnée en entrée)
        S   :   vide
    }
    AffecterClasse   :   la fonction (1 pointeur sur Vaisseau, 1 chaîne de caractères) -> vide
*/
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

 /*
    {
        R   :   Fonction permettant d'affecter une valeur à la caractérisitque "m_nom" d'un Vaisseau
        E   :   1 chaîne de caractères (la valeur du nom du vaisseau)
        E/S :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau auquel on affecte la valeur donnée en entrée)
        S   :   vide
    }
    AffecterNom   :   la fonction (1 pointeur sur Vaisseau, 1 chaîne de caractères) -> vide
 */
 void AffecterNom (Vaisseau* output_vaisseau, const char* input_nom)
 {
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */

    // Affectation du nom du Vaisseau
    strcpy(output_vaisseau->m_nom, input_nom) ;
 }

 /*
    {
        R   :   Fonction permettant d'affecter une valeur à la caractérisitque "m_resistance_coque" d'un Vaisseau
        E   :   1 entier (a valeur de résistance de coque)
        E/S :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau auquel on affecte la valeur donnée en entrée)
        S   :   vide
    }
    AffecterResistanceCoque   :   la fonction (1 pointeur sur Vaisseau, 1 entier) -> vide
 */
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

 /*
    {
        R   :   Fonction permettant d'affecter une valeur à la caractérisitque "m_puissance_feu" d'un Vaisseau
        E   :   1 entier (a valeur de puissance de feu)
        E/S :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau auquel on affecte la valeur donnée en entrée)
        S   :   vide
    }
    AffecterPuissanceFeu   :   la fonction (1 pointeur sur Vaisseau, 1 entier) -> vide
 */
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

/*
    {
        R   :   Fonction permettant de renvoyer la valeur à la caractérisitque "m_classe" d'un Vaisseau
        E   :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau dont on souhaite récupérer la classe)
        E/S :   vide
        S   :   1 chaîne de caractères (en lecture seule) (la classe du vaisseau)
    }
    RenvoyerNom   :   la fonction (1 pointeur sur Vaisseau) -> 1 chaîne de caractères (en lecture seule)
*/
const char* RenvoyerClasse (const Vaisseau* input_vaisseau)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */

    return input_vaisseau -> m_classe ;
}

/*
    {
        R   :   Fonction permettant de renvoyer la valeur à la caractérisitque "m_nom" d'un Vaisseau
        E   :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau dont on souhaite récupérer le nom)
        E/S :   vide
        S   :   1 chaîne de caractères (en lecture seule) (le nom du vaisseau)
    }
    RenvoyerNom   :   la fonction (1 pointeur sur Vaisseau) -> 1 chaîne de caractères (en lecture seule)
*/
const char* RenvoyerNom (const Vaisseau* input_vaisseau)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */

    return input_vaisseau -> m_nom ;
}


/*
    {
        R   :   Fonction permettant de renvoyer la valeur à la caractérisitque "m_resistance_coque" d'un Vaisseau
        E   :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau dont on souhaite récupérer la résistance de coque)
        E/S :   vide
        S   :   1 entier (en lecture seule) (la résistance de coque du vaisseau)
    }
    RenvoyerResistanceCoque   :   la fonction (1 pointeur sur Vaisseau) -> 1 entier
*/
int RenvoyerResistanceCoque (const Vaisseau* input_vaisseau)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */

    return input_vaisseau -> m_resistance_coque ;
}

/*
    {
        R   :   Fonction permettant de renvoyer la valeur à la caractérisitque "m_puissance_feu" d'un Vaisseau
        E   :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau dont on souhaite récupérer la puissance de feu)
        E/S :   vide
        S   :   1 entier (en lecture seule) (la puissance de feu du vaisseau)
    }
    RenvoyerPuissanceFeu   :   la fonction (1 pointeur sur Vaisseau) -> 1 entier
*/
int RenvoyerPuissanceFeu (const Vaisseau* input_vaisseau)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */

    return input_vaisseau -> m_puissance_feu ;
}
