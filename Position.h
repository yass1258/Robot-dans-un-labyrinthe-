#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED
class Robot;
class Position {

public:
    // Constructeurs
    Position();
    Position(int ligne, int colonne);

    // Op�rateurs
    Position& operator=(const Position& pos);
    bool operator==(const Position& pos) const;

    // Accesseurs
    int getX() const; // R�cup�re la ligne
    int getY() const; // R�cup�re la colonne

    // Modificateurs
    void setX(int ligne);
    void setY(int colonne);
    void setPosition(int ligne, int colonne);


private:
    int d_ligne, d_colonne; // Attributs : ligne et colonne
    friend class Robot;
};


#endif // POSITION_H_INCLUDED
