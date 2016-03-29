#ifndef SCRABBLE_H
#define SCRABBLE_H

#include <QMainWindow>
#include <Qstack>

namespace Ui {
class Scrabble;
}

class Scrabble : public QMainWindow
{
    Q_OBJECT

public:
    explicit Scrabble(QWidget *parent = 0);
    ~Scrabble();
    void setScore();
    void addScore();
    void updateBoardState();
    void updateHandState();
    void refillHand();
    void hideHand1();
    void showHand1();
    void hideHand2();
    void showHand2();
    void toggleEnableHand1();
    void toggleEnableHand2();
    bool isValidMove();

private slots:
    void on_pushButton_tile000_clicked();
    void on_pushButton_tile001_clicked();
    void on_pushButton_tile002_clicked();
    void on_pushButton_tile003_clicked();
    void on_pushButton_tile004_clicked();
    void on_pushButton_tile005_clicked();
    void on_pushButton_tile006_clicked();
    void on_pushButton_tile007_clicked();
    void on_pushButton_tile008_clicked();
    void on_pushButton_tile009_clicked();
    void on_pushButton_tile010_clicked();
    void on_pushButton_tile011_clicked();
    void on_pushButton_tile012_clicked();
    void on_pushButton_tile013_clicked();
    void on_pushButton_tile014_clicked();
    void on_pushButton_tile015_clicked();
    void on_pushButton_tile016_clicked();
    void on_pushButton_tile017_clicked();
    void on_pushButton_tile018_clicked();
    void on_pushButton_tile019_clicked();
    void on_pushButton_tile020_clicked();
    void on_pushButton_tile021_clicked();
    void on_pushButton_tile022_clicked();
    void on_pushButton_tile023_clicked();
    void on_pushButton_tile024_clicked();
    void on_pushButton_tile025_clicked();
    void on_pushButton_tile026_clicked();
    void on_pushButton_tile027_clicked();
    void on_pushButton_tile028_clicked();
    void on_pushButton_tile029_clicked();
    void on_pushButton_tile030_clicked();
    void on_pushButton_tile031_clicked();
    void on_pushButton_tile032_clicked();
    void on_pushButton_tile033_clicked();
    void on_pushButton_tile034_clicked();
    void on_pushButton_tile035_clicked();
    void on_pushButton_tile036_clicked();
    void on_pushButton_tile037_clicked();
    void on_pushButton_tile038_clicked();
    void on_pushButton_tile039_clicked();
    void on_pushButton_tile040_clicked();
    void on_pushButton_tile041_clicked();
    void on_pushButton_tile042_clicked();
    void on_pushButton_tile043_clicked();
    void on_pushButton_tile044_clicked();
    void on_pushButton_tile045_clicked();
    void on_pushButton_tile046_clicked();
    void on_pushButton_tile047_clicked();
    void on_pushButton_tile048_clicked();
    void on_pushButton_tile049_clicked();
    void on_pushButton_tile050_clicked();
    void on_pushButton_tile051_clicked();
    void on_pushButton_tile052_clicked();
    void on_pushButton_tile053_clicked();
    void on_pushButton_tile054_clicked();
    void on_pushButton_tile055_clicked();
    void on_pushButton_tile056_clicked();
    void on_pushButton_tile057_clicked();
    void on_pushButton_tile058_clicked();
    void on_pushButton_tile059_clicked();
    void on_pushButton_tile060_clicked();
    void on_pushButton_tile061_clicked();
    void on_pushButton_tile062_clicked();
    void on_pushButton_tile063_clicked();
    void on_pushButton_tile064_clicked();
    void on_pushButton_tile065_clicked();
    void on_pushButton_tile066_clicked();
    void on_pushButton_tile067_clicked();
    void on_pushButton_tile068_clicked();
    void on_pushButton_tile069_clicked();
    void on_pushButton_tile070_clicked();
    void on_pushButton_tile071_clicked();
    void on_pushButton_tile072_clicked();
    void on_pushButton_tile073_clicked();
    void on_pushButton_tile074_clicked();
    void on_pushButton_tile075_clicked();
    void on_pushButton_tile076_clicked();
    void on_pushButton_tile077_clicked();
    void on_pushButton_tile078_clicked();
    void on_pushButton_tile079_clicked();
    void on_pushButton_tile080_clicked();
    void on_pushButton_tile081_clicked();
    void on_pushButton_tile082_clicked();
    void on_pushButton_tile083_clicked();
    void on_pushButton_tile084_clicked();
    void on_pushButton_tile085_clicked();
    void on_pushButton_tile086_clicked();
    void on_pushButton_tile087_clicked();
    void on_pushButton_tile088_clicked();
    void on_pushButton_tile089_clicked();
    void on_pushButton_tile090_clicked();
    void on_pushButton_tile091_clicked();
    void on_pushButton_tile092_clicked();
    void on_pushButton_tile093_clicked();
    void on_pushButton_tile094_clicked();
    void on_pushButton_tile095_clicked();
    void on_pushButton_tile096_clicked();
    void on_pushButton_tile097_clicked();
    void on_pushButton_tile098_clicked();
    void on_pushButton_tile099_clicked();
    void on_pushButton_tile100_clicked();
    void on_pushButton_tile101_clicked();
    void on_pushButton_tile102_clicked();
    void on_pushButton_tile103_clicked();
    void on_pushButton_tile104_clicked();
    void on_pushButton_tile105_clicked();
    void on_pushButton_tile106_clicked();
    void on_pushButton_tile107_clicked();
    void on_pushButton_tile108_clicked();
    void on_pushButton_tile109_clicked();
    void on_pushButton_tile110_clicked();
    void on_pushButton_tile111_clicked();
    void on_pushButton_tile112_clicked();
    void on_pushButton_tile113_clicked();
    void on_pushButton_tile114_clicked();
    void on_pushButton_tile115_clicked();
    void on_pushButton_tile116_clicked();
    void on_pushButton_tile117_clicked();
    void on_pushButton_tile118_clicked();
    void on_pushButton_tile119_clicked();
    void on_pushButton_tile120_clicked();

    void on_pushButton_player1hand0_clicked();
    void on_pushButton_player1hand1_clicked();
    void on_pushButton_player1hand2_clicked();
    void on_pushButton_player1hand3_clicked();
    void on_pushButton_player1hand4_clicked();
    void on_pushButton_player1hand5_clicked();

    void on_pushButton_player2hand0_clicked();
    void on_pushButton_player2hand1_clicked();
    void on_pushButton_player2hand2_clicked();
    void on_pushButton_player2hand3_clicked();
    void on_pushButton_player2hand4_clicked();
    void on_pushButton_player2hand5_clicked();

    void on_pushButton_submitTurn_clicked();

    void on_pushButton_undo_clicked();

private:
    Ui::Scrabble *ui;
};

#endif // SCRABBLE_H
