#ifndef _WEKTOR_HH
#define _WEKTOR_HH

#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <fstream>
#include <cfloat>
#include <iomanip>
#include "Draw3D_api_interface.hh"

template <class T, int size>
class Wektor
{
    T tab[size];
    static int aktualna_liczba_wektorow;
    static int calkowita_liczba_wektorow;
public:
    Wektor() 
    {
        //for (T &TAB : tab) TAB = 0; 
        for(int i(0); i < size; i++)
        { tab[i] = 0.0; }
        ++aktualna_liczba_wektorow; 
        ++calkowita_liczba_wektorow; 
    }
    Wektor(T TAB[]);
    Wektor(double x, double y, double z);
    Wektor(const Wektor<T, size> & );
    ~Wektor() { --aktualna_liczba_wektorow; }
    const T &operator [] (unsigned int )const;
    T &operator [] (unsigned int );
    Wektor<T, size> operator + (const Wektor<T, size> &) const;
    Wektor<T, size> operator - (const Wektor<T, size> &) const;
    T operator * (const Wektor<T, size> &) const; //skalarnie
    Wektor<T, size> operator * (const T &) const;
    Wektor<T, size> operator / (const T &) const;
    bool operator == (const Wektor<T, size> &) const;
    bool operator != (const Wektor<T, size> &) const; 
    double dlugosc() const;
    const drawNS::Point3D punkt() const;
    static int get_aktualna_liczba_wektorow() { return aktualna_liczba_wektorow; }
    static int get_calkowita_liczba_wektorow() { return calkowita_liczba_wektorow; }
};

template<class T, int size>
std::ostream &operator << (std::ostream &strm, const Wektor<T,size> &);
template<class T, int size>
std::istream &operator >> (std::istream &strm, Wektor<T,size> &);


#endif