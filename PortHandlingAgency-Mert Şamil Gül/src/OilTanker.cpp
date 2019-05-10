#include "OilTanker.h"
#include <string.h>
OilTanker::OilTanker(int id,char *name,int capacity)
{
    char *name_=new char[strlen(name)+1]; // Allocating memory for ship's name.
    strcpy(name_,name);
    this->name=name_;
    this->capacity=capacity;
    this->id=id;
    tanks=0;
}

OilTanker::~OilTanker()
{
    delete []name;
}
OilTanker *OilTanker::getNext()
{
    return next;
}
void OilTanker::setNext(OilTanker *i)
{
    next=i;
}
int OilTanker::getTanks()
{
    return tanks;
}
void OilTanker::setTanks(int tanks)
{
    this->tanks=tanks;
}
