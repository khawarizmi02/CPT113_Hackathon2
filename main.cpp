#include "Deck.h"

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void MyDeckMenu(Deck deck);
void MyEditMenu(Deck deck);
void StartGame(Deck deck);

int main () {
  cout << "Card Dungeon" << endl;
  cout << "1. Start Game" << endl;
  cout << "2. My Deck" << endl;
  cout << "3. Exit" << endl;

  int pick;
  // pick = 2;
  cout << "Enter youre choice: ";
  cin >> pick;

  Deck deck;

  switch (pick) {
    case 1 : 
      system("cls");
      StartGame(deck);
      break;
    case 2 : 
      system("cls");
      MyDeckMenu(deck);
      break;
    case 3 : 
      system("cls");
      cout << "Closing Game" << endl;
      usleep(2000000);
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
  // pick = 1;
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
      MyEditMenu(deck);
      break;
    case 2 : 
      cout << "Deck cleared" << endl;
      deck.clearDeck();
      MyDeckMenu(deck);
      system("cls");
      break;
    case 3 : 
      cout << "Card list" << endl;
      deck.showCardList();
      system("pause");
      MyDeckMenu(deck);
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

void MyEditMenu(Deck deck){
  system("cls");

  deck.showMyDeck();
  cout << endl << endl;

  int pick, n;
  // pick = 1;
  cout << "1. Remove Card" << endl;
  cout << "2. Add Card" << endl;
  cout << "3. Done" << endl;
  cout << "Your choice: ";
  cin >> pick;

  switch (pick){
    case 1:
      cout << "Enter card id to remove: ";
      cin >> n;
      deck.removeCard(n);
      MyEditMenu(deck);
      break;
    case 2:
      cout << "Enter card id to add: ";
      cin >> n;
      cout << "you want to add card: " << n << endl;
      deck.addCard(n);
      MyEditMenu(deck);
      break;
    case 3:
      system("cls");
      MyDeckMenu(deck);
      break;
    default:
      cout << "Pick the right number!!!";
      system("cls");
      MyEditMenu(deck);
      break;
  }
}

