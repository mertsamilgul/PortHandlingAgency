#ifndef PASSENGERSHIP_H
#define PASSENGERSHIP_H
#include <Ship.h>
class PassengerShip : public Ship
{
private:
    int passengers;
    PassengerShip *next;
public:
    PassengerShip(int id,char *name,int capacity);
    ~PassengerShip();
    PassengerShip *getNext();
    void setNext(PassengerShip *i);
    int getPass();
    void setPass(int pass);
};

#endif // PASSENGERSHIP_H
