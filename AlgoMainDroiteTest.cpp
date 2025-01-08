
#include "doctest.h"
#include "AlgoMainDroite.h"
#include "Terrain.h"
#include "Robot.h"

TEST_CASE("Algorithme de la main droite : navigation dans le labyrinthe") {
    SUBCASE("Test dans un labyrinthe simple") {
        Terrain terrain;
        terrain.creer(5, 5);
        terrain.definirDepart(1, 1);
        terrain.definirArrivee(3, 3);
        terrain.modifierCase(2, 2, 'X'); // Mur

        Robot robot(terrain, Position(1, 1), DROITE);
        AlgoMainDroite algo(robot);

        // Exécuter l'algorithme
        REQUIRE_NOTHROW(algo.executer());

        // Le robot doit arriver juste avant l'arrivée
        CHECK(robot.obtenirPosition().getX() == 3);
        CHECK(robot.obtenirPosition().getY() == 3);
    }
}
