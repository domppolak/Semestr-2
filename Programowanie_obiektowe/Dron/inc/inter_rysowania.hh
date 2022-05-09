#ifndef _INTER_RYSOWANIA_HH
#define _INTER_RYSOWANIA_HH

#include <unistd.h>
#include "Dr3D_gnuplot_api.hh"
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using drawNS::Draw3DAPI;
using std::shared_ptr;
using std::string;
using std::vector;

/*!
* \brief klasa reprezuntuje obiekt rysowalny
*
*Klasa abstrakcyjna stanowiaca podstawe dla kazdego 
* rysowalnego obiektu w gnuplocie
*/

class interfejs_rysowania
{
protected:
    /*!
    *  \brief wskaznik na lacze do gnuplota
    */
    shared_ptr<drawNS::Draw3DAPI> gnuplot;
    /*!
    *  \brief zmienna przechowujaca kolor obiektu
    */
    string kolor;
    /*!
    *  \brief numer id obiektu
    */
    int obiekt_id;
public:
    /*!
    * \brief konstruktor
    * \param wsk - wskaznik na lacze do gnuplota
    * \param K - przekazanie koloru obiektu
    */
    interfejs_rysowania(shared_ptr<Draw3DAPI> wsk, string K) :
    gnuplot(wsk)
    , kolor(K)
    , obiekt_id(0) {}

    /*!
    *  \brief destruktor
    */
    virtual ~interfejs_rysowania() {}
    /*!
    *  \brief metoda abstrakcyjna, rysuje obiekt
    */
    virtual void rysuj() = 0;
    /*!
    *  \brief metoda wymazujaca obiekt
    */
    virtual void usun_obiekt()
    {
        gnuplot->erase_shape(obiekt_id);
    }
};

#endif