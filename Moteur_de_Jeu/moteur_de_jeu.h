#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

/* CONSTANTE GLOBALE DÉFINISSANT LA LARGEUR DE LA "CIBLE" */
const unsigned int L_TARGET = 51 ;
/* PARAMÈTRE CARACTÉRISANT LA VITESSE DE DÉPLACEMENT DU CURSEUR DE VISÉE */
const unsigned int INC = 5 ;

/// Fonction de haut niveau Assaut gérant le système de visée/tir
/*
    {
        R : Fonction gérant le sytème de visée/tir dynamique par appui asynchrone sur le touche [ESPACE]
        E : vide
        E/S : vide
        S : 1 booléen (la réussite du tir => VRAI si réussi et FAUX sinon)
    }
*/
bool Assaut() ;

/// Fonctions de bas niveau utilisées dans la fonction Assaut
/*
    {
        R : Fonction affichant le curseur de visée à une position donnée dans le champ de tir
        E : 1 entier non signé (la position du curseur dans le champ de tir)
        E/S : vide
        S : vide
    }
*/
void DisplayTarget(const unsigned int) ;
/*
    {
        R : Fonction remplissant une chaîne de caractères simulant champ de tir avec la "zone de réussite"
        E : vide
        E/S : 1 pointeur sur caractère (chaîne de caractères) => la chaîne à remplir
        S : vide
    }
*/
void GetShootingRange(char*) ;
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
void DisplayCursor(const unsigned int, const char) ;

/// Fonctions de gestion des phases de jeu au "tour par tour"
/*
    {
        R : Fonction d'attente d'un nouvel assaut (attente d'un appui sur la touche [Echap])
        E : vide
        E/S : vide
        S : vide
    }
*/
void GetReady4NextRound() ;
/*
    {
        R : Fonction de validation de fin de partie (attente d'un appui sur la touche [Echap])
        E : vide
        E/S : vide
        S : vide
    }
*/
void GameOver() ;

#endif // FONCTIONS_H_INCLUDED
