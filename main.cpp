#include "Deck.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

void MyDeckMenu(Deck deck);

int main () {
  cout << "Card Dungeon" << endl;
  cout << "1. Start Game" << endl;
  cout << "2. My Deck" << endl;
  cout << "3. Exit" << endl;

  int pick;
  cout << "Enter youre choice: ";
  cin >> pick;

  Deck deck;

  switch (pick) {
    case 1 : 
      cout << "You choose: " << pick << endl;
      break;
    case 2 : 
      MyDeckMenu(deck);
      break;
    case 3 : 
      cout << "You choose: " << pick << endl;
      break;
    default :
      cout << "Pick the right number: ";
      main();
      break;
  }

  return 0;
}

void MyDeckMenu(Deck deck){
  // system("cls");
  deck.showMyDeck();
  // deck.showCardList();
}
