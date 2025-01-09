#include "Capteur.h"
#include "Constantes.h"

Capteur::Capteur(Robot& robot) : d_robot(robot) {}

bool Capteur::devantMur() const {
    // Calculer la position devant le robot
    int ligne = d_robot.obtenirPosition().getX();
    int colonne = d_robot.obtenirPosition().getY();

    switch (d_robot.getDirection()) {
        case HAUT:
            ligne -= 1;
            break;
        case DROITE:
            colonne += 1;
            break;
        case BAS:
            ligne += 1;
            break;
        case GAUCHE:
            colonne -= 1;
            break;
    }

    // Vérifier si la case est un mur
    return d_robot.obtenirTerrain().obtenirCase(ligne, colonne) == MUR;
}

bool Capteur::aDroiteMur() const {
    // Calculer la position à droite du robot
    int ligne = d_robot.obtenirPosition().getX();
    int colonne = d_robot.obtenirPosition().getY();

    switch (d_robot.getDirection()) {
        case HAUT:
            colonne += 1;
            break;
        case DROITE:
            ligne += 1;
            break;
        case BAS:
            colonne -= 1;
            break;
        case GAUCHE:
            ligne -= 1;
            break;
    }

    // Vérifier si la case est un mur
    return d_robot.obtenirTerrain().obtenirCase(ligne, colonne) == MUR;
}

bool Capteur::aGaucheMur() const {
    // Calculer la position à gauche du robot
    int ligne = d_robot.obtenirPosition().getX();
    int colonne = d_robot.obtenirPosition().getY();

    switch (d_robot.getDirection()) {
        case HAUT:
            colonne -= 1;
            break;
        case DROITE:
            ligne -= 1;
            break;
        case BAS:
            colonne += 1;
            break;
        case GAUCHE:
            ligne += 1;
            break;
    }

    // Vérifier si la case est un mur
    return d_robot.obtenirTerrain().obtenirCase(ligne, colonne) == MUR;
}

char Capteur::caseDevant() const {
    // Calculer la position devant le robot
    int ligne = d_robot.obtenirPosition().getX();
    int colonne = d_robot.obtenirPosition().getY();

    switch (d_robot.getDirection()) {
        case HAUT:
            ligne -= 1;
            break;
        case DROITE:
            colonne += 1;
            break;
        case BAS:
            ligne += 1;
            break;
        case GAUCHE:
            colonne -= 1;
            break;
    }

    // Retourner le contenu de la case devant
    return d_robot.obtenirTerrain().obtenirCase(ligne, colonne);
}
