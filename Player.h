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

private:
  // int card_id [20];
  LinkedList<int> player_deck;

};

#endif // !PLAYER_H
