#include "Terrain.h"
#include "Constantes.h"
#include <fstream> // Assure l'accès aux classes std::ifstream et std::ofstream
#include <stdexcept> // Pour lever des exceptions en cas d'erreur
#include <iostream>

// Constructeur par défaut
Terrain::Terrain() : d_lignes(0), d_colonnes(0) {}

// Constructeur avec dimensions
Terrain::Terrain(int lignes, int colonnes) : d_lignes(lignes), d_colonnes(colonnes) {
    creer(lignes, colonnes);
}

// Création d'un terrain vide
/*void Terrain::creer(int lignes, int colonnes) {
    d_lignes = lignes;
    d_colonnes = colonnes;
    d_grille.assign(lignes, std::vector<char>(colonnes, '.')); // Initialise avec des cases vides ('.')
}*/
void Terrain::importerDepuisFichier(const std::string& nomFichier) {
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open()) {
        throw std::runtime_error("Erreur : Impossible d'ouvrir le fichier pour l'importation.");
    }

    d_grille.clear();
    std::string ligne;
    while (std::getline(fichier, ligne)) {
        std::vector<char> ligneGrille;
        for (char c : ligne) {
            if (c != ' ') { // Ignore les espaces
                ligneGrille.push_back(c);
            }
        }
        d_grille.push_back(ligneGrille);
    }

    fichier.close();

    // Mettre à jour les dimensions
    d_lignes = d_grille.size();
    d_colonnes = d_grille.empty() ? 0 : d_grille[0].size();

    // Vérifier que toutes les lignes ont la même largeur
    for (const auto& ligne : d_grille) {
        if (ligne.size() != d_colonnes) {
            throw std::runtime_error("Erreur : Les lignes du labyrinthe ont des tailles différentes.");
        }
    }
}

void Terrain::sauvegarderDansFichier(const std::string& nomFichier) const {
    std::ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        throw std::runtime_error("Erreur : Impossible d'ouvrir le fichier pour la sauvegarde.");
    }

    for (const auto& ligne : d_grille) {
        for (size_t i = 0; i < ligne.size(); ++i) {
            fichier << ligne[i];
            if (i < ligne.size() - 1) {
                fichier << " "; // Ajouter un espace entre les caractères
            }
        }
        fichier << "\n";
    }

    fichier.close();
}


    void Terrain::creer() {
    for (int i = 0; i < d_lignes; ++i) {
        for (int j = 0; j < d_colonnes; ++j) {
            if (i == 0 || i == d_lignes - 1 || j == 0 || j == d_colonnes - 1) {
                d_grille[i][j] = 'X';
            }
        }
    }
}

void Terrain::creer(int lignes, int colonnes) {
    d_lignes = lignes;
    d_colonnes = colonnes;
    d_grille.assign(lignes, std::vector<char>(colonnes, VIDE)); // Initialise avec des cases vides (VIDE)

    // Ajouter des murs tout autour
    for (int i = 0; i < d_lignes; ++i) {
        for (int j = 0; j < d_colonnes; ++j) {
            if (i == 0 || i == d_lignes - 1 || j == 0 || j == d_colonnes - 1) {
                d_grille[i][j] = MUR; // Mur
            }
        }
    }
}


// Définir la case de départ
void Terrain::definirDepart(int ligne, int colonne) {

    if (ligne >= 0 && ligne < d_lignes && colonne >= 0 && colonne < d_colonnes) {
        if (d_grille[ligne][colonne] == 'X') {
            std::cerr << "Erreur : Impossible de définir le départ sur un mur.\n";
            return;
        }
        d_grille[ligne][colonne] = 'D'; // Départ
    }
}

// Définir la case d'arrivée
void Terrain::definirArrivee(int ligne, int colonne) {

    if (ligne >= 0 && ligne < d_lignes && colonne >= 0 && colonne < d_colonnes) {
        if (d_grille[ligne][colonne] == 'X') {
            std::cerr << "Erreur : Impossible de définir l'arrivée sur un mur.\n";
            return;
        }
        d_grille[ligne][colonne] = 'A'; // Arrivée
    }
}



// Placer un mur
void Terrain::placerMur(int ligne, int colonne) {
    /*if (ligne >= 0 && ligne < d_lignes && colonne >= 0 && colonne < d_colonnes) {
        d_grille[ligne][colonne] = 'X'; // 'X' pour Mur
    }*/
    if (ligne >= 0 && ligne < d_lignes && colonne >= 0 && colonne < d_colonnes) {
        if (d_grille[ligne][colonne] != 'D' && d_grille[ligne][colonne] != 'A') {
            d_grille[ligne][colonne] = 'X'; // Mur
        }
    }
}

// Affichage du terrain
void Terrain::afficher(const Robot* robot) const {
    for (int i = 0; i < d_lignes; ++i) {
        for (int j = 0; j < d_colonnes; ++j) {
            if (robot && robot->obtenirPosition().getX() == i && robot->obtenirPosition().getY() == j) {
                std::cout << 'R'; // Superpose le robot
            } else {
                std::cout << d_grille[i][j];
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

// Accesseurs
int Terrain::getLignes() const {
    return d_lignes;
}

int Terrain::getColonnes() const {
    return d_colonnes;
}
const std::vector<std::vector<char>>& Terrain::getGrille() const {
    return d_grille;
}

char Terrain::obtenirCase(int ligne, int colonne) const {
    if (ligne >= 0 && ligne < d_lignes && colonne >= 0 && colonne < d_colonnes) {
        return d_grille[ligne][colonne];
    }
    return '\0'; // Retourne un caractère nul si la position est invalide
}

void Terrain::modifierCase(int ligne, int colonne, char valeur) {
    if (ligne >= 0 && ligne < d_lignes && colonne >= 0 && colonne < d_colonnes) {
        d_grille[ligne][colonne] = valeur;
    }
}
Position Terrain::obtenirPositionDepart() const {
    return depart; // Supposant que `depart` est un membre de type Position
}
