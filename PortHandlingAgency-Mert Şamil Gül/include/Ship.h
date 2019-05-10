#ifndef SHIP_H
#define SHIP_H
class Ship
{
protected:
    char *name;
    int capacity;
    int id;
public:
    int getId();
    // Returns id
    char *getName();
    // Returns name
    int getCapacity();
    // Returns capacity
    void print();
    // Prints name pf ship
};

#endif
