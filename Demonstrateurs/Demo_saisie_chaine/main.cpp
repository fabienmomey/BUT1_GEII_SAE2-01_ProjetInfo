#include <iostream>
#include <limits>

using namespace std;

int main()
{
    char local_nom1[8] = "" ;
    char local_nom2[8] = "" ;
    unsigned int local_coque ;


    cout << "Donnez un nom à votre vaisseau (7 caracteres maximum) : " << endl ;

    cin.exceptions(std::ios_base::failbit); // may throw
    try {
        cin.getline(local_nom1, sizeof(local_nom1)) ; // Permet de lire également les espaces éventuels dans le nom
    } catch (const std::ios_base::failure& fail) {
        // handle exception here
        // std::cout << fail.what() << '\n';
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << endl << "[" << endl ;
    cout << "\tVaisseau " << local_nom1 << " de classe Vaisseau." << endl ;
    cout << "\t|_________________" << endl ;
    cout << "]" << endl ;

    /// La saisie "tronque" automatiquement la chaîne de caractères saisie ...
    /// mais si il y a eu dépassement la saisie suivante récupère ce qui restait dans le buffer, il faut le vider avant toute nouvelle saisie.
    /// En cas de dépassement, cin renvoie une erreur => on ne vide le buffer avant une prochaine saisie que dans ce cas en faisant un try ... catch

    cout << "Donnez un nom à votre vaisseau (7 caracteres maximum) : " << endl ;

    try {
        cin.getline(local_nom2, sizeof(local_nom2)) ; // Permet de lire également les espaces éventuels dans le nom
    } catch (const std::ios_base::failure& fail) {
        // handle exception here
        // std::cout << fail.what() << '\n';
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Donnez une resistance de coque à votre vaisseau : " << endl ;

    try {
        cin >> local_coque ;
    } catch (const std::ios_base::failure& fail) {
        // handle exception here
        // std::cout << fail.what() << '\n';
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << endl << "[" << endl ;
    cout << "\tVaisseau " << local_nom2 << " de classe Vaisseau." << endl ;
    cout << "\t| Resistance de coque (" << local_coque << ")" << endl ;
    cout << "\t|_________________" << endl ;
    cout << "]" << endl ;

    return 0;
}
