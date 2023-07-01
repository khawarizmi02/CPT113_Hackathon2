#include "../header/Deck.h"
#include "../header/Game.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>

using namespace std;

int main(); // function prototype

void StartGame(Deck deck, int level){
  Game game;
  game.Start(level);
  if (!game.getResult()){
    system("pause");
    main();
  }
  char pick;
  cout << "Do you want to continue (y/n): ";
  cin >> pick;

  if (pick == 'n'){ main(); }
  else { StartGame(deck, level + 1); }
}
