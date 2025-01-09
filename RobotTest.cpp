#include "doctest.h"
#include "Robot.h"
#include "Terrain.h"
#include "Deplacement.h"
#include "Capteur.h"
#include "Constantes.h"

TEST_CASE("Classe Robot avec déplacements gérés par Deplacement et interactions avec Terrain") {
    SUBCASE("Test du positionnement initial du robot") {
        Terrain terrain;
        terrain.creer(5, 5); // Crée un terrain 5x5
        Robot robot(terrain, Position(1, 1), DROITE);

        CHECK(robot.obtenirPosition().getX() == 1);
        CHECK(robot.obtenirPosition().getY() == 1);
        CHECK(robot.getDirection() == DROITE);
    }

    SUBCASE("Test des déplacements avec la classe Deplacement") {
        Terrain terrain;
        terrain.creer(5, 5);
        terrain.modifierCase(2, 2, MUR); // Ajout d'un mur à (2, 2)

        Robot robot(terrain, Position(1, 1), DROITE);
        Deplacement deplacement(robot);

        // Test d'un déplacement valide
        deplacement.avancer();
        CHECK(robot.obtenirPosition().getX() == 1);
        CHECK(robot.obtenirPosition().getY() == 2); // Avance vers la droite

        // Test d'un déplacement bloqué par un mur
        deplacement.tournerDroite(); // Tourner vers le bas
        deplacement.avancer();      // Avancer vers (2, 2) bloqué par le mur
        CHECK(robot.obtenirPosition().getX() == 1); // La position reste inchangée
        CHECK(robot.obtenirPosition().getY() == 2);
    }

    SUBCASE("Test de la détection des murs avec la classe Capteur") {
        Terrain terrain;
        terrain.creer(5, 5);
        terrain.modifierCase(1, 2, MUR); // Ajout d'un mur à droite de la position initiale (1, 1)

        Robot robot(terrain, Position(1, 1), DROITE);
        Capteur capteur(robot);

        // Vérifier la détection du mur devant
        CHECK(capteur.devantMur() == true);

        // Tourner à gauche (direction HAUT) et vérifier
        Deplacement deplacement(robot);
        deplacement.tournerGauche();
        CHECK(capteur.aDroiteMur() == true); // Mur à droite
    }

    SUBCASE("Test des rotations via Deplacement") {
        Terrain terrain;
        terrain.creer(5, 5);
        Robot robot(terrain, Position(1, 1), DROITE);
        Deplacement deplacement(robot);

        deplacement.tournerDroite(); // Tourner vers le bas
        CHECK(robot.getDirection() == BAS);

        deplacement.tournerGauche(); // Retour à droite
        CHECK(robot.getDirection() == DROITE);

        deplacement.tournerGauche(); // Tourner vers le haut
        CHECK(robot.getDirection() == HAUT);
    }

    SUBCASE("Test des interactions robot-terrain via Deplacement") {
        Terrain terrain;
        terrain.creer(5, 5);
        Robot robot(terrain, Position(1, 1), DROITE);
        Deplacement deplacement(robot);

        // Place un robot sur le terrain et vérifie la grille
        terrain.modifierCase(1, 1, ROBOT);
        CHECK(terrain.obtenirCase(1, 1) == ROBOT);

        // Déplace le robot et vérifie la mise à jour de la grille
        deplacement.avancer();
        CHECK(terrain.obtenirCase(1, 1) == VIDE);    // Ancienne position vidée
        CHECK(terrain.obtenirCase(1, 2) == ROBOT);  // Nouvelle position occupée
    }
}
