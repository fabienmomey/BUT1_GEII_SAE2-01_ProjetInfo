#include <iostream>
#include <limits>
#include <windows.h>
#include "moteur_de_jeu.h"
#include "lib_vaisseau2.h"
#include "procedures_test_phase2.h"

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
        R : Fonction d'annonce du Vaisseau assaillant (attente d'un appui sur la touche [Echap])
        E : 1 pointeur sur Vaisseau (l'adresse du Vaisseau assaillant)
        E/S : vide
        S : vide
    }
*/
void NextPlayer(const Vaisseau*) ;
/// Cette fonction s'intègre au moteur de jeu

using namespace std;

int main()
{
    /* Déclaration des variables principales */
    bool flag_tour_joueur = 0 ; // variable indiquant le tour du joueur courant (false : joueur 1 ; true : joueur 2)
    /// Déclaration des 2 vaisseaux pour le duel
    Vaisseau vaisseau_j1, vaisseau_j2 ;

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

        if (!flag_tour_joueur)      /// Tour du joueur 1
        {
            NextPlayer(&vaisseau_j1) ;
            /// Le vaisseau du joueur 2 encaisse des dégâts égaux à la puissance de feu du vaisseau du joueur 1
            cout << endl << endl ;
            cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl ;
            if (Assaut())
            {
                SubirDegatsCoque(&vaisseau_j2, RenvoyerPuissanceFeu(&vaisseau_j1)) ;
                cout << "LE VAISSEAU " << RenvoyerNom(&vaisseau_j2) << " ENCAISSE " <<  RenvoyerPuissanceFeu(&vaisseau_j1) << " DEGATS DE COQUE." << endl ;
            }
            else
            {
                cout << "LE VAISSEAU " << RenvoyerNom(&vaisseau_j1) << " MANQUE SA CIBLE." << endl ;
            }
            // On affiche le nouvel état du vaisseau cible
            AfficherCarac(&vaisseau_j2) ;
            cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl ;
            cout << endl << endl ;
        }
        else                        /// Tour du joueur 2
        {
            NextPlayer(&vaisseau_j2) ;
            /// Le vaisseau du joueur 1 encaisse des dégâts égaux à la puissance de feu du vaisseau du joueur 2
            cout << endl << endl ;
            cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl ;
            if (Assaut())
            {
                SubirDegatsCoque(&vaisseau_j1, RenvoyerPuissanceFeu(&vaisseau_j2)) ;
                cout << "LE VAISSEAU " << RenvoyerNom(&vaisseau_j1) << " ENCAISSE " <<  RenvoyerPuissanceFeu(&vaisseau_j2) << " DEGATS DE COQUE." << endl ;
            }
            else
            {
                cout << "LE VAISSEAU " << RenvoyerNom(&vaisseau_j2) << " MANQUE SA CIBLE." << endl ;
            }
            // On affiche le nouvel état du vaisseau
            AfficherCarac(&vaisseau_j1) ;
            cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl ;
            cout << endl << endl ;
        }

        /// Changement de joueur ("inversion de valeur" du booléen)
        flag_tour_joueur = !flag_tour_joueur ;
    }
    while ( (RenvoyerResistanceCoque(&vaisseau_j1) > 0) && (RenvoyerResistanceCoque(&vaisseau_j2) > 0) ) ;

    /// Désignation du vainqueur
    // Le dernier vaisseau à avoir encaissé des dégâts de l'adversaire est détruit en sortie de boucle => il est le perdant
    if (flag_tour_joueur)
    {
        /// Le vaisseau du joueur 1 est vainqueur
        AfficherVaisseauVainqueur(&vaisseau_j1) ;
    }
    else
    {
        /// Le vaisseau du joueur 2 est vainqueur
        AfficherVaisseauVainqueur(&vaisseau_j2) ;
    }

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

void NextPlayer(const Vaisseau* input_vaisseau)
{
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

