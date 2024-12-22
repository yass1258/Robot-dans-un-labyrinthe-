#include "Robot.h"
#include <iostream>

// Constructeur
Robot::Robot(Terrain &t) : terrain(t), ligne(0), colonne(0), direction(DROITE) {}

// Déplacement
void Robot::avancer() {
    switch (direction) {
        case HAUT:    if (ligne > 0 && terrain.obtenirCase(ligne - 1, colonne) != 'X') ligne--; break;
        case DROITE:  if (colonne < terrain.obtenirColonnes() - 1 && terrain.obtenirCase(ligne, colonne + 1) != 'X') colonne++; break;
        case BAS:     if (ligne < terrain.obtenirLignes() - 1 && terrain.obtenirCase(ligne + 1, colonne) != 'X') ligne++; break;
        case GAUCHE:  if (colonne > 0 && terrain.obtenirCase(ligne, colonne - 1) != 'X') colonne--; break;
    }
    rafraichirTerrain();
    terrain.afficher(); // Affiche le terrain après chaque mouvement
    afficherPosition();
}

void Robot::tournerGauche() {
    direction = static_cast<Direction>((direction + 3) % 4);
    rafraichirTerrain();
    terrain.afficher(); // Affiche le terrain après chaque rotation
    afficherPosition();
}

void Robot::tournerDroite() {
    direction = static_cast<Direction>((direction + 1) % 4);
    rafraichirTerrain();
    terrain.afficher(); // Affiche le terrain après chaque rotation
    afficherPosition();
}

// Positionner le robot
void Robot::sePositionner(int l, int c, Direction dir) {
    ligne = l;
    colonne = c;
    direction = dir;
    afficherPosition();
}

// Détection des obstacles
bool Robot::devantMur() const {
    switch (direction) {
        case HAUT:    return ligne == 0 || terrain.obtenirCase(ligne - 1, colonne) == 'X';
        case DROITE:  return colonne == terrain.obtenirColonnes() - 1 || terrain.obtenirCase(ligne, colonne + 1) == 'X';
        case BAS:     return ligne == terrain.obtenirLignes() - 1 || terrain.obtenirCase(ligne + 1, colonne) == 'X';
        case GAUCHE:  return colonne == 0 || terrain.obtenirCase(ligne, colonne - 1) == 'X';
    }
    return false;
}

bool Robot::aGaucheMur() const {
    switch (direction) {
        case HAUT:    return colonne == 0 || terrain.obtenirCase(ligne, colonne - 1) == 'X';
        case DROITE:  return ligne == terrain.obtenirLignes() - 1 || terrain.obtenirCase(ligne + 1, colonne) == 'X';
        case BAS:     return colonne == terrain.obtenirColonnes() - 1 || terrain.obtenirCase(ligne, colonne + 1) == 'X';
        case GAUCHE:  return ligne == 0 || terrain.obtenirCase(ligne - 1, colonne) == 'X';
    }
    return false;
}

bool Robot::aDroiteMur() const {
    switch (direction) {
        case HAUT:    return colonne == terrain.obtenirColonnes() - 1 || terrain.obtenirCase(ligne, colonne + 1) == 'X';
        case DROITE:  return ligne == 0 || terrain.obtenirCase(ligne - 1, colonne) == 'X';
        case BAS:     return colonne == 0 || terrain.obtenirCase(ligne, colonne - 1) == 'X';
        case GAUCHE:  return ligne == terrain.obtenirLignes() - 1 || terrain.obtenirCase(ligne + 1, colonne) == 'X';
    }
    return false;
}

bool Robot::estArrive() const {
    return terrain.obtenirCase(ligne, colonne) == 'A';
}

// Afficher la position actuelle du robot
void Robot::afficherPosition() const {
    std::cout << "Robot positionné en (" << ligne << ", " << colonne << ") direction : ";
    switch (direction) {
        case HAUT:    std::cout << "Haut"; break;
        case DROITE:  std::cout << "Droite"; break;
        case BAS:     std::cout << "Bas"; break;
        case GAUCHE:  std::cout << "Gauche"; break;
    }
    std::cout << std::endl;
}

// Algorithme de la main droite
void Robot::sortirMainDroite() {
    while (terrain.obtenirCase(ligne, colonne) != 'A') { // Tant que le robot n'est pas arrivé
        if (!aDroiteMur()) {
            tournerDroite();
            avancer();
        } else if (!devantMur()) {
            avancer();
        } else {
            tournerGauche();
        }
    }
    std::cout << "Le robot a atteint la sortie !" << std::endl;
}

// Algorithme de Pledge
void Robot::sortirPledge() {
    int compteur = 0;

    while (terrain.obtenirCase(ligne, colonne) != 'A') { // Tant que le robot n'est pas arrivé
        if (!devantMur()) {
            avancer();
        } else {
            tournerDroite();
            compteur--;
            if (!devantMur()) {
                avancer();
                compteur++;
            }
        }
    }
    std::cout << "Le robot a atteint la sortie !" << std::endl;
}
void Robot::rafraichirTerrain() {
    // Effacer la position précédente du robot
    for (int i = 0; i < terrain.obtenirLignes(); ++i) {
        for (int j = 0; j < terrain.obtenirColonnes(); ++j) {
            if (terrain.obtenirCase(i, j) == 'R') {
                terrain.modifierCase(i, j, '.'); // Remettre une case vide
            }
        }
    }
    // Mettre à jour la position actuelle
    terrain.modifierCase(ligne, colonne, 'R');
}


int Robot::obtenirLigne() const {
    return ligne;
}

int Robot::obtenirColonne() const {
    return colonne;
}

Terrain& Robot::obtenirTerrain() {
    return terrain;
}
