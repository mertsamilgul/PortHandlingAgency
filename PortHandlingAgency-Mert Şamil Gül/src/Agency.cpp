#include "Agency.h"
#include <iostream>
#include <string.h>
using namespace std;
Agency::Agency(char *name)
{
    head=NULL;
    char *name_=new char[strlen(name)+1];
    strcpy(name_,name);
    this->name=name_;

}
Agency::~Agency()
{
    delete []name;
    Port *i=head;
    while(i)
    {
        i=i->getNext();
        delete head;
        head=i;
    }
}

void Agency::addPort(int id,char *name,int maxships,int capacity)
{

    for(Port *i=head;i!=NULL;i=i->getNext())
        if(id==i->getId()){cout << "ID already exists." << endl; return;}
    Port *j=new Port(id,name,maxships,capacity);
    j->setNext(NULL);
    if(head==NULL)
    {
        head=j;
        return;
    }
    Port *i;
    for(i=head;i->getNext()!=NULL;i=i->getNext());
    i->setNext(j);
}

void Agency::removePort(int id)
{
    if(head==NULL)
    {
        cout << "Port not found" << endl;
        return;
    }
    if(head->getId()==id)
    {
        Port *tmp=head;
        head=head->getNext();
        delete tmp;
        return;
    }
    Port *i=head;
    while(i->getNext() && i->getNext()->getId()!=id)
        i=i->getNext();
    if(i->getNext())
    {
        Port *tmp=i->getNext();
        i->setNext(i->getNext()->getNext());
        delete tmp;
    }
    else
        cout << "Port not found" << endl;
}



void Agency::print()
{
    cout << name << endl;
    for(Port *i=head;i!=NULL;i=i->getNext())
        {
            cout << " -" << i->getName() << endl;
            i->print();
        }
    cout << endl;
}

void Agency::addCsToPort(int portid,int id,char *name,int capacity)
{
    Port *i=findPort(portid);
    if(i)
        i->addCargoShip(id,name,capacity);
    else
    cout << "Port not found." << endl;
}

void Agency::addOtToPort(int portid,int id,char *name,int capacity)
{
    Port *i=findPort(portid);
    if(i)
        i->addOilTanker(id,name,capacity);
    else
    cout << "Port not found." << endl;
}

void Agency::addPsToPort(int portid,int id,char *name,int capacity)
{
    Port *i=findPort(portid);
    if(i)
        i->addPassengerShip(id,name,capacity);
    else
    cout << "Port not found." << endl;
}


void Agency::getPassToPort(int portid,int passengers)
{
    Port *i=findPort(portid);
    if(i)
        i->getPassenger(passengers);
    else
    cout << "Port not found." << endl;
}

void Agency::getContToPort(int portid,int containers)
{
    Port *i=findPort(portid);
    if(i)
        i->getContainer(containers);
    else
    cout << "Port not found." << endl;
}

void Agency::getTankerToPort(int portid,int tanks)
{
    Port *i=findPort(portid);
    if(i)
        i->getTanker(tanks);
    else
    cout << "Port not found." << endl;
}

Port *Agency::findPort(int portid)
{
    Port *i=head;
    while(i && portid!=i->getId())
        i=i->getNext();
    return i;
}

void Agency::loadPsInPort(int portid,int id,int passengers)
{
    Port *i=findPort(portid);
    if(i)
        i->loadPs(id,passengers);
    else
    cout << "Port not found." << endl;
}
void Agency::loadCsInPort(int portid,int id,int containers)
{
    Port *i=findPort(portid);
    if(i)
        i->loadCs(id,containers);
    else
    cout << "Port not found." << endl;
}
void Agency::loadOtInPort(int portid,int id,int tanks)
{
    Port *i=findPort(portid);
    if(i)
        i->loadOt(id,tanks);
    else
    cout << "Port not found." << endl;
}

void Agency::unloadPsInPort(int portid,int id,int passengers)
{
    Port *i=findPort(portid);
    if(i)
        i->unloadPs(id,passengers);
    else
        cout << "Port not found." << endl;
}
void Agency::unloadCsInPort(int portid,int id,int containers)
{
    Port *i=findPort(portid);
    if(i)
        i->unloadCs(id,containers);
    else
        cout << "Port not found." << endl;
}
void Agency::unloadOtInPort(int portid,int id,int tanks)
{
    Port *i=findPort(portid);
    if(i)
        i->unloadOt(id,tanks);
    else
        cout << "Port not found." << endl;
}


void Agency::removeCsFromPort(int portid,int id)
{
    Port *i=findPort(portid);
    if(i)
        i->removeCs(id);
    else
        cout << "Port not found." << endl;
}
void Agency::removeOtFromPort(int portid,int id)
{
    Port *i=findPort(portid);
    if(i)
        i->removeOt(id);
    else
        cout << "Port not found." << endl;
}
void Agency::removePsFromPort(int portid,int id)
{
    Port *i=findPort(portid);
    if(i)
        i->removePs(id);
    else
        cout << "Port not found." << endl;
}

void Agency::moveCsToPort(Agency &a,int portid,int id,int portid2)
{
    Port *i=findPort(portid);
    if(i)
    {
        CargoShip *j=i->getCsHead();
        while(j && j->getId()!=id)
            j=j->getNext();
        if(j)
        {
            a.addCsToPort(portid2,id,j->getName(),j->getCapacity());
            Port *k=a.findPort(portid2);
            CargoShip *cs=k->getCsHead();
            while(cs->getId()!=id) cs=cs->getNext();
            cs->setCont(j->getCont());
            removeCsFromPort(portid,id);
        }
        else
        {
            cout << "Ship not found." << endl;
        }
    }
    else
        cout << "Port not found." << endl;
}
void Agency::moveOtToPort(Agency &a,int portid,int id,int portid2)
{
    Port *i=findPort(portid);
    if(i)
    {
        OilTanker *j=i->getOtHead();
        while(j && j->getId()!=id)
            j=j->getNext();
        if(j)
        {
            a.addOtToPort(portid2,id,j->getName(),j->getCapacity());
            Port *k=a.findPort(portid2);
            OilTanker *ot=k->getOtHead();
            while(ot->getId()!=id) ot=ot->getNext();
            ot->setTanks(j->getTanks());
            removeOtFromPort(portid,id);
        }
        else
        {
            cout << "Ship not found." << endl;
        }
    }
    else
        cout << "Port not found." << endl;
}
void Agency::movePsToPort(Agency &a,int portid,int id,int portid2)
{
    Port *i=findPort(portid);
    if(i)
    {
        PassengerShip *j=i->getPsHead();
        while(j && j->getId()!=id)
            j=j->getNext();
        if(j)
        {
            a.addPsToPort(portid2,id,j->getName(),j->getCapacity());
            Port *k=a.findPort(portid2);
            PassengerShip *ps=k->getPsHead();
            while(ps->getId()!=id) ps=ps->getNext();
            ps->setPass(j->getPass());
            removePsFromPort(portid,id);
        }
        else
        {
            cout << "Ship not found." << endl;
        }
    }
    else
        cout << "Port not found." << endl;
}
