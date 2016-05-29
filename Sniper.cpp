#include "Functions.h"
#include "Sniper.h"
#include <stdlib.h>

Sniper::Sniper()
{
        _hp = baseHp = randomValue();
        _us = randomValue();
        _agility = randomValue();
        _observation = randomValue();
        _camouflage = randomValue();

}

bool Sniper::shot(int a )
{
        return (_us-a>=test()) ? true : false;

}

bool Sniper::scan(int a)
{
    return (_observation - a/2>=test() ) ? true : false;

}

bool Sniper::hide(int a)
{
    return (_camouflage - a/2>=test()) ? true : false;

}

int Sniper::move()
{
    return _agility/VALUE;
}

int Sniper::demage()
{
    int d=test()/VALUE;
    _hp -= d;
    return d;
}

string Sniper::description()
{
    return "\tHP: " + to_string(_hp) +
    "\n\tUS: " + to_string (_us) +
    "\n\tAgility: " + to_string (_agility) +
    "\n\tObservation: " + to_string (_observation) +
    "\n\tCamouflage: " + to_string (_camouflage);
}




