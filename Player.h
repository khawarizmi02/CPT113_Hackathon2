#ifndef PLAYER_H
#define PLAYER_H

#include <string>

using namespace std;

class Player
{
public:
  Player();
  ~Player();

  int getCardId(int i);
  void setDeck(int deck[], int size);

private:
  int card_id [20];
};

#endif // !PLAYER_H