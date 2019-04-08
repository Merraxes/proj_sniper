#pragma once


#include <string>

using namespace std;


class Sniper
{

    int _hp, baseHp;
    int _us;
    int _agility, _observation, _camouflage;

public:

    Sniper();
    //~Sniper();

    int hp() { return _hp; }
    int agility() {return _agility;}
    int observation() {return _observation;}
    int camouflage() {return _camouflage;}


    bool shot(int a);
    bool scan(int a);
    bool hide(int a);
    int demage ();
  //  void heal();11

    int move();

    string description();
};
