#ifndef MONSTER_H
#define MONSTER_H

#include "LinkedList.h"

#include <string>
#include <iostream>

using namespace std;

class Monster
{
public:
  Monster();
  ~Monster();

  void reduceHealth(int value, string dmg_type);
  void displayMonster();
  int getMonsterHealth();

private:
  // int monster_id;
  string monster_name;
  int monster_attack;
  int monster_health;
  string monster_skill;
};
#endif // !MONSTER_H

  // int monster_id[5];
  // string monster_name[5];
  // int monster_attack[5];
  // int monster_health[5];
  // int monster_skill[5];

