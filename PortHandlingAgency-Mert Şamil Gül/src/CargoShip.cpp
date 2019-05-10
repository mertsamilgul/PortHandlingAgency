#include "CargoShip.h"
#include <Ship.h>
#include <string.h>
#include <iostream>
CargoShip::CargoShip(int id,char *name,int capacity)
{
    char *name_=new char[strlen(name)+1]; // Allocating memory for ship's name.
    strcpy(name_,name);
    this->name=name_;
    this->capacity=capacity;
    this->id=id;
    containers=0;
}
CargoShip::~CargoShip()
{
    delete []name;
}

CargoShip *CargoShip::getNext()
{
    return next;
}
void CargoShip::setNext(CargoShip *i)
{
    next=i;
}
int CargoShip::getCont()
{
    return containers;
}
void CargoShip::setCont(int cont)
{
    containers=cont;
}
