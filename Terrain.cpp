#include "Terrain.h"

// Constructeur
Terrain::Terrain() : nbLignes(0), nbColonnes(0) {}

// Création d'un terrain vide
void Terrain::creer(int lignes, int colonnes) {
    nbLignes = lignes;
    nbColonnes = colonnes;
    grille.assign(lignes, std::vector<char>(colonnes, '.')); // '.' pour les cases vides
}

// Configuration des cases spéciales
void Terrain::definirDepart(int ligne, int colonne) {
    grille[ligne][colonne] = 'D'; // Case départ
}

void Terrain::definirArrivee(int ligne, int colonne) {
    grille[ligne][colonne] = 'A'; // Case arrivée
}

void Terrain::placerMur(int ligne, int colonne) {
    grille[ligne][colonne] = 'X'; // Mur
}

// Affichage simple
void Terrain::afficher() const {
    for (const auto& ligne : grille) {
        for (char cellule : ligne) {
            std::cout << cellule; // Affiche chaque case
        }
        std::cout << std::endl; // Nouvelle ligne
    }
}

//affichage en incluant la position du robot
void Terrain::afficher(const Robot* robot=nullptr) const {
    for (int i = 0; i < nbLignes; ++i) {
        for (int j = 0; j < nbColonnes; ++j) {
            if (robot && robot->obtenirLigne() == i && robot->obtenirColonne() == j) {
                std::cout << 'R'; // Affiche le robot à sa position actuelle
            } else {
                std::cout << grille[i][j]; // Affiche la case du terrain
            }
        }
        std::cout << std::endl;
    }
}

// Accesseurs
int Terrain::obtenirLignes() const {
    return nbLignes;
}

int Terrain::obtenirColonnes() const {
    return nbColonnes;
}

char Terrain::obtenirCase(int ligne, int colonne) const {
    return grille[ligne][colonne];
}

void Terrain::modifierCase(int ligne, int colonne, char valeur) {
    grille[ligne][colonne] = valeur;
}
