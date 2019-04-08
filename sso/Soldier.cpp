#include "Functions.h"
#include "Soldier.h"
#include "Sniper.h"
#include <stdlib.h>

Soldier::Soldier()
{
        _us = randomValue()- DOWNSIDE;
        _agility = randomValue() - DOWNSIDE;
        _observation = randomValue() - DOWNSIDE;
        _camouflage = randomValue() - DOWNSIDE;

}

bool Soldier::shot(int a)
{
        return (_us-a>=test()) ? true : false;

}

bool Soldier::scan(int a)
{
    return (_observation-a/2>=test()) ? true : false;

}


int Soldier::move()
{
    return _agility/VALUE;
}

string Soldier::description()
{
    return //"HP: " + to_string(_hp) +
    "\n\tUS: " + to_string (_us) +
    "\n\tAgility: " + to_string (_agility) +
    "\n\tObservation: " + to_string (_observation) +
    "\n\tCamouflage: " + to_string (_camouflage);
}




