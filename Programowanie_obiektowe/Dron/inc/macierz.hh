#ifndef _MACIERZ_HH
#define _MACIERZ_HH

#include "wektor.hh"

template <class T, int size>
class macierz
{
protected:
    Wektor<T, size> tab[size];
public:
    macierz();
    macierz(Wektor<T, size> tab[]);
    virtual ~macierz() {};
    const Wektor<T, size> &operator[] (unsigned int) const;
    Wektor<T, size> &operator [] (unsigned int);
    macierz<T, size> operator + (const macierz<T, size> &) const;
    macierz<T, size> operator - (const macierz<T, size> &) const;
    macierz<T, size> operator * (const macierz<T, size> &) const;
    macierz<T, size> operator * (const T &) const;
    Wektor<T, size> operator * (const Wektor<T, size> &) const;
    T wyznacznik() const;
    bool operator == (const macierz<T, size> &) const;
    bool operator != (const macierz<T, size> &) const;
    macierz<T, size> transponuj() const;
    void jednostkowa();
    void transponuj();
};

template<class T, int size>
std::ostream &operator << (std::ostream &, const macierz<T, size>&);
template<class T, int size>
std::istream &operator >> (std::istream &, macierz<T, size> &);

#endif







