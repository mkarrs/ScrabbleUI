#include <QString>
#include <scrabble.h>
#include <tile.h>
class scrabble;
class Tile;
/**Tile::Tile(QString letter, bool enabled, int letter_multiplier, int word_multiplier)
{
    setLetter(letter);
    setEnabled(enabled);
    setLetterMultiplier(letter_multiplier);
    setWordMultiplier(word_multiplier);
}**/

Tile::Tile()
{
    setLetter("letter");
    setEnabled(1);
    setLetterMultiplier(4);
    setWordMultiplier(3);
}
QString Tile::getLetter()
{
    return this->letter;
}

void Tile::setLetter(QString theLetter)
{
    this -> letter = theLetter;
}

bool Tile::getEnabled()
{
    return this -> enabled;
}

void Tile::setEnabled(bool theEnabled)
{
    this -> enabled = theEnabled;
}

int Tile::getLetterMultiplier()
{
    return this -> letter_multiplier;
}

void Tile::setLetterMultiplier(int multiplier)
{
    this -> letter_multiplier = multiplier;
}

int Tile::getWordMultiplier()
{
    return this -> word_multiplier;
}

void Tile::setWordMultiplier(int multiplier)
{
    this -> word_multiplier = multiplier;
}

/**main(int argc, char** argv)
{
    Tile theTile = new Tile();
    theTile.setLetter("H");
    cout<<theTile.getLetter();
    return 0;
}**/

/**void setLetter(QString letter)
{
    this.letter = letter;
}**/
