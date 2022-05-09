#ifndef _UKLAD_HH
#define _UKLAD_HH

#include "Macierz.hh"

template<class T, int size>
class uklad_rownan
{
    macierz<T, size> arg1; //macierz wspolczynnikow
    Wektor<T, size> arg2; //wyrazy wolne
public:
    uklad_rownan() {}; 
    uklad_rownan(macierz<T, size> arg11, Wektor<T, size> arg22) : 
        arg1(arg11)
        , arg2(arg22) {};
    const macierz<T, size> & get_arg1() const;
    const Wektor<T, size> & get_arg2() const;
    void set_arg1 (const macierz<T, size> &);
    void set_arg2 (const Wektor<T, size> &);
    Wektor<T, size> Oblicz() const;
    //Wektor<T, size> wektor_bledu (const Wektor<T, size> &) const;
};

template<class T, int size>
std::ostream &operator << (std::ostream &, const uklad_rownan<T, size> &);
template<class T, int size>
std::istream &operator >> (std::istream &, uklad_rownan<T, size> &);
template<class T, int size>
Wektor<T, size> wektor_bledu (const uklad_rownan<T, size> &, const Wektor<T, size> &);
#endif