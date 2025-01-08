
#include "doctest.h"
#include "Terrain.h"
#include <fstream>
#include <sstream>

TEST_CASE("Test des fonctionnalités de la classe Terrain") {
    SUBCASE("Créer un terrain vide et ajouter des éléments") {
        // Créer un terrain de 10x10
        Terrain terrain;
        terrain.creer(10, 10);

        CHECK(terrain.getLignes() == 10);  // Vérifie que le nombre de lignes est correct
        CHECK(terrain.getColonnes() == 10);  // Vérifie que le nombre de colonnes est correct

        // Définir le départ
        terrain.definirDepart(1, 1);
        CHECK(terrain.obtenirCase(1, 1) == 'D');  // Vérifie que la case (1, 1) est le départ

        // Définir l'arrivée
        terrain.definirArrivee(8, 8);
        CHECK(terrain.obtenirCase(8, 8) == 'A');  // Vérifie que la case (8, 8) est l'arrivée

        // Ajouter des murs
        terrain.placerMur(2, 2);
        terrain.placerMur(3, 3);
        terrain.placerMur(4, 5);

        CHECK(terrain.obtenirCase(2, 2) == 'X');  // Vérifie que la case (2, 2) est un mur
        CHECK(terrain.obtenirCase(3, 3) == 'X');  // Vérifie que la case (3, 3) est un mur
        CHECK(terrain.obtenirCase(4, 5) == 'X');  // Vérifie que la case (4, 5) est un mur
    }

    SUBCASE("Vérification de l'affichage du terrain") {
        Terrain terrain;
        terrain.creer(10, 10);
        terrain.definirDepart(1, 1);
        terrain.definirArrivee(8, 8);
        terrain.placerMur(2, 2);
        terrain.placerMur(3, 3);
        terrain.placerMur(4, 5);

        // Capture de l'affichage
        std::ostringstream oss;
        std::streambuf* oldCoutBuffer = std::cout.rdbuf(oss.rdbuf());  // Redirige std::cout
        terrain.afficher();
        std::cout.rdbuf(oldCoutBuffer);  // Rétablit std::cout

        // Vérifier que l'affichage contient les éléments ajoutés
        std::string affichage = oss.str();
        CHECK(affichage.find("D") != std::string::npos);  // Vérifie que le départ est affiché
        CHECK(affichage.find("A") != std::string::npos);  // Vérifie que l'arrivée est affichée
        CHECK(affichage.find("X") != std::string::npos);  // Vérifie que les murs sont affichés
    }
}
