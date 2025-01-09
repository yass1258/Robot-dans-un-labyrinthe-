#include "TerrainSauvegarde.h"
#include <fstream>
#include <iostream>

void TerrainSauvegarde::sauvegarderDansFichier(const Terrain& terrain, const std::string& nomFichier) {
    std::ofstream fichier(nomFichier);
    if (!fichier) {
        std::cerr << "Erreur : Impossible de créer le fichier " << nomFichier << "\n";
        return;
    }

    fichier << terrain.getLignes() << " " << terrain.getColonnes() << "\n";
    for (const auto& ligne : terrain.getGrille()) {
        for (const auto& caseGrille : ligne) {
            fichier << caseGrille;
        }
        fichier << '\n';
    }

    fichier.close();
    std::cout << "Terrain sauvegardé dans le fichier : " << nomFichier << "\n";
}

