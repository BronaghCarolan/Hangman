#include "visHang.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <locale>
using namespace std;
visHang::visHang(){
  
  entry = new QLineEdit(this);
  button = new QPushButton("Guess", this);
  lives = 10;
  scoreCount = 0;

  hangInput.open("hangmanWords");

  while(hangInput >> word)
    {
      words.push_back(word);
    }

  srand(time(NULL));
  int i = rand() % words.size();
  string test = words[i];
  transform(test.begin(), test.end(), test.begin(),::tolower);
  currentWord = QString::fromStdString(test);
  for(int j = 0; j < currentWord.size(); j++)
    {
      wordInGame.insert(j, "_");
    }
  
  label = new QLabel(wordInGame, this);
  deadOrAlive = new QLabel("", this);
  letters = new QLabel(QString::number(wordInGame.size()) + " letters", this);
  picture = new QLabel("", this); //Set pic to BLANK
  startButton = new QPushButton("Start Again", this);
  overMessage = new QLabel("", this);
  guessed = new QLabel("", this);
  headingGuess = new QLabel("", this);
  score = new QLabel("", this);
 

  startButton->setGeometry(5, 70, 100, 30);
  entry->setGeometry(100,400,100,30);
  button->setGeometry(100, 450, 100, 30);
  label->setGeometry(100,330,300,80);
  QFont f("Arial", 20);
  label->setFont(f);
  deadOrAlive->setGeometry(50, 500, 250, 80);
  letters->setGeometry(5, 330, 100, 100);
  picture->setGeometry(150, 25, 300, 300);
  overMessage->setGeometry(5,0,100,80);
  guessed->setGeometry(300, 400, 200, 80);
  headingGuess->setGeometry(300,350,200,80);
  score->setGeometry(5, 120, 100, 70);

  picture->setPixmap(QPixmap("blank.png"));

  connect(button,SIGNAL(clicked()), this, SLOT(guess()));
  connect(startButton,SIGNAL(clicked()), this, SLOT(reset()));
}

void visHang::guess(){
  QString answer = entry->text();
  int index = 0;
  
  if(currentWord.contains(answer) && answer != ""){
    int i = currentWord.count(answer);
    while(i>0)
    {
      index = currentWord.indexOf(answer, index);
      wordInGame.remove(index, 1);
      wordInGame.insert(index, answer);
      index++;
      i--;
    }
  }
  else
    {
      //Draw a part of man
      if(!guessedString.contains(answer)){
	lives--;
	headingGuess->setText("Guesses so far:");
	guessedString = guessedString + " " + answer;
	guessed->setText(guessedString);
      }
      switch(lives){
      case 9 : picture->setPixmap(QPixmap("dead1.png"));
	break;
      case 8 : picture->setPixmap(QPixmap("dead2.png"));
	break;
      case 7 : picture->setPixmap(QPixmap("dead3.png"));
	break;
      case 6 : picture->setPixmap(QPixmap("dead4.png"));
	break;
      case 5 : picture->setPixmap(QPixmap("dead5.png"));
	break;
      case 4 : picture->setPixmap(QPixmap("dead6.png"));
	break;
      case 3 : picture->setPixmap(QPixmap("dead7.png"));
	break;
      case 2 : picture->setPixmap(QPixmap("dead8.png"));
	break;
      case 1 : picture->setPixmap(QPixmap("dead9.png"));
	break;
      case 0 : picture->setPixmap(QPixmap("dead10.png"));
	break;
      }
    }
  if(lives == 0)
    {
      deadOrAlive->setText("You lose! The word was " + currentWord);
       overMessage->setText("GAME OVER");
      button->setEnabled(false);
    }
  if(!wordInGame.contains("_"))
    {
      deadOrAlive->setText("Good job!");
      scoreCount++;
      score->setText("Your score is " + QString::number(scoreCount));
      button->setEnabled(false);
    }
  entry->clear();
  label->setText(wordInGame);
  repaint();
}

void visHang:: reset(){
  lives = 10;

  hangInput.open("hangmanWords");

  while(hangInput >> word)
    {
      words.push_back(word);
    }

  srand(time(NULL));
  int i = rand() % words.size();
  string test = words[i];
  transform(test.begin(), test.end(), test.begin(),::tolower);
  currentWord = QString::fromStdString(test);
  wordInGame = "";
  for(int j = 0; j < currentWord.size(); j++)
    {
      wordInGame.insert(j, "_");
    }
  label->setText(wordInGame);
  deadOrAlive->setText("");
  overMessage->setText("");
  letters->setText(QString::number(wordInGame.size()) + " letters");
  picture->setPixmap(QPixmap("blank.png"));
  button->setEnabled(true);
  headingGuess->setText("");
  guessed->setText("");
  score->setText("");
  guessedString = "";
  repaint();

}




  
