#ifndef TERRAINFICHIER_H
#define TERRAINFICHIER_H

#include "Terrain.h"
#include <string>

class TerrainFichier : public Terrain {
public:
    TerrainFichier();
    TerrainFichier(const std::string& nomFichier);
    void creer() override;

private:
     int d_lignes;
    int d_colonnes;
    std::string nomFichier;
    std::vector<std::vector<char>> d_grille;
};

#endif
