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

  void setMonsterStats(int level);
  void monsterChallengeMode(int level);
  void reduceHealth(int value, string dmg_type);
  void displayMonster();
  int getMonsterHealth();
  int getMonsterAttack();

private:
  // to set current monster
  int current_monster_level;
  string current_monster_name;
  int current_monster_attack;
  int current_monster_health;
  string current_monster_skill;
  string current_monster_image;

  int monster_level[5];
  string monster_name[5];
  int monster_attack[5];
  int monster_health[5];
  string monster_skill[5];
  string monster_image[5];
};
#endif // !MONSTER_H
