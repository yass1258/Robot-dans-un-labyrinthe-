#include "TerrainFichier.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
TerrainFichier::TerrainFichier() : Terrain() {}

TerrainFichier::TerrainFichier(const std::string& nomFichier)
    : Terrain(0, 0), nomFichier(nomFichier) {}

void TerrainFichier::creer()  {
    std::ifstream fichier(nomFichier);
    if (!fichier) {
        throw std::runtime_error("Impossible d'ouvrir le fichier : " + nomFichier);
    }

    std::vector<std::vector<char>> nouvelleGrille;
    std::string ligne;
    while (std::getline(fichier, ligne)) {
        std::vector<char> ligneGrille(ligne.begin(), ligne.end());
        nouvelleGrille.push_back(ligneGrille);
    }

    d_lignes = nouvelleGrille.size();
    d_colonnes = nouvelleGrille.empty() ? 0 : nouvelleGrille[0].size();
    //d_grille = std::move(nouvelleGrille);

    fichier.close();
}
