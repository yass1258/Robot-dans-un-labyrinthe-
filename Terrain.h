#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>
#include "Position.h"
#include "Robot.h"

class Terrain {
public:
    // Constructeurs
    Terrain();
    Terrain(int lignes, int colonnes);

    // Importer le labyrinthe depuis un fichier texte
    void importerDepuisFichier(const std::string& nomFichier);
    // Sauvegarder le labyrinthe dans un fichier texte
    void sauvegarderDansFichier(const std::string& nomFichier) const;

    // Gestion du terrain
    void creer(int lignes, int colonnes);
    void definirDepart(int ligne, int colonne);
    void definirArrivee(int ligne, int colonne);
    void placerMur(int ligne, int colonne);
    void afficher(const Robot* robot = nullptr) const;

    Position obtenirPositionDepart() const;
    Position obtenirPositionArrivee() const;

    // Accesseurs
    int getLignes() const;
    int getColonnes() const;
    char obtenirCase(int ligne, int colonne) const;
    void modifierCase(int ligne, int colonne, char valeur);

private:
    int d_lignes;
    int d_colonnes;
    Position depart;
    Position arrivee;
    std::vector<std::vector<char>> d_grille;
};

#endif // TERRAIN_H_INCLUDED
