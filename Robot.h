#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include "Terrain.h"
#include "Position.h"
#include "Direction.h"
#include <iostream>

class Position;
class Terrain;

class Robot {
public:
    // Constructeur
    Robot(Terrain &terrain, const Position &pos = Position(0, 0), Direction dir = DROITE);

    // D�placement
    void avancer();
    void tournerGauche();
    void tournerDroite();

    // Gestion de la position
    void setPositionner(const Position &pos, Direction dir);
    void setPositionner(int ligne, int colonne, Direction dir);
    Position getPosition() const;
    Direction getDirection() const;


    // D�tection des obstacles
    bool devantMur() const;
    bool aGaucheMur() const;
    bool aDroiteMur() const;
    char caseDevant() const;
    bool murDansDirectionActuelle() const;
    // �tat du robot
    bool estArrive() const;

    // Affichage
    void afficherPosition() const;
    Position obtenirPosition() const;
    Terrain& obtenirTerrain();

private:
    Terrain &d_terrain;
    Position  d_position;
    Direction d_direction;

    friend class Position;
    friend class AfficheurRobot;

    // M�thodes priv�es
    void mettreAJourTerrain();
};

#endif // ROBOT_H_INCLUDED
