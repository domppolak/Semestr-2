#include "dron.hh"

void dron::przesun(const double &odleglosc, const double &kat)
{
        //Wektor3D przesuniecie(odleglosc, 0, 0);
        Wektor3D przesuniecie(0,0,0);
        double kat_rad = M_PI * kat / 180;
        przesuniecie[0] = cos(kat_rad) * odleglosc;
        przesuniecie[1] = 0.0;
        przesuniecie[2] = sin(kat_rad) * odleglosc;
        //obroc_os_y(kat);
        srodek_bryly = srodek_bryly + orientacja * przesuniecie;
        prostopadloscian::przemiesc(przesuniecie);
        lewy_wirnik.obrot(15);
        prawy_wirnik.obrot(15);
        usun_obiekt();
        //rysuj();
    
}

void dron::obroc_os_y(const double kat)
{
    macierz_ob tmp(os_y, kat);
    orientacja = macierz_ob(orientacja * tmp);
    usun_obiekt();
    rysuj();
}

void dron::rysuj()
{
    prostopadloscian::rysuj();
    lewy_wirnik.rysuj(srodek_bryly + orientacja * ((wierzcholki[3] + wierzcholki[7]) / 2), orientacja);
    prawy_wirnik.rysuj(srodek_bryly + orientacja * ((wierzcholki[0] + wierzcholki[4]) / 2), orientacja);
    //std::cerr << "Dron "<< kolor << std::endl;
}

void dron::usun_obiekt()
{
    prostopadloscian::usun_obiekt();
    lewy_wirnik.usun_obiekt();
    prawy_wirnik.usun_obiekt();
    gnuplot->redraw();
}

void dron::obroc(const double kat)
{   

    prostopadloscian::obroc(kat);
    lewy_wirnik.obroc(kat);
    prawy_wirnik.obroc(kat);
    lewy_wirnik.obrot(15);
    prawy_wirnik.obrot(15);
    usun_obiekt();
    //rysuj();
}

bool dron::czy_kolizja(const interfejs_drona & Dron)
{   
    if((srodek_bryly - Dron.get_srodek()).dlugosc() < Dron.get_promien())
    { 
        std::cerr << "Kolzija z dronem" << std::endl;
        return true;
    }

    return false;
}