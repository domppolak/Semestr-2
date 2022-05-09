#ifndef _UkladRownanLin_HH
#define _UkladRownanLin_HH

#include "macierz.hh"

/********************
*   Klasa uklad_rownan jest tutaj zdefioniowana wraz z metodami
*   Mamy tutaj 2 argumenty:
*   macierz wspolczynnikow 
*   wektor wyrazow wolnych
**********************/

class uklad_rownan
{
    macierz arg1; //macierz wspolczynnikow
    Wektor arg2; //wyrazy wolne
public:
    uklad_rownan();
    uklad_rownan(macierz arg11, Wektor arg22) : arg1(arg11), arg2(arg22) {}
    const macierz & get_arg1() const;
    const Wektor & get_arg2() const;
    void set_arg1 (const macierz &);
    void set_arg2 (const Wektor &);
    Wektor Oblicz() const;
};

Wektor wektor_bledu(const uklad_rownan &, const Wektor &);
std::ostream &operator << (std::ostream &, const uklad_rownan &);
std::istream &operator >> (std::istream &, uklad_rownan &);
#endif