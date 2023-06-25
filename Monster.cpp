#include "Monster.h"

#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

Monster::Monster() {
  // ifstream file("MonsterList.txt");
  // string line;
  //
  // if (!file.is_open()){
  //   cout << "File cannot be open" << endl;
  //   return;
  // }
  //
  // getline(file,line);
  //
  // int i = 0;
  // while(getline(file,line)){
  //   istringstream iss(line);
  //   iss >> monster_id[i] >> monster_name[i] >> monster_attack[i] >> monster_health[i] >> monster_skill[i];
  //   i++;
  // }
  //
  // file.close();

 monster_name = "Monster 1";
 monster_attack = 5;
 monster_health = 1000;
 monster_skill = "damage";

}

Monster::~Monster(){
  // destructor
}

int Monster::getMonsterHealth(){
  return monster_health;
}

void Monster::displayMonster(){
  cout << "Monster name: " << monster_name << " Health: " << monster_health << endl;
}

void Monster::reduceHealth(int value, string dmg_type){
  if (dmg_type == monster_skill){
    monster_health = monster_health - (0.8 * value);
  }
}
