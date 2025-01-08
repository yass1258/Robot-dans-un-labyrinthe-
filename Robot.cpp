#include "Robot.h"

// Constructeur
Robot::Robot(Terrain &terrain, const Position &pos, Direction dir)
    : d_terrain(terrain), d_position(pos), d_direction(dir) {
    mettreAJourTerrain();
}

// Déplacement
void Robot::avancer() {

    // Calcul de la nouvelle position
    int nouvelleLigne = d_position.getX();
    int nouvelleColonne = d_position.getY();

    // Calculer la nouvelle position
    switch (d_direction) {
        case HAUT:
            nouvelleLigne --;
            break;
        case DROITE:
            nouvelleColonne ++;
            break;
        case BAS:
            nouvelleLigne ++;
            break;
        case GAUCHE:
            nouvelleColonne --;
            break;
    }

    // Vérifie si la case devant est la case d'arrivée
    if (d_terrain.obtenirCase(nouvelleLigne, nouvelleColonne) == 'A') {
        std::cout << "Le robot est juste avant la case d'arrivée. Arrêt.\n";
        return; // Stoppe le déplacement
    }

    // Vérifie si le mouvement est valide
    if (nouvelleLigne >= 0 && nouvelleLigne < d_terrain.getLignes() &&
        nouvelleColonne >= 0 && nouvelleColonne < d_terrain.getColonnes() &&
        d_terrain.obtenirCase(nouvelleLigne, nouvelleColonne) != 'X') {

        // Efface l'ancienne position
        d_terrain.modifierCase(d_position.getX(), d_position.getY(), '.');

        // Met à jour la position
        d_position.setX(nouvelleLigne);
        d_position.setY(nouvelleColonne);

        // Met à jour la grille avec le robot
        d_terrain.modifierCase(d_position.getX(), d_position.getY(), 'R');
    }
    else {
        std::cout << "Mouvement bloqué par un mur ou hors limites.\n";
    }
}




void Robot::tournerGauche() {
    d_direction = static_cast<Direction>((d_direction + 3) % 4);
    afficherPosition();
}

void Robot::tournerDroite() {
    d_direction = static_cast<Direction>((d_direction + 1) % 4);
    afficherPosition();

}

// Gestion de la position
void Robot::setPositionner(const Position &pos, Direction dir) {
    d_position = pos;
    d_direction = dir;
    mettreAJourTerrain();
    afficherPosition();
}
void Robot::setPositionner(int ligne, int colonne, Direction dir) {
    d_position.setPosition(ligne, colonne);
    d_direction = dir;
    mettreAJourTerrain(); // Met à jour la grille avec la nouvelle position du robot
    afficherPosition();   // Affiche la nouvelle position
}

Position Robot::getPosition() const {
    return d_position;
}

Direction Robot::getDirection() const {
    return d_direction;
}

// Détection des obstacles
bool Robot::devantMur() const {
     int ligne = d_position.getX();
    int colonne = d_position.getY();

    switch (d_direction) {
        case HAUT:
            return ligne == 0 || d_terrain.obtenirCase(ligne - 1, colonne) == 'X';
        case DROITE:
            return colonne == d_terrain.getColonnes() - 1 || d_terrain.obtenirCase(ligne, colonne + 1) == 'X';
        case BAS:
            return ligne == d_terrain.getLignes() - 1 || d_terrain.obtenirCase(ligne + 1, colonne) == 'X';
        case GAUCHE:
            return colonne == 0 || d_terrain.obtenirCase(ligne, colonne - 1) == 'X';
    }
    return false;
}

bool Robot::aGaucheMur() const {
    switch (d_direction) {
        case HAUT:
            return d_position.getY() == 0 || d_terrain.obtenirCase(d_position.getX(), d_position.getY() - 1) == 'X';
        case DROITE:
            return d_position.getX() == d_terrain.getLignes() - 1 ||
                   d_terrain.obtenirCase(d_position.getX() + 1, d_position.getY()) == 'X';
        case BAS:
            return d_position.getY() == d_terrain.getColonnes() - 1 ||
                   d_terrain.obtenirCase(d_position.getX(), d_position.getY() + 1) == 'X';
        case GAUCHE:
            return d_position.getX() == 0 || d_terrain.obtenirCase(d_position.getX() - 1, d_position.getY()) == 'X';
    }
    return false;
}

bool Robot::aDroiteMur() const {
   int ligne = d_position.getX();
    int colonne = d_position.getY();

    switch (d_direction) {
        case HAUT:
            return colonne == d_terrain.getColonnes() - 1 || d_terrain.obtenirCase(ligne, colonne + 1) == 'X';
        case DROITE:
            return ligne == d_terrain.getLignes() - 1 || d_terrain.obtenirCase(ligne + 1, colonne) == 'X';
        case BAS:
            return colonne == 0 || d_terrain.obtenirCase(ligne, colonne - 1) == 'X';
        case GAUCHE:
            return ligne == 0 || d_terrain.obtenirCase(ligne - 1, colonne) == 'X';
    }
    return false;
}

bool Robot::estArrive() const
{
    return d_terrain.obtenirCase(d_position.getX(), d_position.getY()) == 'A';

}


// Affichage
void Robot::afficherPosition() const {
    std::cout << "Robot positionné en (" << d_position.getX() << ", " << d_position.getY()
              << ") direction : ";
    switch (d_direction) {
        case HAUT:
            std::cout << "Haut";
            break;
        case DROITE:
            std::cout << "Droite";
            break;
        case BAS:
            std::cout << "Bas";
            break;
        case GAUCHE:
            std::cout << "Gauche";
            break;
    }
    std::cout << std::endl;
}
Terrain& Robot::obtenirTerrain() {
    return d_terrain; // Renvoie une référence au terrain
}

Position Robot::obtenirPosition() const
{
    return d_position;
}
char Robot::caseDevant() const {
    int ligne = d_position.getX();
    int colonne = d_position.getY();

    switch (d_direction) {
        case HAUT:
            return (ligne > 0) ? d_terrain.obtenirCase(ligne - 1, colonne) : 'X';
        case DROITE:
            return (colonne < d_terrain.getColonnes() - 1) ? d_terrain.obtenirCase(ligne, colonne + 1) : 'X';
        case BAS:
            return (ligne < d_terrain.getLignes() - 1) ? d_terrain.obtenirCase(ligne + 1, colonne) : 'X';
        case GAUCHE:
            return (colonne > 0) ? d_terrain.obtenirCase(ligne, colonne - 1) : 'X';
    }
    return 'X'; // Retourne un mur par défaut si aucune direction valide
}

bool Robot::murDansDirectionActuelle() const {
    int ligne = d_position.getX();
    int colonne = d_position.getY();

    switch (d_direction) {
        case HAUT:
            return ligne == 0 || d_terrain.obtenirCase(ligne - 1, colonne) == 'X';
        case DROITE:
            return colonne == d_terrain.getColonnes() - 1 || d_terrain.obtenirCase(ligne, colonne + 1) == 'X';
        case BAS:
            return ligne == d_terrain.getLignes() - 1 || d_terrain.obtenirCase(ligne + 1, colonne) == 'X';
        case GAUCHE:
            return colonne == 0 || d_terrain.obtenirCase(ligne, colonne - 1) == 'X';
    }
    return true; // Par défaut, considère qu'il y a un mur
}
// Méthodes privées
void Robot::mettreAJourTerrain() {
    d_terrain.modifierCase(d_position.getX(), d_position.getY(), 'R');
}
