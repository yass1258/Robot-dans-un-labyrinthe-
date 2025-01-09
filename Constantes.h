#ifndef CONSTANTES_H
#define CONSTANTES_H
#include"Direction.h"

// Constantes pour les caract�res du terrain
const char MUR = 'X';          // Repr�sente un mur
const char VIDE = '.';         // Repr�sente une case vide
const char DEPART = 'D';       // Repr�sente le point de d�part
const char ARRIVEE = 'A';      // Repr�sente le point d'arriv�e
const char ROBOT = 'R';        // Repr�sente la position du robot



// Constantes pour les messages
const std::string MSG_IMPORT_OK = "Labyrinthe import� avec succ�s.";
const std::string MSG_EXPORT_OK = "Terrain sauvegard� avec succ�s.";
const std::string MSG_ERREUR_IMPORT = "Erreur : Impossible d'importer le fichier.";
const std::string MSG_ERREUR_EXPORT = "Erreur : Impossible de sauvegarder le fichier.";

inline std::string obtenirDirectionTexte(Direction direction) {
    switch (direction) {
        case HAUT: return "Haut";
        case DROITE: return "Droite";
        case BAS: return "Bas";
        case GAUCHE: return "Gauche";
        default: return "Inconnue";
    }
}

#endif
