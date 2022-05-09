#ifndef _WEKTOR_HH
#define _WEKTOR_HH

#include "rozmiar.hh"
#include<iostream>
#include<cmath>
#include<cfloat>

/*******************************************
*    Tutaj zostala zdefiniowana klasa wraz z metodami do niej 
*
********************************************/

class Wektor
{
    double tab[ROZMIAR];
public: 
    Wektor();
    Wektor(double, double, double);
    Wektor(const double tab[]);
    Wektor operator + (const Wektor &) const;
    Wektor operator - (const Wektor &) const;
    double operator * (const Wektor &) const; //skalarnie
    Wektor operator * (const double &) const;
    Wektor operator / (const double &) const;
    bool operator == (const Wektor &) const;
    bool operator != (const Wektor &) const;   
    const double &operator [] (const int &) const;
    double & operator [] (const int &);
    double dlugosc() const; 
};

/****************
*   Przeciazenia operatorow wczytywania oraz wyswietlania
*
******************/
std::ostream &operator << (std::ostream &strm, const Wektor &);
std::istream &operator >> (std::istream &strm, Wektor &);

#endif