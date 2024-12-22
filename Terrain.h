#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>

class Terrain {
public:
    // Constructeur
    Terrain();

    // Création et configuration
    void creer(int lignes, int colonnes);
    void definirDepart(int ligne, int colonne);
    void definirArrivee(int ligne, int colonne);
    void placerMur(int ligne, int colonne);

    // Affichage
    void afficher() const;

    // Accesseurs
    int obtenirLignes() const;
    int obtenirColonnes() const;
    char obtenirCase(int ligne, int colonne) const;
    void modifierCase(int ligne, int colonne, char valeur);

private:
    int nbLignes, nbColonnes;
    std::vector<std::vector<char>> grille;
};
#endif // TERRAIN_H_INCLUDED
