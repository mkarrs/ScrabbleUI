#ifndef TILE_H
#define TILE_H
#include <QString>
class Tile;
class Tile
{
    private:
        QString letter;
        bool enabled;
        int letter_multiplier;
        int word_multiplier;

    public:
        Tile();
        QString getLetter();
        void setLetter(QString theLetter);
        bool getEnabled();
        void setEnabled(bool enabled);
        int getLetterMultiplier();
        void setLetterMultiplier(int multiplier);
        int getWordMultiplier();
        void setWordMultiplier(int multiplier);
};
#endif // TILE_H
