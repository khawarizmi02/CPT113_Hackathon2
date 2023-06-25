#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Monster.h"
#include "Player.h"
#include "LinkedList.h"
#include "DynQue.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

class Game
{
public:
  Game();
  // ~Game();

  void Start();
  void DisplayHand();
  void DisplayPlayerStat();
  void DrawCard(); 
  void setHand5Cards();
  void setDeck();
  void StartTurn();

private:
  bool playerTurn;
  DynQue<int> current_deck;
  // int plyr_health, plyr_armor;
  Monster monster;
  Deck deck;
  Player player;
  LinkedList<int> hand_list;
  
};

#endif // !GAME_H
