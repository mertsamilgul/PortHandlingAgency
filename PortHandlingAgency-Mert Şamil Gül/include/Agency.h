#ifndef AGENCY_H
#define AGENCY_H
#include <Port.h>
class Agency
{
    char *name; // Name of the agency
    Port *head; // Head of the list of singly linked list that keeps ports in it

public:

    Agency(char *name);
     // Creates new Agency with give name and empty list.
    ~Agency();
    // Deletes the name and all ports in linked list
    void addPort(int id,char *name,int maxships,int capacity);
    // Adds port with given values to the list.
    void removePort(int id);
    // Removes port with given id.
    void addCsToPort(int portid,int id,char *name,int capacity);
    void addOtToPort(int portid,int id,char *name,int capacity);
    void addPsToPort(int portid,int id,char *name,int capacity);
    // These functions add different types of ships to the given port with given info.
    void getPassToPort(int portid,int passengers);
    void getContToPort(int portid,int containers);
    void getTankerToPort(int portid,int tanks);
    // These functions adds given amount of passengers,containers or tankers to the given port
    void loadPsInPort(int portid,int id,int passengers);
    void loadCsInPort(int portid,int id,int containers);
    void loadOtInPort(int portid,int id,int tanks);
    //These functions load given amount of passengers,containers or tankers to the given ship
    void unloadPsInPort(int portid,int id,int passengers);
    void unloadCsInPort(int portid,int id,int containers);
    void unloadOtInPort(int portid,int id,int tanks);
    // These functions unload ships with given amount of pass,cont or tanks.
    void removeCsFromPort(int portid,int id);
    void removeOtFromPort(int portid,int id);
    void removePsFromPort(int portid,int id);
    // These functions removes different type of ships from list. In given port.
    void moveCsToPort(Agency &a,int portid,int id,int portid2);
    void moveOtToPort(Agency &a,int portid,int id,int portid2);
    void movePsToPort(Agency &a,int portid,int id,int portid2);
    // These functions can be use to move ships to any agencies any port.
    Port *findPort(int portid);
    // finds the port with given Id and returns its pointer
    void print();
    // prints the Agency name and ports in it. Also capacity of ports and ships in the port
};
#endif
