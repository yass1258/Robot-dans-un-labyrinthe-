#ifndef CONSTANTES_H
#define CONSTANTES_H
#include"Direction.h"

// Constantes pour les caractères du terrain
const char MUR = 'X';          // Représente un mur
const char VIDE = '.';         // Représente une case vide
const char DEPART = 'D';       // Représente le point de départ
const char ARRIVEE = 'A';      // Représente le point d'arrivée
const char ROBOT = 'R';        // Représente la position du robot



// Constantes pour les messages
const std::string MSG_IMPORT_OK = "Labyrinthe importé avec succès.";
const std::string MSG_EXPORT_OK = "Terrain sauvegardé avec succès.";
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
