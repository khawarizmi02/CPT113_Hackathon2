#include "Game.h"
#include "Deck.h"
#include "Monster.h"

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <random>
#include <algorithm>

using namespace std;

  // void appendNode(T value);
  // void deleteNode(T value);
  // T getNodeValue(int pos);
  // void displayList() const;
  // void destroyList();
  // int getNodeSize();
  // int getMaxNodeSize();


  // void enqueue(T);
  // void dequeue(T &);
  // bool isEmpty() const;
  // void clear();

Game::Game() : hand_list(5){
  player.resetPlayer();
  playerTurn = true;
}

bool Game::getResult(){
  return gameResult;
}

void Game::Start(int level){
  cout << "The game is start" << endl;

  if (level > 5){
    cout << "Looks like you have defeated all of the monsters..." << endl;
    cout << "Thank you for playing this game :)" << endl;
    return;
  }

  setDeck();
  monster.setMonsterStats(level);
  player.resetPlayer();
  setHand5Cards();
  StartTurn();
}

void Game::DisplayPlayerStat(){
  cout << "This is your health and armor" << endl;
  cout << "Health: " << player.getHealth() << " ";
  cout << "Armor: " << player.getArmor() << endl;
}

void Game::StartTurn(){
  system("cls");
  // check player health
  if (player.getHealth() <= 0){
    cout << "YOU LOSE" << endl;
    cout << "GAME OVER" << endl;
    gameResult = false;
    return;
  }
  if (monster.getMonsterHealth() <= 0){
    cout << "YOU WIN" << endl;
    cout << "GAME OVER" << endl;
    gameResult = true;
    return;
  }

  DisplayPlayerStat();
  monster.displayMonster();

  if (playerTurn){
    int pick;
    DisplayHand();
    cout << "Pick a card to use:" ;
    cin >> pick;
    cout << "You Pick card " << pick << endl;
    PlayerChoose(pick);
    // delete card from hand
    hand_list.deleteNode(pick); 
    DrawCard();
    playerTurn = false;
    StartTurn();
  }
  else {
    cout << "monster's turn" << endl;
    player.reduceHealth(monster.getMonsterAttack());
    system("pause");
    playerTurn = true;
    StartTurn();
  }
}

void Game::PlayerChoose(int id){
  system("cls");
  int pos = id - 1;
  string type = deck.getTypeCard(pos);

  if (type == "Armor"){
    player.addArmor(deck.getHealCard(pos));
    return;
  }
  else if (type == "Spell"){
    monster.reduceHealth(deck.getAttackCard(pos), type);
    return;
  }
  else if (type == "Weapon"){
    monster.reduceHealth(deck.getAttackCard(pos), type);
    return;
  }
  else if (type == "Potion"){
    player.addHealth(deck.getHealCard(pos));
    return;
  }
}

void Game::setHand5Cards(){
  int x = 0, i = 0;
  current_deck.pop(x);
  while(i < 5){
    current_deck.pop(x);
    hand_list.appendNode(x);
    i++;
  }
  if(hand_list.getNodeSize() > 0){
    cout << "5 cards have been drawn" << endl;
    system("pause");
  }
}

void Game::DisplayHand(){
  cout << "This is the available card to use" << endl;
  cout << setw(3) << left << "ID";
  cout << setw(20) << left << "Name" << setw(8) << right << "Damage"; 
  cout << setw(8) << right << "Heal" << endl;

  int i = 1;
  while(i <= 5){
    deck.displayCard(hand_list.getNodeValue(i));
    i++;
  }
}

void Game::DrawCard(){
  int x;
  current_deck.pop(x);
  hand_list.appendNode(x);
  cout << "You have drawn a card" << endl;
}

void Game::setDeck(){
  int i;
  // Create an array with 20 elements
  int arr[20];

  // Assign values from 1 to 20 in order
  for (i = 0; i < 20; i++) {
      arr[i] = i + 1;
  }

  // Shuffle the array using random positions
  random_device rd;
  mt19937 gen(rd());

  for (int i = 19; i > 0; i--) {
      uniform_int_distribution<> dis(0, i);
      int randomIndex = dis(gen);
      swap(arr[i], arr[randomIndex]);
  }

  i = 1;
  while(i <= 20){
    current_deck.push(deck.getCardId(arr[i]));
    i++;
  }
}
