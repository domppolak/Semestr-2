#ifndef _PRZESZKODA_HH
#define _PRZESZKODA_HH

#include "inter_drona.hh"
#include "inter_rysowania.hh"

class przeszkoda
{   
public:
    virtual bool czy_kolizja(const interfejs_drona &) = 0;
    virtual void rysuj() = 0;
};

#endif