#include "Position.h"

// Constructeurs
Position::Position() : d_ligne(0), d_colonne(0) {}

Position::Position(int ligne, int colonne) : d_ligne(ligne), d_colonne(colonne) {}

// Opérateurs
Position& Position::operator=(const Position& pos) {
    if (this != &pos) {
        d_ligne = pos.d_ligne;
        d_colonne = pos.d_colonne;
    }
    return *this;
}

bool Position::operator==(const Position& pos) const {
    return d_ligne == pos.d_ligne && d_colonne == pos.d_colonne;
}


// Accesseurs
int Position::getX() const {
    return d_ligne;
}

int Position::getY() const {
    return d_colonne;
}

// Modificateurs
void Position::setX(int ligne) {
    d_ligne = ligne;
}

void Position::setY(int colonne) {
    d_colonne = colonne;
}

void Position::setPosition(int ligne, int colonne) {
    d_ligne = ligne;
    d_colonne = colonne;
}
