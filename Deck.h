#ifndef DECK_H
#define DECK_H

#include "Player.h"

#include <string>

using namespace std;

class Deck {
  private:
    int id[50];
    string name[50];
    string type[50];
    int health_attack[50][2];
    string description[50];
    Player player;
    int card_list[20];
  
  public:
    Deck();
    ~Deck();

    void showCardList();
    void showMyDeck();
    void clearDeck();
};

#endif // !DECK_H
