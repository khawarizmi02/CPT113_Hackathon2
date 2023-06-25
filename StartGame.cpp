#include "Deck.h"
#include "Game.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>

using namespace std;

int main(); // function prototype

void StartGame(Deck deck){
  Game game;
  game.Start();

  system("pause");
}

// void StartGame(Deck deck){ 
//   string line;
//   cout << setw(80) << right << "MONSTER" << "  " << setw(5) << left << "5/5" << endl;
//
//   ifstream file("fight-monster-image.txt");
//
//   if(!file.is_open()){
//     cout << "Unable to open file" << endl;
//     return;
//   }
//
//   while(getline(file,line)){
//     cout << line << endl;
//   }
//   file.close();
//   cout << setw(25) << right << "PLAYER" << "  " << setw(5) << left << "20/20" <<  endl;
//
//   main();
// }
