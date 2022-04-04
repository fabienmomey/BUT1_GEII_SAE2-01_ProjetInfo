#include <iostream>
#include <windows.h>
#include "moteur_de_jeu.h"

using namespace std;

/// Programme exemple d'utilisation du moteur de jeu
int main()
{
    /* Déclaration des variables principales */
    unsigned int score = 0 ; // Initialisation du score

    /* Algorithme principal */
    while (score < 2) // Tant qu'on n'atteint pas un score de 2
    {
        // Affichage du score
        cout << "Score actuel = " << score << endl ;
        // Attente d'un nouvel assaut
        GetReady4NextRound() ;
        // Assaut et décision
        if (Assaut())
        {
            cout << "Touche !!!" << endl ;
            score++ ; // Incrémentation du score
        }
        else
        {
            cout << "Manque !!!" << endl ;
        }
    }

    // Fin de partie
    cout << "VICTOIRE !!! Vaisseau detruit ..." << endl ;

    GameOver();

    return 0;
}
