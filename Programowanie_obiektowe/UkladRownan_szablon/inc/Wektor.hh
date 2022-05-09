#ifndef _WEKTOR_HH
#define _WEKTOR_HH

#include "rozmiar.hh"
#include "Zespolona.hh"

template <class T, int size>
class Wektor
{
    T tab[size];
public:
    Wektor() {for (T &TAB : tab) TAB = 0;}
    Wektor(T TAB[]);
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
};

template<class T, int size>
std::ostream &operator << (std::ostream &strm, const Wektor<T,size> &);
template<class T, int size>
std::istream &operator >> (std::istream &strm, Wektor<T,size> &);


#endif

