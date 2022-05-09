#include "Wektor.hh"

/****************************
*   Konstruktory dla klasy wektor
*   Pierwszy konsktruktor bezargumentowy zeruje caly wektor
*   Drugi konstruktor przyjmuje 3 liczby typu double 
*   Trzeci wektor przyjumuje tablice 3 elementowa
*
****************************/

Wektor::Wektor()
{
    for(int i(0); i < ROZMIAR; i++)
    {
        this->tab[i] = 0;
    }
}

Wektor::Wektor(double x, double y, double z)
{   
    tab[0] = x;
    tab[1] = y;
    tab[2] = z;
}

Wektor::Wektor(const double tab[])
{   
    for(int i(0); i < ROZMIAR; i++)
    {
        this->tab[i] = tab[i];
    }
}

/****************************
*   Przeciazenie operatora dodawania 
*   
*
****************************/
Wektor Wektor::operator + (const Wektor &Arg1) const
{
    Wektor wynik;
    for(int i(0); i < ROZMIAR; i++)
    {
       wynik[i] = this->tab[i] + Arg1[i];
    }  
    return wynik;
}

/****************************
*   Przeciazenie operatora odejmowania 
*   
*
****************************/

Wektor Wektor::operator - (const Wektor &Arg1) const
{
    Wektor wynik;
    for(int i(0); i < ROZMIAR; i++)
    {
        wynik[i] = this->tab[i] - Arg1[i];
    }  
    return wynik;
}

/****************************
*   Przeciazenie operatora mnozenia 
*   Argumentami sa 2 wektory
*   Funckja mnozy wektory przez siebie skalarnia 
*   Wynikiem jest liczba typu double
****************************/

double Wektor::operator * (const Wektor &Arg1) const
{
    double wynik = 0;
    for(int i(0); i < ROZMIAR; i++)
    {
        wynik += (this->tab[i] * Arg1[i]);
    }
    return wynik;
}

/****************************
*   Przeciazenie operator mnozenia
*   Argumentami sa liczba oraz wektor
*   Wynikiem jest wektor pomnozony przez liczbe 
****************************/
Wektor Wektor::operator * (const double &liczba) const
{
    Wektor wynik;
    for(int i(0); i < ROZMIAR; i++)
    {
        wynik[i] = this->tab[i] * liczba;
    }
    return wynik;
}

/****************************
*   Przeciazenie operatora dzielenia
*   Argumentami sa liczba oraz wektor
*   Wynikiem jest wektor podzielony przez liczbe
****************************/

Wektor Wektor::operator / (const double &liczba) const
{
    Wektor wynik;
    if(liczba == 0)
    {
        std::cerr << "Dzielenie przez zero!" << std::endl;
        exit(1);
    }else 
    {
        for(int i(0); i < ROZMIAR; i++)
        {
            wynik[i] = this->tab[i] / liczba;
        }
    }

    return wynik;
}

/****************************
*   Przeciazenie operatora porownania 
*   
*
****************************/

bool Wektor::operator == (const Wektor &Arg1) const
{
    for(int i(0); i < ROZMIAR; i++)
    {
        if(fabs(this->tab[i] != Arg1[i]) > FLT_EPSILON)
        {return false; }
    }

    return true;
}

bool Wektor::operator != (const Wektor &Arg1) const
{
    return !(*this == Arg1);
}

/****************************
*   Przeciazenia opearatora indeksowania 
*
****************************/

const double &Wektor::operator [] (const int &index) const
{
    if(index < 0 && index > ROZMIAR)
    {
        std::cerr << "Zly indeks!" << std::endl;
        exit(1);
    }

    return tab[index];
}

double &Wektor::operator [] (const int &index)
{
    if(index < 0 && index > ROZMIAR)
    {
        std::cerr << "Zly indeks!" << std::endl;
        exit(1);
    }

    return tab[index];
}

/****************************
*   Funckja wyliczajaca dlugosc wektora
*   
*
****************************/

double Wektor::dlugosc() const
{
    return sqrt((*this) * (*this));
}

std::ostream &operator << (std::ostream &strm, const Wektor &Arg1)
{
    for(int i(0); i < ROZMIAR; i++)
    {
        strm << Arg1[i];
        if(i != ROZMIAR - 1)
        {
            strm << " ";
        }
    }
    return strm;
}

std::istream &operator >> (std::istream &strm, Wektor &Arg1)
{
    for(int i(0); i < ROZMIAR; i++)
    {
        strm >> Arg1[i];
    }

    return strm;
}