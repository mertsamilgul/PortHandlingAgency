#ifndef OILTANKER_H
#define OILTANKER_H
#include <Ship.h>

class OilTanker : public Ship
{
private:
    int tanks; // Number of oil tanks in it
    OilTanker *next;
public:
    OilTanker(int id,char *name,int capacity);
    ~OilTanker();
    OilTanker *getNext();
    void setNext(OilTanker *i);
    int getTanks();
    void setTanks(int tanks);
};

#endif // OILTANKER_H
