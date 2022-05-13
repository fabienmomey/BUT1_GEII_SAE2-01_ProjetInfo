#include <iostream>
#include <limits>
#include <windows.h>
#include "moteur_de_jeu.h"
#include "lib_vaisseau3.h"

/**
    ---------------------------------------------------------------------------------
    | Définition de fonctions et procédures utiles pour le jeu de duel de vaisseaux |
    ---------------------------------------------------------------------------------
 **/

 /*
    {
        R   : Fonction d'initialisation des caractéristiques d'un Vaisseau par demande de saisie à l'utilisateur
        E   : vide
        E/S : 1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau à initialiser)
        S   : vide
    }
    InitialiserCaracVaisseau  : la fonction (1 pointeur sur Vaisseau) -> vide
*/
void InitialiserCaracVaisseau(Vaisseau*) ;

/*
    {
        R   : Fonction d'affichage d'un message indiquant que le Vaisseau passé en entrée est victorieux du duel
        E   : 1 pointeur sur Vaisseau (l'adresse du Vaisseau vainqueur)
        E/S : vide
        S   : vide
    }
    AfficherVaisseauVainqueur  : la fonction (1 pointeur sur Vaisseau) -> vide
*/
void AfficherVaisseauVainqueur(const Vaisseau*) ;

/*
    {
        R : Fonction d'annonce du Vaisseau assaillant et de demande de choix d'attaque
            => 1 pour Basic ; 2 pour Special
        E : 1 pointeur sur Vaisseau (l'adresse du Vaisseau assaillant)
        E/S : vide
        S : 1 entier non signé sur 1 octet (caractère) (le choix d'attaque)
    }
*/
unsigned char ChoisirAttaque(const Vaisseau*) ;

/*
    {
        R : Fonction d'annonce du Vaisseau assaillant (attente d'un appui sur la touche [Echap])
        E : 1 pointeur sur Vaisseau (l'adresse du Vaisseau assaillant)
        E/S : vide
        S : vide
    }
*/
void PresenterVaisseauAttaquant(const Vaisseau*) ;
/// Cette fonction s'intègre au moteur de jeu

using namespace std;

int main()
{
    /* Déclaration des variables principales */
    bool flag_tour_joueur = 0 ; // variable indiquant le tour du joueur courant (false : joueur 1 ; true : joueur 2)
    unsigned char choix_attaque_tour ;
    /// Déclaration des 2 vaisseaux pour le duel
    Vaisseau vaisseau_j1, vaisseau_j2 ;
    /// Déclaration de 2 pointeurs sur Vaisseau
    /// qui recevront respectivement à chaque tour
    /// l'adresse du joueur attaquant (le joueur dont c'est le tour)
    /// et l'adresse du joueur cible,
    Vaisseau* vaisseau_attaquant_tour ;
    Vaisseau* vaisseau_cible_tour ;

    /* Algorithme principal (le duel de vaisseaux) */
    /// Initialisation des 2 vaisseaux pour le duel
    InitialiserCaracVaisseau(&vaisseau_j1) ;
    InitialiserCaracVaisseau(&vaisseau_j2) ;
    /// Affichage des caractéristiques des 2 vaisseaux pour le duel
    AfficherCarac(&vaisseau_j1) ;
    AfficherCarac(&vaisseau_j2) ;

    /// Boucle de duel (tant que les 2 vaisseaux ont encore de la résistance de coque => aucun vaisseau détruit)
    cout << endl << endl ;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl ;
    cout << "LE DUEL DES VAISSEAUX EST PRET A COMMENCER !" << endl ;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl ;
    cout << endl << endl ;

    do
    {
        /// Attente démarrage nouveau round
        GetReady4NextRound() ;

        /// Attribution des "rôles" pour le tour de jeu
        /// - Qui est l'attaquant ?
        /// - Qui est la cible ?
        if (!flag_tour_joueur)      /// Tour du joueur 1 : le joueur 1 est l'attaquant / le joueur 2 est la cible
        {
            vaisseau_attaquant_tour = &vaisseau_j1 ;
            vaisseau_cible_tour = &vaisseau_j2 ;
        }
        else                        /// Tour du joueur 2 : le joueur 2 est l'attaquant / le joueur 1 est la cible
        {
            vaisseau_attaquant_tour = &vaisseau_j2 ;
            vaisseau_cible_tour = &vaisseau_j1 ;
        }

        /// Annonce de l'attaquant et demande de choix d'attaque
        choix_attaque_tour = ChoisirAttaque(vaisseau_attaquant_tour) ;
        PresenterVaisseauAttaquant(vaisseau_attaquant_tour) ;
        /// Le vaisseau du joueur attaquant attaque le vaisseau du joueur cible
        cout << endl << endl ;
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl ;
        if (Assaut())
        {
            /// Déclenchement de l'attaque sélectionnée
            if (choix_attaque_tour == 1)
            {
                AttaquerBasic(vaisseau_attaquant_tour, vaisseau_cible_tour) ;
            }
            else
            {
                AttaquerSpecial(vaisseau_attaquant_tour, vaisseau_cible_tour) ;
            }
            cout << "LE VAISSEAU " << RenvoyerNom(vaisseau_cible_tour) << " ENCAISSE " <<  RenvoyerPuissanceFeu(vaisseau_attaquant_tour) << " DEGATS DE COQUE." << endl ;
        }
        else
        {
            cout << "LE VAISSEAU " << RenvoyerNom(vaisseau_attaquant_tour) << " MANQUE SA CIBLE." << endl ;
        }
        // On affiche le nouvel état du vaisseau cible
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl ;
        cout << "ETAT DU VAISSEAU CIBLE" << endl ;
        AfficherCarac(vaisseau_cible_tour) ;
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl ;
        cout << endl << endl ;

        /// Changement de joueur ("inversion de valeur" du booléen)
        flag_tour_joueur = !flag_tour_joueur ;
    }
    while ( (RenvoyerResistanceCoque(&vaisseau_j1) > 0) && (RenvoyerResistanceCoque(&vaisseau_j2) > 0) ) ;

    /// Désignation du vainqueur
    /// Le dernier vaisseau à avoir encaissé des dégâts de l'adversaire est détruit en sortie de boucle => il est le perdant
    /// Le vaisseau du dernier joueur attaquant est donc vainqueur
    AfficherVaisseauVainqueur(vaisseau_attaquant_tour) ;

    GameOver() ;

    return 0;
}

void InitialiserCaracVaisseau(Vaisseau* output_vaisseau)
{
    /* Déclaration des variables locales */
    char local_nom[64] = "" ;
    int local_coque ;
    int local_feu ;

    /* Algorithme local */
    cout << endl << endl ;
    cout << "|******************************************|" << endl ;
    cout << "|********** SaisirCaracVaisseau ***********|" << endl ;
    cout << "|=> Demande de saisie des caracteristiques |" << endl ;
    cout << "|   de votre Vaisseau.                     |" << endl ;
    cout << "|******************************************|" << endl << endl ;

    /// Initialisation des caractéristiques du Vaisseau par appel à la fonction dédiée AffecterCarac avec des valeurs "en dur"
    cout << "Donnez un nom a votre vaisseau (63 caracteres maximum) : " << endl ;

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
        // std::cout << std::cin.gcount() << " characters read: " << local_nom << '\n';
    } catch (const std::ios_base::failure& fail) {
        // handle exception here
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Donnez une resistance de coque a votre vaisseau : " << endl ;
    cin >> local_coque ;
    cout << "Donnez une puissance de feu a votre vaisseau : " << endl ;
    cin >> local_feu ;

    /// Affectation des caractéristiques du vaisseau
    AffecterCarac(output_vaisseau, local_nom, local_coque, local_feu) ;
}

void AfficherVaisseauVainqueur(const Vaisseau* input_vaisseau)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local */
    cout << endl << endl ;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl ;
    cout << "LE VAISSEAU " << RenvoyerNom(input_vaisseau) << " EST VAINQUEUR !" << endl ;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl ;
    cout << endl << endl ;
}

unsigned char ChoisirAttaque(const Vaisseau* input_vaisseau)
{
    /* Déclaration des variables locales */
    unsigned char local_choix = 0 ;

    /* Algorithme local à la fonction */
    do {
        cout << endl << endl ;
        cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl ;
        cout << "VAISSEAU " << RenvoyerNom(input_vaisseau) << " DEVIENT L'ATTAQUANT" << endl ;
        cout << "Choisissez votre attaque: 1 pour Basic ; 2 pour Special" << endl ;
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl ;
        cout << endl << endl ;

        cin >> local_choix ;
    } while (local_choix != 1 && local_choix != 2) ; // Tant qu'on n'a pas saisi une attaque valide

    // Renvoi du choix d'attaque
    return local_choix ;
}

void PresenterVaisseauAttaquant(const Vaisseau* input_vaisseau)
{
    /* Déclaration des variables locales */
    // Aucune variable locale à déclarer

    /* Algorithme local à la fonction */
    cout << endl << endl ;
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl ;
    cout << "VAISSEAU " << RenvoyerNom(input_vaisseau) << " PRET A L'ASSAUT ?" << endl ;
    cout << "(Appuyez sur [Echap] pour lancer l'assaut !)" << endl ;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl ;
    cout << endl << endl ;
    while (!GetAsyncKeyState(VK_ESCAPE)); // Tant qu'on n'a pas appuyé sur la touche [Echap]

    // On "vide" le buffer de scrutation d'appui sur la touche [Echap]
    while(GetAsyncKeyState(VK_ESCAPE));
}
