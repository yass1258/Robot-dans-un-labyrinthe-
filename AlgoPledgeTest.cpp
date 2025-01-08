
#include "doctest.h"
#include "AlgoPledge.h"
#include "Terrain.h"
#include "Robot.h"
#include <sstream>
TEST_CASE("Test AlgoPledge avec labyrinthe.txt") {
    // Charger le terrain depuis le fichier texte
    Terrain terrain;
    REQUIRE_NOTHROW(terrain.importerDepuisFichier("labyrinthe.txt"));

    // V�rifier que le terrain est charg� correctement
    CHECK(terrain.getLignes() == 10);
    CHECK(terrain.getColonnes() == 10);
    CHECK(terrain.obtenirCase(1, 1) == 'D');
    CHECK(terrain.obtenirCase(8, 8) == 'A');

    // Positionner le robot au d�part
    Robot robot(terrain, Position(1, 1), DROITE);

    // Initialiser l'algorithme de Pledge
    AlgoPledge algo(robot);

    // Capturer les mouvements du robot
    std::ostringstream oss;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(oss.rdbuf());
    algo.executer();
    std::cout.rdbuf(oldCoutBuffer);  // Restaurer std::cout

    // V�rifier que le robot atteint l'arriv�e
    CHECK(robot.obtenirPosition().getX() == 8);  // Le robot doit �tre � l'arriv�e
    CHECK(robot.obtenirPosition().getY() == 8);

    // V�rifier les d�placements dans la sortie console
    std::string log = oss.str();
    CHECK(log.find("Le robot a atteint la sortie") != std::string::npos);
}
