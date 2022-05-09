#ifndef _INTER_DRONA_HH
#define _INTER_DRONA_HH

#include "prostopadloscian.hh"

/*!
*  \brief klasa abstrakcyjna bedaca interfejsem drona
*/
class interfejs_drona
{
public:
    /*!
    *  \brief konstruktor
    *  \param wsk - lacze do gnuplota
    *  \param K - zmienna przechowujaca kolor bryly
    *  \param M - masierz stanowiaca orientacje bryly
    *  \param S - punkt sroka bryly
    *  \param tablica - tablica 8 wektorow reprezentujaca wierzcholki 
    */
    //interfejs_drona(shared_ptr<Draw3DAPI> wsk, string K, macierz_ob M, Wektor3D S, Wektor3D tablica[])
    //: prostopadloscian(wsk, K, M, S, tablica) {}
    /*!
    *  \brief destruktor
    */ 
    virtual ~interfejs_drona() {}

    /*!
    *  \brief metoda odpowiedzialna za przesuwanie calego obiektu
    *  \param odleglosc - o ile ma sie przesunac obiekt
    *  \param kat - kat o jaki ma sie obrocic obiekt
    */  
    virtual void przesun(const double &, const double &) = 0;
        /*!
    *   \brief metoda obracaja wokol osi y
    */
    virtual void obroc_os_y(const double ) = 0;
    /*!
    *  \brief metoda sluza do zmiany orientacji bryly
    *  \param kat - kat o jaki ma sie obrocic obiekt
    */
    virtual void obroc(const double ) = 0;
    virtual double get_promien()const = 0;
    virtual Wektor3D get_srodek()const = 0;
};

#endif