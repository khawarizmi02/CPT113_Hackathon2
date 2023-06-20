#include "Player.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Player::Player() : player_deck(20) {
  ifstream file("playerDeck.txt");
  if (!file) {
    cout << "Failed to open file." << endl;
    return;
  }
  
  int i = 0;
  string line;
  int value;
  while (getline(file, line)) {
    file >> value;
    if (value <= 0 ) { break; }
    player_deck.appendNode(value);
    i++;
  }
  file.close();
}

Player::~Player(){
  setDeck();
}

int Player::getPlayerDeckSize(){
  return player_deck.getNodeSize();
}

int Player::getCardId(int i){
  return player_deck.getNodeValue(i+1);
}

void Player::setDeck(){

  ofstream myFile;
  myFile.open("playerDeck.txt", ios::trunc);
  myFile.close();
  myFile.open("playerDeck.txt");
  
  myFile << "ID" << endl;
  int i = 0;
  while(i < player_deck.getNodeSize()){
  myFile << player_deck.getNodeValue(i+1) << endl;
  i++;
 }
 myFile.close();
}

void Player::deletePlayerCard(int value){
  player_deck.deleteNode(value);
  setDeck();
}

void Player::addPlayerCard(int value){
  player_deck.appendNode(value);
  setDeck();
}

void Player::clearPlayerDeck(){
  player_deck.destroyList();
  setDeck();
}
