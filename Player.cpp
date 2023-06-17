#include "Player.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Player::Player(){
  ifstream file("playerDeck.txt");
  if (!file) {
    cout << "Failed to open file." << endl;
    return;
  }
  
  int i = 0;
  string line;
  while (getline(file, line) && i < 20) {
    file >> card_id[i];
    i++;
  }
  file.close();
}

Player::~Player(){
  setDeck(card_id, 20);
}

int Player::getCardId(int i){
  return card_id[i];
}

void Player::setDeck(int deck[], int size){

  ofstream myFile;
  myFile.open("playerDeck.txt", ios::trunc);
  myFile.close();
  myFile.open("playerDeck.txt");
  
  myFile << "ID" << endl;
  int i = 0;
  while(i < size){
    myFile << deck[i] << endl;
    i++;
  }

  myFile.close();
}
