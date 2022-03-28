#ifndef LIB_VAISSEAU_H_INCLUDED
#define LIB_VAISSEAU_H_INCLUDED

/**
    ---------------------------------------
    | Définition de la Structure Vaisseau |
    ---------------------------------------

    { Contient toutes les caractéritiques d'un conteneur Vaisseau générique }

    Vaisseau :  le type composé de
                <
                    m_classe            :   1 chaîne de caractères  { la classe du vaisseau : sa valeur sera fixée à "Vaisseau" }
                    m_nom               :   1 chaîne de caractères  { le nom du Vaisseau }
                    m_resistance_coque  :   1 entier                { la résistance de coque du vaisseau = ses "points de vie"  }
                    m_puissance_feu     :   1 entier                { la puissance de feu du vaisseau = ses "points d'attaque"  }
                >
 **/

struct Vaisseau {

    char m_classe[32]               ; // Chaîne de caractères pouvant contenir 31 caractères maximum + le caractère de fin de chaîne '\0'
    char m_nom[64]                  ; // Chaîne de caractères pouvant contenir 63 caractères maximum + le caractère de fin de chaîne '\0'
    int m_resistance_coque ;
    int m_puissance_feu    ;
} ;

/**
    -------------------------------------------------------------------------------------
    | Définition de la librairie permettant de manipuler des variables de type Vaisseau |
    -------------------------------------------------------------------------------------
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
void AffecterCarac (Vaisseau*, const char*, const int, const int) ;

/*
    {
        R   :   Fonction permettant d'afficher toutes les caractéristiques d'un Vaisseau
        E   :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau dont on souhaite afficher les caractéristiques)
        E/S :   vide
        S   :   vide
    }
    AfficherCarac   :   la fonction (1 pointeur sur Vaisseau) -> vide
*/
void AfficherCarac (const Vaisseau*) ;

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
void AffecterClasse (Vaisseau*, const char*) ;

/*
    {
        R   :   Fonction permettant d'affecter une valeur à la caractérisitque "m_nom" d'un Vaisseau
        E   :   1 chaîne de caractères (la valeur du nom du vaisseau)
        E/S :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau auquel on affecte la valeur donnée en entrée)
        S   :   vide
    }
    AffecterNom   :   la fonction (1 pointeur sur Vaisseau, 1 chaîne de caractères) -> vide
*/
void AffecterNom (Vaisseau*, const char*) ;

/*
    {
        R   :   Fonction permettant d'affecter une valeur à la caractérisitque "m_resistance_coque" d'un Vaisseau
        E   :   1 entier (a valeur de résistance de coque)
        E/S :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau auquel on affecte la valeur donnée en entrée)
        S   :   vide
    }
    AffecterResistanceCoque   :   la fonction (1 pointeur sur Vaisseau, 1 entier) -> vide
*/
void AffecterResistanceCoque (Vaisseau*, const int) ;

/*
    {
        R   :   Fonction permettant d'affecter une valeur à la caractérisitque "m_puissance_feu" d'un Vaisseau
        E   :   1 entier (a valeur de puissance de feu)
        E/S :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau auquel on affecte la valeur donnée en entrée)
        S   :   vide
    }
    AffecterPuissanceFeu   :   la fonction (1 pointeur sur Vaisseau, 1 entier) -> vide
*/
void AffecterPuissanceFeu (Vaisseau*, const int) ;

/*
    {
        R   :   Fonction permettant de renvoyer la valeur à la caractérisitque "m_classe" d'un Vaisseau
        E   :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau dont on souhaite récupérer la classe)
        E/S :   vide
        S   :   1 chaîne de caractères (en lecture seule) (la classe du vaisseau)
    }
    RenvoyerNom   :   la fonction (1 pointeur sur Vaisseau) -> 1 chaîne de caractères (en lecture seule)
*/
const char* RenvoyerClasse (const Vaisseau*) ;
/// On envoie un pointeur vers une variable en "lecture seule". Les champs sont donc en lecture seule également
/// et on est obligé de renvoyer un type "non modifiable" avec le mot-clé const.

/*
    {
        R   :   Fonction permettant de renvoyer la valeur à la caractérisitque "m_nom" d'un Vaisseau
        E   :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau dont on souhaite récupérer le nom)
        E/S :   vide
        S   :   1 chaîne de caractères (en lecture seule)
    }
    RenvoyerNom   :   la fonction (1 pointeur sur Vaisseau) -> 1 chaîne de caractères (en lecture seule)
*/
const char* RenvoyerNom (const Vaisseau*) ;
/// On envoie un pointeur vers une variable en "lecture seule". Les champs sont donc en lecture seule également
/// et on est obligé de renvoyer un type "non modifiable" avec le mot-clé const.

/*
    {
        R   :   Fonction permettant de renvoyer la valeur à la caractérisitque "m_resistance_coque" d'un Vaisseau
        E   :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau dont on souhaite récupérer la résistance de coque)
        E/S :   vide
        S   :   1 entier (en lecture seule)
    }
    RenvoyerResistanceCoque   :   la fonction (1 pointeur sur Vaisseau) -> 1 entier
*/
int RenvoyerResistanceCoque (const Vaisseau*) ;
/// On envoie un pointeur vers une variable en "lecture seule". Les champs sont donc en lecture seule également
/// et on est obligé de renvoyer un type "non modifiable" avec le mot-clé const.

/*
    {
        R   :   Fonction permettant de renvoyer la valeur à la caractérisitque "m_puissance_feu" d'un Vaisseau
        E   :   1 pointeur sur Vaisseau (l'adresse de la variable Vaisseau dont on souhaite récupérer la puissance de feu)
        E/S :   vide
        S   :   1 entier (en lecture seule)
    }
    RenvoyerPuissanceFeu   :   la fonction (1 pointeur sur Vaisseau) -> 1 entier
*/
int RenvoyerPuissanceFeu (const Vaisseau*) ;
/// On envoie un pointeur vers une variable en "lecture seule". Les champs sont donc en lecture seule également
/// et on est obligé de renvoyer un type "non modifiable" avec le mot-clé const.


#endif // LIB_VAISSEAU_H_INCLUDED
