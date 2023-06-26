#ifndef DECK_H
#define DECK_H

#include "Player.h"
#include "LinkedList.h"

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
    // int card_list[20];
    LinkedList<int> deck_list_id;

  
  public:
    Deck();
    ~Deck();

    void showCardList();
    void showMyDeck();
    void clearDeck();
    void removeCard(int value);
    void addCard(int value);
    int getCardId(int value);
    void displayCard(int value);

    // gameplay function
    int getIdCard(int pos);
    int getHealCard(int pos);
    int getAttackCard(int pos);
    string getTypeCard(int pos);
};

#endif // !DECK_H
