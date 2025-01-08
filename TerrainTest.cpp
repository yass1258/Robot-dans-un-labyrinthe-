
#include "doctest.h"
#include "Terrain.h"
#include <fstream>
#include <sstream>

TEST_CASE("Test des fonctionnalit�s de la classe Terrain") {
    SUBCASE("Cr�er un terrain vide et ajouter des �l�ments") {
        // Cr�er un terrain de 10x10
        Terrain terrain;
        terrain.creer(10, 10);

        CHECK(terrain.getLignes() == 10);  // V�rifie que le nombre de lignes est correct
        CHECK(terrain.getColonnes() == 10);  // V�rifie que le nombre de colonnes est correct

        // D�finir le d�part
        terrain.definirDepart(1, 1);
        CHECK(terrain.obtenirCase(1, 1) == 'D');  // V�rifie que la case (1, 1) est le d�part

        // D�finir l'arriv�e
        terrain.definirArrivee(8, 8);
        CHECK(terrain.obtenirCase(8, 8) == 'A');  // V�rifie que la case (8, 8) est l'arriv�e

        // Ajouter des murs
        terrain.placerMur(2, 2);
        terrain.placerMur(3, 3);
        terrain.placerMur(4, 5);

        CHECK(terrain.obtenirCase(2, 2) == 'X');  // V�rifie que la case (2, 2) est un mur
        CHECK(terrain.obtenirCase(3, 3) == 'X');  // V�rifie que la case (3, 3) est un mur
        CHECK(terrain.obtenirCase(4, 5) == 'X');  // V�rifie que la case (4, 5) est un mur
    }

    SUBCASE("V�rification de l'affichage du terrain") {
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
        std::cout.rdbuf(oldCoutBuffer);  // R�tablit std::cout

        // V�rifier que l'affichage contient les �l�ments ajout�s
        std::string affichage = oss.str();
        CHECK(affichage.find("D") != std::string::npos);  // V�rifie que le d�part est affich�
        CHECK(affichage.find("A") != std::string::npos);  // V�rifie que l'arriv�e est affich�e
        CHECK(affichage.find("X") != std::string::npos);  // V�rifie que les murs sont affich�s
    }
}
