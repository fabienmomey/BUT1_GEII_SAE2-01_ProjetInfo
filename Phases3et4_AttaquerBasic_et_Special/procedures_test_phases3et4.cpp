#include <iostream>
#include "moteur_de_jeu.h"
#include "lib_vaisseau3.h"
#include "procedures_test_phases3et4.h"

using namespace std ;

/**
    ---------------------------------------------------------------------------------------------------------------------------------------------------------------
    | Définition de la librairie de procédures de test permettant de valider les nouvelles fonctionnalités de gestionn d'un duel de vaisseaux (phase 2 du projet) |
    ---------------------------------------------------------------------------------------------------------------------------------------------------------------
 **/

void TestAttaquerBasic()
{
    /* Déclaration des variables locales */
    int local_coque_attaquant, local_puissance_attaquant ;
    int local_coque_cible, local_puissance_cible ;
    /// Déclaration de 2 variables de type Vaisseau (l'attaquant et la cible)
    Vaisseau attaquant, cible ;

    /* Algorithme local */
    cout << "|*****************************************|" << endl ;
    cout << "|*********** TestAttaquerBasic ***********|" << endl ;
    cout << "|=> test d'un Vaisseau réalisant          |" << endl ;
    cout << "|   une attaque basique sur un            |" << endl ;
    cout << "|   Vaisseau cible avec la fonction       |" << endl ;
    cout << "|   AttaquerBasic.                        |" << endl ;
    cout << "|*****************************************|" << endl << endl ;

    /// Saisie des caractéristiques (coque et puissance) de chaque Vaisseau
    cout << "Saisir la resistance de coque du Vaisseau attaquant : " << endl ;
    cin >> local_coque_attaquant ;
    cout << "Saisir la puissance de feu du Vaisseau attaquant : " << endl ;
    cin >> local_puissance_attaquant ;
    cout << "Saisir la resistance de coque du Vaisseau cible : " << endl ;
    cin >> local_coque_cible ;
    cout << "Saisir la puissance de feu du Vaisseau cible : " << endl ;
    cin >> local_puissance_cible ;

    /// Initialisation des caractéristiques du Vaisseau attaquant par appel à la fonction dédiée AffecterCarac avec des valeurs "en dur"
    /// => On doit donner l'adresse de la variable de type Vaisseau concernée comme 1er argument de la fonction AffecterCarac
    AffecterCarac(&attaquant, "faucon millenium", local_coque_attaquant, local_puissance_attaquant) ;
    /// Initialisation des caractéristiques du Vaisseau cible par appel à la fonction dédiée AffecterCarac avec des valeurs "en dur"
    /// => On doit donner l'adresse de la variable de type Vaisseau concernée comme 1er argument de la fonction AffecterCarac
    AffecterCarac(&cible, "tie fighter", local_coque_cible, local_puissance_cible) ;

    /// Affichage des caractéristiques des Vaisseaux attaquant et cible
    AfficherCarac(&attaquant) ;
    AfficherCarac(&cible) ;

    /// Appel de la fonction d'encaissement de dégâts SubirDegatsCoque par la Vaisseau cible
    /// avec un nombre de dégâts supérieur à la résistance de coque actuelle
    /// => le vaisseau n'est pas encore détruit
    cout << endl << "[" << endl ;
    cout << "\tVaisseau " << RenvoyerNom(&attaquant) << " de classe " << RenvoyerClasse(&attaquant) << endl ;
    cout << "\tréalise une attaque basique sur " << endl ;
    cout << "\tVaisseau " << RenvoyerNom(&cible) << " de classe " << RenvoyerClasse(&cible) << " : " << endl ;
    cout << "\t| => la cible subit " << RenvoyerPuissanceFeu(&attaquant) << " degats de coque." << endl ;
    cout << "\t|_________________" << endl ;
    cout << "]" << endl ;
    AttaquerBasic(&attaquant, &cible) ;

    /// Affichage des caractéristiques du Vaisseau déclaré pour vérification
    /// => le vaisseau doit être détruit
    AfficherCarac(&cible) ;
}

void TestAttaquerSpecial()
{
    /* Déclaration des variables locales */
    int local_coque_attaquant, local_puissance_attaquant ;
    int local_coque_cible, local_puissance_cible ;
    /// Déclaration de 2 variables de type Vaisseau (l'attaquant et la cible)
    Vaisseau attaquant, cible ;

    /* Algorithme local */
    cout << "|*****************************************|" << endl ;
    cout << "|*********** TestAttaquerBasic ***********|" << endl ;
    cout << "|=> test d'un Vaisseau réalisant          |" << endl ;
    cout << "|   une attaque spéciale sur un           |" << endl ;
    cout << "|   Vaisseau cible avec la fonction       |" << endl ;
    cout << "|   AttaquerBasic.                        |" << endl ;
    cout << "|*****************************************|" << endl << endl ;

    /// Saisie des caractéristiques (coque et puissance) de chaque Vaisseau
    cout << "Saisir la resistance de coque du Vaisseau attaquant : " << endl ;
    cin >> local_coque_attaquant ;
    cout << "Saisir la puissance de feu du Vaisseau attaquant : " << endl ;
    cin >> local_puissance_attaquant ;
    cout << "Saisir la resistance de coque du Vaisseau cible : " << endl ;
    cin >> local_coque_cible ;
    cout << "Saisir la puissance de feu du Vaisseau cible : " << endl ;
    cin >> local_puissance_cible ;

    /// Initialisation des caractéristiques du Vaisseau attaquant par appel à la fonction dédiée AffecterCarac avec des valeurs "en dur"
    /// => On doit donner l'adresse de la variable de type Vaisseau concernée comme 1er argument de la fonction AffecterCarac
    AffecterCarac(&attaquant, "faucon millenium", local_coque_attaquant, local_puissance_attaquant) ;
    /// Initialisation des caractéristiques du Vaisseau cible par appel à la fonction dédiée AffecterCarac avec des valeurs "en dur"
    /// => On doit donner l'adresse de la variable de type Vaisseau concernée comme 1er argument de la fonction AffecterCarac
    AffecterCarac(&cible, "tie fighter", local_coque_cible, local_puissance_cible) ;

    /// Affichage des caractéristiques des Vaisseaux attaquant et cible
    AfficherCarac(&attaquant) ;
    AfficherCarac(&cible) ;

    /// Appel de la fonction d'encaissement de dégâts SubirDegatsCoque par la Vaisseau cible
    /// avec un nombre de dégâts supérieur à la résistance de coque actuelle
    /// => le vaisseau n'est pas encore détruit
    cout << endl << "[" << endl ;
    cout << "\tVaisseau " << RenvoyerNom(&attaquant) << " de classe " << RenvoyerClasse(&attaquant) << endl ;
    cout << "\tréalise une attaque sépciale sur " << endl ;
    cout << "\tVaisseau " << RenvoyerNom(&cible) << " de classe " << RenvoyerClasse(&cible) << " : " << endl ;
    cout << "\t|_________________" << endl ;
    cout << "]" << endl ;
    AttaquerSpecial(&attaquant, &cible) ;

    /// Affichage des caractéristiques du Vaisseau déclaré pour vérification
    /// => le vaisseau doit être détruit
    AfficherCarac(&cible) ;
}
