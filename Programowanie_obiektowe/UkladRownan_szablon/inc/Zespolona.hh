#ifndef _ZESPOLONA_HH
#define _ZESPOLONA_HH

#include<iostream>
#include<string>
#include<cmath>
#include<cstring>
#include<fstream>
#include<cfloat>
#include <iomanip> 

/*
*   Plik zawieta klase liczba zespolona wraz z metodami tej klasy
*/

class LZespolona
{
    double re;
    double im;
public:
    explicit LZespolona(double re1 = 0, double im1 = 0) : 
        re(re1)
        , im(im1){};
    void set_re(double);
    void set_im(double);
    double get_re() const;
    double get_im() const;
    LZespolona &operator = (const LZespolona &Sk1);
    LZespolona &operator = (const double &);
    LZespolona operator + (const LZespolona &Sk1) const;
    LZespolona operator - (const LZespolona &Sk1) const;
    LZespolona operator * (const LZespolona &Sk1) const;
    LZespolona operator * (const double &) const;
    LZespolona operator / (const LZespolona &) const;
    LZespolona operator / (const double &liczba) const;
    bool operator == (const LZespolona &Sk1) const;
    bool operator != (const LZespolona &Sk1) const;
    double modul() const;
    LZespolona sprzezenie() const;
    void sprzezenie();
};

/*
*   Przeciazenia operatow wczytywania liczby zespolonej
*
*/

std::ostream &operator << (std::ostream &wyjscie, const  LZespolona &Sk1);
std::istream &operator >> (std::istream &wejscie, LZespolona &Sk1);

#endif
