#ifndef _MACIERZ_HH
#define _MACIERZ_HH

#include "Wektor.hh"

/************
*   Enum zdefuniowany do wybory metody liczenia wyznacznika
*
*************/
enum metoda_wyznacznika {m_gauss, m_sarrus, m_la_place};

/**********
*   Zdefiniowana klasa wraz  z metodami do niej
*
***********/

class macierz
{
    Wektor tab[ROZMIAR];
    double gauss(macierz) const;
    double la_place(int, macierz, int, Wektor) const;
    double sarrus(macierz) const;
public:
    macierz();
    macierz(const Wektor tab[]);
    macierz(Wektor, Wektor, Wektor);
    const Wektor &operator [] (const int&) const;
    Wektor &operator [] (const int&);
    macierz operator + (const macierz &) const;
    macierz operator - (const macierz &) const;
    macierz operator * (const macierz &) const;
    macierz operator * (const double &) const;
    Wektor operator * (const Wektor &) const;
    double wyznacznik(const metoda_wyznacznika &) const;
    void transponuj();
};


std::ostream &operator << (std::ostream &, const macierz&);
std::istream &operator >> (std::istream &, macierz &);
#endif