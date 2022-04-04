#include <iostream>
#include <windows.h>
#include "moteur_de_jeu.h"

using namespace std ;

/// Fonction de haut niveau Assaut gérant le système de visée/tir
/*
    {
        R : Fonction gérant le sytème de visée/tir dynamique par appui asynchrone sur le touche [ESPACE]
        E : vide
        E/S : vide
        S : 1 booléen (la réussite du tir => VRAI si réussi et FAUX sinon)
    }
*/
bool Assaut()
{
    /* Déclaration des variables locales */
    unsigned int local_pos ;
    bool local_touche ;

    /* Algorithme local à la fonction */
    /// Affichage de la cible dynamique avec curseur en mouvement (par raffraîchissement du terminal)
    local_pos = 0 ;
    while (!GetAsyncKeyState(VK_SPACE)) // Tant qu'on n'a pas appuyé sur la touche [ESPACE]
    {
        // Affichage de la cible complète
        DisplayTarget(local_pos) ;

        // Calcul de la position suivante du curseur de cible
        local_pos+=INC ;
        local_pos=local_pos%(L_TARGET-1);

        // Attente et raffraîchissment du terminal
        Sleep(1) ;
        system("cls") ; /// ATTENTION cette fonction est "lente" et prend quelques centaines de millisecondes (on ne peut pas aller plus vite)
    }

    /// Récupération de la dernière position du curseur
    local_pos -= INC ;
    // Décision de réussite du tir
    if (local_pos>((L_TARGET/2)-(INC/2)) && local_pos<((L_TARGET/2)+(INC/2)))
    {
        local_touche = true ; // Tir réussi => touché !!!
    }
    else
    {
        local_touche = false ; // Tir manqué
    }

    // On "vide" le buffer de scrutation d'appui sur la touche [ESPACE]
    while(GetAsyncKeyState(VK_SPACE));

    // On retourne le résultat du tir
    return local_touche ;
}

/// Fonctions de bas niveau utilisées dans la fonction Assaut
/*
    {
        R : Fonction affichant le curseur de visée à une position donnée dans le champ de tir
        E : 1 entier non signé (la position du curseur dans le champ de tir)
        E/S : vide
        S : vide
    }
*/
void DisplayTarget(const unsigned int input_pos)
{
    /* Déclaration des variables locales */
    char target[L_TARGET+3] ;

    /* Algorithme local à la fonction */
    GetShootingRange(target) ;

    // Affichage champ de tir
    cout << target << endl ;
    // Affichage du curseur de visée
    // => choix de 3 symboles positionnés en vertical : '^' ; '|' ; '-'
    DisplayCursor(input_pos, 0x5e) ;
    DisplayCursor(input_pos, '|') ;
    DisplayCursor(input_pos, '-') ;
    // Affichage champ de tir
    cout << target << endl ;

}
/*
    {
        R : Fonction remplissant une chaîne de caractères simulant champ de tir avec la "zone de réussite"
        E : vide
        E/S : 1 pointeur sur caractère (chaîne de caractères) => la chaîne à remplir
        S : vide
    }
*/
void GetShootingRange(char* output_target)
{
    /* Déclaration des variables locales */
    unsigned int i ;

    /* Algorithme local à la fonction */
    // Boucle de remplissage de la chaîne "champ de tir"
    for (i=0; i<L_TARGET+2; i++)
    {
        output_target[i] = '-' ; // Symbole '-' définissant le champ de tir
    }
    output_target[(L_TARGET/2)-INC/2+1] = '|' ; // Début de la zone de réussite (symbole '|' pour signifier cette borne)
    output_target[(L_TARGET/2)+INC/2+1] = '|' ; // Fin de la zone de réussite (symbole '|' pour signifier cette borne)
    output_target[L_TARGET+2] = '\0' ;          // caractère de fin de chaîne
}
/*
    {
        R : Fonction affichant une partie du curseur de visée à une position donnée dans le champ de tir
            et avec un symbole donné => permet de construire son propre curseur de visée en 1 composition
            de symboles sur plusieurs lignes
        E : 1 entier non signé (la position du curseur dans le champ de tir)
            1 caractère (le symbole souhaité comme élément du curseur)
        E/S : vide
        S : vide
    }
*/
void DisplayCursor(const unsigned int input_pos, const char input_symbol)
{
    /* Déclaration des variables locales */
    unsigned int i ;

    /* Algorithme local à la fonction */
    i=0 ;
    cout << "|" ; // Début du champ
    for (i=0; i<L_TARGET; i++) // Parcours du champ de tir
    {
        // Affichage symbole si position courante correspondante à la position d'entrée
        if (input_pos != i)
        {
            cout << " " ;
        }
        else
        {
            cout << input_symbol ;
        }
    }
    cout << "|" << endl ; // Fin du champ
}

/// Fonctions de gestion des phases de jeu au "tour par tour"
/*
    {
        R : Fonction d'attente d'un nouvel assaut (attente d'un appui sur la touche [Echap])
        E : vide
        E/S : vide
        S : vide
    }
*/
void GetReady4NextRound()
{
    /* Algorithme local à la fonction */
    cout << "Pret pour l'assaut suivant ? (Appuyez sur [Echap] pour continuer)" << endl ;
    while (!GetAsyncKeyState(VK_ESCAPE)); // Tant qu'on n'a pas appuyé sur la touche [Echap]

    // On "vide" le buffer de scrutation d'appui sur la touche [Echap]
    while(GetAsyncKeyState(VK_ESCAPE));
    system("cls") ;
}
/*
    {
        R : Fonction de validation de fin de partie (attente d'un appui sur la touche [Echap])
        E : vide
        E/S : vide
        S : vide
    }
*/
void GameOver()
{
    /* Algorithme local à la fonction */
    cout << "La partie est terminee. Appuyez sur [Echap] pour quitter." << endl ;
    while (!GetAsyncKeyState(VK_ESCAPE)); // Tant qu'on n'a pas appuyé sur la touche [Echap]

    // On "vide" le buffer de scrutation d'appui sur la touche [Echap]
    while(GetAsyncKeyState(VK_ESCAPE));
    system("cls") ;
}
