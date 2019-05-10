#include "Port.h"
#include <iostream>
#include <string.h>
#include <typeinfo>
using namespace std;
Port::Port(int id,char *name,int maxships,int capacity)
{
    char *name_=new char[strlen(name)+1];
    strcpy(name_,name);
    headcs=NULL;
    headot=NULL;
    headps=NULL;
    this->name=name_;
    this->maxships=maxships;
    this->capacity=capacity;
    this->id=id;
    total=0;
    numships=0;
    numcont=0;
    numtanks=0;
    numpeople=0;
}
Port::~Port()
{
    delete []name;
    PassengerShip *ps=headps;
    OilTanker *ot=headot;
    CargoShip *cs=headcs;
    while(ps)
    {
        ps=ps->getNext();
        delete headps;
        headps=ps;
    }
    while(ot)
    {
        ot=ot->getNext();
        delete headot;
        headot=ot;
    }
    while(cs)
    {
        cs=cs->getNext();
        delete headcs;
        headcs=cs;
    }
}

int Port::getId()
{
    return id;
}

CargoShip *Port::getCsHead()
{
    return headcs;
}

OilTanker *Port::getOtHead()
{
    return headot;
}

PassengerShip *Port::getPsHead()
{
    return headps;
}

void Port::addCargoShip(int id,char *name,int capacity)
{
    CargoShip *i;
    if(maxships==numships) { cout << "Port is Full." << endl; return;}
    for(i=headcs;i!=NULL;i=i->getNext())
        if(id==i->getId())
        {
            cout << "Ship already exist." << endl;
            return;
        }

    CargoShip *j=new CargoShip(id,name,capacity);
    j->setNext(NULL);
    if(headcs==NULL)
    {
        headcs=j; return;
    }
    for(i=headcs;i->getNext()!=NULL;i=i->getNext());
    i->setNext(j);
    numships++;
}

void Port::addOilTanker(int id,char *name,int capacity)
{
    OilTanker *i;
    if(maxships==numships) { cout << "Port is Full." << endl; return;}
    for(i=headot;i!=NULL;i=i->getNext())
        if(id==i->getId())
        {
            cout << "Ship already exist." << endl;
            return;
        }

    OilTanker *j=new OilTanker(id,name,capacity);
    j->setNext(NULL);
    if(headot==NULL)
    {
        headot=j; return;
    }
    for(i=headot;i->getNext()!=NULL;i=i->getNext());
    i->setNext(j);
    numships++;
}

void Port::addPassengerShip(int id,char *name,int capacity)
{
    PassengerShip *i;
    if(maxships==numships) { cout << "Port is Full." << endl; return;}
    for(i=headps;i!=NULL;i=i->getNext())
        if(id==i->getId())
        {
            cout << "Ship already exist." << endl;
            return;
        }

    PassengerShip *j=new PassengerShip(id,name,capacity);
    j->setNext(NULL);
    if(headps==NULL)
    {
        headps=j; return;
    }
    for(i=headps;i->getNext()!=NULL;i=i->getNext());
    i->setNext(j);
    numships++;
}

void Port::print()
{
    cout << "   Containers: " << numcont << endl;
    cout << "   Tankers: " << numtanks << endl;
    cout << "   Passengers: " << numpeople << endl;

    cout << "   Total: " << numtanks*15+numcont*10+numpeople << "/" << capacity << endl;

    for(CargoShip *cs=headcs;cs!=NULL;cs=cs->getNext())
    {
        cs->print();
        cout << " (" << cs->getCont() << "/" << cs->getCapacity() << ")" << endl;
    }
    for(OilTanker *ot=headot;ot!=NULL;ot=ot->getNext())
    {
        ot->print();
        cout << " (" << ot->getTanks() << "/" << ot->getCapacity() << ")" << endl;
    }
    for(PassengerShip *ps=headps;ps!=NULL;ps=ps->getNext())
    {
        ps->print();
        cout << " (" << ps->getPass() << "/" << ps->getCapacity() << ")" << endl;
    }
}

void Port::setNext(Port *x)
{
    next=x;
}

Port *Port::getNext()
{
    return next;
}

char *Port::getName()
{
    return name;
}

void Port::getPassenger(int passengers)
{
    if(capacity>=(total+passengers))
    {
        numpeople+=passengers;
        total+=passengers;
    }
    else
        cout << "There is no enough space in port" << endl;
}

void Port::getContainer(int containers)
{
    if(capacity>=(total+containers*10))
    {
        numcont+=containers;
        total+=containers*10;
    }
    else
        cout << "There is no enough space in port" << endl;
}

void Port::getTanker(int tankers)
{
    if(capacity>=(total+tankers*15))
    {
        numtanks+=tankers;
        total+=tankers*15;
    }
    else
        cout << "There is no enough space in port" << endl;
}

void Port::loadCs(int id,int containers)
{
    if(numcont<containers)
    {
        cout << "Not enough containers in Port." << endl; return;
    }

    CargoShip *i=headcs;
    while(i && i->getId()!=id)
        i=i->getNext();
    if(i)
    {
        if((containers+i->getCont())<=i->getCapacity())
        {
            i->setCont(i->getCont()+containers);
            numcont-=containers;
            total-=containers*10;
        }
        else
            cout << "There is not enough space in Ship." << endl;
    }
    else
        cout << "Ship not found." << endl;
}

void Port::loadOt(int id,int tanks)
{
    if(numtanks<tanks)
    {
        cout << "Not enough tanks in Port." << endl; return;
    }
    OilTanker *i=headot;
    while(i && i->getId()!=id)
        i=i->getNext();
    if(i)
    {
        if((tanks+i->getTanks())<=i->getCapacity())
        {
            i->setTanks(i->getTanks()+tanks);
            numtanks-=tanks;
            total-=tanks*15;
        }
        else
            cout << "There is not enough space in Ship." << endl;
    }
    else
        cout << "Ship not found." << endl;
}

void Port::loadPs(int id,int passengers)
{
    if(numpeople<passengers)
    {
        cout << "Not enough passengers in Port." << endl; return;
    }
    PassengerShip *i=headps;
    while(i && i->getId()!=id)
        i=i->getNext();
    if(i)
    {
        if((passengers+i->getPass())<=i->getCapacity())
        {
            i->setPass(i->getPass()+passengers);
            numpeople-=passengers;
            total-=passengers;
        }
        else
            cout << "There is not enough space in Ship." << endl;
    }
    else
        cout << "Ship not found." << endl;
}

void Port::unloadCs(int id,int containers)
{
    if(capacity<(total+containers*10))
    {
        cout << "Not enough space in port." << endl; return;
    }

    CargoShip *i=headcs;
    while(i && i->getId()!=id)
        i=i->getNext();
    if(i)
    {
        if(containers<=i->getCont())
        {
            numcont+=containers;
            total+=containers*10;
            i->setCont(i->getCont()-containers);
        }
        else
            cout << "There is not enough containers in Ship." << endl;
    }
    else
        cout << "Ship not found." << endl;
}

void Port::unloadOt(int id,int tanks)
{
    if(capacity<(total+tanks*15))
    {
        cout << "Not enough space in port." << endl; return;
    }

    OilTanker *i=headot;
    while(i && i->getId()!=id)
        i=i->getNext();
    if(i)
    {
        if(tanks<=i->getTanks())
        {
            numtanks+=tanks;
            total+=tanks*15;
            i->setTanks(i->getTanks()-tanks);
        }
        else
            cout << "There is not enough containers in Ship." << endl;
    }
    else
        cout << "Ship not found." << endl;
}

void Port::unloadPs(int id,int passengers)
{
    if(capacity<(total+passengers))
    {
        cout << "Not enough space in port." << endl; return;
    }

    PassengerShip *i=headps;
    while(i && i->getId()!=id)
        i=i->getNext();
    if(i)
    {
        if(passengers<=i->getPass())
        {
            numpeople+=passengers;
            total+=passengers;
            i->setPass(i->getPass()-passengers);
        }
        else
            cout << "There is not enough containers in Ship." << endl;
    }
    else
        cout << "Ship not found." << endl;
}

void Port::removeCs(int id)
{
    if(headcs==NULL)
    {
        cout << "Ship not found" << endl;
        return;
    }
    if(headcs->getId()==id)
    {
        CargoShip *tmp=headcs;
        headcs=headcs->getNext();
        delete tmp;
        return;
    }
    CargoShip *i=headcs;
    while(i->getNext() && i->getNext()->getId()!=id)
        i=i->getNext();
    if(i->getNext())
    {
        CargoShip *tmp=i->getNext();
        i->setNext(i->getNext()->getNext());
        delete tmp;
    }
    else
        cout << "Ship not found" << endl;
}

void Port::removeOt(int id)
{
    if(headot==NULL)
    {
        cout << "Ship not found" << endl;
        return;
    }
    if(headot->getId()==id)
    {
        OilTanker *tmp=headot;
        headot=headot->getNext();
        delete tmp;
        return;
    }
    OilTanker *i=headot;
    while(i->getNext() && i->getNext()->getId()!=id)
        i=i->getNext();
    if(i->getNext())
    {
        OilTanker *tmp=i->getNext();
        i->setNext(i->getNext()->getNext());
        delete tmp;
    }
    else
        cout << "Ship not found" << endl;
}

void Port::removePs(int id)
{
    if(headps==NULL)
    {
        cout << "Ship not found" << endl;
        return;
    }
    if(headps->getId()==id)
    {
        PassengerShip *tmp=headps;
        headps=headps->getNext();
        delete tmp;
        return;
    }
    PassengerShip *i=headps;
    while(i->getNext() && i->getNext()->getId()!=id)
        i=i->getNext();
    if(i->getNext())
    {
        PassengerShip *tmp=i->getNext();
        i->setNext(i->getNext()->getNext());
        delete tmp;
    }
    else
        cout << "Ship not found" << endl;
}
