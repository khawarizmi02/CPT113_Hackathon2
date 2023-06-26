#include "Deck.h"
#include "Player.h"
#include "LinkedList.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Deck::Deck() : deck_list_id(20) {
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

  i = 0;
  while(i < player.getPlayerDeckSize()){
    deck_list_id.appendNode(player.getCardId(i));
    i++;
  }
}

Deck::~Deck(){
  // destructor
}

void Deck::displayCard(int value){

  int n = value - 1;
  cout << setw(3) << left << id[n];
  cout << setw(20) << left << name[n] << setw(8) << right << health_attack[n][0]; 
  cout << setw(8) << right << health_attack[n][1] << endl;
}

int Deck::getCardId(int value){
  return deck_list_id.getNodeValue(value);
}

void Deck::showCardList (){

  cout << "All cards list: " << endl;
  cout << setw(3) << left << "ID" << setw(20) << left << "Name";
  cout << setw(10) << left << "Type" << " ";
  cout << setw(8) << right << "Damage" << setw(8) << right << "Heal" << "  ";
  cout << setw(60) << left << "Description" << endl;

  for (int i=0; i < 50; i++){
    cout << setw(3) << left << id[i] << setw(20) << left << name[i];
    cout << setw(10) << left << type[i] << " ";
    cout << setw(8) << right << health_attack[i][0] << setw(8) << right << health_attack[i][1] << "  ";
    cout << setw(60) << left << description[i] << endl;
  }
}

void Deck::showMyDeck(){
  cout << "this is your deck list" << endl;

  cout << setw(3) << left << "ID";
  cout << setw(20) << left << "Name" << setw(8) << right << "Damage"; 
  cout << setw(8) << right << "Heal" << endl;

  for (int j = 0; j < deck_list_id.getNodeSize(); j++ ){
    for (int i = 0; i < 50; i++){
      if (deck_list_id.getNodeValue(j+1) == id[i]){
        cout << setw(3) << left << id[i];
        cout << setw(20) << left << name[i] << setw(8) << right << health_attack[i][0]; 
        cout << setw(8) << right << health_attack[i][1] << endl;
      }
    }
  }
}

void Deck::clearDeck(){
  player.clearPlayerDeck();
  deck_list_id.destroyList();
}

void Deck::removeCard(int value){
  deck_list_id.deleteNode(value); 
  player.deletePlayerCard(value);
}

void Deck::addCard(int value){
  if (deck_list_id.getNodeSize() >= deck_list_id.getMaxNodeSize()){
    cout << "Deck is full. Please remove one to replace another card." << endl;
    system("pause");
    return;
  }
  deck_list_id.appendNode(value);
  player.addPlayerCard(value);
}
    // int getIdCard(int pos);
    // int getHealCard(int pos);
    // int getAttackCard(int pos);

int Deck::getIdCard(int pos){
  return deck_list_id.getNodeValue(pos); 
}

int Deck::getHealCard(int pos){
  return health_attack[pos][1]; 
}

int Deck::getAttackCard(int pos){
  return health_attack[pos][0]; 
}

string Deck::getTypeCard(int pos){
  return type[pos];
}

