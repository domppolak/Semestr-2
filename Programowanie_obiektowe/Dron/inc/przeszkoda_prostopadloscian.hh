#ifndef _PRZESZKODA_PROSTOPADLOSCIENNA_HH
#define _PRZESZKODA_PROSTOPADLOSCIENNA_HH

#include "przeszkoda.hh"
#include "prostopadloscian.hh"

class przeszkoda_prost : public prostopadloscian, public przeszkoda
{   
public:
    przeszkoda_prost(shared_ptr<Draw3DAPI> wsk, string K, macierz_ob M, Wektor3D S, Wektor3D tablica[])
    : prostopadloscian(wsk, K, M, S, tablica) {}

    void rysuj() { prostopadloscian::rysuj(); }

    bool czy_kolizja(const interfejs_drona & Dron)
    {   
        if((Dron.get_srodek() - srodek_bryly).dlugosc() < 0.4 * Dron.get_promien())
        {
            std::cerr << "Kolzija z pudelkiem" << std::endl;
            return true;
        }

        return false;
    }

    void obroc_y(const double kat)
    {
        macierz_ob tmp(os_y, kat);
        orientacja = macierz_ob(orientacja * tmp);
        usun_obiekt();
        rysuj();
    }
};
#endif