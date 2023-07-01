#include "../header/Player.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Player::Player() : player_deck(20) {
  ifstream file("data/playerDeck.txt");
  if (!file) {
    cout << "Failed to open file." << endl;
    return;
  }
  
  string line;
  int value;

  while (getline(file, line)) {
    if (line.empty()) continue;  // Skip empty lines

    stringstream ss(line);
    if (ss >> value) {
      if (value <= 0) break;
      player_deck.appendNode(value);
    }
  }
  file.close();
  health = 20;
  armor = 0;
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
  myFile.open("data/playerDeck.txt", ios::trunc);
  myFile.close();
  myFile.open("data/playerDeck.txt");
  
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

// gameplay function

void Player::resetPlayer(){
  health = 20;
  armor = 0;
}

void Player::reduceHealth(int value){
  if (armor > 0 && value < armor){
    armor = armor - value;
    return;
  }
  if (armor > 0 && value >= armor){
    value = value - armor;
    health = health - value;
    armor = 0;
    return;
  }
  health = health - value;
}

void Player::addHealth(int value){
  health = health + value;
}

void Player::addArmor(int value){
  armor += value;
}

int Player::getHealth(){
  return health;
}

int Player::getArmor(){
  return armor;
}
