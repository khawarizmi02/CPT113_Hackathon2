#include "Deck.h"
#include "Player.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Deck::Deck() {
  ifstream file("cards.txt");
  if (!file) {
      cout << "Failed to open file." << endl;
      return;
  }

  string line;
  int i = 0;
  while (getline(file, line) && i < 50) {
    file >> id[i] >> name[i] >> type[i] >> health_attack[i][0] >> health_attack[i][1] >> description[i];

    // replace the - with space
    string new_str = "";
    for (char ch : description[i]) {
      if (ch == '-') {
        new_str += ' ';
      } else {
        new_str += ch;
      }
    }
    description[i] = new_str;

    new_str = "";
    for (char ch : name[i]) {
      if (ch == '-') {
        new_str += ' ';
      } else {
        new_str += ch;
      }
    }
    name[i] = new_str;

    i++;
  }
    file.close();

  // get the current deck
  for (int i = 0; i < 20; i++){
    card_list[i] = player.getCardId(i);
  }
}


Deck::~Deck(){
  // destructor
}
    // int id[MAX_CARDNUM];
    // string name[MAX_CARDNUM];
    // char type[MAX_CARDNUM];
    // int health_attack[MAX_CARDNUM][2];
    // string description[MAX_CARDNUM];

void Deck::showCardList (){
  cout << "All cards list: " << endl;
  for (int i=0; i < 50; i++){
    cout << id[i] << " " << name[i] << " " << type[i] << " " << health_attack[i][0] << " " << health_attack[i][1];
    cout << " " << description[i] << endl;
  }
}

void Deck::showMyDeck(){
  cout << "this is your deck list" << endl;
  for (int i = 0; i < 20; i++){
    card_list[i] = player.getCardId(i);
  }

  cout << setw(20) << left << "Name" << setw(8) << right << "Damage"; 
  cout << setw(8) << right << "Heal" << endl;

  for (int j = 0; j < 20; j++ ){
    for (int i = 0; i < 50; i++){
      if (card_list[j] == id[i]){
        cout << setw(20) << left << name[i] << setw(8) << right << health_attack[i][0]; 
        cout << setw(8) << right << health_attack[i][1] << endl;
      }
    }
  }
}

void Deck::clearDeck(){
  for (int i = 0; i < 20; i++){
    card_list[i] = 0;
    player.editPlayerCard(card_list[i], i);
  }
}


