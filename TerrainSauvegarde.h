#ifndef TERRAINSAUVEGARDE_H
#define TERRAINSAUVEGARDE_H

#include "Terrain.h"
#include <string>

class TerrainSauvegarde {
public:
    explicit TerrainSauvegarde(const Terrain& terrain); // Constructeur prenant un Terrain en param�tre

    static void sauvegarderDansFichier(const Terrain& terrain, const std::string& nomFichier);

private:
    const Terrain& d_terrain; // R�f�rence constante au terrain
};

#endif
