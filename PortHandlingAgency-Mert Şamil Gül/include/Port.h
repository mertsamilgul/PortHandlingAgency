#ifndef PORT_H
#define PORT_H
#include <Ship.h>
#include <CargoShip.h>
#include <OilTanker.h>
#include <PassengerShip.h>
class Port
{
    int id;
    char *name;
    int maxships; // Maximum capacity of ships in the port
    int capacity;

    int numships;
    int numpeople; // Number of people for passenger ships
    int numtanks; // Number of tanks for oil tankers
    int numcont; // Number of containers for cargo ships
    int total; // Total number of loads
    Port *next;
    CargoShip *headcs; // Head of the list of cargoships
    OilTanker *headot; // Head of the list of Oiltankers
    PassengerShip *headps; // Head of the list of Passengerhips.

public:

    Port(int id,char *name,int maxship,int capacity);
    // Creates new port with given infos and empty lists.
    ~Port();
    // Deletes all the ships in it
    int getId();
    // Returns id of the port
    void print();
    // Prints all the loads and ships in it
    CargoShip *getCsHead();
    OilTanker *getOtHead();
    PassengerShip *getPsHead();
    // Returns heads of different lists
    void addCargoShip(int id,char *name,int capacity);
    void addOilTanker(int id,char *name,int capacity);
    void addPassengerShip(int id,char *name,int capacity);
    // Adds different type of ships to different lists.
    void getPassenger(int passengers);
    void getContainer(int containers);
    void getTanker(int tankers);
    // Gets loads from land
    void loadCs(int id,int containers);
    void loadOt(int id,int tanks);
    void loadPs(int id,int passengers);
    // Loads ships with different types
    void unloadCs(int id,int containers);
    void unloadOt(int id,int tanks);
    void unloadPs(int id,int passengers);
    // Unloads ships with different types
    void removeCs(int id);
    void removeOt(int id);
    void removePs(int id);
    // Removes given type of ship with given id
    void setNext(Port *x);
    // Setter for private *next
    Port *getNext();
    // Getter for private *next
    char *getName();
    // Getter for private *name
};
#endif
