#include "doctest.h"
#include "Robot.h"
#include "Terrain.h"
#include "Deplacement.h"
#include "Capteur.h"
#include "Constantes.h"

TEST_CASE("Classe Robot avec d�placements g�r�s par Deplacement et interactions avec Terrain") {
    SUBCASE("Test du positionnement initial du robot") {
        Terrain terrain;
        terrain.creer(5, 5); // Cr�e un terrain 5x5
        Robot robot(terrain, Position(1, 1), DROITE);

        CHECK(robot.obtenirPosition().getX() == 1);
        CHECK(robot.obtenirPosition().getY() == 1);
        CHECK(robot.getDirection() == DROITE);
    }

    SUBCASE("Test des d�placements avec la classe Deplacement") {
        Terrain terrain;
        terrain.creer(5, 5);
        terrain.modifierCase(2, 2, MUR); // Ajout d'un mur � (2, 2)

        Robot robot(terrain, Position(1, 1), DROITE);
        Deplacement deplacement(robot);

        // Test d'un d�placement valide
        deplacement.avancer();
        CHECK(robot.obtenirPosition().getX() == 1);
        CHECK(robot.obtenirPosition().getY() == 2); // Avance vers la droite

        // Test d'un d�placement bloqu� par un mur
        deplacement.tournerDroite(); // Tourner vers le bas
        deplacement.avancer();      // Avancer vers (2, 2) bloqu� par le mur
        CHECK(robot.obtenirPosition().getX() == 1); // La position reste inchang�e
        CHECK(robot.obtenirPosition().getY() == 2);
    }

    SUBCASE("Test de la d�tection des murs avec la classe Capteur") {
        Terrain terrain;
        terrain.creer(5, 5);
        terrain.modifierCase(1, 2, MUR); // Ajout d'un mur � droite de la position initiale (1, 1)

        Robot robot(terrain, Position(1, 1), DROITE);
        Capteur capteur(robot);

        // V�rifier la d�tection du mur devant
        CHECK(capteur.devantMur() == true);

        // Tourner � gauche (direction HAUT) et v�rifier
        Deplacement deplacement(robot);
        deplacement.tournerGauche();
        CHECK(capteur.aDroiteMur() == true); // Mur � droite
    }

    SUBCASE("Test des rotations via Deplacement") {
        Terrain terrain;
        terrain.creer(5, 5);
        Robot robot(terrain, Position(1, 1), DROITE);
        Deplacement deplacement(robot);

        deplacement.tournerDroite(); // Tourner vers le bas
        CHECK(robot.getDirection() == BAS);

        deplacement.tournerGauche(); // Retour � droite
        CHECK(robot.getDirection() == DROITE);

        deplacement.tournerGauche(); // Tourner vers le haut
        CHECK(robot.getDirection() == HAUT);
    }

    SUBCASE("Test des interactions robot-terrain via Deplacement") {
        Terrain terrain;
        terrain.creer(5, 5);
        Robot robot(terrain, Position(1, 1), DROITE);
        Deplacement deplacement(robot);

        // Place un robot sur le terrain et v�rifie la grille
        terrain.modifierCase(1, 1, ROBOT);
        CHECK(terrain.obtenirCase(1, 1) == ROBOT);

        // D�place le robot et v�rifie la mise � jour de la grille
        deplacement.avancer();
        CHECK(terrain.obtenirCase(1, 1) == VIDE);    // Ancienne position vid�e
        CHECK(terrain.obtenirCase(1, 2) == ROBOT);  // Nouvelle position occup�e
    }
}
