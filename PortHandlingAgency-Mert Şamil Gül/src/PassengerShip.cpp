#include "PassengerShip.h"
#include <string.h>
PassengerShip::PassengerShip(int id,char *name,int capacity)
{
    char *name_=new char[strlen(name)+1]; // Allocating memory for ship's name.
    strcpy(name_,name);
    this->name=name_;
    this->capacity=capacity;
    this->id=id;
    passengers=0;
}

PassengerShip::~PassengerShip()
{
    delete []name;
}
PassengerShip *PassengerShip::getNext()
{
    return next;
}
void PassengerShip::setNext(PassengerShip *i)
{
    next=i;
}
int PassengerShip::getPass()
{
    return passengers;
}
void PassengerShip::setPass(int pass)
{
    passengers=pass;
}
