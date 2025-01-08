
#include "doctest.h"
#include "Robot.h"
#include "Terrain.h"

TEST_CASE("Classe Robot : déplacements, rotations et interactions avec Terrain") {
    SUBCASE("Test du positionnement initial du robot") {
        Terrain terrain;
        terrain.creer(5, 5);
        Robot robot(terrain, Position(1, 1), DROITE);

        CHECK(robot.obtenirPosition().getX() == 1);
        CHECK(robot.obtenirPosition().getY() == 1);
        CHECK(robot.getDirection() == DROITE);
    }

    SUBCASE("Test des déplacements du robot") {
        Terrain terrain;
        terrain.creer(5, 5);
        terrain.modifierCase(2, 2, 'X'); // Mur

        Robot robot(terrain, Position(1, 1), DROITE);
        robot.avancer();
        CHECK(robot.obtenirPosition().getX() == 1);
        CHECK(robot.obtenirPosition().getY() == 2);

        robot.tournerDroite();
        robot.avancer();
        CHECK(robot.obtenirPosition().getX() == 2);
        CHECK(robot.obtenirPosition().getY() == 2); // Doit être bloqué par le mur
    }

    SUBCASE("Test de la détection des murs") {
        Terrain terrain;
        terrain.creer(3, 3);
        terrain.modifierCase(1, 2, 'X'); // Mur devant

        Robot robot(terrain, Position(1, 1), DROITE);
        CHECK(robot.devantMur() == true); // Mur détecté
        robot.tournerGauche();
        CHECK(robot.aDroiteMur() == true); // Mur à droite
    }
}
