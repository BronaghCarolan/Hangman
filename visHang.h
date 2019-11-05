#include <qwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#ifndef QPIXMAP_SHOW_H
#define QPIXMAP_SHOW_H

#include <QtGui>
using namespace std;
class visHang : public QWidget{
  Q_OBJECT

 public:
  visHang();

  public slots:
    void guess();
    void reset();
private:
    
    QPushButton *button;
     QPushButton *startButton;
    QLineEdit *entry;
    QLabel *label;
    QLabel *deadOrAlive;
    QLabel *letters;
    QLabel *picture;
    QLabel *overMessage;
    QLabel *guessed;
    QLabel *headingGuess;
    QLabel *score;
    int scoreCount;
    QString guessedString;
    string word;
    vector<string> words;
    ifstream hangInput;
    QString currentWord;
    QString wordInGame;
    int lives;
};
#endif
