#include <iostream>
#include <Agency.h>
#include <Port.h>
#include <CargoShip.h>
#include <PassengerShip.h>
#include <OilTanker.h>
using namespace std;
int main()
{
     //-------Creating Agency-------//
    Agency a1("Agency a1");

    a1.removePort(0); // Trying to remove Port thats not created.

    //-------Creating Ports-------//
    a1.addPort(1,"Port p1",5,10000);
    a1.addPort(2,"Port p2",5,20000);
    a1.addPort(3,"Port p3",5,30000);
    a1.addPort(3,"Port p3",5,30000); // Trying to add same port

    //------Adding Ships To Ports-------//
    a1.addCsToPort(2,1,"CargoShip c1",1000);
    a1.addCsToPort(2,2,"CargoShip c2",2000);
    a1.addCsToPort(2,3,"CargoShip c3",3000);

    a1.addOtToPort(2,4,"OilTanker o1",1000);

    a1.addPsToPort(3,5,"PassengerShip p1",2000);
    a1.addPsToPort(3,6,"PassengerShip p2",3000);

    Agency a2("Agency a2");
    a2.addPort(4,"Port p4",6,3000);

    a2.addCsToPort(4,7,"CargoShip c4",1000);

    a1.print(); // Same senario as in memory map

    a1.removeCsFromPort(2,2); // removing CargoShip c2 from Port p1

    a1.getContToPort(2,100); // Added 100 container to port2
    a1.loadCsInPort(2,1,50); // Loaded 50 container to CargoShip c1
    a1.moveCsToPort(a2,2,1,4); // CargoShip c1 from Port p2 moves to Port p4
    a2.unloadCsInPort(4,1,40); // Unloaded 40 container in Port p4

    a1.print();
    a2.print();
    return 0;
}
