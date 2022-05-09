#include "wektor.hh"

template<class T, int size>
int Wektor<T, size>::aktualna_liczba_wektorow = 0;

template<class T, int size>
int Wektor<T, size>::calkowita_liczba_wektorow = 0;

template<class T, int size>
Wektor<T, size>::Wektor(T TAB[])
{
    for(int i(0); i < size; i++)
    {
        tab[i] = TAB[i];
    }

    ++aktualna_liczba_wektorow;
    ++calkowita_liczba_wektorow;
}

template<class T, int size>
Wektor<T, size>::Wektor(double x, double y, double z)
{
    tab[0] = x;
    tab[1] = y;
    tab[2] = z;
    ++aktualna_liczba_wektorow;
    ++calkowita_liczba_wektorow;
}
template<class T, int size>
Wektor<T, size>::Wektor(const Wektor & We)
{ 
    for(int i(0); i < size; i++)
    { tab[i] = We[i]; }
    ++aktualna_liczba_wektorow; 
    ++calkowita_liczba_wektorow; 
}

template<class T, int size>
const T &Wektor<T, size>::operator[] (unsigned int index) const
{
    if(index < 0 && index > size)
    {
        std::cerr << "Zly indeks!" << std::endl;
        exit(1);
    } 

    return tab[index];
}

template<class T, int size>
T &Wektor<T, size>::operator[] (unsigned int index)
{
    if(index < 0 && index > size)
    {
        std::cerr << "Zly indeks!" << std::endl;
        exit(1);
    } 

    return tab[index];
}

template<class T, int size>
Wektor<T,size> Wektor<T,size>::operator + (const Wektor<T,size> &Arg1) const
{
    Wektor wynik;
    for(int i(0); i < size; i++)
    {
       wynik[i] = this->tab[i] + Arg1[i];
    }  
    return wynik;
}

template<class T, int size>
Wektor<T,size> Wektor<T,size>::operator - (const Wektor<T,size> &Arg1) const
{
    Wektor wynik;
    for(int i(0); i < size; i++)
    {
        wynik[i] = this->tab[i] - Arg1[i];
    }  
    return wynik;
}

template<class T, int size>
T Wektor<T,size>::operator * (const Wektor<T,size> &Arg1) const
{
    T wynik(0.0);
    for(int i(0); i < size; i++)
    {
        wynik = wynik + (this->tab[i] * Arg1[i]);
    }
    return wynik;
}

template<class T, int size>
Wektor<T,size> Wektor<T,size>::operator * (const T &liczba) const
{
    Wektor<T,size> wynik;
    for(int i(0); i < size; i++)
    {
        wynik[i] = this->tab[i] * liczba;
    }
    return wynik;
}

template<class T, int size>
Wektor<T,size> Wektor<T,size>::operator / (const T &liczba) const
{
    Wektor<T,size> wynik;
    T rowna(0.0);
    if(liczba == rowna)
    {
        std::cerr << "Dzielenie przez zero!" << std::endl;
        exit(1);
    }else 
    {
        for(int i(0); i < size; i++)
        {
            wynik[i] = this->tab[i] / liczba;
        }
    }

    return wynik;
}

template<class T, int size>
bool Wektor<T, size>::operator == (const Wektor<T, size> &Arg1) const
{
    for(int i(0); i < size; i++)
    {
        if(fabs(this->tab[i] != Arg1[i]) > FLT_EPSILON)
        {return false; }
    }

    return true;
}

template<class T, int size>
bool Wektor<T, size>::operator != (const Wektor<T, size> &Arg1) const
{
    return !(*this == Arg1);
}

template<class T, int size>
std::ostream &operator << (std::ostream &strm, const Wektor<T,size> &Arg1)
{
    for(int i(0); i < size; i++)
    {
        strm <<  Arg1[i];
        if(i != size - 1)
        {
            strm << " ";
        }
    }
    return strm;
}

template<class T, int size>
std::istream &operator >> (std::istream &strm, Wektor<T,size> &Arg1)
{
    for(int i(0); i < size; i++)
    {
        strm >> Arg1[i];
    }

    return strm;
}

template<class T, int size>
double Wektor<T, size>::dlugosc() const
{
    return sqrt((*this) * (*this));
}

template<class T, int size>
const drawNS::Point3D Wektor<T,size>::punkt() const
{
    drawNS::Point3D punkt(tab[0],tab[1],tab[2]);
    return punkt;
}