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
  int pick;
  cout << "My Deck: " << endl;
  deck.showMyDeck();

  cout << endl << endl;

  cout << "Option" << endl;
  cout << "1. Edit Deck" << endl;
  cout << "2. Clear Deck" << endl;
  cout << "3. Show All Cards" << endl;
  cout << "4. Back" << endl;

  cout << "Enter your choice: ";
  cin >> pick;

  system("cls");
  switch (pick) {
    case 1 : 
      cout << "Edit your deck: "<< endl;
      break;
    case 2 : 
      cout << "Deck cleared" << endl;
      MyDeckMenu(deck);
      break;
    case 3 : 
      cout << "Card list" << endl;
      deck.showCardList();
      break;
    case 4 : 
      main();
      break;
    default :
      cout << "Pick the right number: ";
      system("cls");
      MyDeckMenu(deck);
      break;
  }
  // system("cls");
}
