#include "Ship.h"
#include <iostream>
#include <string.h>
using namespace std;
int Ship::getId()
{
    return id;
}
char *Ship::getName()
{
    return name;
}

void Ship::print()
{
    cout << "  -- " << name;
}
int Ship::getCapacity()
{
    return capacity;
}
