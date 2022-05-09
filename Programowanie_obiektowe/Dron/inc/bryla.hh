#ifndef _BRYLA_HH
#define _BRYLA_HH

#include "inter_rysowania.hh"
#include "macierz_obrotu.hh"

using std::vector;

/*!
*  \brief Klasa abstrakcyjna, ktora reprezentuje dowolna bryle
*  
*    Stanowi interfejs dla klas pochodnych
*   Posiada wspolne metody dla kazdej bryly: obroc, przemiesc
*/
class bryla : public interfejs_rysowania
{

protected:
    /*!
    *  \brief macierz obrotu przechowujaca orientacje bryly
    */
    macierz_ob orientacja;
    /*!
    *  \brief zmienna przechowujaca punkt srodkowy bryly
    */
    Wektor3D srodek_bryly;
    
    static int aktualna_liczba_bryl;
    static int calkowita_liczba_bryl;

public:
    /*!
    *  \brief konstruktor
    *  \param wsk - lacze do gnuplota
    *  \param K - zmienna przechowujaca kolor bryly
    *  \param M - macierz stanowiaca orientacje bryly
    *  \param S - punkt srodka bryly
    */
    bryla(shared_ptr<Draw3DAPI> wsk, string K, macierz_ob M, Wektor3D S) 
    : interfejs_rysowania(wsk, K)
    , orientacja(M)
    , srodek_bryly(S) 
    {
        ++aktualna_liczba_bryl;
        ++calkowita_liczba_bryl;
    }

    /*!
    *  \brief konstruktor
    *  \param wsk - lacze do gnuplota
    *  \param K - zmienna przechowujaca kolor bryly
    *  \param S - punkt srodka bryly
    */
    bryla(shared_ptr<Draw3DAPI> wsk, string K, macierz_ob M) 
    : interfejs_rysowania(wsk, K)
    , orientacja(M) 
    {
        ++aktualna_liczba_bryl;
        ++calkowita_liczba_bryl;
    }

    /*!
    *  \brief destruktor
    */
    virtual ~bryla() 
    {
        --aktualna_liczba_bryl;
    }

    /*!
    *  \brief metoda do zmiany wspolrzednych srodka bryly
    *  \param we - nowe wspolrzedne srodka bryly
    */
    void set_srodek(const Wektor3D & we) { srodek_bryly = we; }
    /*!
    *  \brief metoda zwracajaca wspolrzedne srodka bryly
    */
    Wektor3D get_srodek() {return srodek_bryly; }
    /*!
    *  \brief metoda abstrakcyjna do rysowania bryly
    */
    virtual void rysuj() = 0;
    /*!
    *  \brief metoda przsuwajaca bryle o podany wektor
    *  \param we - wektor o jaki ma sie przesunac bryla
    */
    virtual void  przemiesc (const Wektor3D &we) 
    { 
        srodek_bryly = srodek_bryly + we;
        usun_obiekt();
        rysuj(); 
    }
    /*!
    *  \brief metoda zmieniajaca orientacje bryly 
    *  \param kat - kat zmiany orientacji
    */
    virtual void obroc(const double &kat)
    {
        macierz_ob tmp(os_z, kat);
        orientacja = macierz_ob(orientacja * tmp);
        usun_obiekt();
        rysuj();
    }

    static int get_calkowita_liczba_bryl() { return calkowita_liczba_bryl; }
    static int get_aktualna_liczba_bryl() {return aktualna_liczba_bryl; }

}; 


#endif