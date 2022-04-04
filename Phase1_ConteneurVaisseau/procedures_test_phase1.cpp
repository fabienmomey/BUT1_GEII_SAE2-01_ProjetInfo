#include <iostream>
#include <limits>
#include "lib_vaisseau.h"
#include "procedures_test_phase1.h"

using namespace std ;

/**
    ---------------------------------------------------------------------------------------------------------------------------------------------------------
    | Définition des fonctions de la librairie de procédures de test permettant de valider la structure Vaisseau et ses fonctionnalités (phase 1 du projet) |
    ---------------------------------------------------------------------------------------------------------------------------------------------------------
 **/

/*
    {
        R   : Procédure de test global n°1 de la structure Vaisseau et fonctionnalités associées (phase 1 du projet)
              => test de la fonction d'affectation globale des caractéristiques AffecterCarac
              => valeurs des champs données "en dur"
        E   : vide
        E/S : vide
        S   : vide
    }
    TestStructVaisseau1  : la fonction (vide) -> vide
*/
void TestStructVaisseau1()
{
    /* Déclaration des variables locales */
    /// Déclaration d'une variable de type Vaisseau
    Vaisseau faucon ;

    /* Algorithme local */
    cout << "|*****************************************|" << endl ;
    cout << "|********** TestStructVaisseau1 **********|" << endl ;
    cout << "|=> test de la fonction d'affectation     |" << endl ;
    cout << "|   globale des caracteristiques          |" << endl ;
    cout << "|   AffecterCarac.                        |" << endl ;
    cout << "|=> valeurs des champs donnees \"en dur\".|" << endl ;
    cout << "|*****************************************|" << endl << endl ;

    /// Initialisation des caractéristiques du Vaisseau par appel à la fonction dédiée AffecterCarac avec des valeurs "en dur"
    /// => On doit donner l'adresse de la variable de type Vaisseau concernée comme 1er argument de la fonction AffecterCarac
    AffecterCarac(&faucon, "faucon millenium", 100, 100) ;

    /// Affichage des caractéristiques du Vaisseau déclaré pour vérification
    cout << "[" << endl ;
    cout << "\tVaisseau " << faucon.m_nom << " de classe " << faucon.m_classe << " : " << endl ;
    cout << "\t| Resistance de coque (" << faucon.m_resistance_coque << ")" << endl ;
    cout << "\t| Puissance de feu (" << faucon.m_puissance_feu << ")" << endl ;
    cout << "\t|_________________" << endl ;
    cout << "]" << endl ;
}

/*
    {
        R   : Procédure de test global n°2 de la structure Vaisseau et fonctionnalités associées (phase 1 du projet)
              => test de la fonction d'affectation globale des caractéristiques AffecterCarac
              => valeurs des champs demandées en saisie à l'utilisateur
        E   : vide
        E/S : vide
        S   : vide
    }
    TestStructVaisseau2  : la fonction (vide) -> vide
*/
void TestStructVaisseau2()
{
    /* Déclaration des variables locales */
    char local_nom[64] = "" ;
    int local_coque ;
    int local_feu ;

    /// Déclaration d'une variable de type Vaisseau
    Vaisseau faucon ;

    /* Algorithme local */
    cout << "|*****************************************|" << endl ;
    cout << "|********** TestStructVaisseau2 **********|" << endl ;
    cout << "|=> test de la fonction d'affectation     |" << endl ;
    cout << "|   globale des caracteristiques          |" << endl ;
    cout << "|   AffecterCarac.                        |" << endl ;
    cout << "|=> valeurs des champs demandees en       |" << endl ;
    cout << "|   saisie à l'utilisateur.               |" << endl ;
    cout << "|*****************************************|" << endl << endl ;

    /// Initialisation des caractéristiques du Vaisseau par appel à la fonction dédiée AffecterCarac avec des valeurs "en dur"
    cout << "Donnez un nom à votre vaisseau (63 caracteres maximum) : " << endl ;

    /// Saisie sécurisée d'une chaîne de caractères de longueur limitée
    ///     =>  La saisie "tronque" automatiquement la chaîne de caractères saisie si celle-ci dépasse le nombre de caractères maximal requis.
    ///         Si il y a eu dépassement, la saisie suivante récupère ce qui restait dans le buffer, il faut donc le vider avant toute nouvelle saisie.
    ///         En cas de dépassement, cin renvoie une erreur => on ne vide le buffer avant une prochaine saisie que dans ce cas
    ///         en faisant un "try ... catch" qui ne bloque pas l'exécution du programme après erreur.
    // On vide le buffer d'entrée au préalable si il reste des caractères dans le buffer
    if (cin.gcount()>0)
    {
        cin.ignore() ;
    }
    cin.exceptions(std::ios_base::failbit); // may throw

    try {
        cin.getline(local_nom, sizeof(local_nom)) ; // Permet de lire également les espaces éventuels dans le nom
    } catch (const std::ios_base::failure& fail) {
        // handle exception here
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Donnez une resistance de coque à votre vaisseau : " << endl ;
    cin >> local_coque ;
    cout << "Donnez une puissance de feu à votre vaisseau : " << endl ;
    cin >> local_feu ;
    /// => On doit donner l'adresse de la variable de type Vaisseau concernée comme 1er argument de la fonction AffecterCarac
    AffecterCarac(&faucon, local_nom, local_coque, local_feu) ;

    /// Affichage des caractéristiques du Vaisseau déclaré pour vérification
    cout << endl << "[" << endl ;
    cout << "\tVaisseau " << faucon.m_nom << " de classe " << faucon.m_classe << " : " << endl ;
    cout << "\t| Resistance de coque (" << faucon.m_resistance_coque << ")" << endl ;
    cout << "\t| Puissance de feu (" << faucon.m_puissance_feu << ")" << endl ;
    cout << "\t|_________________" << endl ;
    cout << "]" << endl ;
}

/*
    {
        R   : Procédure de test global n°3 de la structure Vaisseau et fonctionnalités associées (phase 1 du projet)
              => test de la fonction d'affectation globale des caractéristiques AffecterCarac + fonction d'affichage des caractéristiques AfficherCarac
        E   : vide
        E/S : vide
        S   : vide
    }
    TestStructVaisseau3  : la fonction (vide) -> vide
*/
void TestStructVaisseau3()
{
    /* Déclaration des variables locales */
    char local_nom[64] = "" ;
    int local_coque ;
    int local_feu ;

    /// Déclaration d'une variable de type Vaisseau
    Vaisseau faucon ;

    /* Algorithme local */
    cout << "|*****************************************|" << endl ;
    cout << "|********** TestStructVaisseau3 **********|" << endl ;
    cout << "|=> test de la fonction d'affectation     |" << endl ;
    cout << "|   globale des caracteristiques          |" << endl ;
    cout << "|   AffecterCarac.                        |" << endl ;
    cout << "|   + fonction d'affichage des            |" << endl ;
    cout << "|     caracteristiques AfficherCarac.     |" << endl ;
    cout << "|*****************************************|" << endl << endl ;

    /// Initialisation des caractéristiques du Vaisseau par appel à la fonction dédiée AffecterCarac avec des valeurs "en dur"
    cout << "Donnez un nom à votre vaisseau (63 caracteres maximum) : " << endl ;
    /// Saisie sécurisée d'une chaîne de caractères de longueur limitée
    ///     =>  La saisie "tronque" automatiquement la chaîne de caractères saisie si celle-ci dépasse le nombre de caractères maximal requis.
    ///         Si il y a eu dépassement, la saisie suivante récupère ce qui restait dans le buffer, il faut donc le vider avant toute nouvelle saisie.
    ///         En cas de dépassement, cin renvoie une erreur => on ne vide le buffer avant une prochaine saisie que dans ce cas
    ///         en faisant un "try ... catch" qui ne bloque pas l'exécution du programme après erreur.
    cin.clear() ;
    // On vide le buffer d'entrée au préalable si il reste des caractères dans le buffer
    if (cin.gcount()>0)
    {
        cin.ignore() ;
    }
    cin.exceptions(std::ios_base::failbit); // may throw

    try {
        cin.getline(local_nom, sizeof(local_nom)) ; // Permet de lire également les espaces éventuels dans le nom
    } catch (const std::ios_base::failure& fail) {
        // handle exception here
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Donnez une resistance de coque à votre vaisseau : " << endl ;
    cin >> local_coque ;
    cout << "Donnez une puissance de feu à votre vaisseau : " << endl ;
    cin >> local_feu ;
    /// => On doit donner l'adresse de la variable de type Vaisseau concernée comme 1er argument de la fonction AffecterCarac
    AffecterCarac(&faucon, local_nom, local_coque, local_feu) ;

    /// Affichage des caractéristiques du Vaisseau déclaré pour vérification
    AfficherCarac(&faucon) ;
}

/*
    {
        R   : Procédure de test global n°4 de la structure Vaisseau et fonctionnalités associées (phase 1 du projet)
              => test des fonctions d'affectations unitaires des caractéristiques AffecterNom, AffecterResistanceCoque, AffecterPuissanceFeu
                 + fonctions de renvois unitaires des caractéristiques RenvoyerClasse, RenvoyerNom, RenvoyerResistanceCoque, RenvoyerPuissanceFeu
        E   : vide
        E/S : vide
        S   : vide
    }
    TestStructVaisseau4  : la fonction (vide) -> vide
*/
void TestStructVaisseau4()
{
    /* Déclaration des variables locales */
    char local_nom[64] = "" ;
    int local_coque ;
    int local_feu ;

    /// Déclaration d'une variable de type Vaisseau
    Vaisseau faucon ;

    /* Algorithme local */
    cout << "|*****************************************|" << endl ;
    cout << "|********** TestStructVaisseau4 **********|" << endl ;
    cout << "|=> test des fonctions d'affectations     |" << endl ;
    cout << "|   unitaires des caractéristiques        |" << endl ;
    cout << "|   AffecterNom, AffecterResistanceCoque, |" << endl ;
    cout << "|   AffecterPuissanceFeu                  |" << endl ;
    cout << "|   + fonctions de renvois unitaires des  |" << endl ;
    cout << "|     caractéristiques RenvoyerClasse,    |" << endl ;
    cout << "|     RenvoyerNom, RenvoyerResistanceCoque|" << endl ;
    cout << "|     et RenvoyerPuissanceFeu             |" << endl ;
    cout << "|*****************************************|" << endl << endl ;

    /// Initialisation des caractéristiques du Vaisseau par appel à la fonction dédiée AffecterCarac avec des valeurs "en dur"
    /// => On doit donner l'adresse de la variable de type Vaisseau concernée comme 1er argument de la fonction AffecterCarac
    AffecterCarac(&faucon, "inconnu", 0, 0) ;

    /// Initialisation des caractéristiques du Vaisseau par appel à la fonction dédiée AffecterCarac avec des valeurs "en dur"
    cout << "Donnez un nom à votre vaisseau (63 caracteres maximum) : " << endl ;
    /// Saisie sécurisée d'une chaîne de caractères de longueur limitée
    ///     =>  La saisie "tronque" automatiquement la chaîne de caractères saisie si celle-ci dépasse le nombre de caractères maximal requis.
    ///         Si il y a eu dépassement, la saisie suivante récupère ce qui restait dans le buffer, il faut donc le vider avant toute nouvelle saisie.
    ///         En cas de dépassement, cin renvoie une erreur => on ne vide le buffer avant une prochaine saisie que dans ce cas
    ///         en faisant un "try ... catch" qui ne bloque pas l'exécution du programme après erreur.
    cin.clear() ;
    // On vide le buffer d'entrée au préalable si il reste des caractères dans le buffer
    if (cin.gcount()>0)
    {
        cin.ignore() ;
    }
    cin.exceptions(std::ios_base::failbit); // may throw

    try {
        cin.getline(local_nom, sizeof(local_nom)) ; // Permet de lire également les espaces éventuels dans le nom
    } catch (const std::ios_base::failure& fail) {
        // handle exception here
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Donnez une resistance de coque à votre vaisseau : " << endl ;
    cin >> local_coque ;
    cout << "Donnez une puissance de feu à votre vaisseau : " << endl ;
    cin >> local_feu ;
    /// Ré-affectation des caractéristiques du Vaisseau par appel aux fonctions dédiées AffecterNom, AffecterResistanceCoque
    /// et AffecterPuissanceFeu avec des valeurs "en dur"
    /// => On doit donner l'adresse de la variable de type Vaisseau concernée comme 1er argument de la fonction AffecterCarac
    AffecterNom(&faucon, local_nom) ;
    AffecterResistanceCoque(&faucon, local_coque) ;
    AffecterPuissanceFeu(&faucon, local_feu) ;

    /// Affichage des caractéristiques du Vaisseau déclaré pour vérification
    AfficherCarac(&faucon) ;

    /// Affichage des caractéristiques du Vaisseau déclaré à partir de valeurs renvoyées par les fonctions Renvoyer... dédiées
    cout << "[" << endl ;
    cout << "\tVaisseau " << RenvoyerNom(&faucon) << " de classe " << RenvoyerClasse(&faucon) << " : " << endl ;
    cout << "\t| Resistance de coque (" << RenvoyerResistanceCoque(&faucon) << ")" << endl ;
    cout << "\t| Puissance de feu (" << RenvoyerPuissanceFeu(&faucon) << ")" << endl ;
    cout << "\t|_________________" << endl ;
    cout << "]" << endl ;
}
