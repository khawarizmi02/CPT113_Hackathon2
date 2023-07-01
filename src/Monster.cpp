#include "../header/Monster.h"

#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

Monster::Monster() {
  ifstream file("data/monster.txt");
  string line;

  if (!file.is_open()){
    cout << "File cannot be open" << endl;
    return;
  }

  getline(file,line);

  int i = 0;
  while(getline(file,line)){
    istringstream iss(line);
    iss >> monster_level[i] >> monster_name[i] >> monster_health[i] >> monster_attack[i] >> monster_skill[i] >> monster_image[i];
    i++;
  }

  file.close();
}

void Monster::setMonsterStats(int level){
  current_monster_level = monster_level[level - 1];
  current_monster_name = monster_name[level - 1];
  current_monster_attack = monster_attack[level - 1];
  current_monster_health = monster_health[level - 1];
  current_monster_skill = monster_skill[level - 1];
  current_monster_image = monster_image[level - 1];
}

int Monster::getMonsterHealth(){
  return current_monster_health;
}

int Monster::getMonsterAttack(){
  return current_monster_attack;
}

void Monster::displayMonster(){
  cout << "Name: " << current_monster_name << " Health: " << current_monster_health << endl;
  string line;
  ifstream file(current_monster_image);

  if(!file.is_open()){
    cout << "Unable to open file" << endl;
    return;
  }

  while(getline(file,line)){
    cout << line << endl;
  }
  file.close();
}

void Monster::reduceHealth(int value, string dmg_type){
  if (dmg_type == current_monster_skill){
    current_monster_health -= (0.8 * value);
    return;
  }
  current_monster_health -= value;
}
