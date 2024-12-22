#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include <vector>
#include <iostream>
#include "Terrain.h"

// D�finir les directions du robot
enum Direction { HAUT, DROITE, BAS, GAUCHE };

class Robot {
public:
    // Constructeur
    Robot(Terrain &terrain);

    // D�placements
    void avancer();
    void tournerGauche();
    void tournerDroite();
    void sePositionner(int ligne, int colonne, Direction direction);

    // D�tection des obstacles
    bool devantMur() const;
    bool aGaucheMur() const;
    bool aDroiteMur() const;

    //si le rebot est arriv� a la fin du labyrinth
     bool estArrive() const;
    // Affichage de la position
    void afficherPosition() const;

    // Algorithmes de sortie
    void sortirMainDroite();
    void sortirPledge();
    void rafraichirTerrain();

    int obtenirLigne() const;
    int obtenirColonne() const;
    Terrain& obtenirTerrain();
private:
    Terrain& terrain;
    int ligne, colonne;
    Direction direction;
};


#endif // ROBOT_H_INCLUDED
