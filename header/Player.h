#ifndef PLAYER_H
#define PLAYER_H

#include "LinkedList.h"

#include <string>

using namespace std;

class Player
{
public:
  Player();
  ~Player();

  int getCardId(int i);
  void setDeck();
  void deletePlayerCard(int value);
  void addPlayerCard(int value);
  void clearPlayerDeck();
  int getPlayerDeckSize();

  // gameplay function
  void resetPlayer();
  void reduceHealth(int value);
  void addHealth(int value);
  void addArmor(int value);
  int getHealth();
  int getArmor();


private:
  LinkedList<int> player_deck;
  int health;
  int armor;

};

#endif // !PLAYER_H
