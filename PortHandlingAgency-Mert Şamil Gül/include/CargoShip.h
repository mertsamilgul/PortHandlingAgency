#ifndef CARGOSHIP_H
#define CARGOSHIP_H
#include <Ship.h>
class CargoShip : public Ship
{
private:
    int containers; // Number of containers in it
    CargoShip *next;
public:
    CargoShip(int id,char *name,int capacity);
    // Creates new empty ship
    ~CargoShip();
    // Deletes its allocated name
    CargoShip *getNext();
    void setNext(CargoShip *i);
    int getCont();
    void setCont(int cont);
};

#endif
