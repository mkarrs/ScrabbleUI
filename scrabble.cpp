#include "scrabble.h"
#include "ui_scrabble.h"
#include <QStack>
#include <tile.h>
class Tile;
#define HAND_SIZE 6
#define BOARD_SIZE 121

QString currBoardState[BOARD_SIZE] = {};
QString hand1[HAND_SIZE] = {"A", "B", "C", "D", "E", "F"};
QString hand2[HAND_SIZE] = {"Z", "Y", "X", "W", "V", "U"};

QString prevBoardState[BOARD_SIZE] = currBoardState;
QString prevHand1[HAND_SIZE] = hand1;
QString prevHand2[HAND_SIZE] = hand2;

bool playerTurn = 0; //0 for player1, 1 for player 2
int player1Score = 0;
int player2Score = 0;
int turn = 0;

int pushedIndex = 0;

QString new_letter = "H";
bool new_bool = 0;
int new_let_mult = 5;
int new_word_mult = 10;

QString let = "H";
Tile* theTile = new Tile();
theTile -> setLetter(let);
QString theString = theTile -> getLetter();


Scrabble::Scrabble(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Scrabble)
{
    ui->setupUi(this);
    updateBoardState();
    updateHandState();
    hideHand1();
    hideHand2();
    setScore();
    ui -> pushButton_submitTurn -> setText(theString);
}

Scrabble::~Scrabble()
{
    delete ui;
}

void Scrabble::setScore()
{
    QString score1 = QString::number(player1Score);
    QString score2 = QString::number(player2Score);
    ui -> label_player1Score -> setText(score1);
    ui -> label_player2Score -> setText(score2);
}

void Scrabble::addScore()
{
    if(playerTurn == 0)
    {
        player1Score = player1Score + 3;
    }
    else
    {
        player2Score = player2Score + 3;
    }
    setScore();
}

void Scrabble::updateHandState()
{
    ui -> pushButton_player1hand0 -> setText(hand1[0]);
    ui -> pushButton_player1hand1 -> setText(hand1[1]);
    ui -> pushButton_player1hand2 -> setText(hand1[2]);
    ui -> pushButton_player1hand3 -> setText(hand1[3]);
    ui -> pushButton_player1hand4 -> setText(hand1[4]);
    ui -> pushButton_player1hand5 -> setText(hand1[5]);

    ui -> pushButton_player2hand0 -> setText(hand2[0]);
    ui -> pushButton_player2hand1 -> setText(hand2[1]);
    ui -> pushButton_player2hand2 -> setText(hand2[2]);
    ui -> pushButton_player2hand3 -> setText(hand2[3]);
    ui -> pushButton_player2hand4 -> setText(hand2[4]);
    ui -> pushButton_player2hand5 -> setText(hand2[5]);
}

void Scrabble::updateBoardState()
{
    ui -> pushButton_tile000 -> setText(currBoardState[0]);
    ui -> pushButton_tile001 -> setText(currBoardState[1]);
    ui -> pushButton_tile002 -> setText(currBoardState[2]);
    ui -> pushButton_tile003 -> setText(currBoardState[3]);
    ui -> pushButton_tile004 -> setText(currBoardState[4]);
    ui -> pushButton_tile005 -> setText(currBoardState[5]);
    ui -> pushButton_tile006 -> setText(currBoardState[6]);
    ui -> pushButton_tile007 -> setText(currBoardState[7]);
    ui -> pushButton_tile008 -> setText(currBoardState[8]);
    ui -> pushButton_tile009 -> setText(currBoardState[9]);
    ui -> pushButton_tile010 -> setText(currBoardState[10]);
    ui -> pushButton_tile011 -> setText(currBoardState[11]);
    ui -> pushButton_tile012 -> setText(currBoardState[12]);
    ui -> pushButton_tile013 -> setText(currBoardState[13]);
    ui -> pushButton_tile014 -> setText(currBoardState[14]);
    ui -> pushButton_tile015 -> setText(currBoardState[15]);
    ui -> pushButton_tile016 -> setText(currBoardState[16]);
    ui -> pushButton_tile017 -> setText(currBoardState[17]);
    ui -> pushButton_tile018 -> setText(currBoardState[18]);
    ui -> pushButton_tile019 -> setText(currBoardState[19]);
    ui -> pushButton_tile020 -> setText(currBoardState[20]);
    ui -> pushButton_tile021 -> setText(currBoardState[21]);
    ui -> pushButton_tile022 -> setText(currBoardState[22]);
    ui -> pushButton_tile023 -> setText(currBoardState[23]);
    ui -> pushButton_tile024 -> setText(currBoardState[24]);
    ui -> pushButton_tile025 -> setText(currBoardState[25]);
    ui -> pushButton_tile026 -> setText(currBoardState[26]);
    ui -> pushButton_tile027 -> setText(currBoardState[27]);
    ui -> pushButton_tile028 -> setText(currBoardState[28]);
    ui -> pushButton_tile029 -> setText(currBoardState[29]);
    ui -> pushButton_tile030 -> setText(currBoardState[30]);
    ui -> pushButton_tile031 -> setText(currBoardState[31]);
    ui -> pushButton_tile032 -> setText(currBoardState[32]);
    ui -> pushButton_tile033 -> setText(currBoardState[33]);
    ui -> pushButton_tile034 -> setText(currBoardState[34]);
    ui -> pushButton_tile035 -> setText(currBoardState[35]);
    ui -> pushButton_tile036 -> setText(currBoardState[36]);
    ui -> pushButton_tile037 -> setText(currBoardState[37]);
    ui -> pushButton_tile038 -> setText(currBoardState[38]);
    ui -> pushButton_tile039 -> setText(currBoardState[39]);
    ui -> pushButton_tile040 -> setText(currBoardState[40]);
    ui -> pushButton_tile041 -> setText(currBoardState[41]);
    ui -> pushButton_tile042 -> setText(currBoardState[42]);
    ui -> pushButton_tile043 -> setText(currBoardState[43]);
    ui -> pushButton_tile044 -> setText(currBoardState[44]);
    ui -> pushButton_tile045 -> setText(currBoardState[45]);
    ui -> pushButton_tile046 -> setText(currBoardState[46]);
    ui -> pushButton_tile047 -> setText(currBoardState[47]);
    ui -> pushButton_tile048 -> setText(currBoardState[48]);
    ui -> pushButton_tile049 -> setText(currBoardState[49]);
    ui -> pushButton_tile050 -> setText(currBoardState[50]);
    ui -> pushButton_tile051 -> setText(currBoardState[51]);
    ui -> pushButton_tile052 -> setText(currBoardState[52]);
    ui -> pushButton_tile053 -> setText(currBoardState[53]);
    ui -> pushButton_tile054 -> setText(currBoardState[54]);
    ui -> pushButton_tile055 -> setText(currBoardState[55]);
    ui -> pushButton_tile056 -> setText(currBoardState[56]);
    ui -> pushButton_tile057 -> setText(currBoardState[57]);
    ui -> pushButton_tile058 -> setText(currBoardState[58]);
    ui -> pushButton_tile059 -> setText(currBoardState[59]);
    ui -> pushButton_tile060 -> setText(currBoardState[60]);
    ui -> pushButton_tile061 -> setText(currBoardState[61]);
    ui -> pushButton_tile062 -> setText(currBoardState[62]);
    ui -> pushButton_tile063 -> setText(currBoardState[63]);
    ui -> pushButton_tile064 -> setText(currBoardState[64]);
    ui -> pushButton_tile065 -> setText(currBoardState[65]);
    ui -> pushButton_tile066 -> setText(currBoardState[66]);
    ui -> pushButton_tile067 -> setText(currBoardState[67]);
    ui -> pushButton_tile068 -> setText(currBoardState[68]);
    ui -> pushButton_tile069 -> setText(currBoardState[69]);
    ui -> pushButton_tile070 -> setText(currBoardState[70]);
    ui -> pushButton_tile071 -> setText(currBoardState[71]);
    ui -> pushButton_tile072 -> setText(currBoardState[72]);
    ui -> pushButton_tile073 -> setText(currBoardState[73]);
    ui -> pushButton_tile074 -> setText(currBoardState[74]);
    ui -> pushButton_tile075 -> setText(currBoardState[75]);
    ui -> pushButton_tile076 -> setText(currBoardState[76]);
    ui -> pushButton_tile077 -> setText(currBoardState[77]);
    ui -> pushButton_tile078 -> setText(currBoardState[78]);
    ui -> pushButton_tile079 -> setText(currBoardState[79]);
    ui -> pushButton_tile080 -> setText(currBoardState[80]);
    ui -> pushButton_tile081 -> setText(currBoardState[81]);
    ui -> pushButton_tile082 -> setText(currBoardState[82]);
    ui -> pushButton_tile083 -> setText(currBoardState[83]);
    ui -> pushButton_tile084 -> setText(currBoardState[84]);
    ui -> pushButton_tile085 -> setText(currBoardState[85]);
    ui -> pushButton_tile086 -> setText(currBoardState[86]);
    ui -> pushButton_tile087 -> setText(currBoardState[87]);
    ui -> pushButton_tile088 -> setText(currBoardState[88]);
    ui -> pushButton_tile089 -> setText(currBoardState[89]);
    ui -> pushButton_tile090 -> setText(currBoardState[90]);
    ui -> pushButton_tile091 -> setText(currBoardState[91]);
    ui -> pushButton_tile092 -> setText(currBoardState[92]);
    ui -> pushButton_tile093 -> setText(currBoardState[93]);
    ui -> pushButton_tile094 -> setText(currBoardState[94]);
    ui -> pushButton_tile095 -> setText(currBoardState[95]);
    ui -> pushButton_tile096 -> setText(currBoardState[96]);
    ui -> pushButton_tile097 -> setText(currBoardState[97]);
    ui -> pushButton_tile098 -> setText(currBoardState[98]);
    ui -> pushButton_tile099 -> setText(currBoardState[99]);
    ui -> pushButton_tile100 -> setText(currBoardState[100]);
    ui -> pushButton_tile101 -> setText(currBoardState[101]);
    ui -> pushButton_tile102 -> setText(currBoardState[102]);
    ui -> pushButton_tile103 -> setText(currBoardState[103]);
    ui -> pushButton_tile104 -> setText(currBoardState[104]);
    ui -> pushButton_tile105 -> setText(currBoardState[105]);
    ui -> pushButton_tile106 -> setText(currBoardState[106]);
    ui -> pushButton_tile107 -> setText(currBoardState[107]);
    ui -> pushButton_tile108 -> setText(currBoardState[108]);
    ui -> pushButton_tile109 -> setText(currBoardState[109]);
    ui -> pushButton_tile110 -> setText(currBoardState[110]);
    ui -> pushButton_tile111 -> setText(currBoardState[111]);
    ui -> pushButton_tile112 -> setText(currBoardState[112]);
    ui -> pushButton_tile113 -> setText(currBoardState[113]);
    ui -> pushButton_tile114 -> setText(currBoardState[114]);
    ui -> pushButton_tile115 -> setText(currBoardState[115]);
    ui -> pushButton_tile116 -> setText(currBoardState[116]);
    ui -> pushButton_tile117 -> setText(currBoardState[117]);
    ui -> pushButton_tile118 -> setText(currBoardState[118]);
    ui -> pushButton_tile119 -> setText(currBoardState[119]);
    ui -> pushButton_tile120 -> setText(currBoardState[120]);
}

void Scrabble::refillHand()
{
    for(int i = 0; i < HAND_SIZE; i++)
    {
        if(hand1[i].compare("") == 0)
        {
            hand1[i] = "R";
        }
        if(hand2[i].compare("") == 0)
        {
            hand2[i] = "R";
        }
    }
}

void Scrabble::hideHand1()
{
    ui -> pushButton_player1hand0 -> hide();
    ui -> pushButton_player1hand1 -> hide();
    ui -> pushButton_player1hand2 -> hide();
    ui -> pushButton_player1hand3 -> hide();
    ui -> pushButton_player1hand4 -> hide();
    ui -> pushButton_player1hand5 -> hide();
}

void Scrabble::showHand1()
{
    ui -> pushButton_player1hand0 -> show();
    ui -> pushButton_player1hand1 -> show();
    ui -> pushButton_player1hand2 -> show();
    ui -> pushButton_player1hand3 -> show();
    ui -> pushButton_player1hand4 -> show();
    ui -> pushButton_player1hand5 -> show();
}

void Scrabble::toggleEnableHand1()
{
    if(ui -> pushButton_player1hand0 ->isEnabled() == 0)
    {
        ui -> pushButton_player1hand0 -> setEnabled(1);
        ui -> pushButton_player1hand1 -> setEnabled(1);
        ui -> pushButton_player1hand2 -> setEnabled(1);
        ui -> pushButton_player1hand3 -> setEnabled(1);
        ui -> pushButton_player1hand4 -> setEnabled(1);
        ui -> pushButton_player1hand5 -> setEnabled(1);
    }
    else
    {
        ui -> pushButton_player1hand0 -> setEnabled(0);
        ui -> pushButton_player1hand1 -> setEnabled(0);
        ui -> pushButton_player1hand2 -> setEnabled(0);
        ui -> pushButton_player1hand3 -> setEnabled(0);
        ui -> pushButton_player1hand4 -> setEnabled(0);
        ui -> pushButton_player1hand5 -> setEnabled(0);
    }
}

void Scrabble::hideHand2()
{
    ui -> pushButton_player2hand0 -> hide();
    ui -> pushButton_player2hand1 -> hide();
    ui -> pushButton_player2hand2 -> hide();
    ui -> pushButton_player2hand3 -> hide();
    ui -> pushButton_player2hand4 -> hide();
    ui -> pushButton_player2hand5 -> hide();
}

void Scrabble::showHand2()
{
    ui -> pushButton_player2hand0 -> show();
    ui -> pushButton_player2hand1 -> show();
    ui -> pushButton_player2hand2 -> show();
    ui -> pushButton_player2hand3 -> show();
    ui -> pushButton_player2hand4 -> show();
    ui -> pushButton_player2hand5 -> show();
}

void Scrabble::toggleEnableHand2()
{
    if(ui -> pushButton_player2hand0 ->isEnabled() == 0)
    {
        ui -> pushButton_player2hand0 -> setEnabled(1);
        ui -> pushButton_player2hand1 -> setEnabled(1);
        ui -> pushButton_player2hand2 -> setEnabled(1);
        ui -> pushButton_player2hand3 -> setEnabled(1);
        ui -> pushButton_player2hand4 -> setEnabled(1);
        ui -> pushButton_player2hand5 -> setEnabled(1);
    }
    else
    {
        ui -> pushButton_player2hand0 -> setEnabled(0);
        ui -> pushButton_player2hand1 -> setEnabled(0);
        ui -> pushButton_player2hand2 -> setEnabled(0);
        ui -> pushButton_player2hand3 -> setEnabled(0);
        ui -> pushButton_player2hand4 -> setEnabled(0);
        ui -> pushButton_player2hand5 -> setEnabled(0);
    }
}
void Scrabble::on_pushButton_tile000_clicked()
{
    QString buttonText = ui -> pushButton_tile000 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile000 -> text();
                currBoardState[0] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile000 -> text();
                currBoardState[0] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 0;
}

void Scrabble::on_pushButton_tile001_clicked()
{
    QString buttonText = ui -> pushButton_tile001 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile001 -> text();
                currBoardState[1] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile001 -> text();
                currBoardState[1] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 1;
}

void Scrabble::on_pushButton_tile002_clicked()
{
    QString buttonText = ui -> pushButton_tile002 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile002 -> text();
                currBoardState[2] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile002 -> text();
                currBoardState[2] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 2;
}

void Scrabble::on_pushButton_tile003_clicked()
{
    QString buttonText = ui -> pushButton_tile003 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile003 -> text();
                currBoardState[3] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile003 -> text();
                currBoardState[3] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 3;
}

void Scrabble::on_pushButton_tile004_clicked()
{
    QString buttonText = ui -> pushButton_tile004 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile004 -> text();
                currBoardState[4] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile004 -> text();
                currBoardState[4] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 4;
}

void Scrabble::on_pushButton_tile005_clicked()
{
    QString buttonText = ui -> pushButton_tile005 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile005 -> text();
                currBoardState[5] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile005 -> text();
                currBoardState[5] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 5;
}

void Scrabble::on_pushButton_tile006_clicked()
{
    QString buttonText = ui -> pushButton_tile006 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile006 -> text();
                currBoardState[6] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile006 -> text();
                currBoardState[6] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 6;
}

void Scrabble::on_pushButton_tile007_clicked()
{
    QString buttonText = ui -> pushButton_tile007 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile007 -> text();
                currBoardState[7] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile007 -> text();
                currBoardState[7] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 7;
}

void Scrabble::on_pushButton_tile008_clicked()
{
    QString buttonText = ui -> pushButton_tile008 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile008 -> text();
                currBoardState[8] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile008 -> text();
                currBoardState[8] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 8;
}

void Scrabble::on_pushButton_tile009_clicked()
{
    QString buttonText = ui -> pushButton_tile009 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile009 -> text();
                currBoardState[9] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile009 -> text();
                currBoardState[9] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 9;
}

void Scrabble::on_pushButton_tile010_clicked()
{
    QString buttonText = ui -> pushButton_tile010 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile010 -> text();
                currBoardState[10] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile010 -> text();
                currBoardState[10] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 10;
}

void Scrabble::on_pushButton_tile011_clicked()
{
    QString buttonText = ui -> pushButton_tile011 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile011 -> text();
                currBoardState[11] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile011 -> text();
                currBoardState[11] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 11;
}

void Scrabble::on_pushButton_tile012_clicked()
{
    QString buttonText = ui -> pushButton_tile012 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile012 -> text();
                currBoardState[12] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile012 -> text();
                currBoardState[12] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 12;
}

void Scrabble::on_pushButton_tile013_clicked()
{
    QString buttonText = ui -> pushButton_tile013 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile013 -> text();
                currBoardState[13] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile013 -> text();
                currBoardState[13] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 13;
}

void Scrabble::on_pushButton_tile014_clicked()
{
    QString buttonText = ui -> pushButton_tile014 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile014 -> text();
                currBoardState[14] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile014 -> text();
                currBoardState[14] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 14;
}

void Scrabble::on_pushButton_tile015_clicked()
{
    QString buttonText = ui -> pushButton_tile015 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile015 -> text();
                currBoardState[15] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile015 -> text();
                currBoardState[15] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 15;
}

void Scrabble::on_pushButton_tile016_clicked()
{
    QString buttonText = ui -> pushButton_tile016 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile016 -> text();
                currBoardState[16] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile016 -> text();
                currBoardState[16] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 16;
}

void Scrabble::on_pushButton_tile017_clicked()
{
    QString buttonText = ui -> pushButton_tile017 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile017 -> text();
                currBoardState[17] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile017 -> text();
                currBoardState[17] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 17;
}

void Scrabble::on_pushButton_tile018_clicked()
{
    QString buttonText = ui -> pushButton_tile018 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile018 -> text();
                currBoardState[18] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile018 -> text();
                currBoardState[18] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 18;
}

void Scrabble::on_pushButton_tile019_clicked()
{
    QString buttonText = ui -> pushButton_tile019 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile019 -> text();
                currBoardState[19] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile019 -> text();
                currBoardState[19] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 19;
}

void Scrabble::on_pushButton_tile020_clicked()
{
    QString buttonText = ui -> pushButton_tile020 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile020 -> text();
                currBoardState[20] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile020 -> text();
                currBoardState[20] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 20;
}

void Scrabble::on_pushButton_tile021_clicked()
{
    QString buttonText = ui -> pushButton_tile021 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile021 -> text();
                currBoardState[21] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile021 -> text();
                currBoardState[21] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 21;
}

void Scrabble::on_pushButton_tile022_clicked()
{
    QString buttonText = ui -> pushButton_tile022 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile022 -> text();
                currBoardState[22] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile022 -> text();
                currBoardState[22] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 22;
}

void Scrabble::on_pushButton_tile023_clicked()
{
    QString buttonText = ui -> pushButton_tile023 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile023 -> text();
                currBoardState[23] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile023 -> text();
                currBoardState[23] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 23;
}

void Scrabble::on_pushButton_tile024_clicked()
{
    QString buttonText = ui -> pushButton_tile024 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile024 -> text();
                currBoardState[24] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile024 -> text();
                currBoardState[24] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 24;
}

void Scrabble::on_pushButton_tile025_clicked()
{
    QString buttonText = ui -> pushButton_tile025 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile025 -> text();
                currBoardState[25] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile025 -> text();
                currBoardState[25] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 25;
}

void Scrabble::on_pushButton_tile026_clicked()
{
    QString buttonText = ui -> pushButton_tile026 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile026 -> text();
                currBoardState[26] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile026 -> text();
                currBoardState[26] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 26;
}

void Scrabble::on_pushButton_tile027_clicked()
{
    QString buttonText = ui -> pushButton_tile027 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile027 -> text();
                currBoardState[27] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile027 -> text();
                currBoardState[27] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 27;
}

void Scrabble::on_pushButton_tile028_clicked()
{
    QString buttonText = ui -> pushButton_tile028 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile028 -> text();
                currBoardState[28] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile028 -> text();
                currBoardState[28] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 28;
}

void Scrabble::on_pushButton_tile029_clicked()
{
    QString buttonText = ui -> pushButton_tile029 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile029 -> text();
                currBoardState[29] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile029 -> text();
                currBoardState[29] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 29;
}

void Scrabble::on_pushButton_tile030_clicked()
{
    QString buttonText = ui -> pushButton_tile030 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile030 -> text();
                currBoardState[30] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile030 -> text();
                currBoardState[30] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 30;
}

void Scrabble::on_pushButton_tile031_clicked()
{
    QString buttonText = ui -> pushButton_tile031 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile031 -> text();
                currBoardState[31] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile031 -> text();
                currBoardState[31] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 31;
}

void Scrabble::on_pushButton_tile032_clicked()
{
    QString buttonText = ui -> pushButton_tile032 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile032 -> text();
                currBoardState[32] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile032 -> text();
                currBoardState[32] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 32;
}

void Scrabble::on_pushButton_tile033_clicked()
{
    QString buttonText = ui -> pushButton_tile033 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile033 -> text();
                currBoardState[33] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile033 -> text();
                currBoardState[33] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 33;
}

void Scrabble::on_pushButton_tile034_clicked()
{
    QString buttonText = ui -> pushButton_tile034 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile034 -> text();
                currBoardState[34] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile034 -> text();
                currBoardState[34] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 34;
}

void Scrabble::on_pushButton_tile035_clicked()
{
    QString buttonText = ui -> pushButton_tile035 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile035 -> text();
                currBoardState[35] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile035 -> text();
                currBoardState[35] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 35;
}

void Scrabble::on_pushButton_tile036_clicked()
{
    QString buttonText = ui -> pushButton_tile036 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile036 -> text();
                currBoardState[36] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile036 -> text();
                currBoardState[36] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 36;
}

void Scrabble::on_pushButton_tile037_clicked()
{
    QString buttonText = ui -> pushButton_tile037 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile037 -> text();
                currBoardState[37] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile037 -> text();
                currBoardState[37] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 37;
}

void Scrabble::on_pushButton_tile038_clicked()
{
    QString buttonText = ui -> pushButton_tile038 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile038 -> text();
                currBoardState[38] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile038 -> text();
                currBoardState[38] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 38;
}

void Scrabble::on_pushButton_tile039_clicked()
{
    QString buttonText = ui -> pushButton_tile039 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile039 -> text();
                currBoardState[39] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile039 -> text();
                currBoardState[39] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 39;
}

void Scrabble::on_pushButton_tile040_clicked()
{
    QString buttonText = ui -> pushButton_tile040 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile040 -> text();
                currBoardState[40] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile040 -> text();
                currBoardState[40] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 40;
}

void Scrabble::on_pushButton_tile041_clicked()
{
    QString buttonText = ui -> pushButton_tile041 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile041 -> text();
                currBoardState[41] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile041 -> text();
                currBoardState[41] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 41;
}

void Scrabble::on_pushButton_tile042_clicked()
{
    QString buttonText = ui -> pushButton_tile042 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile042 -> text();
                currBoardState[42] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile042 -> text();
                currBoardState[42] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 42;
}

void Scrabble::on_pushButton_tile043_clicked()
{
    QString buttonText = ui -> pushButton_tile043 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile043 -> text();
                currBoardState[43] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile043 -> text();
                currBoardState[43] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 43;
}

void Scrabble::on_pushButton_tile044_clicked()
{
    QString buttonText = ui -> pushButton_tile044 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile044 -> text();
                currBoardState[44] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile044 -> text();
                currBoardState[44] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 44;
}

void Scrabble::on_pushButton_tile045_clicked()
{
    QString buttonText = ui -> pushButton_tile045 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile045 -> text();
                currBoardState[45] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile045 -> text();
                currBoardState[45] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 45;
}

void Scrabble::on_pushButton_tile046_clicked()
{
    QString buttonText = ui -> pushButton_tile046 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile046 -> text();
                currBoardState[46] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile046 -> text();
                currBoardState[46] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 46;
}

void Scrabble::on_pushButton_tile047_clicked()
{
    QString buttonText = ui -> pushButton_tile047 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile047 -> text();
                currBoardState[47] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile047 -> text();
                currBoardState[47] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 47;
}

void Scrabble::on_pushButton_tile048_clicked()
{
    QString buttonText = ui -> pushButton_tile048 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile048 -> text();
                currBoardState[48] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile048 -> text();
                currBoardState[48] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 48;
}

void Scrabble::on_pushButton_tile049_clicked()
{
    QString buttonText = ui -> pushButton_tile049 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile049 -> text();
                currBoardState[49] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile049 -> text();
                currBoardState[49] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 49;
}

void Scrabble::on_pushButton_tile050_clicked()
{
    QString buttonText = ui -> pushButton_tile050 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile050 -> text();
                currBoardState[50] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile050 -> text();
                currBoardState[50] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 50;
}

void Scrabble::on_pushButton_tile051_clicked()
{
    QString buttonText = ui -> pushButton_tile051 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile051 -> text();
                currBoardState[51] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile051 -> text();
                currBoardState[51] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 51;
}

void Scrabble::on_pushButton_tile052_clicked()
{
    QString buttonText = ui -> pushButton_tile052 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile052 -> text();
                currBoardState[52] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile052 -> text();
                currBoardState[52] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 52;
}

void Scrabble::on_pushButton_tile053_clicked()
{
    QString buttonText = ui -> pushButton_tile053 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile053 -> text();
                currBoardState[53] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile053 -> text();
                currBoardState[53] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 53;
}

void Scrabble::on_pushButton_tile054_clicked()
{
    QString buttonText = ui -> pushButton_tile054 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile054 -> text();
                currBoardState[54] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile054 -> text();
                currBoardState[54] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 54;
}

void Scrabble::on_pushButton_tile055_clicked()
{
    QString buttonText = ui -> pushButton_tile055 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile055 -> text();
                currBoardState[55] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile055 -> text();
                currBoardState[55] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 55;
}

void Scrabble::on_pushButton_tile056_clicked()
{
    QString buttonText = ui -> pushButton_tile056 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile056 -> text();
                currBoardState[56] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile056 -> text();
                currBoardState[56] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 56;
}

void Scrabble::on_pushButton_tile057_clicked()
{
    QString buttonText = ui -> pushButton_tile057 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile057 -> text();
                currBoardState[57] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile057 -> text();
                currBoardState[57] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 57;
}

void Scrabble::on_pushButton_tile058_clicked()
{
    QString buttonText = ui -> pushButton_tile058 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile058 -> text();
                currBoardState[58] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile058 -> text();
                currBoardState[58] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 58;
}

void Scrabble::on_pushButton_tile059_clicked()
{
    QString buttonText = ui -> pushButton_tile059 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile059 -> text();
                currBoardState[59] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile059 -> text();
                currBoardState[59] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 59;
}

void Scrabble::on_pushButton_tile060_clicked()
{
    QString buttonText = ui -> pushButton_tile060 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile060 -> text();
                currBoardState[60] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile060 -> text();
                currBoardState[60] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 60;
}

void Scrabble::on_pushButton_tile061_clicked()
{
    QString buttonText = ui -> pushButton_tile061 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile061 -> text();
                currBoardState[61] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile061 -> text();
                currBoardState[61] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 61;
}

void Scrabble::on_pushButton_tile062_clicked()
{
    QString buttonText = ui -> pushButton_tile062 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile062 -> text();
                currBoardState[62] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile062 -> text();
                currBoardState[62] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 62;
}

void Scrabble::on_pushButton_tile063_clicked()
{
    QString buttonText = ui -> pushButton_tile063 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile063 -> text();
                currBoardState[63] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile063 -> text();
                currBoardState[63] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 63;
}

void Scrabble::on_pushButton_tile064_clicked()
{
    QString buttonText = ui -> pushButton_tile064 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile064 -> text();
                currBoardState[64] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile064 -> text();
                currBoardState[64] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 64;
}

void Scrabble::on_pushButton_tile065_clicked()
{
    QString buttonText = ui -> pushButton_tile065 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile065 -> text();
                currBoardState[65] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile065 -> text();
                currBoardState[65] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 65;
}

void Scrabble::on_pushButton_tile066_clicked()
{
    QString buttonText = ui -> pushButton_tile066 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile066 -> text();
                currBoardState[66] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile066 -> text();
                currBoardState[66] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 66;
}

void Scrabble::on_pushButton_tile067_clicked()
{
    QString buttonText = ui -> pushButton_tile067 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile067 -> text();
                currBoardState[67] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile067 -> text();
                currBoardState[67] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 67;
}

void Scrabble::on_pushButton_tile068_clicked()
{
    QString buttonText = ui -> pushButton_tile068 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile068 -> text();
                currBoardState[68] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile068 -> text();
                currBoardState[68] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 68;
}

void Scrabble::on_pushButton_tile069_clicked()
{
    QString buttonText = ui -> pushButton_tile069 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile069 -> text();
                currBoardState[69] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile069 -> text();
                currBoardState[69] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 69;
}

void Scrabble::on_pushButton_tile070_clicked()
{
    QString buttonText = ui -> pushButton_tile070 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile070 -> text();
                currBoardState[70] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile070 -> text();
                currBoardState[70] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 70;
}

void Scrabble::on_pushButton_tile071_clicked()
{
    QString buttonText = ui -> pushButton_tile071 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile071 -> text();
                currBoardState[71] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile071 -> text();
                currBoardState[71] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 71;
}

void Scrabble::on_pushButton_tile072_clicked()
{
    QString buttonText = ui -> pushButton_tile072 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile072 -> text();
                currBoardState[72] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile072 -> text();
                currBoardState[72] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 72;
}

void Scrabble::on_pushButton_tile073_clicked()
{
    QString buttonText = ui -> pushButton_tile073 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile073 -> text();
                currBoardState[73] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile073 -> text();
                currBoardState[73] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 73;
}

void Scrabble::on_pushButton_tile074_clicked()
{
    QString buttonText = ui -> pushButton_tile074 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile074 -> text();
                currBoardState[74] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile074 -> text();
                currBoardState[74] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 74;
}

void Scrabble::on_pushButton_tile075_clicked()
{
    QString buttonText = ui -> pushButton_tile075 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile075 -> text();
                currBoardState[75] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile075 -> text();
                currBoardState[75] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 75;
}

void Scrabble::on_pushButton_tile076_clicked()
{
    QString buttonText = ui -> pushButton_tile076 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile076 -> text();
                currBoardState[76] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile076 -> text();
                currBoardState[76] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 76;
}

void Scrabble::on_pushButton_tile077_clicked()
{
    QString buttonText = ui -> pushButton_tile077 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile077 -> text();
                currBoardState[77] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile077 -> text();
                currBoardState[77] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 77;
}

void Scrabble::on_pushButton_tile078_clicked()
{
    QString buttonText = ui -> pushButton_tile078 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile078 -> text();
                currBoardState[78] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile078 -> text();
                currBoardState[78] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 78;
}

void Scrabble::on_pushButton_tile079_clicked()
{
    QString buttonText = ui -> pushButton_tile079 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile079 -> text();
                currBoardState[79] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile079 -> text();
                currBoardState[79] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 79;
}

void Scrabble::on_pushButton_tile080_clicked()
{
    QString buttonText = ui -> pushButton_tile080 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile080 -> text();
                currBoardState[80] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile080 -> text();
                currBoardState[80] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 80;
}

void Scrabble::on_pushButton_tile081_clicked()
{
    QString buttonText = ui -> pushButton_tile081 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile081 -> text();
                currBoardState[81] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile081 -> text();
                currBoardState[81] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 81;
}

void Scrabble::on_pushButton_tile082_clicked()
{
    QString buttonText = ui -> pushButton_tile082 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile082 -> text();
                currBoardState[82] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile082 -> text();
                currBoardState[82] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 82;
}

void Scrabble::on_pushButton_tile083_clicked()
{
    QString buttonText = ui -> pushButton_tile083 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile083 -> text();
                currBoardState[83] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile083 -> text();
                currBoardState[83] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 83;
}

void Scrabble::on_pushButton_tile084_clicked()
{
    QString buttonText = ui -> pushButton_tile084 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile084 -> text();
                currBoardState[84] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile084 -> text();
                currBoardState[84] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 84;
}

void Scrabble::on_pushButton_tile085_clicked()
{
    QString buttonText = ui -> pushButton_tile085 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile085 -> text();
                currBoardState[85] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile085 -> text();
                currBoardState[85] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 85;
}

void Scrabble::on_pushButton_tile086_clicked()
{
    QString buttonText = ui -> pushButton_tile086 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile086 -> text();
                currBoardState[86] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile086 -> text();
                currBoardState[86] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 86;
}

void Scrabble::on_pushButton_tile087_clicked()
{
    QString buttonText = ui -> pushButton_tile087 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile087 -> text();
                currBoardState[87] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile087 -> text();
                currBoardState[87] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 87;
}

void Scrabble::on_pushButton_tile088_clicked()
{
    QString buttonText = ui -> pushButton_tile088 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile088 -> text();
                currBoardState[88] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile088 -> text();
                currBoardState[88] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 88;
}

void Scrabble::on_pushButton_tile089_clicked()
{
    QString buttonText = ui -> pushButton_tile089 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile089 -> text();
                currBoardState[89] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile089 -> text();
                currBoardState[89] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 89;
}

void Scrabble::on_pushButton_tile090_clicked()
{
    QString buttonText = ui -> pushButton_tile090 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile090 -> text();
                currBoardState[90] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile090 -> text();
                currBoardState[90] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 90;
}

void Scrabble::on_pushButton_tile091_clicked()
{
    QString buttonText = ui -> pushButton_tile091 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile091 -> text();
                currBoardState[91] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile091 -> text();
                currBoardState[91] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 91;
}

void Scrabble::on_pushButton_tile092_clicked()
{
    QString buttonText = ui -> pushButton_tile092 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile092 -> text();
                currBoardState[92] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile092 -> text();
                currBoardState[92] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 92;
}

void Scrabble::on_pushButton_tile093_clicked()
{
    QString buttonText = ui -> pushButton_tile093 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile093 -> text();
                currBoardState[93] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile093 -> text();
                currBoardState[93] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 93;
}

void Scrabble::on_pushButton_tile094_clicked()
{
    QString buttonText = ui -> pushButton_tile094 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile094 -> text();
                currBoardState[94] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile094 -> text();
                currBoardState[94] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 94;
}

void Scrabble::on_pushButton_tile095_clicked()
{
    QString buttonText = ui -> pushButton_tile095 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile095 -> text();
                currBoardState[95] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile095 -> text();
                currBoardState[95] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 95;
}

void Scrabble::on_pushButton_tile096_clicked()
{
    QString buttonText = ui -> pushButton_tile096 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile096 -> text();
                currBoardState[96] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile096 -> text();
                currBoardState[96] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 96;
}

void Scrabble::on_pushButton_tile097_clicked()
{
    QString buttonText = ui -> pushButton_tile097 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile097 -> text();
                currBoardState[97] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile097 -> text();
                currBoardState[97] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 97;
}

void Scrabble::on_pushButton_tile098_clicked()
{
    QString buttonText = ui -> pushButton_tile098 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile098 -> text();
                currBoardState[98] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile098 -> text();
                currBoardState[98] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 98;
}

void Scrabble::on_pushButton_tile099_clicked()
{
    QString buttonText = ui -> pushButton_tile099 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile099 -> text();
                currBoardState[99] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile099 -> text();
                currBoardState[99] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 99;
}

void Scrabble::on_pushButton_tile100_clicked()
{
    QString buttonText = ui -> pushButton_tile100 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile100 -> text();
                currBoardState[100] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile100 -> text();
                currBoardState[100] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 100;
}

void Scrabble::on_pushButton_tile101_clicked()
{
    QString buttonText = ui -> pushButton_tile101 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile101 -> text();
                currBoardState[101] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile101 -> text();
                currBoardState[101] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 101;
}

void Scrabble::on_pushButton_tile102_clicked()
{
    QString buttonText = ui -> pushButton_tile102 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile102 -> text();
                currBoardState[102] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile102 -> text();
                currBoardState[102] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 102;
}

void Scrabble::on_pushButton_tile103_clicked()
{
    QString buttonText = ui -> pushButton_tile103 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile103 -> text();
                currBoardState[103] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile103 -> text();
                currBoardState[103] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 103;
}

void Scrabble::on_pushButton_tile104_clicked()
{
    QString buttonText = ui -> pushButton_tile104 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile104 -> text();
                currBoardState[104] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile104 -> text();
                currBoardState[104] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 104;
}

void Scrabble::on_pushButton_tile105_clicked()
{
    QString buttonText = ui -> pushButton_tile105 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile105 -> text();
                currBoardState[105] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile105 -> text();
                currBoardState[105] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 105;
}

void Scrabble::on_pushButton_tile106_clicked()
{
    QString buttonText = ui -> pushButton_tile106 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile106 -> text();
                currBoardState[106] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile106 -> text();
                currBoardState[106] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 106;
}

void Scrabble::on_pushButton_tile107_clicked()
{
    QString buttonText = ui -> pushButton_tile107 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile107 -> text();
                currBoardState[107] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile107 -> text();
                currBoardState[107] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 107;
}

void Scrabble::on_pushButton_tile108_clicked()
{
    QString buttonText = ui -> pushButton_tile108 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile108 -> text();
                currBoardState[108] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile108 -> text();
                currBoardState[108] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 108;
}

void Scrabble::on_pushButton_tile109_clicked()
{
    QString buttonText = ui -> pushButton_tile109 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile109 -> text();
                currBoardState[109] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile109 -> text();
                currBoardState[109] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 109;
}

void Scrabble::on_pushButton_tile110_clicked()
{
    QString buttonText = ui -> pushButton_tile110 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile110 -> text();
                currBoardState[110] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile110 -> text();
                currBoardState[110] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 110;
}

void Scrabble::on_pushButton_tile111_clicked()
{
    QString buttonText = ui -> pushButton_tile111 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile111 -> text();
                currBoardState[111] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile111 -> text();
                currBoardState[111] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 111;
}

void Scrabble::on_pushButton_tile112_clicked()
{
    QString buttonText = ui -> pushButton_tile112 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile112 -> text();
                currBoardState[112] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile112 -> text();
                currBoardState[112] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 112;
}

void Scrabble::on_pushButton_tile113_clicked()
{
    QString buttonText = ui -> pushButton_tile113 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile113 -> text();
                currBoardState[113] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile113 -> text();
                currBoardState[113] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 113;
}

void Scrabble::on_pushButton_tile114_clicked()
{
    QString buttonText = ui -> pushButton_tile114 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile114 -> text();
                currBoardState[114] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile114 -> text();
                currBoardState[114] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 114;
}

void Scrabble::on_pushButton_tile115_clicked()
{
    QString buttonText = ui -> pushButton_tile115 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile115 -> text();
                currBoardState[115] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile115 -> text();
                currBoardState[115] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 115;
}

void Scrabble::on_pushButton_tile116_clicked()
{
    QString buttonText = ui -> pushButton_tile116 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile116 -> text();
                currBoardState[116] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile116 -> text();
                currBoardState[116] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 116;
}

void Scrabble::on_pushButton_tile117_clicked()
{
    QString buttonText = ui -> pushButton_tile117 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile117 -> text();
                currBoardState[117] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile117 -> text();
                currBoardState[117] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 117;
}

void Scrabble::on_pushButton_tile118_clicked()
{
    QString buttonText = ui -> pushButton_tile118 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile118 -> text();
                currBoardState[118] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile118 -> text();
                currBoardState[118] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 118;
}

void Scrabble::on_pushButton_tile119_clicked()
{
    QString buttonText = ui -> pushButton_tile119 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile119 -> text();
                currBoardState[119] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile119 -> text();
                currBoardState[119] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 119;
}

void Scrabble::on_pushButton_tile120_clicked()
{
    QString buttonText = ui -> pushButton_tile120 -> text();
    if(buttonText.isEmpty() && playerTurn == 0)
    {
        showHand1();
        hideHand2();
        toggleEnableHand1();
    }
    else if(buttonText.isEmpty() && playerTurn == 1)
    {
        hideHand1();
        showHand2();
        toggleEnableHand2();
    }
    else if(!buttonText.isEmpty() && playerTurn == 0)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand1[i] == "")
            {
                hand1[i] = ui -> pushButton_tile120 -> text();
                currBoardState[120] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    else if(!buttonText.isEmpty() && playerTurn == 1)
    {
        for(int i = 0; i < HAND_SIZE; i++)
        {
            if(hand2[i] == "")
            {
                hand2[i] = ui -> pushButton_tile120 -> text();
                currBoardState[120] = "";
                updateHandState();
                updateBoardState();
                break;
            }
        }
    }
    pushedIndex = 120;
}

void Scrabble::on_pushButton_player1hand0_clicked()
{
    QString chosenLetter = ui -> pushButton_player1hand0 -> text();
    currBoardState[pushedIndex] = chosenLetter;
    hand1[0] = "";
    toggleEnableHand1();
    updateBoardState();
    updateHandState();
}

void Scrabble::on_pushButton_player1hand1_clicked()
{
    QString chosenLetter = ui -> pushButton_player1hand1 -> text();
    currBoardState[pushedIndex] = chosenLetter;
    hand1[1] = "";
    toggleEnableHand1();
    updateBoardState();
    updateHandState();
}

void Scrabble::on_pushButton_player1hand2_clicked()
{
    QString chosenLetter = ui -> pushButton_player1hand2 -> text();
    currBoardState[pushedIndex] = chosenLetter;
    hand1[2] = "";
    toggleEnableHand1();
    updateBoardState();
    updateHandState();
}

void Scrabble::on_pushButton_player1hand3_clicked()
{
    QString chosenLetter = ui -> pushButton_player1hand3 -> text();
    currBoardState[pushedIndex] = chosenLetter;
    hand1[3] = "";
    toggleEnableHand1();
    updateBoardState();
    updateHandState();
}

void Scrabble::on_pushButton_player1hand4_clicked()
{
    QString chosenLetter = ui -> pushButton_player1hand4 -> text();
    currBoardState[pushedIndex] = chosenLetter;
    hand1[4] = "";
    toggleEnableHand1();
    updateBoardState();
    updateHandState();
}

void Scrabble::on_pushButton_player1hand5_clicked()
{
    QString chosenLetter = ui -> pushButton_player1hand5 -> text();
    currBoardState[pushedIndex] = chosenLetter;
    hand1[5] = "";
    toggleEnableHand1();
    updateBoardState();
    updateHandState();
}

void Scrabble::on_pushButton_player2hand0_clicked()
{
    QString chosenLetter = ui -> pushButton_player2hand0 -> text();
    currBoardState[pushedIndex] = chosenLetter;
    hand2[0] = "";
    toggleEnableHand2();
    updateBoardState();
    updateHandState();
}

void Scrabble::on_pushButton_player2hand1_clicked()
{
    QString chosenLetter = ui -> pushButton_player2hand1 -> text();
    currBoardState[pushedIndex] = chosenLetter;
    hand2[1] = "";
    toggleEnableHand2();
    updateBoardState();
    updateHandState();
}

void Scrabble::on_pushButton_player2hand2_clicked()
{
    QString chosenLetter = ui -> pushButton_player2hand2 -> text();
    currBoardState[pushedIndex] = chosenLetter;
    hand2[2] = "";
    toggleEnableHand2();
    updateBoardState();
    updateHandState();
}

void Scrabble::on_pushButton_player2hand3_clicked()
{
    QString chosenLetter = ui -> pushButton_player2hand3 -> text();
    currBoardState[pushedIndex] = chosenLetter;
    hand2[3] = "";
    toggleEnableHand2();
    updateBoardState();
    updateHandState();
}

void Scrabble::on_pushButton_player2hand4_clicked()
{
    QString chosenLetter = ui -> pushButton_player2hand4 -> text();
    currBoardState[pushedIndex] = chosenLetter;
    hand2[4] = "";
    toggleEnableHand2();
    updateBoardState();
    updateHandState();
}

void Scrabble::on_pushButton_player2hand5_clicked()
{
    QString chosenLetter = ui -> pushButton_player2hand5 -> text();
    currBoardState[pushedIndex] = chosenLetter;
    hand2[5] = "";
    toggleEnableHand2();
    updateBoardState();
    updateHandState();
}

bool Scrabble::isValidMove()
{
    return 1;
}

void Scrabble::on_pushButton_submitTurn_clicked()
{
    if(isValidMove() == 0)
    {

    }
    else
    {
        addScore();
        refillHand();
        playerTurn = !playerTurn;
        hideHand1();
        hideHand2();

        for(int i = 0; i < BOARD_SIZE; i++)
        {
            prevBoardState[i] = currBoardState[i];
        }

        for(int i = 0; i < HAND_SIZE; i++)
        {
            prevHand1[i] = hand1[i];
            prevHand2[i] = hand2[i];
        }

    }
}

void Scrabble::on_pushButton_undo_clicked()
{
    for(int i = 0; i < BOARD_SIZE; i++)
    {
        currBoardState[i] = prevBoardState[i];
    }

    for(int i = 0; i < HAND_SIZE; i++)
    {
        hand1[i] = prevHand1[i];
        hand2[i] = prevHand2[i];
    }

    updateBoardState();
    updateHandState();
    playerTurn = !playerTurn;
}
