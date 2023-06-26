#ifndef GAME_H
#define GAME_H

#include "Deck.h"
#include "Monster.h"
#include "Player.h"
#include "LinkedList.h"
#include "Stack.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

class Game
{
public:
  Game();
  // ~Game();

  bool getResult();
  void Start(int level);
  void DisplayHand();
  void DisplayPlayerStat();
  void DrawCard(); 
  void setHand5Cards();
  void setDeck();
  void StartTurn();
  void PlayerChoose(int id);

private:
  bool playerTurn;
  Stack<int> current_deck;
  Monster monster;
  Deck deck;
  Player player;
  LinkedList<int> hand_list;
  bool gameResult;
  
};

#endif // !GAME_H
