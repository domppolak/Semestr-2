#ifndef _POWIERZCHNIA_HH
#define _POWIERZCHNIA_HH

#include "inter_rysowania.hh"

/*!
*  \brief klasa reprezentujaca powierzhcnia
*/
class powierzchnia : public interfejs_rysowania
{

public:
    /*!
    *  \brief konstruktor
    *  \param wsk - laczego do gnuplota
    *  \param K - zmienna przechowujaca kolor bryly
    */
    powierzchnia(shared_ptr<Draw3DAPI> wsk, string K) 
    : interfejs_rysowania(wsk,K) {}
    /*!
    *  \brief destruktor
    */
    virtual ~powierzchnia() {}


};
#endif