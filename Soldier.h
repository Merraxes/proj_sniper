#pragma once

#include <string>

using namespace std;


class Soldier
{

   // int _hp, baseHp;
    int _us;
    int _agility, _observation, _camouflage;
    bool _alive;
public:

    Soldier();
    //~Soldier();

 //   int hp() { return _hp; }
    int agility() {return _agility;}
    int observation() {return _observation;}
    int camouflage() {return _camouflage;}
    bool alive() {return _alive;}

    bool shot(int a);
    bool scan(int a);

  //  void heal();

    int move();

    string description();
};


